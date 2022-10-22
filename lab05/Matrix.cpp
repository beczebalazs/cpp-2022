//
// Created by Balazs on 10/19/2022.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols): mRows(mRows), mCols(mCols) {
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double [mCols];
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(a, b);
    for (int i=0;i<mRows;++i)
    {
        for (int j=0;j<mCols;++j)
        {
            mElements[i][j]=dist(mt);
        }
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[what.mRows];
    for (int i = 0; i < what.mRows; ++i) {
        this->mElements[i] = new double [what.mCols];
        for (int j = 0; j < what.mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[what.mRows];
    for (int i = 0; i < what.mRows; ++i) {
        this->mElements[i] = new double [what.mCols];
        for (int j = 0; j < what.mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
    for (int i = 0; i < what.mRows; ++i) {
        delete[] what.mElements[i];
    }
    delete[] what.mElements;
    what.mRows = 0;
    what.mCols = 0;
}


Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
    this->mRows = 0;
    this->mCols = 0;
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("Incompatible Matrix dimensions!\n");
    }
    Matrix m(x.mRows,x.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            m.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return m;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mCols){
        throw out_of_range("Incompatible Matrix dimensions!\n");
    }
    Matrix m(x.mRows,y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            for (int k = 0; k < x.mCols; ++k) {
                m.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return m;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    cout << "Matrix:\n";
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

double *Matrix::operator[](int index) {
    if (index < 0 || index >= mCols) {
        throw out_of_range("Index does not exist!\n");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 || index >= mCols) {
        throw out_of_range("Index does not exist!\n");
    }
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw out_of_range("Not matching dimensions!\n");
    }
    delete[] this->mElements;
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if (this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw out_of_range("Not matching dimensions!\n");
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
    mat.mElements = nullptr;
    mat.mRows = 0;
    mat.mCols = 0;
    return *this;
}

//
// Created by Balazs on 10/26/2022.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for (int i = 0; i < what.capacity-1; ++i) {
        out << what.coefficients[i] << "*X^" << (what.capacity-1-i) <<" + ";
    }
    out << what.coefficients[what.capacity-1] << " ";
    return out;
}

Polynomial::~Polynomial() {
    if(coefficients != nullptr){
            delete[] coefficients;
            capacity=0;
    }
}

double Polynomial::evaluate(double x) const {
    double p = this->coefficients[0];
    for (int i = 0; i < this->capacity-1; ++i) {
        p = p * x + coefficients[i+1];
    }
    return p;
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double [that.capacity];
    for (int i = 0; i < that.capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}


Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = new double [that.capacity];
    for (int i = 0; i < that.capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial Polynomial::derivative() const {
    Polynomial der(this->capacity-2,new double [this->capacity-1]);
    for (int i = 0, j = this->capacity-1; i < der.capacity && j > 0; ++i, --j) {
        der.coefficients[i] = this->coefficients[i] * j;
    }
    return der;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial res(a);
    for (int i = 0; i < a.capacity; ++i) {
        res.coefficients[i] *= -1;
    }
    return res;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if (a.capacity > b.capacity) {
        Polynomial res(a);
        int j = 0;
        for (int i = a.capacity-b.capacity; i < a.capacity; ++i) {
            res.coefficients[i] += b.coefficients[j++];
        }
        return res;
    } else {
        Polynomial res(b);
        int j = 0;
        for (int i = b.capacity-a.capacity; i < b.capacity; ++i) {
            res.coefficients[i] += a.coefficients[j++];
        }
        return res;
    }
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if (a.capacity > b.capacity) {
        Polynomial res(a);
        int j = 0;
        for (int i = a.capacity-b.capacity; i < a.capacity; ++i) {
            res.coefficients[i] -= b.coefficients[j++];
        }
        return res;
    } else {
        Polynomial res(b);
        int j = 0;
        for (int i = b.capacity-a.capacity; i < b.capacity; ++i) {
            res.coefficients[i] -= a.coefficients[j++];
        }
        return res;
    }
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int size = a.degree()+b.degree();
    Polynomial res(size,new double [size+1]{0});
    for (int i = 0; i < a.capacity; ++i) {
        for (int j = 0; j < b.capacity; ++j) {
            res.coefficients[i+j] += a.coefficients[i]*b.coefficients[j];
        }
    }
    return res;
}
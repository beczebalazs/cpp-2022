#include "functions.h"

using namespace std;
int main(int argc, char * argv[]) {
    //-----------1.feladat
    cout<<"ELSO FELDAT:\n";
    for (int i=0;i<127;i++)
        cout<<countBits(i)<<endl;

    //------------2. feladat
    cout<<"\nMASODIK FELADAT:\n";
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }

    //-----------3.feladat
    cout<<"\nHARMADIK FELADAT:\n";
    double arr[]={2.0, 3.0, 5.5, 7.9, 9.1};
    print_container(arr, 5);
    cout<<"Atlag: "<<mean(arr, 5)<<endl;

    //----------4.feladat
    cout<<"\nNEGYEDIK FELADAT:\n";
    cout<<"Tomb:";
    print_container(arr, 5);
    cout<<"Standard deviaton: "<<stddev(arr, 5)<<endl;

    //----------5.feladat
    cout<<"\nOTODIK FELADAT:\n";
    cout<<"Tomb:";
    print_container(arr, 5);
    pair<double, double> pair1=max2(arr, 5);
    cout<<"Maximum ertekek:"<<pair1.first<<", "<<pair1.second<<endl;

    //----------1.Feladat(String)
    cout<<"ELSO FELADAT(STRING)"<<endl;
    cout<<"Tomb:";
    for (int i=1;i<argc;i++)
        cout<<argv[i]<<" ";
    cout<<endl;
    cout<<"Numerikus argumentumok osszege: "<<calcSum(argv, argc)<<endl;

    //----------2.Feladat(String)
    cout<<"MASODIK FELADAT(STRING)"<<endl;
    string myStr="This is a six word sentence";
    cout<<myStr<<endl;
    cout<<"Szavak szama: "<<countWords(myStr)<<endl;

    //----------3.Feladat(String)
    cout<<"HARMADIK FELADAT(STRING)"<<endl;
    string test_string="abc123def";
    cout<<"Eredeti:"<<test_string<<endl;
    cout<<"Kodolt: "<<code(test_string)<<endl;

    //----------4.Feladat(String)
    cout<<"NEGYEDIK FELADAT(STRING)"<<endl;
    cout<<"Irjon be mondatokat '0' vegjelig!"<<endl;
    getline(cin, myStr);
    while (myStr!="0")
    {
        cout<<capitalizeWords(myStr)<<endl;
        getline(cin, myStr);
    }

    //-------PLUSZ FELADAT
    mostCommonWords("D:\\Egyetem\\3.FELEV\\Fejlettprog\\Labor\\cpp-labor\\cmake-build-debug\\test.txt", 5);
    return 0;
}

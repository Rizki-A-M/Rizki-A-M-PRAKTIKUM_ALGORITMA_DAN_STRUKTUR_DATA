#include<iostream>

using namespace std;

struct Inputan
{
    char Huruf;
    string Kata;
    int Angka;
};

int main(){
    Inputan data;

    //Input Data
    cout << "\n------------------------------------------\n";
    cout << "a. Masukkan Sebuah huruf = ";
    cin >> data.Huruf;
    cout << "b. Masukkan Sebuah kata = ";
    cin >> data.Kata;
    cout << "c. Masukkan Angka = ";
    cin >> data.Angka;

    //Output Data
    cout << "d. Huruf yang Anda masukkan adalah " << data.Huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << data.Kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << data.Angka << endl;
    cout << "------------------------------------------\n";
    return 0;
}
#include<iostream>

using namespace std;

struct Kendaraan
{
    char Plat_Nomor[15];
    char Jenis_Kendaraan[30];
    char Nama_Pemilik[50];
    char Alamat[100];
    char Kota[30];
};

int main(){
    Kendaraan data;

    //Input Data
    cout << "\n------------------------------------------------\n";
    cout << "a. Plat Nomor Kendaraan : ";
    cin.getline(data.Plat_Nomor, 15);
    cout << "b. Jenis Kendaraan      : ";
    cin.getline(data.Jenis_Kendaraan, 30);
    cout << "c. Nama Pemilik         : ";
    cin.getline(data.Nama_Pemilik, 50);
    cout << "d. Alamat               : ";
    cin.getline(data.Alamat, 100);
    cout << "e. Kota                 : ";
    cin.getline(data.Kota, 30);
    cout << "------------------------------------------------\n\n";

    //Output Data
    cout << "------------------------------------------------\n";
    cout << "a. Plat Nomor Kendaraan : " << data.Plat_Nomor << endl;
    cout << "b. Jenis Kendaraan      : " << data.Jenis_Kendaraan << endl;
    cout << "c. Nama Pemilik         : " << data.Nama_Pemilik << endl;
    cout << "d. Alamat               : " << data.Alamat << endl;
    cout << "e. Kota                 : " << data.Kota << endl;
    cout << "------------------------------------------------\n";

    return 0;
}
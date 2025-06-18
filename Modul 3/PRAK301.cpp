#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode
{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan [2];
string dataBaru, dataDelete;

void Init();
int Kosong();

void TambahDepan();
void TambahBelakang();
void HapusDepan();
void HapusBelakang();
void Tampilkan();
void Reset();
void CariData();
void HapusData();
void SisipkanSebelum();
void SisipkanSetelah();

int main()
{
    do
    {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Keluar"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil = atoi(pilihan);

        switch(pil)
        {
        case 1:
            TambahDepan();
            break;
        case 2:
            TambahBelakang();
            break;
        case 3:
            HapusDepan();
            cout<<"Data \""<<dataDelete<<"\" yang berada di depan telah berhasil dihapus."<<endl;
            break;
        case 4:
            HapusBelakang();
            cout<<"Data \""<<dataDelete<<"\" yang berada di belakang telah berhasil dihapus."<<endl;
            break;
        case 5:
            Tampilkan();
            break;
        case 6:
            Reset();
            break;
        case 7:
            CariData();
            break;
        case 8:
            HapusData();
            break;
        case 9:
            SisipkanSebelum();
            break;
        case 10:
            SisipkanSetelah();
            break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by Rizki Adhitiya Maulana (2410817110014)"<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");
    }
    while (pil<11);
}

void Init()
{
    head = NULL;
    tail = NULL;
}

int Kosong()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

void TambahDepan()
{
    cout<<"Masukkan Data : ";
    TNode *baru;
    baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(Kosong() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout<<"Data \""<<dataBaru<<"\" telah berhasil dimasukkan di bagian depan."<<endl;
}

void TambahBelakang()
{
    cout<<"Masukkan Data : ";
    TNode *baru;
    baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(Kosong() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout<<"Data \""<<dataBaru<<"\" telah berhasil dimasukkan di bagian belakang."<<endl;
}

void HapusDepan()
{
    if(Kosong() == 0)
    {
        TNode *hapus;
        hapus = head;
        dataDelete = hapus->data;

        if(head != tail)
        {
        head = head->next;
        tail->next = head;
        }
        else
        {
            Init();
        }

        delete hapus;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void HapusBelakang()
{
    if(Kosong() == 0)
    {
        TNode *hapus, *newTail;
        hapus = tail;
        dataDelete = hapus->data;

        if(head != tail)
        {
            newTail = head;
            while(newTail->next != tail)
            {
                newTail = newTail->next;
            }
            tail = newTail;
            tail->next = head;
        }
        else
        {
            Init();
        }
        delete hapus;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void Tampilkan()
{
    if(Kosong() == 0)
    {
        TNode *bantu;
        bantu = head;

        do
        {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        while (bantu != head);
        cout<<endl;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void Reset()
{
    if(Kosong() == 0)
    {
        TNode *bantu, *hapus;
        bantu = head;

        do
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        while (bantu != head);
        Init();
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void CariData()
{
    if(Kosong() == 0)
    {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu, *hapus, *newTail, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            if(cari == bantu->data)
            {
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                    <<"merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;

                do
                {
                    if(cari == bantuTampilkan->data)
                    {
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    }
                    else
                    {
                        cout<<bantuTampilkan->data<<' ';
                    }
                    bantuTampilkan = bantuTampilkan->next;
                }
                while (bantuTampilkan != head);

                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        }
        while (bantu != head);

        if(apaDitemukan == false)
        {
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void HapusData()
{
    if(Kosong() == 0)
    {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            bantu2 = bantu;
            if(cari == bantu->data)
            {
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail)
                {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        }
        while (bantu != head);
        
        if(apaDitemukan == true)
        {
            for(int i=0; i<hitung; i++)
            {
                if(hapus[i] == head)
                {
                    HapusDepan();
                }
                else if(hapus[i] == tail)
                {
                    HapusBelakang();
                }
                else
                {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus."<<endl;
        }
        else
        {
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void SisipkanSebelum()
{
    if(Kosong() == 0)
    {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda;

        bantu = head;
        sebelum = tail;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do
        {
            if(nextData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
            {
                sebelum = bantu;
                bantu = bantu->next;
            }
        }
        while (bantu != head);

        if(apaAda == true)
        {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu;

            sebelum->next = baru;

            if(bantu == head)
            {
                head = baru;
            }
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        }
        else
        {
            cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void SisipkanSetelah()
{
    if(Kosong() == 0)
    {
        TNode *bantu;
        string prevData;
        bool apaAda;

        bantu = head;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do
        {
            if(prevData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
            {
                bantu = bantu->next;
            }
        }
        while (bantu != head);

        if(apaAda == true)
        {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu->next;

            bantu->next = baru;

            if(bantu == tail)
            {
                tail = baru;
            }
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<prevData<<"\"."<<endl;
        }
        else
        {
            cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;}
}
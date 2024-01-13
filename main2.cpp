#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
using namespace std;

struct mobil
{
    string nama, merek, platnomor, status, warna;
    double harga;
};

struct pembeli
{
    string nama, alamat;
    string noHp;
};

struct nota
{
    double total, subtotal;
    int durasi;
    double byr;
};

void gotoxy(short int x, short int y)
{
    COORD k = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void array(vector<mobil> &datamobil)
{
    mobil daftarmobil[3];

    daftarmobil[0].merek = "Honda";
    daftarmobil[0].nama = "cr-v";
    daftarmobil[0].platnomor = "L 1234 OK";
    daftarmobil[0].warna = "Putih";
    daftarmobil[0].status = "Not Ready";
    daftarmobil[0].harga = 5000;

    daftarmobil[1].merek = "Toyota";
    daftarmobil[1].nama = "Rush";
    daftarmobil[1].platnomor = "L 4567 KO";
    daftarmobil[1].warna = "Hitam";
    daftarmobil[1].status = "Ready";
    daftarmobil[1].harga = 4000;

    daftarmobil[2].merek = "Honda";
    daftarmobil[2].nama = "Jazz";
    daftarmobil[2].platnomor = "L 7890 OK";
    daftarmobil[2].warna = "Merah";
    daftarmobil[2].status = "Ready";
    daftarmobil[2].harga = 4500;

    for (int i = 0; i < 3; i++)
    {
        datamobil.push_back(daftarmobil[i]);
    }
}

void tambahMobil(vector<mobil> &datamobil)
{
    while (true)
    {
        mobil daftarmobil[10];
        string tambahlagi;
        int tambah;

        cout << "Jumlah mobil Yang Ditambahkan : ";
        cin >> tambah;

        for (int i = 3; i < tambah + 3; i++)
        {
            cout << "\nmerek \t\t: ";
            cin >> daftarmobil[i].merek;
            cout << "nama \t\t: ";
            cin >> daftarmobil[i].nama;

            bool PlatNomorSama = false;
            do
            {
                cin.ignore();
                cout << "plat nomor \t: ";
                getline(cin, daftarmobil[i].platnomor);

                PlatNomorSama = false;
                for (mobil &mobils : datamobil)
                {
                    if (mobils.platnomor == daftarmobil[i].platnomor)
                    {
                        cout << "Plat nomor sudah ada. Silakan masukkan plat nomor yang berbeda." << endl;
                        PlatNomorSama = true;
                        break;
                    }
                }
            } while (PlatNomorSama);

            cout << "warna \t\t: ";
            cin >> daftarmobil[i].warna;
            cout << "status \t\t: ";
            cin >> daftarmobil[i].status;
            cout << "Harga \t\t: ";
            cin >> daftarmobil[i].harga;

            datamobil.push_back(daftarmobil[i]);
        }

        cout << "\ntambahlagi (ya/tidak) ?";
        cin >> tambahlagi;

        if (tambahlagi != "ya")
        {
            break;
        }
    }
}

void header()
{
    gotoxy(0, 1);
    cout << "====================================================================";
    gotoxy(0, 2);
    cout << " | no | merek  |   nama   | Plat Nomor | warna |  status   | Harga |";
}

void infomobil(int row, mobil car)
{
    for (int j = 3; j <= row + 1; j += 2)
    {
        for (int k = 0; k <= 67; k++)
        {
            gotoxy(k, j);
            cout << "=";
        }
    }

    gotoxy(1, row);
    cout << "|";

    gotoxy(3, row);
    cout << row / 2 - 1;
    gotoxy(6, row);
    cout << "|";

    gotoxy(8, row);
    cout << car.merek;
    gotoxy(15, row);
    cout << "|";

    gotoxy(17, row);
    cout << car.nama;
    gotoxy(26, row);
    cout << "|";

    gotoxy(28, row);
    cout << car.platnomor;
    gotoxy(39, row);
    cout << "|";

    gotoxy(41, row);
    cout << car.warna;
    gotoxy(47, row);
    cout << "|";

    gotoxy(49, row);
    cout << car.status;
    gotoxy(59, row);
    cout << "|";

    gotoxy(61, row);
    cout << car.harga;
    gotoxy(67, row);
    cout << "|";
}

void tampilkanMobil(vector<mobil> &datamobil)
{
    system("cls");
    cout << "Daftar Mobil : " << endl;
    header();

    for (int i = 0; i < datamobil.size(); i++)
    {

        infomobil(4 + i * 2, datamobil[i]);
    }
    getch();
    system("cls");
}

void hapusDataMobil(vector<mobil> &datamobil)
{
    int hpus_data;

    cout << "masukkan nomor barang yang ingin dihapus : ";
    cin >> hpus_data;

    if (hpus_data >= 1 && hpus_data <= datamobil.size())
    {
        datamobil.erase(datamobil.begin() + hpus_data - 1);
        cout << "barang berhasil dihapus" << endl;
    }
    else
    {
        cout << "nomor barang tidak valid" << endl;
    }
}

void login_admin(int &result)
{
    string admin = "adm", pass_adm = "adm123";
    string adm_user, adm_pass;
    char coba;

    do
    {
        cout << "Username : ";
        cin >> adm_user;
        cout << "Password : ";
        cin >> adm_pass;

        if (adm_pass == pass_adm)
        {
            cout << "Login Berhasil" << endl;
            result = 1;
        }
        else
        {
            cout << "Login Gagal" << endl;
            cout << "Coba Lagi ? (y/t)";
            cin >> coba;

            if (coba != 'y')
            {
                cout << "Terima Kasih" << endl;
                result = 0;
                break;
            }
        }

    } while (adm_pass != pass_adm);
}

void login_petugas(int &result)
{

    string pass_ptgs = "ptgs123";
    string ptgs_pass, nama_petugas;
    char coba;

    do
    {
        cout << "Username : ";
        cin >> nama_petugas;
        cout << "Password : ";
        cin >> ptgs_pass;

        if (ptgs_pass == pass_ptgs)
        {
            cout << "Login Berhasil" << endl;
            result = 1;
        }
        else
        {
            cout << "Login Gagal" << endl;
            cout << "Coba Lagi ? (y/t)";
            cin >> coba;

            if (coba != 'y')
            {
                cout << "Terima Kasih" << endl;
                result = 0;
                break;
            }
        }

    } while (ptgs_pass != pass_ptgs);
}

void menu_adm(vector<mobil> &datamobil)
{
menu:
    mobil daftarmobil;
    int pilihan;

    cout << "|==================================|" << endl;
    cout << "|      RENTAL MOBIL AUTO 86        |" << endl;
    cout << "|==================================|" << endl;
    cout << "|            MENU ADMIN            |" << endl;
    cout << "|==================================|" << endl;
    cout << "|        1. TAMBAH STOK MOBIL      |" << endl;
    cout << "|        2. TAMPILKAN STOK         |" << endl;
    cout << "|        3. HAPUS DATA             |" << endl;
    cout << "|        4. KELUAR                 |" << endl;
    cout << "|==================================|" << endl;

    cout << "Pilihan : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        tambahMobil(datamobil);
        getch();
        goto menu;
    case 2:
        tampilkanMobil(datamobil);
        goto menu;
    case 3:
        hapusDataMobil(datamobil);
        getch();
        goto menu;
    case 4:
        cout << "Terima Kasih" << endl;
        break;
    default:
        break;
    }
}

void Dpembeli(vector<pembeli> &datapembeli)
{
    pembeli daftarPembeli;

    cout << "Masukkan Data Pembeli" << endl;

    cout << "Masukkan Nama \t: ";
    cin.ignore();
    getline(cin, daftarPembeli.nama);
    cout << "Masukkan Alamat : ";
    cin.ignore();
    getline(cin, daftarPembeli.alamat);
    cout << "Masukkan NO. HP : ";
    cin >> daftarPembeli.noHp;

    datapembeli.push_back(daftarPembeli);
}

void durasi(vector<mobil> &datamobil, vector<nota> &dataAkhir, int Hmobil)
{
    nota hasil;
    int pilih_jam;

    cout << "Durasi : " << endl;
    cout << "1. 6 jam\n2. 12 jam\n3. 24jam\n4. 48 jam" << endl;
    cout << "Pilih : ";
    cin >> pilih_jam;

    switch (pilih_jam)
    {
    case 1:
        hasil.durasi = 6;
        hasil.total = 6 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : Rp." << hasil.total << endl;
        break;
    case 2:
        hasil.durasi = 12;
        hasil.total = 12 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : Rp." << hasil.total << endl;
        break;
    case 3:
        hasil.durasi = 24;
        hasil.total = 24 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : Rp." << hasil.total << endl;
        break;
    case 4:
        hasil.durasi = 48;
        hasil.total = 48 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : Rp." << hasil.total << endl;
        break;
    default:
        break;
    }

    cout << "Bayar : ";
    cin >> hasil.byr;

    hasil.subtotal = hasil.byr - hasil.total;

    if (hasil.subtotal == 0)
    {
        cout << "uang pas" << endl;
    }
    if (hasil.subtotal > 0)
    {
        cout << "kembalian : Rp." << hasil.subtotal << endl;
    }
    dataAkhir.push_back(hasil);
}

void notas(vector<mobil> &datamobil, vector<pembeli> &datapembeli, vector<nota> &dataAkhir, int Hmobil)
{
    system("cls");
    cout << "===== NOTA PEMBELIAN =====" << endl;

    cout << "\n===== DETAIL MOBIL =====" << endl;
    cout << "Merek \t\t: " << datamobil[Hmobil].merek << endl;
    cout << "Nama \t\t: " << datamobil[Hmobil].nama << endl;
    cout << "Plat Nomor \t: " << datamobil[Hmobil].platnomor << endl;
    cout << "Warna \t\t: " << datamobil[Hmobil].warna << endl;
    cout << "Harga per-jam \t: Rp." << datamobil[Hmobil].harga << endl;

    cout << "\n===== DETAIL PEMBELI =====" << endl;
    cout << "Nama Pembeli \t: " << datapembeli.back().nama << endl;
    cout << "Alamat Pembeli \t: " << datapembeli.back().alamat << endl;
    cout << "No. HP Pembeli \t: " << datapembeli.back().noHp << endl;

    cout << "\n===== DETAIL PEMESANAN =====" << endl;
    cout << "Durasi Pemesanan: " << dataAkhir.back().durasi << " jam" << endl;
    cout << "Total Transaksi : Rp." << dataAkhir.back().total << endl;
    cout << "Pembayaran \t: Rp." << dataAkhir.back().byr << endl;
    cout << "Kembaliannya \t: Rp." << dataAkhir.back().subtotal << endl;

    cout << "\n===== TERIMA KASIH =====" << endl;

    getch();
    system("cls");
}

void pesan(vector<mobil> &datamobil)
{
    vector<pembeli> datapembeli;
    vector<nota> dataAkhir;
    string platNomorTarget;
    char persetujuan;

    while (true)
    {
        cin.ignore();
        cout << "Masukkan Plat Nomor Mobil: ";
        getline(cin, platNomorTarget);

        bool ready = false;
        int Hmobil = -1;

        for (int i = 0; i < datamobil.size(); i++)
        {
            if (platNomorTarget == datamobil[i].platnomor)
            {
                ready = true;
                Hmobil = i;
                break;
            }
        }

        if (ready)
        {
            if (datamobil[Hmobil].status == "Ready")
            {
                cout << "Data Mobil yang dipesan: " << endl;
                cout << "Merek \t\t: " << datamobil[Hmobil].merek << endl;
                cout << "Nama \t\t: " << datamobil[Hmobil].nama << endl;
                cout << "Plat Nomor \t: " << datamobil[Hmobil].platnomor << endl;
                cout << "Warna \t\t: " << datamobil[Hmobil].warna << endl;
                cout << "Status \t\t: " << datamobil[Hmobil].status << endl;
                cout << "Harga per-jam \t: " << datamobil[Hmobil].harga << endl;

                cout << "Apakah Data Mobil yang Disewa sudah Benar? (y/n): ";
                cin >> persetujuan;

                if (persetujuan == 'y')
                {
                    Dpembeli(datapembeli);
                    durasi(datamobil, dataAkhir, Hmobil);
                    notas(datamobil, datapembeli, dataAkhir, Hmobil);
                    datamobil[Hmobil].status = "Not Ready";
                    break;
                }
                else
                {
                }
            }
            else
            {
                cout << "Mobil Sudah Di Pesan" << endl;
            }
        }
        else
        {
            cout << "Mobil Tidak Ditemukan!!!" << endl;
        }
    }
}

void menu_ptgs(vector<mobil> &datamobil)
{
    mobil daftarmobil;
    int pilihan;

menup:
    cout << "|==================================|" << endl;
    cout << "|      RENTAL MOBIL AUTO 86        |" << endl;
    cout << "|==================================|" << endl;
    cout << "|           MENU PETUGAS           |" << endl;
    cout << "|==================================|" << endl;
    cout << "|         1. INFORMASI MOBIL       |" << endl;
    cout << "|         2. PEMESANAN             |" << endl;
    cout << "|         3. KELUAR                |" << endl;
    cout << "|==================================|" << endl;

    cout << "Piihan (1/2) : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        tampilkanMobil(datamobil);
        goto menup;
        break;
    case 2:
        pesan(datamobil);
        getch();
        goto menup;
        break;
    case 3:
        cout << "Terima Kasih" << endl;
        getch();
    }
}

int main()
{
    vector<nota> dataAkhir;
    vector<mobil> datamobil;
    int pilihan, loginresult;

    array(datamobil);

login:
    cout << "|==================================|" << endl;
    cout << "|      RENTAL MOBIL AUTO 86        |" << endl;
    cout << "|==================================|" << endl;
    cout << "|          LOGIN SEBAGAI           |" << endl;
    cout << "|==================================|" << endl;
    cout << "|           1. ADMIN               |" << endl;
    cout << "|           2. PETUGAS             |" << endl;
    cout << "|           3. Exit                |" << endl;
    cout << "|==================================|" << endl;

    cout << "Pilihan : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        login_admin(loginresult);

        if (loginresult)
        {
            menu_adm(datamobil);
            goto login;
        }
        else
        {
            goto login;
        }
    case 2:
        login_petugas(loginresult);

        if (loginresult)
        {
            menu_ptgs(datamobil);
            goto login;
        }
        else
        {
            goto login;
        }
        break;
    case 3:
        cout << "Layanan Telah Terputus. Mohon Memulai Ulang Program";
        break;
    }
}
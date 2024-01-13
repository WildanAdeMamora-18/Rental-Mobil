#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>
using namespace std;

struct mobil
{
    string nama, merek, platnomor, status, warna;
    double harga;
    int subtotal;
};

struct pembeli
{
    string nama, alamat;
    int noHp;
};

void array(vector<mobil> &datamobil)
{
    mobil daftarmobil[3];

    daftarmobil[0].merek = "Honda";
    daftarmobil[0].nama = "cr-v";
    daftarmobil[0].platnomor = "L 1234 OK";
    daftarmobil[0].warna = "Putih";
    daftarmobil[0].status = "Ready";
    daftarmobil[0].harga = 50000;

    daftarmobil[1].merek = "Toyota";
    daftarmobil[1].nama = "Rush";
    daftarmobil[1].platnomor = "L 4567 KO";
    daftarmobil[1].warna = "Hitam";
    daftarmobil[1].status = "Ready";
    daftarmobil[1].harga = 40000;

    daftarmobil[2].merek = "Honda";
    daftarmobil[2].nama = "Jazz";
    daftarmobil[2].platnomor = "L 7890 OK";
    daftarmobil[2].warna = "Merah";
    daftarmobil[2].status = "Ready";
    daftarmobil[2].harga = 45000;

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

void tampilkanMobil(vector<mobil> &datamobil)
{
    cout << "Daftar Mobil : " << endl;

    for (int i = 0; i < datamobil.size(); i++)
    {
        cout << "Data Mobil Ke-  " << i + 1 << endl;
        cout << "Merek \t\t: " << datamobil[i].merek << endl;
        cout << "Nama \t\t: " << datamobil[i].nama << endl;
        cout << "Plat Nomor \t: " << datamobil[i].platnomor << endl;
        cout << "Warna \t\t: " << datamobil[i].warna << endl;
        cout << "Status \t\t: " << datamobil[i].status << endl;
        cout << "Harga per-jam \t\t: " << datamobil[i].harga << endl;
    }
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
    string admin = "wildan", pass_adm = "wildan123";
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
    string petugas = "junifer", pass_ptgs = "junifer123";
    string ptgs_user, ptgs_pass;
    char coba;

    do
    {
        cout << "Username : ";
        cin >> ptgs_user;
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
        getch();
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

void nota(pembeli &pembeliData, mobil &mobilData)
{
    cout << "Nota Pemesanan Auto 86" << endl;
    cout << "Nama Pembeli : " << pembeliData.nama << endl;
    cout << "Alamat \t: " << pembeliData.alamat << endl;
    cout << "No. HP \t: " << pembeliData.noHp << endl;
    cout << "Mobil \t: " << mobilData.merek << "(" << mobilData.nama << ")" << endl;
    cout << "PlatNomor : " << mobilData.platnomor << endl;
    cout << "Warna \t: " << mobilData.warna << endl;
    cout << "Harga per-Jam : " << mobilData.harga << endl;
    cout << "Total Bayar : " << mobilData.subtotal << endl;
}

void Dpembeli(vector<pembeli> &datapembeli)
{
    pembeli daftarPembeli;

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

void durasi(vector<mobil> &datamobil, int Hmobil)
{
    int pilih_jam;
    double total, byr;

    cout << "Durasi : " << endl;
    cout << "1. 6 jam\n2. 12 jam\n3. 24jam\n4. 48 jam" << endl;
    cout << "Pilih : ";
    cin >> pilih_jam;

    switch (pilih_jam)
    {
    case 1:
        total = 6 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : " << total << endl;
        break;
    case 2:
        total = 12 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : " << total << endl;
        break;
    case 3:
        total = 24 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : " << total << endl;
        break;
    case 4:
        total = 48 * datamobil[Hmobil].harga;
        cout << "Subtotal Pemesanan : " << total << endl;
        break;
    default:
        break;
    }

    cout << "Bayar : ";
    cin >> byr;

    datamobil[Hmobil].subtotal = byr - total;

    if (datamobil[Hmobil].subtotal == 0)
    {
        cout << "uang pas" << endl;
    }
    if (datamobil[Hmobil].subtotal > 0)
    {
        cout << "kembalian : " << datamobil[Hmobil].subtotal << endl;
    }
}

void pesan(vector<mobil> &datamobil)
{
    vector<pembeli> datapembeli;
    string platNomorTarget;

plat:
    cout << "Masukkan Plat Nomor Mobil: ";
    cin.ignore();
    getline(cin, platNomorTarget);

    bool ready = false;
    int Hmobil = -1;
    for (int i = 0; i < datamobil.size(); i++)
    {
        if (platNomorTarget == datamobil[i].platnomor)
        {
            if (datamobil[i].status == "Ready")
            {
                cout << "Detail Mobil yang Tersedia:" << endl;
                cout << "---------------------------------" << endl;
                cout << "Merek\t\t: " << datamobil[i].merek << endl;
                cout << "Nama\t\t: " << datamobil[i].nama << endl;
                cout << "Plat Nomor\t: " << datamobil[i].platnomor << endl;
                cout << "Warna\t\t: " << datamobil[i].warna << endl;
                cout << "Status\t\t: " << datamobil[i].status << endl;
                cout << "Harga per Jam\t: " << datamobil[i].harga << endl;

                ready = true;
                Hmobil = i;
                Dpembeli(datapembeli);
                durasi(datamobil, Hmobil);

                datamobil[i].status = "Not Ready";

                cout << "\nPemesanan berhasil!" << endl;
                cout << "---------------------------------" << endl;
                nota(datapembeli.back(), datamobil[i]);

                getch();
            }
            else if (datamobil[i].status == "Not Ready")
            {
                cout << "Maaf, mobil sudah dipesan. Silakan coba lagi." << endl;
                ready = false;
                goto plat;
            }
        }
    }

    if (!ready)
    {
        cout << "Maaf, mobil dengan plat nomor tersebut tidak ditemukan." << endl;
        goto plat;
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
        goto menup;
        break;
    case 3:
        cout << "Terima Kasih" << endl;
        break;
    default:
        break;
    }
}

void ubahStatus_ptgs(vector<mobil> &datamobil)
{
    mobil Smobil[10];
    string platNomorTarget, statusBaru;

    cout << "Masukkan Plat Nomor Yang Statusnya akan diubah.";
    cin.ignore();
    getline(cin, platNomorTarget);

    bool ada = false;
    for (int i = 0; i < datamobil.size(); i++)
    {
        if (Smobil[i].platnomor == platNomorTarget)
        {
            cout << "Masukkan Status Baru : ";
            cin >> statusBaru;

            Smobil[i].status = statusBaru;
            ada = true;
            break;
        }
    }

    if (!ada)
    {
        cout << "Mobil dengan Plat Nomor Tersebut Tidak diTemukan!!!";
    }
}

void pencarianData(vector<mobil> &datamobil)
{
    mobil Pmobil[10];
    string MobilTarget;

    cout << "Masukkan Plat Nomor Yang Dicari : ";
    cin.ignore();
    getline(cin, MobilTarget);

    bool ada = false;
    for (int i = 0; i < datamobil.size(); i++)
    {
        if (Pmobil[i].platnomor == MobilTarget)
        {
            cout << "Data Mobil Ke-  " << i + 1 << endl;
            cout << "Merek \t\t: " << datamobil[i].merek << endl;
            cout << "Nama \t\t: " << datamobil[i].nama << endl;
            cout << "Plat Nomor \t: " << datamobil[i].platnomor << endl;
            cout << "Warna \t\t: " << datamobil[i].warna << endl;
            cout << "Status \t\t: " << datamobil[i].status << endl;

            ada = true;
            break;
        }
    }
    if (!ada)
    {
        cout << "Plat Nomor yang anda masukkan tidak ada di data!!!";
    }
}

int main()
{
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
            break;
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
            break;
        }
        else
        {
            goto login;
        }
    }
}
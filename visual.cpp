#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

struct mobil
{
    string nama, merek, platnomor, status, warna;
    double harga;
};

void gotoxy(short int x, short int y)
{
    COORD k = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),k);
}

int main()
{   
    system("cls");

    vector<mobil> datamobil;
    mobil daftarmobil[1];
    daftarmobil[0].merek = "Honda";
    daftarmobil[0].nama = "cr-v";
    daftarmobil[0].platnomor = "L 1234 OK";
    daftarmobil[0].warna = "Putih";
    daftarmobil[0].status = "Ready";
    daftarmobil[0].harga = 50000;

    gotoxy(0,0);cout << "===================================================================="; // 67 garis
    gotoxy(0,1);cout << " | no | merek  |   nama   | Plat Nomor | warna |  status   | Harga |";
                        //(no = 5) (merek = 9) (nama = 11) (PN = 13) (waran = 8) (status = 12) (harga = 8)



    for (int i = 0; i <= 67; i++) //kolom
    {
        for(int j = 2; j <= 10; j+=2) // Baris
        {
            gotoxy(i,j); cout << "=";
        }

    }
    // no
     for (int i = 1; i <= 6; i+=5) //kolom untuk (no)
    {
        for(int j = 3; j <= 10; j+=2) // Baris
        {
            gotoxy(i,j); cout << "|";
        }

    }
    //merek
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(15,i); cout<< "|";
    }
    //nama
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(26,i); cout<< "|";
    }
    //Plat nomor
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(39,i); cout<< "|";
    }
    //warna
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(47,i); cout<< "|";
    }
    //status
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(59,i); cout<< "|";
    }
    //harga
    for(int i = 3; i < 10; i+=2)
    {
        gotoxy(67,i); cout<< "|";
    }
}
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib> 
#include <conio.h>
#include <list>
#include <fstream>

using namespace std;

static int jml;

class Gerbong 
{  
public :
    typedef struct 
	  { 
        int nokursi;
        int statuskursi;   // 0 = kursi kosong; 1=kursi terisi orang/barang
      }InfoKursi; 
    class InfoPenumpang
	{
	  public:
      char nama[20];
      int baris;
      int kolom;
      int nokursi;
    };
    int jumlahkosong;
    int baris, kolom;
    list<Gerbong> daftar;
    list<Gerbong> :: iterator pos;
    InfoKursi Kursi[4][10];
    InfoPenumpang Penumpang[40];
    ofstream savefile;
    Gerbong(void) 
  { 
    int  gb, kolom, baris; 
    baris = 0; 
    while (baris < 4 ) 
      { 
        kolom = 0; 
        while (kolom < 10)  
          {
            Kursi[baris][kolom].nokursi=baris*10+kolom+1;
            Kursi[baris][kolom].statuskursi = 0;
            kolom++;
          } 
        baris++;
      } 
  } 
  public:
  	void Log();
    void SaveLog(string s,int xbar,int xkolom);
    void CetakGerbong(void);     
    void PesanKursi();    
    void searching();
    void kursikosong();
    void menu();
    void Set(Gerbong grbx);
    void GetKursi(int x, int y);
};
#endif

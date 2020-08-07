#include <iostream>
#include <stdlib.h> 
#include <list>
using namespace std;

class Gerbong 
{ 
 
  public : 
     typedef struct { 
        int nomorkursi; 
        int statuskursi;   // 0 = kursi kosong; 1=kursi terisi orang/barang
     } InfoKursi; 

     typedef struct {
       char nama[20];
       int baris;
       int kolom;
     } InfoPenumpang;

       int baris, kolom;
       list<int> daftar;
       InfoKursi Kursi[4][10];
       InfoPenumpang Penumpang[40];
 
  public : 
   //Inisialisasi  Gerbong 
    Gerbong(void) 
    { 
       int  gb, kolom, baris; 
       kolom = 0; 
       while (kolom < 10)  {
           baris = 0; 
           while (baris < 4 ) { 
             Kursi[baris][kolom].nomorkursi = 4 * (kolom) + (baris+1);
             Kursi[baris][kolom].statuskursi = 0;
             baris++;
            } 
       kolom++;
      } 
     } 
 
        void CetakGerbong(void) 
     { 
       int baris = 0;
       cout << "\nSETATUSE GERBONG\n";
       cout << "---------------------\n";
       while (baris < 4)  { 
         int kolom = 0;
              while (kolom < 10 ) {
     cout << Kursi[baris][kolom].nomorkursi << "~"<< Kursi[baris][kolom].statuskursi << " ";
     kolom++;
   }
              cout << endl;
              baris++;
        } 
      }  
void PesanKursi()
    {
      int x,y;
        cout << "\n------------------------------------------------------------\n";
        cout << "| nb : untuk memilih baris dan kolom di mulai dari 0 (nol) |";
        cout << "\n------------------------------------------------------------\n\n";
	  cout << "Jumlah Kursi Yang Dipesan:"; cin >> x;
      for (y = 0;y < x;y++)
      {
        cout << "Nama penumpang ke-" << y+1 << ":"; cin >> Penumpang[y].nama;
        cout << "Baris:"; cin >> Penumpang[y].baris;
        cout << "Kolom:"; cin >> Penumpang[y].kolom;
        Kursi[Penumpang[y].baris][Penumpang[y].kolom].statuskursi = 1;
      }
      system("cls");
      for (y = 0;y < x;y++)
      {
        cout << "Penumpang " << y+1 << ":" << Penumpang[y].nama << "-" << "Nomor Kursi:" << Kursi[Penumpang[y].baris][Penumpang[y].kolom].nomorkursi << "\n";
      }
     
      cout << "\nList Kursi Yang Terisi\n";
      cout << "--------------------\n";
      for (y = 0;y < x;y++)
      {
        daftar.push_back(Kursi[Penumpang[y].baris][Penumpang[y].kolom].nomorkursi);
      }

      daftar.sort();
      daftar.reverse();

      while (! daftar.empty())
      {
        cout << daftar.front() << ' ';
        daftar.pop_front();
      }
     cout << "\n";
     
      }
     void searching()
      {
        int input,x,y;
        int kursi;
        list<int> coll;         
    	list<int>::iterator pos; 
		pos = coll.begin();
		bool found;
		found=false;
		while ((!found)&&(pos!=coll.end()))
		{
			if((*pos)==Penumpang[y].nama[x]){
				found = true;
			}
			else{
				pos++;
			}
		}
		if (found){
		}
        char nama[20];
        cout << "\n[1] Nama\n";
        cout << "[2] Nomor Kursi\n";
        cout << "---------------\n";
        cout << "Cari berdasarkan:";
        cin >> input;
        if (input == 0 || input > 2)
        {
          cout << "Pilihan Anda Salah !!!";
        }
        else
        {
          switch(input)
          {
            case 1:
            {
              system("cls");
        cout << "\n------------------------------------------------------------\n";
        cout << "| nb : untuk memilih baris dan kolom di mulai dari 0 (nol) |";
        cout << "\n------------------------------------------------------------\n\n";
              cout << "ENTER YOUR NAME:";
               cin >> nama;
              y = 0;
              while (y<=5)
              {
                x = 0;
                while (x <= 20)
                {
                  if (nama[x] == Penumpang[y].nama[x])
                  {
                    cout << nama << " FOUND A NUMBER ...OF CHAIR-" << Kursi[Penumpang[y].baris][Penumpang[y].kolom].nomorkursi << "\n";
                    cout << "\n";
                    goto ada;
                  }
                  else
                  {
                    break;
                  }
                  x++;
                }
                y++;
              }
              cout << "NOT FOUND " << nama << "\n";
              ada:
              break;
             }

            case 2:
            system("cls");
            cout << "ENTRER YOUR NUMBER OF CHAIR:"; cin >> kursi;
              for(x=1;x<=5;x++)
              {
                if (kursi == Kursi[Penumpang[x].baris][Penumpang[x].kolom].nomorkursi)
                {
                  cout << "FOUND..." << "NAME:" << Penumpang[x].nama;
                  goto loncat;
                }
                else
                break;
              }
              cout << "THE CHAIR STILL EMPTY ...";
              loncat:
              cout << endl;
              break;
          }
        }
      }

      void kursikosong()
      {
        int jumlahkosong = 0;
        int kolom = 0;
         while (kolom < 10) {
           int baris = 0;
           while (baris < 4 ) {
             Kursi[baris][kolom].nomorkursi = 4*(kolom)+(baris+1);
             if (Kursi[baris][kolom].statuskursi == 0)
             {
              jumlahkosong++;
             }
             baris++;
            }
           kolom++;
         }
         cout << "THE SUM OF CHAIR THAT STILL EMPTY:" << jumlahkosong << "\n";
      }

      void menu()
      {
        int pilih;
        cout << "              PROGRAM TO ORDER CARRIAGES\n";
        cout << "                  INDRAMAYU -- JAKARTA\n\n";
        cout << "             WELCOME AND CHOOSE A MENU :\n\n";
        cout << "[1] Pemesanan Kursi\n";
        cout << "[2] pencarian penumpang\n";
        cout << "pilihan anda : \n";

        cin >> pilih;
        switch(pilih)
        {
          case 1: system("cls"); 
          PesanKursi(); 
          CetakGerbong(); 
          kursikosong(); 
          break;
          case 2:
          system("cls");
          cout << "THE TRAIN STILL EMPTY\n";
          cout << "ENTRY THE NAME PLEASE!!\n";
          cout << "------------------------------------\n";
          PesanKursi();
          searching();
          CetakGerbong();
          kursikosong();
          break;
        }
      }
};
 
int main() 
{ 
      Gerbong grb;
      grb.menu();
      system ("pause");
      return 0; 
} 

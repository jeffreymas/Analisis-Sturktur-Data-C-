#include "header.h" 

void Gerbong::Log()
  {
    savefile.open("save.txt", ios::app);
	savefile << "\n          PROGRAM LOKET TIKET               \n";
    savefile << "         PT. KERETA JAYA ABADI              \n";
    savefile << "--------------------------------------------\n\n";
  }

void Gerbong::SaveLog (string s, int xbar,int xkolom){
    savefile << "Pesanan Tiket untuk nomer kursi ";
	savefile << xkolom+1;
    switch(xbar)
	  {
        case 0: savefile<< "A";  break;
		case 1: savefile<< "B";  break;
		case 2: savefile<< "C";  break;
		case 3: savefile<< "D";  break;
	  }
	savefile << " atas nama "<<s;
	savefile << endl;
  }

void Gerbong::GetKursi(int x, int y){
    cout << y+1;
    switch(x)
	  {
        case 0: cout<< "A";  break;
		case 1: cout<< "B";  break;
		case 2: cout<< "C";  break;
		case 3: cout<< "D";  break;
	  }	
  }
  
void Gerbong::CetakGerbong(void) 
  { 
    int baris = 0;
    cout << "\nStatus Gerbong Kereta\n";
    cout << "---------------------\n";
    while (baris < 4)  
	  { 
        int kolom = 0;
        while (kolom < 10 ) 
		{
          GetKursi(baris, kolom );
	      cout <<"["<< Kursi[baris][kolom].statuskursi << "]"<<"~ ";
          kolom++;
        }
        cout << endl;
        baris++;
      } 
  }  

void Gerbong::PesanKursi()
  {
    int x,y,baris,kolom;
    y=jml;
    cout << "\n------------------------------------------------------------\n";
    cout << "| nb :       untuk memilih baris 0-3 dan kolom 0-9         |\n";
    cout << "|      untuk nama penumpang gunakan _ sebagai ganti spasi  |";
    cout << "\n------------------------------------------------------------\n\n";
	int TotalJual;
    cout <<"Nama penumpang ke-"<< y+1<<" : "; cin >> Penumpang[y].nama;
        input:
        cout << "Baris : "; cin >> Penumpang[y].baris;
        cout << "Kolom : "; cin >> Penumpang[y].kolom;
        if ((Penumpang[y].baris<0)||(Penumpang[y].baris>3)||(Penumpang[y].kolom<0)||(Penumpang[y].kolom>9))
          {
            cout << "Kursi tidak ditemukan, masukan lagi!\n";
	        goto input; 
	      }
	    if ( Kursi[Penumpang[y].baris][Penumpang[y].kolom].statuskursi == 1)
          {
            cout << "Kursi sudah di pesan\n";
	        goto input; 
	      }
	    SaveLog(Penumpang[y].nama,Penumpang[y].baris,Penumpang[y].kolom);
	    Kursi[Penumpang[y].baris][Penumpang[y].kolom].statuskursi = 1;
        Penumpang[y].nokursi=Kursi[Penumpang[y].baris][Penumpang[y].kolom].nokursi;
        jml++;
        system("cls");
        cout <<"List Penumpang\n";
        cout << "\nPenumpang " << y+1 << " : " << Penumpang[y].nama << "-" << "Nomor Kursi : " ;
        GetKursi(Penumpang[y].baris,Penumpang[y].kolom);
  }

void Gerbong::searching()
  {
    int input,x,y;
    int kursi,temp;
    char bloks;
    list<int> coll;         
    list<int>::iterator pos; 
	pos = coll.begin();
	bool found;
	found=false;
	while ((!found)&&(pos!=coll.end()))
	  {
	    if((*pos)==Penumpang[y].nama[x])
		  {
		    found = true;
		    pos++;
		  }
	    else
		  {
		    pos++;
	      }
	  }
	if (found)
      {cout << "Ditemukan!!"<<endl;}
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
                cout << "masukkan nama:";
                cin >> nama;
                y = 0;
                while (y<=40)
                  {
                    x = 0;
                      while (x <= 20)
                        {
                          if (nama[x] == Penumpang[y].nama[x])
                            {
                              cout << nama<< " ditemukan...Kursi Nomor-"; GetKursi(Penumpang[y].baris,Penumpang[y].kolom);
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
                cout << "Tidak terdapat nama penumpang " << nama << "\n";
                ada:
                break;
             }

            case 2:
              {
                system("cls");
                CetakGerbong();
                cout << "Masukan Nomor kursi:"; cin >> temp;
                cout << "Masukan Blok Kursi (kapital):"; cin >> bloks;
                switch(bloks)
                  {
                    case 'A': kursi=temp; break;
                    case 'B': kursi=temp+10; break;
                    case 'C': kursi=temp+20; break;
                    case 'D': kursi=temp+30; break;
                  }
                y = 0;
                while (y<=40)
                  {
                    if (kursi == Penumpang[y].nokursi)
                      {
                        cout << Penumpang[y].nama << " ditemukan...Kursi Nomor-"; GetKursi(Penumpang[y].baris,Penumpang[y].kolom);
                              goto loncat;
                            }
                          else
                            {
                              y++;
                            }
                  }
                cout << "Tidak terdapat nama penumpang " << nama << "\n";
                loncat:
                break;             
			  }
          }
      }
}

void Gerbong::kursikosong()
  {
    jumlahkosong = 0;
    int kolom = 0;
    while (kolom < 10) 
	  {
        int baris = 0;
        while (baris < 4 ) 
		  {	
            if (Kursi[baris][kolom].statuskursi == 0)
              {
                jumlahkosong++;
              }
            baris++;
          }
        kolom++;
      }
    cout << "Jumlah kursi yang masih kosong:" << jumlahkosong << "\n";
  }

void Gerbong::menu()
  {
    char pilih;
    system("cls");
    cout << "          PROGRAM LOKET TIKET               \n";
    cout << "         PT. KERETA JAYA ABADI              \n";
    cout << "--------------------------------------------\n\n";
    cout << "Selamat datang, Pilihlah Menu Dibawah :     \n\n";
    cout << "[1] Pemesanan Kursi                         \n";
    cout << "[2] Pencarian penumpang                     \n";
    cout << "[3] Info Gerbong                         \n";
	cout << "Tekan Tombol Angka dari Menu Diatas : \n";
    cin >> pilih;
    switch(pilih)
      {
        case '1': 
		  {
		    system("cls"); 
            PesanKursi(); 
            break;
          }
        case '2':
          {
            system("cls");
            if(jumlahkosong == 40)
              {
		        cout << "Kereta masih kosong\n";
                cout << "tolong isi daftar penumpang dahulu!!\n";
                cout << "------------------------------------\n";
                PesanKursi();
              }
		    searching();
            break;
          }
        case '3':
          {
            CetakGerbong(); 
            kursikosong(); 
            break;
          }
      }
  }

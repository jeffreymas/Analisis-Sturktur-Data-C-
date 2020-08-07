#include "header.h"

int main() 
  { 
    char tombol;
    Gerbong grb;
    grb.Log();
    do
	  {
	    grb.menu();
	    cout << "\nTekan \"T\" untuk Exit atau Tombol Lain untuk Kembali ke Menu : ";
	    cin >> tombol;
	  } while ((tombol!='T')&&(tombol!='t'));
	system ("pause");
    return 0; 
  }

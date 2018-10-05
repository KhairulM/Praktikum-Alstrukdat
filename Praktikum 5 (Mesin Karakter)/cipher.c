/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : ekspresi.c
	Topik : Praktikum 05
	Tanggal : 27 September 2018
	Deskripsi :  Menghasilkan Output isi pita karakter (menuliskan 'Ekspresi Kosong jika pita kosong"*/

/*Program Ekspresi
  Menghasilkan Output isi pita karakter (menuliskan 'Ekspresi Kosong jika pita kosong" */

#include "mesintoken.h"
#include <stdio.h>


int main(){
	// Kamus
	int JmlGeser;
	// Algoritma
	STARTTOKEN();
	if (EndToken){
		printf("Ekspresi kosong");
	}
	else{
		while(!EndKata){
			printgeserKata(CKata, JmlGeser);
			ADVKATA();
			if (!EndKata){
				printf(" ");
			}
			else{
				printf(".\n");
			}
		}	
	}
	return 0;
}


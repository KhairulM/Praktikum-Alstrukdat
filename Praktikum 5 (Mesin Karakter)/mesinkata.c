/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : mesinkata.c
	Topik : Pra Praktikum 05
	Tanggal : 21 September 2018
	Deskripsi : Implementasi semua prosedur yang sudah didefinisikan di file mesinkata.h */


#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
	while ((CC == BLANK) && (CC != MARK)){
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){
	START();
	IgnoreBlank();
	if (CC == MARK){
		EndKata = true;
	}
	else{
		SalinKata();
		EndKata = false;
	}
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
	IgnoreBlank();
	if (CC == MARK){
		EndKata = true;
	}
	else{
		SalinKata();
		IgnoreBlank();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
	CKata.Length = 0;
	do{
		if (CKata.Length < NMax){
			CKata.TabKata[CKata.Length + 1] = CC;
			CKata.Length++;
		}
		ADV();
	} while ((CC != BLANK) && (CC != MARK));
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

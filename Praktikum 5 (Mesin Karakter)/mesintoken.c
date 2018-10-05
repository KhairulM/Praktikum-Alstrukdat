/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : mesintoken.c
	Topik : Praktikum 05
	Tanggal : 27 September 2018
	Deskripsi : Implementasi semua prosedur yang sudah didefinisikan di file mesintoken.h */

#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
	while ((CC == BLANK) && (CC != MARK)){
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN(){
	START();
	IgnoreBlank();
	if (CC == MARK){
		EndToken = true;
	}
	else{
		SalinToken();
		EndToken = false;
	}
}
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN(){
	IgnoreBlank();
	if (CC == MARK){
		EndToken = true;
	}
	else{
		SalinToken();
		IgnoreBlank();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken(){
	// Kamus Lokal
	int length;
	// Algoritma
	if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^')){
		CToken.tkn = CC;
		CToken.val = -1;
		ADV();
	}
	else{
		length = 0;
		CToken.tkn = 'b';
		CToken.val = 0;
		do{
			if (length < NMax){
				CToken.val *= 10;
				CToken.val += (CC - 48);
				length++;
			}
			ADV();
		} while ((CC != BLANK) && (CC != MARK));
	}
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

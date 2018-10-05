/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01h.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 25 Agustus 2018
Deskripsi : pengulangan
*/

#include <stdio.h>

#define N 1000

int main(){

    //kamus
    int i=2;
    float TANDA=1;
    float S=1;

    while (i<=N){
        TANDA=(-1)*TANDA;
        S=S+(TANDA/i);
        i=i+1;
    }

    printf("%f\n", S);

return 0;
}

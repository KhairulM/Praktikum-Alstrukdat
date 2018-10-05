/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01g.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 25 Agustus 2018
Deskripsi : pengulangan
*/

#include <stdio.h>

int main(){
    //kamus
    int i=0;
    int sum=0;
    int x;

    //algoritma
    scanf("%d", &x);    //inisiasi awal

    while (x!=9999) {
        printf("%d\n", x);
        i=i+1;
        sum=sum+x;
        scanf("%d", &x);
    }

    printf("Jumlah : %d\n", sum);
    printf("Banyaknya bilangan : %d\n", i);


return 0;
}

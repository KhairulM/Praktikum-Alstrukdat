/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01f.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 25 Agustus 2018
Deskripsi : procedure
*/
#include <stdio.h>

int main(){
    //Kamus
    int a, b, c;

    //Procedure
    void PROCTUKAR (int *px, int *py){
       int temp;

       temp=*px;
       *px=*py;
       *py=temp;
    }

    //Algoritma
    scanf("%d %d %d", &a, &b, &c);

    PROCTUKAR (&a, &c);
    PROCTUKAR (&b, &c);

    printf("%d %d %d\n", a, b, c);
   

return 0;
}

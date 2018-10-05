/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01d.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 24 Agustus 2018
Deskripsi : analisis kasus
*/


int main(){
    //Kamus
    int T;

    //Algoritma
    scanf("%d", &T); //Inisiasi

    if (T<=0){
        printf("Beku\n");
    }else if (T>0 && T<=100){
        printf("Cair\n");
    }else{
        printf("Uap\n");
    }

    return 0;
}

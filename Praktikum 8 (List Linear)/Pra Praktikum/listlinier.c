#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return(First(L)==Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L)=Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P;

    P = malloc (1*sizeof(infotype));
    if(P!=Nil){
        Info(P)=X;
        Next(P)=Nil;
    }

    return P;
    
    
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P;

    P=First(L);
    if(P!=Nil){
        while((Info(P)!=X) && (Next(P)!=Nil)){
            P=Next(P);
        }
        if (Info(P)!=X){
            P=Nil;
        }
    }
    

    return P;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P;

    if (IsEmpty(*L)){
        First(*L)=Alokasi(X);
    }else{
        P=Alokasi(X);
        Next(P)=First(*L);
        First(*L)=P;
    }
    
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P, Padr;

    if (IsEmpty(*L)){
        First(*L)=Alokasi(X);
    }else{
        P=Alokasi(X);
        Padr=First(*L);
        while (Next(Padr)!=Nil){
            Padr=Next(Padr);
        }
        Next(Padr)=P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;

    P=First(*L);
    (*X)=Info(P);
    First(*L)=Next(P);

}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P, seclastP;

    P=First(*L);
    if (Next(P)==Nil){
        DelVFirst(L, X);
    }else{
        while (Next(P)!=Nil){
            seclastP=P;
            P=Next(P);
        }
        Next(seclastP)=Nil;
        *X=Info(P);
    }
    
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P)=First(*L);
    First(*L)=P;
    
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address lastP=First(*L);

    if (!IsEmpty(*L)){
        while(Next(lastP)!=Nil){
            lastP=Next(lastP);
        }
        Next(lastP)=P;
    }else{
        First(*L)=P;
    }
    

    
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P=First(*L);
    First(*L)=Next(*P);

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    address seclastP, P;

    P=First(*L);
    if (!IsEmpty(*L)){
        if (Info(P)==X){
            First(*L)=Next(P);
            Dealokasi(&P);
        }else{
            while(Next(P)!=Nil && Info(P)!=X){
                seclastP=P;
                P=Next(P);
            }
            if (Info(P)==X){
                Next(seclastP)=Next(P);
                Dealokasi(&P);
            }
        }
            
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    address lastP=First(*L);
    address seclastP;

    if(Next(lastP)==Nil){
        *P=lastP;
        First(*L)=Nil;
    }else{
        while (Next(lastP)!=Nil){
            seclastP=lastP;
            lastP=Next(lastP);
        }
        *P=lastP;
        Next(seclastP)=Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    address P;

    P=First(*L);
    while(P!=Prec){
        P=Next(P);
    }
    if (Next(P)!=Nil){
        *Pdel=Next(P);
        Next(P)=Next(*Pdel);
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P=First(L);

    printf("[");
    while (P!=Nil){
        if (P==First(L)){
            printf("%d", Info(P));
        }else{
            printf(",%d", Info(P));
        }
        P=Next(P);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    address P=First(L);
    int NBELMT=0;

    while (P!=Nil){
        NBELMT++;
        P=Next(P);
    }

    return NBELMT;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    address P=First(L);
    infotype MAX=Info(P);

    while (Next(P)!=Nil){
        P=Next(P);
        if(Info(P)>MAX){
            MAX=Info(P);
        }
    }

    return MAX;
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    address lastP;

    CreateEmpty(L3);
    if (IsEmpty(*L1)){
        First(*L3)=First(*L2);
    }else{
        First(*L3)=First(*L1);
        if (!IsEmpty(*L2)){
            lastP=First(*L1);
            while (Next(lastP)!=Nil){
                lastP=Next(lastP);
            }
            Next(lastP)=First(*L2);
        }
    }
    
    CreateEmpty(L1);
    CreateEmpty(L2);

}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
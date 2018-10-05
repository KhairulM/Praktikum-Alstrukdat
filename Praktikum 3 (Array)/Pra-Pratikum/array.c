#include "stdio.h"
#include "array.h"

void MakeEmpty (TabInt * T){
    Neff(*T)=0;
}

int NbElmt (TabInt T){
    return (Neff(T));
}

int MaxNbEl (TabInt T){
    return (IdxMax);
}

IdxType GetFirstIdx (TabInt T){
    return(IdxMin);
}
/* Karena arraynya dalam bentuk eksplisit maka bisa langsung manggil IdxMin*/
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
   return(IdxMin+Neff(T)-1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return ((i>=IdxMin) && (i<=IdxMax));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
    return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return (Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return (Neff(T)==IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    int N;
    IdxType FirstIdx=GetFirstIdx(*T);

    scanf("%d", &N);
    while (N<0 || N>MaxNbEl(*T)){
        scanf("%d", &N);
    }
    if (N!=0){
        for (IdxType i=FirstIdx;i<=FirstIdx+N-1;i++){
            scanf("%d", &(Elmt(*T,i)));
        }
    }
    Neff(*T)=N;

}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void BacaIsiTab (TabInt * T){
    ElType Stop=-9999;
    IdxType i=0;
    ElType Nilai;

    scanf("%d", &Nilai);

    while ((Nilai!=Stop) && (GetFirstIdx(*T)+i<=MaxNbEl(*T))){
        Elmt((*T),GetFirstIdx(*T)+i)=Nilai;
        i++;
        scanf("%d", &Nilai);
    }

    Neff(*T)=i;
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
void TulisIsi (TabInt T){
    IdxType i;
    
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }else {
        for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            printf("[%d]%d\n", i, Elmt(T,i));
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T){
    IdxType i;

    if (IsEmpty(T)){
        printf("[]");
    }else {
        printf("[");
        for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            if (i==GetFirstIdx(T)){
                printf("%d", Elmt(T,i));
            }else {
                printf(",%d", Elmt(T,i));    
            }
            
        }
        printf("]");
    }
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
    TabInt T3;
    IdxType FirstIdx=GetFirstIdx(T1);
    IdxType LastIdx=GetLastIdx(T1);
    IdxType i;

    for (i=FirstIdx;i<=LastIdx;i++){
        Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
    }
    Neff(T3)=Neff(T1);
    return (T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2){
    TabInt T3;
    IdxType FirstIdx=GetFirstIdx(T1);
    IdxType LastIdx=GetLastIdx(T1);
    IdxType i;

    for (i=FirstIdx;i<=LastIdx;i++){
        Elmt(T3,i)=Elmt(T1,i)-Elmt(T2,i);
    }
    Neff(T3)=Neff(T1);
    return (T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2){
    TabInt T3;
    IdxType FirstIdx=GetFirstIdx(T1);
    IdxType LastIdx=GetLastIdx(T1);
    IdxType i;

    for (i=FirstIdx;i<=LastIdx;i++){
        Elmt(T3,i)=Elmt(T1,i)*Elmt(T2,i);
    }
    Neff(T3)=Neff(T1);
    return (T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c){
    TabInt T3;
    IdxType FirstIdx=GetFirstIdx(Tin);
    IdxType LastIdx=GetLastIdx(Tin);
    IdxType i;

    for(i=FirstIdx;i<=LastIdx;i++){
        Elmt(T3,i)=Elmt(Tin,i)*c;
    }
    Neff(T3)=Neff(Tin);
    return (T3);

}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
    IdxType FirstIdx=GetFirstIdx(T1);
    IdxType LastIdx=GetLastIdx(T1);
    IdxType i;

    if ((Neff(T1)==Neff(T2)) && (Neff(T1)==0)){
        return true;
    }else if (Neff(T1)==Neff(T2)){
        for(i=FirstIdx;i<=LastIdx;i++){
            if (Elmt(T1,i)!=Elmt(T2,i)){
                return false;
                break;
            }else if (i==LastIdx){
                return true;
            }
        }
    }else{
        return false;
    }
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2){
    IdxType MaxIdx, i;
    boolean Less=true;

    if (IsEQ(T1, T2)){
        Less=false;
    }else{
        if(Neff(T1)==0){
            Less=true;
        }else if (Neff(T2)==0){
            Less=false;
        }else{
            if (Neff(T1)<=Neff(T2)){
                MaxIdx=Neff(T1);
            }else {
                MaxIdx=Neff(T2);
            }

            for (i=GetFirstIdx(T1);i<=MaxIdx;i++){
                if (Elmt(T1,i)<Elmt(T2,i)){
                    break;
                }else if(Elmt(T1,i)>Elmt(T2,i)){
                    Less=false;
                    break;
                }
            }

            if (i==MaxIdx){
                if (MaxIdx==Neff(T2)){
                    Less=false;
                }
            }  
        }
    }

    return Less;
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
    IdxType IdxF, i;

    if (IsEmpty(T)){                                             /*Tabel kosong*/
        IdxF=IdxUndef;
    }else{                                                       /*Tabel tidak kosong*/
        for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){             /*Mencari X dengan traversal tabel T*/
            if (Elmt(T,i)==X){                                   /*Jika X ketemu*/
                IdxF=i;
                break;
            }else if (i==GetLastIdx(T)){                         /*Jika X tidak ketemu*/
                IdxF=IdxUndef;
            }
        }
    }

    return IdxF;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X){
    boolean Found=false;                               /*Boolean untuk menentukan apakah sudah ketemu atau belum*/
    IdxType IdxF;
    IdxType i=GetFirstIdx(T);                          /*Variabel untuk mengakses indeks array*/

    if (IsEmpty(T)){
        IdxF=IdxUndef;
    }else{
        while (!Found){
            if (Elmt(T,i)==X){
                Found=true;
                IdxF=i;
            }else if (i==GetLastIdx(T)){
                IdxF=IdxUndef;
                break;
            }else{
                i++;
            }

        }
    }

    return IdxF;

}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X){
    boolean Found=false;
    IdxType i;


    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        if (Elmt(T,i)==X){
            Found=true;
            break;
        }
    }

    return Found;

}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X){
    IdxType i=GetLastIdx(T);    /*Pencarian  dimulai dari indeks terakhir*/
    boolean Found=false;

    Elmt(T,0)=X;                /*Inisialisasi elemen*/

    if (!IsEmpty(T)){
        while (Elmt(T,i)!=X){
            i--;
        }

        if (i>0){               /*Elemen ketemu*/
            Found=true;
        }
    }
    return Found;

}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    IdxType i;
    ElType Max=Elmt(T,GetFirstIdx(T));                     /*Inisialisasi nilai Max sebagai elemen pertama tabel T*/

    if (NbElmt(T)>1){
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
            if (Elmt(T,i)>Max){
                Max=Elmt(T,i);
            }
        }
    }

    

    return Max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T){
    IdxType i;
    ElType Min=Elmt(T,GetFirstIdx(T));                     /*Inisialisasi nilai Min sebagai elemen pertama tabel T*/

    if (NbElmt(T)>1){
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
            if (Elmt(T,i)<Min){
                Min=Elmt(T,i);
            }
        }    
    }

    

    return Min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
    ElType Max=ValMax(T);
    return (Search1(T, Max));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T){
    ElType Min=ValMin(T);
    return (Search2(T, Min));

}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
    IdxType i;

    if (!IsEmpty(Tin)){
        for (i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
            Elmt(*Tout,i)=Elmt(Tin,i);
        }
    }
    Neff(*Tout)=Neff(Tin);
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T){
    TabInt TInv;
    IdxType i=GetFirstIdx(T);
    IdxType j=GetLastIdx(T);

    while (i<=j){
        Elmt(TInv,i)=Elmt(T,j);
        Elmt(TInv,j)=Elmt(T,i);

        i++;
        j--;
    }
    Neff(TInv)=Neff(T);

    return TInv;
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T){                  /*???Apakah tabel yang belum keisi penuh bukan merupakan tabel simetris???*/
    boolean Simetris=true;
    IdxType i=GetFirstIdx(T);
    IdxType j=GetLastIdx(T);

    if (IsEmpty(T)){                            /*Array kosong berarti simetris*/
        Simetris=true;
    }else {
        while (i<j && Simetris){                /*Jika ada elemen yang tidak sama maka langsung berhenti*/
            if (Elmt(T,i)!=Elmt(T,j)){
                Simetris=false;
            }else{
                i++;
                j--;
            }
        }
    }
    return Simetris;

}
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
    IdxType Pass, i, IMax;
    ElType Temp;
    IdxType FirstIdx=GetFirstIdx(*T);
    IdxType LastIdx=GetLastIdx(*T);

    if (Neff(*T)>1){
        for (Pass=FirstIdx;Pass<LastIdx;Pass++){
            IMax=Pass;
            for(i=Pass+1;i<=LastIdx;i++){
                if (Elmt(*T,IMax)<Elmt(*T,i)){
                    IMax=i;
                }
            }

            Temp=Elmt(*T,Pass);
            Elmt(*T,Pass)=Elmt(*T,IMax);
            Elmt(*T,IMax)=Temp;
        }
    }


}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt * T){
    IdxType Pass, i;
    ElType Temp;
    IdxType FirstIdx=GetFirstIdx(*T);
    IdxType LastIdx=GetLastIdx(*T);

    if (Neff(*T)>1){
        for (Pass=FirstIdx+1;Pass<=LastIdx;Pass++){
            for (i=FirstIdx;i<Pass;i++){
                if (Elmt(*T,i)>Elmt(*T,Pass)){
                    Temp=Elmt(*T,Pass);
                    Elmt(*T,Pass)=Elmt(*T,i);
                    Elmt(*T,i)=Temp;
                }
            }
        }
    }

}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
    if (IsEmpty(*T)){
        Elmt(*T,GetFirstIdx(*T))=X;
    }else {
        Elmt(*T,GetLastIdx(*T)+1)=X;
    }
    Neff(*T)++;   
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, ElType X, IdxType i){
    IdxType j;
    for(j=GetLastIdx(*T);j>=i;j--){
        Elmt(*T,j+1)=Elmt(*T,j);
    }
    Elmt(*T,i)=X;
    Neff(*T)++;
        
    
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
    (*X)=Elmt(*T,GetLastIdx(*T));
    Neff(*T)--;

}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X){
    IdxType j;
    (*X)=Elmt(*T,i);

    if (GetFirstIdx(*T)<GetLastIdx(*T)){
        for (j=i;j<GetLastIdx(*T);j++){
        Elmt((*T),j)=Elmt((*T),j+1);
        }
    }
    Neff(*T)--; 
    
    
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
    if (!IsFull(*T)){
        if (SearchSentinel((*T), X)){
        printf("nilai sudah ada\n");
        }else {
        AddAsLastEl(T, X);
        }
    }
    
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
    IdxType i;
    IdxType FirstIdx=GetFirstIdx(T);
    IdxType LastIdx=GetLastIdx(T);

    if (!IsEmpty(T)){
        for (i=FirstIdx;i<=LastIdx;i++){
            if (Elmt(T,i)==X){
                break;
            }else if (i==LastIdx){
                i=IdxUndef;
            }
        }
    }else{
        i=IdxUndef;
    }

    return i;

}
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
ElType MaxUrut (TabInt T){
    return (Elmt(T,GetLastIdx(T)));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
ElType MinUrut (TabInt T){
    return (Elmt(T,GetFirstIdx(T)));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
    *Max=MaxUrut(T);
    *Min=MinUrut(T);
}
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
void Add1Urut (TabInt * T, ElType X){
    AddAsLastEl(T, X);
    InsSortAsc(T);
   
}
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
void Del1Urut (TabInt * T, ElType X){
    IdxType i=Search1(*T, X);
    if (i!=IdxUndef){
        DelEli(T, i, &X);
    }
        
}

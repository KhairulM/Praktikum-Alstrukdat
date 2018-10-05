/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel dinamik */

#include "arraydin.h"
#include "stdio.h"
#include "stdlib.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
	TI(*T) = (int *) malloc ((maxel+1)*sizeof(int));
	Neff(*T)=0;

}

/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabInt *T){
	free(TI(*T));
}
/* I.S. T terdefinisi;
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
	return (Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
		return (T.MaxEl);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
	return (IdxMin);
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
	return (IdxMin+Neff(T)-1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
	return ((i>=IdxMin) && (i<=T.MaxEl));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
	return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
	return (Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
	return (Neff(T)==T.MaxEl);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
	int N;
    IdxType FirstIdx=GetFirstIdx(*T);

    scanf("%d", &N);
    while (N<0 || N>(*T).MaxEl){
        scanf("%d", &N);
    }
    if (N!=0){
        for (IdxType i=FirstIdx;i<=FirstIdx+N-1;i++){
            scanf("%d", &(Elmt(*T,i)));
        }
    }
    Neff(*T)=N;
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
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
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
	TabInt *T3;
	(*T3).MaxEl=T1.MaxEl;
	MakeEmpty (T3,(*T3).MaxEl);
	IdxType FirstIdx=GetFirstIdx(T1);
    IdxType LastIdx=GetLastIdx(T1);
    IdxType i;
    
	if (plus){
		for (i=FirstIdx;i<=LastIdx;i++){
			Elmt(*T3,i)=Elmt(T1,i)+Elmt(T2,i);
		}
	}else {
		for (i=FirstIdx;i<=LastIdx;i++){
			Elmt(*T3,i)=Elmt(T1,i)-Elmt(T2,i);
		}
	}
	
	Neff(*T3)=Neff(T1);
	return (*T3);
	Dealokasi(T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
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

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
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
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
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
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
	IdxType i;
	*Max=Elmt(T,IdxMin);
	*Min=Elmt(T,IdxMin);
	
	for (i=IdxMin+1;i<=GetLastIdx(T);i++){
		if (Elmt(T,i)>*Max){
			*Max=Elmt(T,i);
		}if (Elmt(T,i)<*Min){
			*Min=Elmt(T,i);
		}
	}
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
	IdxType i;

	(*Tout).MaxEl=Tin.MaxEl;
	MakeEmpty(Tout, (*Tout).MaxEl);
    if (!IsEmpty(Tin)){
        for (i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
            Elmt(*Tout,i)=Elmt(Tin,i);
        }
    }
    Neff(*Tout)=Neff(Tin);
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
	ElType Sum=0;
	IdxType i;
	
	if (!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			Sum+=Elmt(T,i);
		}
	}
	
	return Sum;
	
	
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
	int Count=0;
	IdxType i;
	
	if (!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)==X){
				Count++;
			}
		}
	}
	
	return Count;
	
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
	IdxType i;
	boolean Genap=true;
	
	if (!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)%2!=0){
				Genap=false;
			}
		}
	}
	
	return Genap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
	IdxType Pass, i, IMax;
    ElType Temp;
    IdxType FirstIdx=GetFirstIdx(*T);
    IdxType LastIdx=GetLastIdx(*T);
	
	
	if (asc){
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
	}else{
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
	
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
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
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
	(*X)=Elmt(*T,GetLastIdx(*T));
    Neff(*T)--;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
	TabInt *T2;
	
	
	(*T).MaxEl+=num;
	(*T2).MaxEl=(*T).MaxEl;
	MakeEmpty(T2, (*T2).MaxEl);
	CopyTab(*T, T2);
	MakeEmpty(T, (*T).MaxEl);
	CopyTab(*T2, T);
	free(T2);
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
	TabInt *T2;
	
	
	(*T).MaxEl-=num;
	(*T2).MaxEl=(*T).MaxEl;
	MakeEmpty(T2, (*T2).MaxEl);
	CopyTab(*T, T2);
	MakeEmpty(T, (*T).MaxEl);
	CopyTab(*T2, T);
	free(T2);
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
	ShrinkTab(T, ((*T).MaxEl-Neff(*T)));
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */



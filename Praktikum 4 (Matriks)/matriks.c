#include "matriks.h"
#include "stdio.h"
#include "math.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	return (((i>=BrsMin) && (i<=BrsMax)) && ((j>=KolMin) && (j<=KolMax)));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
	return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
	return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
	return (BrsMin+NBrsEff(M)-1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
	return (KolMin+NKolEff(M)-1);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	return (((i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M))) && ((j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M))));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
	return (Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(MIn);
	indeks FirstKol=GetFirstIdxKol(MIn);
	indeks LastBrs=GetLastIdxBrs(MIn);
	indeks LastKol=GetLastIdxKol(MIn);

	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

	if ((NBrsEff(MIn)>0) && (NKolEff(MIn)>0)){
		for (i=FirstBrs;i<=LastBrs;i++){
			for (j=FirstKol;j<=LastKol;j++){
				Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
			}
		}
	}
		
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	indeks i, j;
	
	MakeMATRIKS(NB, NK, M);

	
	indeks FirstBrs=GetFirstIdxBrs(*M);
	indeks FirstKol=GetFirstIdxKol(*M);

	for (i=FirstBrs;i<=NB;i++){
		for (j=FirstKol;j<=NK;j++){
			scanf("%d", &Elmt(*M,i,j));
		}
	}
	

	

}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M);
	indeks FirstKol=GetFirstIdxKol(M);
	indeks LastBrs=GetLastIdxBrs(M);
	indeks LastKol=GetLastIdxKol(M);

	if ((NBrsEff(M)>0) && (NKolEff(M)>0)){
		for (i=FirstBrs;i<=LastBrs;i++){
			for (j=FirstKol;j<=LastKol;j++){
				if (i==LastBrs && j==LastKol){
					printf("%d", Elmt(M,i,j));
				}else if (j==LastKol){
					printf("%d\n", Elmt(M,i,j));
				}else{
					printf("%d ", Elmt(M,i,j));
				}
			}
		}
	}
		

}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M1);
	indeks FirstKol=GetFirstIdxKol(M1);
	indeks LastBrs=GetLastIdxBrs(M1);
	indeks LastKol=GetLastIdxKol(M1);

	if ((NBrsEff(M1)>0) && (NKolEff(M1)>0)){
		for (i=FirstBrs;i<=LastBrs;i++){
			for (j=FirstKol;j<=LastKol;j++){
				Elmt(M1,i,j)+=Elmt(M2,i,j);
			}
		}
	}
	

	return M1;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M1);
	indeks FirstKol=GetFirstIdxKol(M1);
	indeks LastBrs=GetLastIdxBrs(M1);
	indeks LastKol=GetLastIdxKol(M1);

if ((NBrsEff(M1)>0) && (NKolEff(M1)>0)){
	for (i=FirstBrs;i<=LastBrs;i++){
		for (j=FirstKol;j<=LastKol;j++){
			Elmt(M1,i,j)-=Elmt(M2,i,j);
		}
	}
}
	

	return M1;
}
/* Prekondisi : M1 berukuran sama dengan M2 */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i, j, k;
	ElType Sum;
	MATRIKS M3;

	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);

	if ((NBrsEff(M1)>0) && (NKolEff(M1)>0) && (NBrsEff(M2)>0) && (NKolEff(M2)>0)){
		for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
			for (k=GetFirstIdxKol(M2);k<=GetLastIdxKol(M2);k++){
				Sum=0;
				for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
					Sum+=Elmt(M1,i,j)*Elmt(M2,j,k);
				}
				Elmt(M3,i,k)=Sum;
			}
		}

		return M3;

	}
	

}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M);
	indeks LastBrs=GetLastIdxBrs(M);
	indeks FirstKol=GetFirstIdxKol(M);
	indeks LastKol=GetLastIdxKol(M);
	MATRIKS M1;

	MakeMATRIKS(NBrsEff(M), NKolEff(M), &M1);

	
	for (i=FirstBrs;i<=LastBrs;i++){
		for (j=FirstKol;j<=LastKol;j++){
			Elmt(M1,i,j)=Elmt(M,i,j)*X;
		}
	}
	
	
	return (M1);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
	(*M)=KaliKons(*M, K);
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M1);
	indeks LastBrs=GetLastIdxBrs(M1);
	indeks FirstKol=GetFirstIdxKol(M1);
	indeks LastKol=GetLastIdxKol(M1);
	boolean Equal=false;

	if (EQSize(M1, M2)){
		if (NBrsEff(M1)==0){
			Equal=true;
		}else {
			for (i=FirstBrs;i<=LastBrs;i++){
				for (j=FirstKol;j<=LastKol;j++){
					if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
						break;
					}else if ((i==LastBrs) && (j==LastKol)){
						Equal=true;
					}
				}
				if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
					break;
				}
			}
		}
		
	}

	return (Equal);
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
	return(!(EQ(M1, M2)));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	return((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
	return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
	MATRIKS Mt;

if (IsBujurSangkar(M)){
	CopyMATRIKS(M, &Mt);
	Transpose(&Mt);

	return (EQ(M, Mt));
}else{
	return false;
}
	

}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M);
	indeks LastBrs=GetLastIdxBrs(M);
	indeks FirstKol=GetFirstIdxKol(M);
	indeks LastKol=GetLastIdxKol(M);
	boolean Satuan=false;

	if (IsBujurSangkar(M)){
		for (i=FirstBrs;i<=LastBrs;i++){
			for (j=FirstKol;j<=LastKol;j++){
				if (((i==j) && (Elmt(M,i,j)!=1)) || ((i!=j) && (Elmt(M,i,j)!=0))){
					break;
				}else if ((i==LastBrs) && (j==LastKol)){
					Satuan=true;
				}
			}
		}
	}

	return Satuan;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
	int Percentage=(5*NBElmt(M))/100;
	int Count=0;
	indeks i, j;
	indeks FirstBrs=GetFirstIdxBrs(M);
	indeks LastBrs=GetLastIdxBrs(M);
	indeks FirstKol=GetFirstIdxKol(M);
	indeks LastKol=GetLastIdxKol(M);

	if ((NBrsEff(M)>0) && (NKolEff(M)>0)){
		for (i=FirstBrs;i<=LastKol;i++){
			for (j=FirstKol;j<=LastKol;j++){
				if (Elmt(M,i,j)!=0){
					Count++;
				}
			}
		}

		return (Count<=Percentage);
	}else {
		return false;
	}
	


}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
	return (KaliKons(M, (-1)));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
MATRIKS DelBrs1AndKol (MATRIKS M, indeks Kol){
	MATRIKS M1;
	indeks i, j;
	indeks KolM1=KolMin;

	MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &M1);

	for (i=GetFirstIdxBrs(M)+1;i<=GetLastIdxBrs(M);i++){
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			if (j!=Kol){
				Elmt(M1,i-1,KolM1)=Elmt(M,i,j);
				KolM1++;
			}if (KolM1>NKolEff(M1)){
				KolM1=KolMin;
			}
		}
	}

	return M1;

}
float Determinan (MATRIKS M){
	float Sum=0;
	MATRIKS M1;
	indeks i, j;
	indeks BrsM, KolM;
	indeks BrsM1=BrsMin;
	indeks KolM1;

	/*Basis*/
	if ((NBrsEff(M)==1) && (NKolEff(M)==1)){
		return (Elmt(M,1,1)*1.0);
	}
	if ((NBrsEff(M)==2) && (NKolEff(M)==2)){
		Sum+=(Elmt(M,1,1)*Elmt(M,2,2))-(Elmt(M,1,2)*Elmt(M,2,1));
	}
	else {

		for (i=GetFirstIdxKol(M);i<=GetLastIdxKol(M);i++){
			if (i%2==0){
				Sum+=Elmt(M,1,i)*(-1)*Determinan(DelBrs1AndKol(M, i));
			}else{
				Sum+=Elmt(M,1,i)*Determinan(DelBrs1AndKol(M, i));
			}
			
		}
	}
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
	(*M)=Inverse1(*M);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
	indeks FirstBrs=GetFirstIdxBrs(*M);
	indeks LastBrs=GetLastIdxBrs(*M);
	indeks FirstKol=GetFirstIdxKol(*M);
	indeks LastKol=GetLastIdxKol(*M);
	ElType Temp;
	indeks i;
	indeks j=FirstKol;

	
	for (i=FirstBrs;i<=LastBrs;i++){
		while (j<=LastKol){
			Temp=Elmt(*M,i,j);
			Elmt(*M,i,j)=Elmt(*M,j,i);
			Elmt(*M,j,i)=Temp;
			j++;
		}
		j=FirstKol+i;
	}
}

/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */



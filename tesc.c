#include "stdio.h"
#include "math.h"
#include "listlinier.h"

int main(){
List L1, L2;
address P1, P2;


CreateEmpty(&L1);
CreateEmpty(&L2);
P1=First(L1);
P2=First(L2);

printf("%s, %s", First(L1), First(L2));

P1=Alokasi(10);
InsertFirst(&L1, P1);
P2=Alokasi(15);
First(L2)=P2;
Next(P1)=Alokasi(12);
PrintInfo(L1);
PrintInfo(L2);




return 0;
}

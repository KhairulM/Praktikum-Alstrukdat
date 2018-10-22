#include "stackt.h"
#include "boolean.h"
#include "stdio.h"
#include "string.h"


int main(){
    /***KAMUS***/
    Stack S1, S2, SHsl;
    char str1[101];
    char str2[101];
    int i, j, carry;
    infotype CI, i1, i2, iHsl;
    boolean isNeg=false;
    boolean isLess=false;
    boolean isLeadingZero=true;




    /***ALGORITMA***/
    carry=0;

    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&SHsl);

    scanf("%s", str1);
    scanf("%s", str2);

    for (i=0;i<=strlen(str1)-1;i++){
        CI=(int) str1[i] - 48;
        Push(&S1, CI);
    }

    for (i=0;i<=strlen(str2)-1;i++){
        CI=(int) str2[i] - 48;
        Push(&S2, CI);
    }

    if (Top(S1)<Top(S2)){
        isNeg=true;
    }

    if (Top(S1)==Top(S2)){
        i=1;
        while (!isLess && i<=Top(S1)){
            if (S1.T[i]<S2.T[i]){
                isLess=true;
            }
            i++;
        }
        if (isLess){
            isNeg=true;
        }
    }

    if (isNeg){
        while (Top(S1)!=Nil){
            Pop(&S1, &i1);
            Pop(&S2, &i2);

            if (carry==1){
                i2-=1;
                carry=0;
            }
            
            if (i2<i1){
                i2+=10;
                carry=1;
            }
            
            Push(&SHsl, i2-i1);
        }

        while (Top(S2)!=Nil){
            Pop(&S2, &i2);

            if (carry==1){
                i2-=1;
                carry=0;
            }
            
            if (i2<0){
                i2+=10;
                carry=1;
            }

            Push(&SHsl, i2);
        }
    }else{
        while (Top(S2)!=Nil){
            Pop(&S1, &i1);
            Pop(&S2, &i2);

            if (carry==1){
                i1-=1;
                carry=0;
            }
            
            if (i1<i2){
                i1+=10;
                carry=1;
            }
            
            Push(&SHsl, i1-i2);
        }

        while (Top(S1)!=Nil){
            Pop(&S1, &i1);
            
            if (carry==1){
                i1-=1;
                carry=0;
            }
            
            if(i1<0){
                i1+=10;
                carry=1;
            }


            Push(&SHsl, i1);
        }

    }
    if (isNeg){
        printf("-");
    }

    Pop(&SHsl, &iHsl);
    while(isLeadingZero && iHsl==0 && Top(SHsl) != Nil){
            Pop(&SHsl, &iHsl);
    }
    printf("%d", iHsl);
    while(Top(SHsl) != Nil){
        Pop(&SHsl, &iHsl);

        printf("%d", iHsl);
        
        
    }


    return 0;
}
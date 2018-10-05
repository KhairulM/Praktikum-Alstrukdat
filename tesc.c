#include "stdio.h"
#include "math.h"

int main(){
 int retval, i, CI;
 FILE *Test;

 Test=fopen("Test.txt","r");
 retval=fscanf(Test, "%d", &CI);
 i=0;
while (i<=5){
    printf("%d\n", CI);
    i++;
}

//printf("%d", 9/4);



 return 0;
}

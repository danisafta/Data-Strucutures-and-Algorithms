#include <stdio.h>
#include <string.h>

int main(){

char sir[256],cuvant[64];
char* cuvSir;
int k=0;

gets(sir);
gets(cuvant);

cuvSir=strtok(sir," ");

while(cuvSir){
    
    if(strcmp(cuvSir,cuvant)==0) k++;
    cuvSir=strtok(NULL," ");
}


printf("%d",k);
return 0;
} 
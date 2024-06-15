#include<stdio.h>

int main(void){
    FILE* file = fopen("./123.txt","r");
    if(file == NULL){
        perror("fopen");
    }
    fscanf(file,"123");
    int a = fseek(file,0,SEEK_END);
    int end = ftell(file);
    rewind(file);
    int start = ftell(file);
    printf("fseek_end%d end %d,start%d,长度%d",a,end,start,end-start); 
    return 0;
}

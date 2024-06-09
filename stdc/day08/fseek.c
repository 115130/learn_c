#include<stdio.h>
int main(void){
    FILE* f_p =fopen("test.txt","w+");
    if(f_p == NULL){
        printf("文件打开失败");
        return -1; 
    }
    int a[8] = {48,49,50,51,52,53,54,55};
    fwrite(a,sizeof(char),8,f_p);
    fseek(f_p,4,SEEK_SET);
    int a1[8] = {};
    fread(a1,sizeof(char),8,f_p);
    for(int i = 0;i< 8;i++){
        printf("%c\n",a1[i]);
    }    
    fclose(f_p);
    f_p=NULL;

    return 0;
}

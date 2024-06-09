#include<stdio.h>
int main(void){
    FILE* f_p =fopen("test.txt","w");
    if(f_p == NULL){
        printf("文件打开失败");
        return -1; 
    }
    char a[8] = {48,49,50,51,52,53,54,55};
    fwrite(a,sizeof(char),8,f_p);
    
    fclose(f_p);
    f_p=NULL;

    return 0;
}

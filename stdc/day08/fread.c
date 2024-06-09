#include<stdio.h>
int main(void){
    FILE* f_p =fopen("test.txt","r");
    if(f_p == NULL){
        printf("文件打开失败");
        return -1; 
    }
    char a[9] = {};
    int size = fread(a,sizeof(char),8,f_p);
    printf("读取到%d个元素",size);
    //a[8] = '\0';
    printf("%s",a);
    for(int i = 0;i < 8;i++){
        printf("%d\n",a[i]);
    }
    fclose(f_p);
    f_p=NULL;

    return 0;
}

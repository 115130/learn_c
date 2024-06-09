#include<stdio.h>
int main(void){
    FILE* fw = fopen("./out","w");
    if(fw == NULL){
        printf("文件打开失败");
        return -1;
    }
    fprintf(fw,"马上就放假啦\n");
    fclose(fw);
    fw = NULL;
    return 0;
}

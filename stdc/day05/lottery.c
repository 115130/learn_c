#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main(void){
    time_t now = time(0);
    srand(now);
    int blue = rand() % 16 + 1;
    int red[6] = {};
    int size = sizeof(red)/sizeof(red[0]);
    for(int i = 0;i<size; i++){
        int r = rand() % 33 +1;
        int j = 0;
        for(j = 0;j < i;j++){
            if(r == red[j]){
                i--; //可以通过操作外层循环来控制键不结束
                break;
            }
        }
        if(j==i){
            red[i] = r;
        }
    }
    printf("红球:");
    for(int i = 0;i<size;i++){
        printf("%d ",red[i]);
    }

    printf("\n蓝球: %d",blue);
    return 0;
}


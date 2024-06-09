#include<stdio.h>

typedef struct {
    int age;
    char name[32];
}stu_t;
int main(void){
    stu_t arr[3] = {{18,"123"},{32,"321"},{21,"5476"}};
    for (int i = 0;i < 3; i++){
        printf("age:%d,name:%s\n",arr[i].age,arr[i].name);
    }
    printf("\n");
    stu_t* arr_p = arr;
    for (int i = 0;i < 3; i++){
        printf("age:%d,name:%s\n",arr_p[i].age,arr_p[i].name);
    }
    printf("\n");
    for (int i = 0;i < 3; i++){
        printf("age:%d,name:%s\n",arr_p -> age,arr_p -> name);
        arr_p++;
    }

    return 0;
}

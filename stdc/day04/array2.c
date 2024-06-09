#include<stdio.h>
int main(void){
    int count = 0;
    double sum = 0,max = 0;
    printf("请输入学生数量,然后开始录入每个学生的分数");
    scanf("%d",&count);
    double arr[count]={};
    for(int i = 0; i < count; i++){
        printf("请输入第%d同学的成绩",i);
        scanf("%lf",&arr[i]);
    }
    for(int i = 0; i < count; i++){
        sum+=arr[i];
        if(arr[i]>max){
            max = arr[i];
        }
    }
    printf("总分是%.2lf,平均分是%.2lf,最高分是%.2lf",sum,sum/count,max);
    return 0;
}

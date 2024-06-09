#include<stdio.h>
#include<string.h>
struct student{
    int age;
    char name[64];
    double score;
};

int main(void){
    struct student stu1 = {19,"12435",89.1};
    printf("%s今年%d岁,成绩%lg分\n",stu1.name,stu1.age,stu1.score);   
    *stu1.name = *"43421";
    strcpy(stu1.name,"241");
    stu1.age = 19;
    stu1.score = 72.9;
    printf("%s今年%d岁,成绩%lg分\n",stu1.name,stu1.age,stu1.score);   

    struct student s2 = {.name="张三",.score=76.8,.age=21};
    printf("%s今年%d岁,成绩%lg分\n",s2.name,s2.age,s2.score);   
    struct student *p_s2 = &s2;
    printf("%d",p_s2 -> age);
    p_s2 -> age = 32;
    printf("%d",p_s2 -> age);
    return 0;
}

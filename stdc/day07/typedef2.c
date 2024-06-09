#include<stdio.h>
typedef struct{
    int age;
    char name[32];
}stu_t;

void fun(stu_t* s){
    printf("%s->年%d岁\n",s->name,s->age);
    s->age = 19;
    printf("%s->年%d岁\n",s->name,s->age);
}
stu_t bar(){
    stu_t s = {19,"李云龙"};
    return s;
}
stu_t* bar1(){
    stu_t s = {19,"李云龙"};
    stu_t *p_s = &s;
    return p_s;
}
int main(void){
    stu_t s = {18,"zhangsan"};
    printf("主函数:%s,%d\n",s.name,s.age);
    fun(&s);

    printf("主函数:%s,%d\n",s.name,s.age);

    stu_t s1 = bar();
    printf("主函数:%s,%d\n",s1.name,s1.age);

    stu_t* s2 = bar1();
    printf("主函数1:%s,%d\n",s2->name,s2->age);
    return 0;
}

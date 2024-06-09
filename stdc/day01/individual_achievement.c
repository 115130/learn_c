#include<stdio.h>
int main(void){
    float stu1_chinese = 80.2,stu1_math = 70.4,stu2_chinese = 90.67, stu2_math = 86.1;
    printf("学生1的语文成绩是%.2f, 学生1的数学成绩是%.2f, 学生2的语文成绩是%.2f, 学生2的数学成绩是%.2f, 学生1的总成绩是%.2f, 学生2的总成绩是%.2f", stu1_chinese, stu1_math, stu2_chinese, stu2_math, stu1_math + stu1_chinese, stu2_math + stu2_chinese);
    return 0;
}

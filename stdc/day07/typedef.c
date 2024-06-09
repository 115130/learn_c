#include <stdlib.h>
#include<stdio.h>
#include <string.h>
 struct student{
    int age;
    char* name;
    double score; 
} ;
typedef struct student stu_t;
int main(void){
    typedef int data_t;
    stu_t stu = {};    
    stu.name = malloc(sizeof(char)*64);
    stu.score = 65.1;
    *stu.name = *"dsadsaf";
    //strcpy(stu.name,"2434232");
    stu.age = 789;
    printf("%d,%s,%.2lf",stu.age,stu.name,stu.score);
    return 0;
}

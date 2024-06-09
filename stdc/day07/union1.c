#include<stdio.h>
typedef struct person{
    char name[32];
    char job;
    union {
        char position[32];
        int number;
    } un;
}ps_t;

int main(void){
    ps_t p[3] = {
                {"115",'s',.un.number = 1234567},
                {"321",'t',.un.position = "4313"},
                {"547",'s',.un.number = 343345}};
    for(int i = 0;i<3;i++){
        if(p[i].job == 's'){
            printf("姓名: %s,学号:%d\n",p[i].name,p[i].un.number);
        }else if(p[i].job == 't'){ 
            printf("姓名:%s,职称%s\n",p[i].name,p[i].un.position);
        }
    }
    return 0;
}

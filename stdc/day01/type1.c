#include<stdio.h>
int main(void){
    char n1 = 127;
    printf("char %lu\n",sizeof(char));
    printf("unsigned char %lu\n",sizeof(unsigned char));
    printf("short %lu\n",sizeof(short));
    printf("unsigned short %lu\n",sizeof(unsigned short));
    printf("int %lu\n",sizeof(int));
    printf("unsigned int %lu\n",sizeof(unsigned int));
    printf("long %lu\n",sizeof(long));
    printf("unsigned long %lu\n",sizeof(unsigned long));
    printf("float %lu\n",sizeof(float));
    printf("double %lu\n",sizeof(double));
    return 0;
}

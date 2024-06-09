#include<stdio.h>
#include<string.h>
int main(void){

    char * str1 = "hello";
    char str2[10] = "hello";
    printf("%lu",strlen(str1));
    printf("%lu",strlen(str2));

    char* str3 = "abc";
    char *str4 = "def";
    while(1);
//    char* str5 = strcat(str3,str4);
 //   printf("%s",str5);
    char str6[10] ={};
    strcpy(str6,"123456789");
    printf("\n%s",str6);
    strcpy(str6,"6789");
    printf("\n%s",str6);

    return 0;
}

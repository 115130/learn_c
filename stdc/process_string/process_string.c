#include<stdio.h>
//拷贝字符串
char* str_cpy(char str,char str1);
//连接字符串
char* str_cat(char* str1,char str2);
//比较字符串
int str_cmp(char* str1,char* str2);
//查找字符串
int find_str(char* str,char* sub);
//替换字符串
char* replace_str(char* str,char* str1);
//计算字符串长度
unsigned long str_len(char* str);

int main(void){
    unsigned long len = str_len("123456");
    printf("%lu",len);
    return 0;
}
//拷贝字符串
char* str_cpy(char str,char str1){
    return NULL;
}
//连接字符串
char* str_cat(char* str1,char str2){
    return NULL;
}
//比较字符串
int str_cmp(char* str1,char* str2){
    return 0;
}
//查找字符串
int find_str(char* str,char* sub){
    return 0;
}
//替换字符串
char* replace_str(char* str,char* str1){
    return NULL;
}
//计算字符串长度
unsigned long str_len(char* str){
    unsigned long i = 0;
    while(*(str + i) != '\0'){
        i++;
    }
    return i;
}

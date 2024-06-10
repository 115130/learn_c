#include<stdio.h>
//拷贝字符串
char* str_cpy(char* str,char* str1);
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
    printf("%lu\n",len);
    char str[20] = "abcdefg";
    char* str1="123456";
    printf("%s %s\n",str,str1);
    str_cpy(str,str1);
    printf("%s %s\n",str,str1);
    return 0;
}
//拷贝字符串
char* str_cpy(char* str,char* str1){
    unsigned long str1_len = str_len(str1);
    for(int i = 0;i < str1_len;i++){
        str[i] = str1[i];
    }
    return str;
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

#include<stdio.h>
//拷贝字符串
char* str_cpy(char* str,char* str1);
//连接字符串
char* str_cat(char* str1,char* str2);
//比较字符串
int str_cmp(char* str1,char* str2);
//查找字符串
int find_str(char* str,char* sub);
//替换字符串
char* replace_str(char*,char*,char*);
//计算字符串长度
unsigned long str_len(char* str);

int main(void){
    unsigned long len = str_len("123456");
    printf("%lu\n",len);
    char str[20] = "123456";
    char* str1="";
    printf("%s %s\n",str,str1);
    //str_cpy(str,str1);
    //str_cat(str,str1);
    //printf("%d\n",str_cmp(str,str1));
    //printf("%d\n",find_str(str,str1));
    printf("%s %s\n",str,str1);
    return 0;
}
//拷贝字符串,只需要把字符串末尾带\0也复制进去就行了
char* str_cpy(char* str,char* str1){
    unsigned long str1_len = str_len(str1);
    for(unsigned long i = 0;i <= str1_len;i++){
        str[i] = str1[i];
    }
    return str;
}
//连接字符串
char* str_cat(char* str1,char* str2){
    unsigned long str1_len = str_len(str1);
    int index = 0;
    char c = 0;
    do{
        c = str2[index];
        str1[str1_len + index] = c;
        index++;
    }while(c != '\0');
    return NULL;
}
//比较字符串
int str_cmp(char* str1,char* str2){
    unsigned long str1_len = str_len(str1);
    unsigned long str2_len = str_len(str2);
    long str1_v = 0;
    long str2_v = 0;
    for(int i = 0;i < str1_len;i++){
        str1_v += *(str1 + i);
    }
    
    for(int i = 0;i < str2_len;i++){
        str2_v += *(str2 + i);
    }
    return str1_v - str2_v;
}
//查找字符串
int find_str(char* str1,char* str2){
    unsigned long str1_len = str_len(str1);
    unsigned long str2_len = str_len(str2);
    int flag = 0;
    for(unsigned long i = 0;i < str1_len;i++){
        int c = 0;
        for(unsigned long j = 0;j < str2_len;j++){
            if(str1[i+j] == str2[j]){
                c++;
            }
        }
        if(c == str2_len && str2_len != 0){
            flag++;
            break;
        }
    }
    return flag;
}
//替换字符串
char* replace_str(char* source,char* str1,char* str2){
    if(find_str(source,str1) == 1){
        unsigned long str2_len = str_len(str2);
        unsigned long str1_len = str_len(str1);

        
    }else{
        return source;
    }
}
//计算字符串长度
unsigned long str_len(char* str){
    unsigned long i = 0;
    while(*(str + i) != '\0'){
        i++;
    }
    return i;
}

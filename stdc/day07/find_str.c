#include <stdint.h>
#include<stdio.h>
#include <string.h>
int find_str(char*,char*);
int main(void){
    int i = find_str("asdfghjkl","fg"); 
    printf("子字符串在字符串中%s",i?"被找到了":"没被找到");
    return 0;
}
int find_str(char* content,char* sub_str){
    unsigned long content_size = strlen(content);
    unsigned long sub_str_size = strlen(content);
    int flag = 0;
    for(int i = 0;i < content_size;i++){
         flag = 0;
        for(int j = 0;j < sub_str_size;j++){
            if(content[i]==sub_str[j]){
                flag++;
            }          
        }    
    }
    if(flag == sub_str_size){
        return 1;
    }
    return 0;
}

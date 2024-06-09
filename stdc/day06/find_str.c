#include<stdio.h>
#include <string.h>
int find_str(char*,char*);
int main(void){
    int i = find_str("asdfghjkl","fg"); 
    printf("子字符串在%d被找到",i);
    return 0;
}
int find_str(char* content,char* sub_str){
    unsigned long content_size = strlen(content);
    unsigned long sub_str_size = strlen(content);
    for(int i = 0;i < content_size;i++){
        int flag = 0;
        for(int j = 0;j < sub_str_size;j++){
            
        }    
    }
    
}

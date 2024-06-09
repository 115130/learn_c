#include<stdio.h>
int main(){
    char *str = "hello";
    printf("%s\n ",str);
    printf("%s\n",str +1 );
    printf("%c %c %c\n",*str,*(str+2),*(str+4));
    printf("%c %c %c\n",str[0],str[2],str[4]);
    
    char arr[] = {'h','e','l','l','o','\0'};
    char arr1[] = "hello";
    printf("%s\n",arr);
    printf("%s\n",arr1);

    return 0;
}

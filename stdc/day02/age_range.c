#include<stdio.h>
int main(void){
    char year = 0;
    printf("请输入年纪");
    scanf("%c",&year);
    printf("%s",year < 18 ? "你未成年,不能上班":year<60?"欢迎上班":"你该退休了");
}

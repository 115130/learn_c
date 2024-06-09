#include<stdio.h>
typedef struct point{
    int x;
    int y;
}point;

typedef struct rectangle{
    point p1;
    point p2;
}rect;

int main(void){
    point p1 = {};
    printf("请输入第一个坐标点\n");
    scanf("%d%d",&(p1.x),&(p1.y));
    point p2 = {}; 
    printf("请输入第二个坐标点\n");
    scanf("%d%d",&(p2.x),&(p2.y));
    rect rect = {p1,p2};
    int width = 0;
    int height = 0;
    if(rect.p1.x>rect.p2.x){
        width = rect.p1.x - rect.p2.x;
    }else{
        width = rect.p2.x - rect.p1.x;
    }
    if(rect.p1.y>rect.p2.y){
        height = rect.p1.y - rect.p2.y;
    }else{
        height = rect.p2.y - rect.p1.y;
    }
    printf("长方形面积为:%d\n",width*height);

    return 0;
}

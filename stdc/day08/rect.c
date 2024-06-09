#include<stdio.h>

typedef struct{
    int x;
    int y;
}point_t;

typedef struct{
    point_t p1;
    point_t p2;
}rect_t;

int main(void){
    rect_t rect = {};
    printf("请输入第一个点的坐标");
    scanf("%d%d",&rect.p1.x,&rect.p1.y);
    
    printf("请输入第二个点的坐标");
    scanf("%d%d",&rect.p2.x,&rect.p2.y);

    int area = (rect.p1.x - rect.p2.y) * (rect.p1.y - rect.p2.y);
    printf("面积是%d",area>0 ? area : (-area));
    return 0;
}

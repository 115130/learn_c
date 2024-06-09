#include<stdio.h>
int fun(int);

int main(){
    fun(5);
    return 0;
}

int fun(int i){
  if(i==0){
      return 0;
  }
  if(i==1){
    return 1;
  }
  return fun(i - 1) + fun(i - 2);
}

void fun1(){
    int i = 0;
    while(1){
        printf("这是第%d次循环",i);
        if(i>100){
            break;
        }
    }
}

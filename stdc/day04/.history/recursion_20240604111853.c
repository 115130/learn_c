#include<stdio.h>
int fun(int);

int main(){
    fun(5);
    return 0;
}

int fun(int i){
  if(i==0){
      return 0;
  }else if(i==1){
    return 1;
  }else{
      return fun(i - 1) + fun(i - 2);
  }
}
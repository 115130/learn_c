//动态库动态加载
#include<stdio.h>
#include<dlfcn.h>

int main(void){
    void* handle = dlopen("./libmath.so",RTLD_NOW);
    if(handle == NULL){
        perror("dlopen");
        return -1;
    }
    int (*add)(int,int)=dlsym(handle,"add");
    printf("动态加载的add返回的结果是%d\n",add(4,6));

    int (*sub)(int,int) = dlsym(handle,"sub");
    printf("动态加载的sub返回的结果是%d\n",sub(1,8));

    void (*show)(int,char,int,int) = dlsym(handle,"show");
    show(2,'-',1,add(2,1));
    return 0;
}

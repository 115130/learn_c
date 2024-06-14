//动态库的动态加载
#include<stdio.h>
#include<dlfcn.h>

int main(void){
    void* handle = dlopen("./dynamic/cal/libmath.so",RTLD_LAZY);
    if(handle==NULL){
        fprintf(stderr,"错误是:%s",dlerror());
        return -1;
    }
    int (*add)(int,int) = dlsym(handle,"add");

    return 0;
}

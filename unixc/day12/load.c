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
    if(add == NULL){
        fprintf(stderr,"dlsym错误是:%s",dlerror());
        return -1;
    }

    int (*sub)(int,int) = dlsym(handle,"sub");
    if(sub == NULL){
        fprintf(stderr,"dlsym错误是:%s",dlerror());
        return -1;
    }

    void (*show)(int,char,int,int) = dlsym(handle,"show");
    if(sub == NULL){
        fprintf(stderr,"dlsym错误是:%s",dlerror());
        return -1;
    }

    int a =123,b=456;
    show(a,'+',b,add(a,b));
    show(a,'-',b,sub(a,b));
    
    dlclose(handle);
    return 0;
}

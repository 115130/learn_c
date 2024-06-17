#include<sys/mman.h>
#include<stdio.h>
int main(void){
    int* p = mmap(NULL,8192,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);  
    if(p  == MAP_FAILED){
        perror("mmap");
        return -1;
    }
    *p = 123;
    printf("%p p = %d",p,*p);
    if(munmap(p,8192) == -1){
        perror("mmap");
        return -1;
    }
    printf("%p p = %d",p,*p);
    
    return 0;
}

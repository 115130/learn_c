#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <pthread.h>

char g_storage[10];
int g_stock = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t pcond = PTHREAD_COND_INITIALIZER;
pthread_cond_t ccond = PTHREAD_COND_INITIALIZER;


void show(char* who,char* op,char prod){
  printf("%s:",who);
  for(int i = 0;i<g_stock;i++){
    printf("%c",g_storage[i]);
  }
  printf("%s:%c\n",op,prod);
}

void* producer(void* t){
  char* who = (char*)t;
  while(1){
    pthread_mutex_lock(&mutex);
    if(g_stock==10){
      printf("%s满仓\n",who);
      pthread_cond_wait(&pcond,&mutex);
    }
    char prod = 'A' + rand() % 26;
    
    show(who,"<--",prod);
    g_storage[g_stock] = prod;
    g_stock++;
    pthread_cond_signal(&ccond);
    pthread_mutex_unlock(&mutex);
    usleep((rand()%100) * 1000); 
  }
   
  return NULL;
}

void* consumer(void* t){
  char* who = (char*)t;
  while(1){    
    pthread_mutex_lock(&mutex);
    if(g_stock==0){
      printf("%s空仓\n",who);
      pthread_cond_wait(&ccond,&mutex);
    }
    char prod = g_storage[--g_stock];
    show(who,"-->",prod);
    pthread_cond_signal(&pcond);
  
    pthread_mutex_unlock(&mutex);
    usleep((rand()%100) * 1000); 
  }
  
  return NULL;
}

int main(void){
  srand(getpid());
  pthread_t t1,t2;
  pthread_create(&t1,NULL,producer,"生产者");
  pthread_create(&t2,NULL,consumer,"消费者");
  getchar();
  return 0;
}

#include<stdlib.h>
#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>

int main(int argc,char* argv[]){
    struct hostent* h = gethostbyname(argv[1]);
    if(h == NULL){
        perror("gethostbyname");
        return -1;
    }
    printf("主机官方名%s\n:",h->h_name);
    printf("主机别名表:\n");
    for(char **pp=h->h_aliases;*pp;pp++){
        printf("%s\n",*pp);
    }
    printf("ip地址表:\n");
    for(struct in_addr **pp =(struct in_addr**) h-> h_addr_list;*pp;pp++){
        printf("%s\n",inet_ntoa(**pp));
    }


}

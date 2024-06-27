#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include <ctype.h>

void urlencode_utf8(const unsigned char *src, char *dest) {
    const char *hex = "0123456789ABCDEF";
    while (*src) {
        if (isalnum(*src) || *src == '-' || *src == '_' || *src == '.' || *src == '~') {
            *dest++ = *src;
        } else {
            *dest++ = '%';
            *dest++ = hex[*src >> 4];
            *dest++ = hex[*src & 15];
        }
        src++;
    }
    *dest = '\0';  // Null-terminate the destination string
}

int main(void){
    const unsigned char city[64]  = "武汉";
    const char* key ="05ec0972bd980656ada59c3d6cacb0d2";
    int sockfd =socket(AF_INET,SOCK_STREAM,0);
    if(sockfd ==-1){
        perror("socket");
        return -1;
    }
    struct sockaddr_in ser;
    ser.sin_family=AF_INET;
    ser.sin_port=htons(80);
    ser.sin_addr.s_addr=inet_addr("203.107.54.210");
    if(connect(sockfd,(struct sockaddr*)&ser,sizeof(ser))==-1){
        perror("connect");
        return -1;
    }
    //printf("请从键盘输入你所在的城市");
    //scanf("%s",city);

    char encode[64] = {};
    urlencode_utf8(city,encode);

    char request[1024] = {};
    sprintf(request,"GET /simpleWeather/query?key=%s&city=%s HTTP/1.1\r\n"
                    "Host: apis.juhe.cn\r\n"
                    "Accept: */*\r\n"
                    "Content-Type: application/x-www-form-urlencoded\r\n"
                    "Connection: close\r\n\r\n",key,encode);

    printf("%s",request);
    if(send(sockfd,request,strlen(request),0) == -1){
        perror("send");
        return -1;
    }

    char buf[10240];
    recv(sockfd,buf , sizeof(buf), 0);
    printf("%s",buf);

    close(sockfd);

    return 0;
}

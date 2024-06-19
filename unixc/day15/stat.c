#include <stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
#include<unistd.h>

char* mtos(mode_t m){
    char *s = malloc(sizeof(char)*11);
    if(S_ISDIR(m)){
        s[0] = 'd';
    }else if(S_ISLNK(m)){
        s[0] = 'l';
    }else if(S_ISSOCK(m)){
        s[0] = 'S';
    }else if(S_ISCHR(m)){
        s[0] = 'c';
    }else if(S_ISBLK(m)){
        s[0] = 'b';
    }else if(S_ISFIFO(m)){
        s[0] = 'p';
    }else{
        s[0] = '-';
    }

    s[1] = S_IRUSR & m ? 'r' :  '-';
    s[2] = S_IWUSR & m ? 'w' :  '-';
    s[3] = S_IXUSR & m ? 'x' :  '-';

    s[4] = S_IRGRP & m ? 'r' :  '-';
    s[5] = S_IWGRP & m ? 'w' :  '-';
    s[6] = S_IXGRP & m ? 'x' :  '-';

    s[7] = S_IROTH & m ? 'r' :  '-';
    s[8] = S_IWOTH & m ? 'w' :  '-';
    s[9] = S_IXOTH & m ? 'x' :  '-';

    return s;
}

char* ttos(time_t t){
    static char time [20];
    struct tm* l = localtime(&t);
    sprintf(time,"%04d-%02d-%02d %02d:%02d:%02d",l->tm_year + 1900,
            l->tm_mon+1,l->tm_mday,l->tm_hour,l->tm_min,l->tm_sec);

    return time;
}

int main(int argc,char** argv){
    if(argc < 2){
        fprintf(stderr,"用法:./stat <文件名>\n");
        return -1;
    }
    struct stat st;
    if(stat(argv[1],&st) == -1){
        perror("stat");
        return -1;
    }
    printf("      设备id:%ld\n",st.st_dev);
    printf("      i节点号:%ld\n",st.st_ino);
    printf("      类型和权限:%s\n",mtos(st.st_mode));
    printf("      硬链接数:%ld\n",st.st_nlink);
    printf("      用户id:%u\n",st.st_uid);
    printf("      组id:%ld\n",st.st_dev);
    printf("      文件大小:%ld\n",st.st_size);
    printf("      特殊设备id:%ld\n",st.st_rdev);
    printf("      IO块字节数:%lu\n",st.st_blksize);
    printf("      存储块数:%lu\n",st.st_blocks);
    printf("      最后访问时间%s\n",ttos(st.st_atime));
    printf("      最后修改时间%s\n",ttos(st.st_mtime));
    printf("      最后改变时间%s\n",ttos(st.st_ctime));



    return  0; 
}

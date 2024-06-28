#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int main(int argc, char* argv[]){
    setbuf(stdout,NULL);
    if(init_server(argc < 2 ? 80 : atoi(argv[1]))==-1){
        return -1;
    };

    if(run_server(argc < 3 ? "../home":argv[2])==-1){
        return -1;
    };
    deinit_server();
    
}

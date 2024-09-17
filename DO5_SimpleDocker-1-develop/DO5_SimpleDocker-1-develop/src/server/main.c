#include "fcgi_stdio.h"
#include <stdio.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\nHello World");
        
    }
    return 0;
}


/* wyattsar@pr-n4 src % docker cp nginx.conf adoring_meninsky:/etc/nginx

wyattsar@pr-n4 src % docker cp main.c adoring_meninsky:/home     

wyattsar@pr-n4 src % docker cp nginx.conf adoring_meninsky:/etc/nginx

wyattsar@pr-n4 src % docker cp main.c adoring_meninsky:/home         

wyattsar@pr-n4 src % docker exec -it adoring_meninsky bash
root@6f10b297a2fb:/# apt-get update */
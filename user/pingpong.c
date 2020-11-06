#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char *argv[]){
    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    int i;
    char *buf="";
    if ((i=fork())!=0){

        write(p1[1],"ping\n",5);
        close(p1[1]);
        // wait(&i);
        read(p2[0],buf,sizeof(buf));
        // printf("%s\n",buf);
        printf("%d: received %s",getpid(),buf);
    }
    else{
    read(p1[0],buf,sizeof(buf));
    // printf("%s\n",buf);
    printf("%d: received %s",getpid(),buf);
    write(p2[1],"pong\n",5);
    close(p2[1]);
    }

    exit();

}
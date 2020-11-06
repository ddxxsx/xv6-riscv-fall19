#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
void main(int argc, char *argv[]){
    int num = atoi(argv[1]);
    if ( num ==0 ){
    printf("wrong input!\n");
    exit();
    }
    sleep(10*num);
    exit();
}
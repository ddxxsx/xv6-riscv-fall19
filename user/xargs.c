#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char *argv[]){
    char * p[40];
    char buff[40];
    char block[40];
    char *pr=buff;
    int k,i,j,l;
    j=0;l=0;

    for(i = 1; i < argc; i++){
        p[j++] = argv[i];
    }
    while((k=read(0,block,sizeof(block)))>0){
        for (i=0;i<k;i++)
        {
            if (block[i]=='\n')
            {
                buff[l]='\0';
                p[j++]=pr;

                l=0;
                pr = buff;
                p[j] = 0;
                j=argc-1;
                if (fork()==0){
                    exec(argv[1],p);
                }
                wait();
                
            }
            else

            if (block[i]==' ')
            {
                buff[l++]='\0';
                p[j++]=pr;
                pr = &buff[l];

            }
            else
            {
                buff[l++]=block[i];
            }
        }
    }

    exit();
}


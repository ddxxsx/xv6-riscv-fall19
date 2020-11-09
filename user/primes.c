#include "kernel/types.h"
#include "user/user.h"

void judge(int j,int k);
void try1();

void try1(){
    int j;
    int k;
    int p[2];
    if (read(0,&j,sizeof(int))){
        printf("prime %d\n",j);
        pipe(p);
        int pid=fork();
        if (pid!=0)//父进程
        {
            close(1);
            dup(p[1]);
            close(p[1]);
            close(p[0]);

            while (read(0,&k,sizeof(int))){
                judge(j,k);
            }

        }

        else{
            close(0);
            dup(p[0]);
            close(p[1]);
            close(p[0]);
            try1();

        }
    }
    exit();



}

void judge(int j,int k){
    if (k%j!=0) 
    write(1,&k,sizeof(int));
}


int main(int argc, char* argv[]){
    int p[2];
    pipe(p);
    int i;
    int pid;
    pid = fork();
    if (pid!=0){
        close(1);
        dup(p[1]);
        close(p[1]);
        close(p[0]);
        for (i=2;i<=35;i++)
        {
            write(1,&i,sizeof(int));
        }
    }
    else
    {
        close(0);
        dup(p[0]);
        close(p[1]);
        close(p[0]);
        try1();
        wait();

    }

     exit();

}

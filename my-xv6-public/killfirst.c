#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc,char *argv[]){
    int pid = fork();
    if(pid == 0){
        sleep(10);//sleep 3 seconds
        exit();//child process
    }else if (pid<0){
        printf(0,"Fork Failed!\n");
        exit();
    }
    printf(1,"(before) children count: %d\n",alive());
    int killed = killfirst();
    if(killed == -1){
        printf(0,"No children!\n");
    }else{
        printf(1, "killed pid:%d\n",killed);
    }
    printf(1,"(after) children count: %d\n",alive());
    wait();
	exit(); 
}
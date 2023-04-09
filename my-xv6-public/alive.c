#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc,char *argv[]){
    for(int i = 0;i<3;i++){
        int pid = fork();
        if(pid == 0){
            exit();//child process
        }else if (pid<0){
            printf(1,"Fork Failed!\n");
        }
    }
    
	printf(1, "alive children count:%d\n",alive());
    for(int i = 0;i<3;i++){
        wait();//wait for children to exit (kill zombies)
    }
	exit(); 

}
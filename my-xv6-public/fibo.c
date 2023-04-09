#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc,char *argv[]){
	int prev_ebx=0, n = atoi(argv[1]);//get argument from command line
	asm volatile(
	"movl %%ebx, %0;" // store current ebx in  prev_ebx
	"movl %1, %%ebx;" // put n in ebx
	: "=r" (prev_ebx) //output
		: "r"(n) //input
	);
	printf(2, "fibo called from user side: %d, result: %d\n" , n,fibo());
	asm("movl %0, %%ebx" : : "r"(prev_ebx)); // restore ebx	
	exit(); 
}
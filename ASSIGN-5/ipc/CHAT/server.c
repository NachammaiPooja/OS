#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<stdio_ext.h>
#include<ctype.h>

int main()
{
int pid;
char *b;
int id;

id=shmget(111,50,IPC_CREAT | 00666);
b=shmat(id,NULL,0);
printf("\nCLIENT : ");
printf(b);
printf("\nSERVER : ");
scanf("%[^\n]",b);
shmdt(b);
}

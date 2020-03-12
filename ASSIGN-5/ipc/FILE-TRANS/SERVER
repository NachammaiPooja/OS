#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
# include<ctype.h>
# include<string.h>
#include <sys/wait.h>
#include <stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main()
{
int pid;
char *a,*b,c,*y,filename[10];
FILE *fd1;
int id,n,i,id1;
printf("Enter the file name : ");
scanf("%s",filename);
fd1 = fopen(filename,"w+");
id=shmget(111,50,0);
id1=shmget(112,50,0);
y=shmat(id1,NULL,0);
b=shmat(id,NULL,0);
while(y[0] != '1')
{
}
b=shmat(id,NULL,0);
fwrite(b,1,strlen(b),fd1);
fclose(fd1);
shmctl(id, IPC_RMID,NULL);
shmctl(id1, IPC_RMID,NULL);

}

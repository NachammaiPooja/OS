#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/types.h>

int main(int argc,char * argv[])
{
 DIR *d;
 struct dirent *s;
 d=opendir(argv[1]);
 while((s=readdir(d))!=NULL)
 {
        if(argc == 2){
                if(s-> d_name[0] != '.')
                    printf("%s\t",s->d_name); }
        else if(argc == 3){
        if(strcmp(argv[2],"-a")==0)
		{printf("%s\t",s->d_name);}
	if(strcmp(argv[2],"-1")==0)
		{if(s-> d_name[0] != '.')
                  printf("%s\n",s->d_name);}
        else if(strcmp(argv[2],"-i")==0)
		{if(s-> d_name[0] != '.')
                 printf("%ld %s\t",s->d_ino,s->d_name);}
        else if(strcmp(argv[2],"-l")==0)
		{if(s-> d_name[0] != '.')
                  printf("%d %d %s\n",s->d_type,s->d_reclen,s->d_name);}
        else if(strcmp(argv[2],"-il")==0)
		{if(s-> d_name[0] != '.')
                  printf("%ld %d %d %s\n",s->d_ino,s->d_type,s->d_reclen,s->d_name);}

        }
       	else
		printf("\nInsuffiecient number of arguments");
 }
 closedir(d);
 return 0;
}


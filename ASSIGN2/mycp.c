#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
    
   int fp1,fp2,flag;
   //char buf[40];
   char ch,cho;

   if(argc < 4){
      printf("\nInsufficient number of arguments\n");
      exit(0);
   }
   

   fp1=open(argv[1],O_RDONLY);
     if(fp1 == -1)
    {
      printf("\nSource File doesn't exist\n");
    }

   fp2=open(argv[2],O_WRONLY|O_CREAT);
   
     if(fp2 != -1)
    {
      flag=1;
      //printf("\nDestination File already has contents\n");
    }

   char *c = (char *) calloc(1,sizeof(char));
    
   if((strcmp(argv[3],"-i"))==0)
  {
                   
     //read(fp1,&buf,40);
     //write(fp2,&buf,40);
     printf("\nDo you want to copy the contents of the file (y/n)\t");
     scanf("%c",&ch);
     if(ch=='y')
     {
     while(read(fp1,c,1))
      {if(flag==1){
            printf("\nDestination File already has contents\n"); 
            printf("\nDo you want to overwrite (y/n)");
            scanf(" %c",&cho);
            if(cho=='n'){exit(0);}
            else{flag=0;}
       } 
       write(fp2,c,1);
      }
     }
     else{ exit(0); }
   
   printf("Contents copied Successfully\n"); 
  }

   else if((strcmp(argv[3],"-f")) == 0)
  {
     while(read(fp1,c,1))
      {
       write(fp2,c,1);
      }
         
  }

   else if((strcmp(argv[3],"-v"))==0)
  {
     while(read(fp1,c,1))
      {
       write(fp2,c,1);
      }
      printf("%s -----> %s\n",argv[1],argv[2]);   
  }

   else if((strcmp(argv[3],"-n")) == 0)
  {  if(flag==1){exit(0);}
     else{
       while(read(fp1,c,1))
        {
         write(fp2,c,1);
        }
    }     
  }
  
  else
    { printf("\nError in Copying");}

   close(fp1);
   close(fp2);
  return 0;

}

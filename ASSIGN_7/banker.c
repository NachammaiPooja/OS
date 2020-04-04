#include<stdio.h>
#include<stdlib.h>


void main()
{
	int n,m;
	int alloc[10][10];
	int max[10][10];
	int need[10][10];
	int avail[1][10];
	int choice;
	printf("\tBANKER'S ALGORITHM\n");
  printf("\t*******************\n");
	printf("1.Read Data\n2.Print Data\n3.Safety Sequence\n4.exit\n");
	while(1)
	{
		printf("Enter the option : ");
		scanf("%d",&choice);
		if(choice == 4)
			exit(0);
		if(choice == 1)
		{
			printf("Number of processes : ");
			scanf("%d",&n);
			printf("Number of resources : ");
			scanf("%d",&m);
			for(int i=0;i<m;i++)
			{
				printf("Number of Available Instances of %c : ",65+i);
				scanf("%d",&avail[0][i]);
			}
			for(int i=0;i<n;i++)
			{
				printf("Maximum requirement for P%d : ",i);
				for(int j=0;j<m;j++)
					scanf("%d",&max[i][j]);
			}
			for(int i=0;i<n;i++)
			{
				printf("Allocated instances to P%d : ",i);
				for(int j=0;j<m;j++)
					scanf("%d",&alloc[i][j]);
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					need[i][j]=max[i][j]-alloc[i][j];
			}
		}
		if(choice == 2)
		{
			printf("pid	Alloc	Max	Need	Avail\n");
			printf("	");
			for(int l=0;l<4;l++)
			{
				for(int k=0;k<m;k++)
				{
					printf("%c ",65+k);
				}
				printf("	");
			}
			printf("\n");
			for(int s=0;s<n;s++)
			{
				printf("P%d	",s);
				for(int k=0;k<m;k++)
				{
					printf("%d ",alloc[s][k]);
				}
				printf("	");
				for(int k=0;k<m;k++)
				{
					printf("%d ",max[s][k]);
				}
				printf("	");
				for(int k=0;k<m;k++)
				{
					printf("%d ",need[s][k]);
				}
				printf("	");
				if(s==0)
				{
					for(int k=0;k<m;k++)
					{
						printf("%d ",avail[s][k]);
					}

				}
				printf("\n");		


			}

		}
		if(choice == 3)
		{

			int ch1;
			int num;
			int req[m];
			printf("Enter\n1 : To make request and check for safe sequence\n2 : to check only safe sequence\nyour choice : ");
			scanf("%d",&ch1);
			if(ch1 == 1)
			{
				printf("Enter the process no: to request : ");
				scanf("%d",&num);
				printf("Enter the new request for allocation : ");
				for(int r=0;r<m;r++)
					scanf("%d",&req[r]);
				int possible = 0;
				for(int q=0;q<m;q++)
				{
					if(req[q]<=avail[0][q])
						possible++;

				}
				if(possible == m)
				{
					printf("The request is possible\n");
					for(int a=0;a<m;a++)
					{
						avail[0][a]-=req[a];
						alloc[num][a]+=req[a];
						need[num][a]-=req[a];
					}
					

				}
				else
				{
					printf("The request cannot be made because request is greater than available\n");
					printf("Displaying the safe sequence for normal values\n");
				}

			}
			int work[10][10];
			for(int g=0;g<n;g++)
				for(int h=0;h<m;h++)
					work[g][h]=avail[g][h];
			int seq[n];
			for(int b=0;b<n;b++)
				seq[b] = -1;
			int count = 0;
			while(count < n)
			{
				int c1 = 0;
				for(int x=0;x<n;x++)
				{
					int yes = 1; 						int times = 0;
                                        for(int b1=0;b1<n;b1++)
					{
						if(x == seq[b1])
							yes = 0;
					}
					for(int ss=0;ss<m;ss++)
					{
					if(need[x][ss] <= work[0][ss])
							times++;
					}
					if(yes == 1 && times == m)
					{
						seq[count++] = x;
						c1++;
						for(int a=0;a<m;a++)
						{
							work[0][a]+=alloc[x][a];						
						}
							
					}			

				}
				if(c1 == 0)
				{
					printf("Error deadlock unsafe sequence\n");
					exit(0);
				}
			}
			printf("The safe sequence is : <");
			for(int p=0;p<n;p++)
			{
				printf("P%d	",seq[p]);
			}
			printf(">\n");

			

		}
	}


}

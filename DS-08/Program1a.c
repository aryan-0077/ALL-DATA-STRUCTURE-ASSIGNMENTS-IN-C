#include<stdio.h>
int main()
{
	int r,c,val;
	int ar[100][3];
	int count = 0;
	while(1)
	{
		printf("Press 1 for new element\nPress 2 for display\nPress 3 for exit\n");
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter row column and value: ");
			scanf("%d%d%d",&r,&c,&val);
			int i,flag=1;
			for(i=0;i<count;i++)
			{
				if(ar[i][0]==r && ar[i][1]==c)
				{
					ar[i][2] = val;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				ar[count][0] = r;
				ar[count][1] = c;
				ar[count][2] = val;
				count++;
			}
		}
		else if(t==2)
		{
			int i;
			printf("row column  value\n");
			for(i=0;i<count;i++)
			{
				printf("%d\t%d\t%d\n",ar[i][0],ar[i][1],ar[i][2]);
			}
		}
		else
			break;
	}
}
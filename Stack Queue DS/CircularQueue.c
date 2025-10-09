#include <stdio.h>
#include <stdlib.h>
#define max 5
int q[max];
int f=-1;
int r=-1;
void enqueue(int v)
{
	if ((r+1)%max==f)
	{
		printf("Circular Queue Full\n");
	}
	else
	{
		if (f==-1)
			f=0;
		r=(r+1)%max;
		q[r]=v;
	}
}
void dequeue()
{
	if (f==-1)
		printf("Circular Queue Empty\n");
	else
	{
		printf("Deleted Element = %d\n",q[f]);
		if (f==r)
		{
			printf("Queue Reset\n");
			f=-1;
			r=-1;
		}
		else
		{
			f=(f+1)%max;
		}	
	}
}
void display()
{
	int i;
	if (f==-1)
		printf("Circular Queue Empty\n");
	else
	{
		i=f;
		printf("Queue :\n");
		while (i!=r)
		{
			printf("%d ",q[i]);
			i=(i+1)%max;
		}
		printf("%d\n",q[r]);
	}
}
int main(void)
{int c,n;
	while (1)
	{
		printf("1. Entry the Queue\n");	
		printf("2. Delete from the Queue\n");
		printf("3. Display\n");
		printf("Enter your choice(anyother to terminate)\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("Enter the element\n");
			scanf("%d",&n);
			enqueue(n);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			default:
			printf("Final ");
			display();
			printf("-------PROGRAM TERMINATED--------\n");
			exit(0);
		}
	}
	return 0;
}

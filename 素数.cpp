#include <stdio.h>
int main()
{
	int i, j, n, k=0;
	printf("������һ��1~2000����");
	scanf("%d",&n);
	for(i = 2; i <= n; i++)
	{
    	for(j = 2; j <= i; j++)
    	{
        	if(j == i)
        	{
            	printf(" %d",i);
            	k++;
        	}
        	else if(i % j == 0)
        	{
            	break;
        	}
        	else if(k % 5 == 0)//���һ�� 
        	{
            	printf("\n");
        	}
   		}
	}
        return 0;
}

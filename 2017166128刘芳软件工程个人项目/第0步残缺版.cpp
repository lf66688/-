#include<stdio.h>

void sort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)

    if(a[j]<a[j+1])
	{
		t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
	}
}

int main()
{
	FILE *fp;
	int i,a[26]={0},b[26]={0},sum1,sum2,pl1,pl2;
	char c;
	fp=fopen("filetest.txt","r");
	
	if(fp!=NULL)
	
	do{
	c=fgetc(fp);
	
	if(c >= 'a'&&c <= 'z')
		b[c-'a']++;
		
	else if(c >= 'A'&&c <= 'Z')
	a[c-'A']++;
	
	}
	
	while(!feof(fp));
	sort(a,26);
	sort(b,26);
	
	for(i=0;a[i];i++)
		printf("%c:%d \t",'A'+i,a[i]);
	
	printf("\n");
	
	for(i=0;b[i];i++)
		printf("%c:%d \t",'a'+i,b[i]);
	
//	printf("\n");
	
	fclose(fp);
	return 0;

}

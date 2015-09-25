#include<stdio.h>
#include<string.h>

int main()
{
	int a[10000]={0};
	char b[110];
	int i,cary,len,temp;
	//memset(a,0,sizeof(a));
	while(scanf("%s",b) != EOF && strcmp(b,"0")!=0)
	{
		len = strlen(b) - 1;
		cary = 0;
		for(i=len;i>=0;i--)
		{
			temp = b[i] - '0' + cary + a[len-i];
			cary = temp >= 10;
			a[len - i] = temp%10;
			//printf("i=%d b[i]=%d cary=%d a[len-i]=%d\n",i,b[i],cary,a[len-i]);
		}
		a[len+1] += cary;		
	}
	
	for(i=9999; i>=0 && a[i]==0; i--)
		;
	for(i;i>=0;i--)
		printf("%d",a[i]);
	printf("\n");
	return 0;	
}
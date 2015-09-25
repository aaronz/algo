#include<stdio.h>
#include<stdlib.h>
#define MAX 101

int comp(const void *a,const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	char s[MAX],d[MAX];
	int si[27],di[27];
	int i,j;
	while(scanf("%s",d)!=EOF)
	{
		scanf("%s",s);
		for(i=0; i<27; i++)
			si[i]=di[i]=0;

		for(i=0; i<MAX && s[i]!='\0'; i++)
			si[s[i]-'A']++;

		for(j=0; j<MAX && d[j]!='\0';j++)
			di[d[j]-'A']++;

		qsort(si,27,sizeof(int),comp);
		qsort(di,27,sizeof(int),comp);

		for(i=0;i<26;i++)
			if(si[i]!=di[i])
			{
				printf("NO\n");
				return 0;
			}
		printf("YES\n");
		
	}
	return 0;
}

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct Island
{
	double start, finish;
};

int compare_island(const void * a, const void * b)
{
	Island i = *(Island *)a;
	Island j  = *(Island *)b;
	double t = i.finish - j.finish;
	if(t>0.0)
		return 1;
	else if(t<0.0)
		return -1;
	else
	{
		t = i.start - j.start;
		if(t>0.0) return 1;
		else return -1;
	}
}

int main()
{
	Island l[1001];
	double x,y;
	double root;
	int n,d,i,j,count,k=0;
	while(cin>>n>>d && (n!=0 && d!=0))
	{
		k++;
		count = 0;
		for(i = 0; i < n; i++)
		{
			cin>>x>>y;
			if(y>d)
			{
				count = -1;
			}
			root = sqrt(d*d - y*y);
			l[i].start = x-root;
			l[i].finish = x+root;
		}
		if(count != -1)
		{
			qsort(l,n,sizeof(Island),compare_island);
			//for(i=0;i<n;i++)
				//cout<<l[i].start<<' '<<l[i].finish<<endl;
			for(i=0; i<n; i++)
			{
				for(j = i+1; j<n; j++)
				{
					if(l[i].finish < l[j].start)
					{
						count++;
						i = j-1;
						break;
					}
				}
			}
			count++;
		}
		cout<<"Case "<<k<<": "<<count<<endl;
	}
	//system("pause");
	return 0;
}
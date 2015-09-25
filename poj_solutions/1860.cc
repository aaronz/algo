#include<iostream>
using namespace std;
const double MIN=-1<<30;

struct Edge{
	int a,b;
	double c,r;
};

bool bellman_ford(struct Edge *e,double *d,int s, double q,int n, int m)
{
	int i,j;
	for(i=1;i<=n;i++)
		d[i]=MIN;
	d[s]=q;
	bool flag;
	for(i=1;i<=n;i++){
		flag=true;
		for(j=1;j<=m;j++)
			if(d[e[j].a]>0&&d[e[j].b] <(d[e[j].a] - e[j].c) * e[j].r){
				d[e[j].b] = (d[e[j].a]-e[j].c)*e[j].r;
				flag = false;
			}
		if(flag) return false;
	}
	return true;
}

int main(){
	int n,m,s;
	double q;
	Edge e[300];
	double d[105];
	cin>>n>>m>>s>>q;
	int i;
	int a,b;
	double r,c;
	for(i=1;i<=m;i++){
		cin>>a>>b>>r>>c;
		e[i].a=a;
		e[i].b=b;
		e[i].r=r;
		e[i].c=c;
		cin>>r>>c;
		e[m+i].a=b;
		e[m+i].b=a;
		e[m+i].r=r;
		e[m+i].c=c;
	}
	if(bellman_ford(e,d,s,q,n,2*m))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	//system("pause");
	return 0;
}
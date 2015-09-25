#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct stone{
	int x,y;
	double w;
	bool operator < (stone const & A) const{
		return w < A.w;
	}
	stone(int a, int b, double c): x(a), y(b), w(c) {};
};

vector<stone> vect;
int parent[201],map[201][2],n,a,b;
double answer;

void make_set(int x)
{
	for(int i=1;i<=x;i++)
		parent[i]=i;
}

int find_set(int x)
{
	if(parent[x]!=x)
		parent[x]=find_set(parent[x]);
	return parent[x];
}

void union_set(int x, int y)
{
	int a = find_set(x);
	int b = find_set(y);
	if(a == b)
		return;
	parent[b]=a;
}

void kruskal()
{
	for(int i=0; i<vect.size(); i++){
		union_set(vect[i].x,vect[i].y);
		answer = vect[i].w;
		if(find_set(1)==find_set(2))
			return;
	}
}

int main()
{
	int count=1;
	while(cin>>n && n){
		vect.clear();
		make_set(n);
		for(int i=1;i<=n;i++)
			cin>>map[i][0]>>map[i][1];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				double c = sqrt((map[i][0] - map[j][0]) * (map[i][0] - map[j][0]) + (map[i][1] - map[j][1]) * (map[i][1] - map[j][1]) + 0.0);
                stone A(i, j, c);
                vect.push_back(A);
            }
        sort(vect.begin(), vect.end());
        kruskal();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", count, answer);
        ++ count;
    }
    return 0;
}
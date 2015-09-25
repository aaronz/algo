#include<iostream>
using namespace std;
#define MAX 1<<20

int map[101][101],answer,num,broker,contact,a,b;
void floyd()
{
	for(int k=1;k<=broker; k++)
		for(int i=1; i<=broker; i++)
			for(int j=1; j<broker; j++)
				if(map[i][j] > map[i][k]+map[k][j])
					map[i][j] = map[i][k]+map[k][j];
}

int main()
{
	while(cin>>broker && broker){
		for(int i=1; i <=broker; i++)
			for(int j=1; j<=broker; j++)
				map[i][j]=(i==j?0:MAX);
		for(int i=1; i<=broker; i++){
			cin>>contact;
			for(int j=1; j<=contact; j++){
				cin>>a>>b;
				map[i][a]=b;
			}
		}
		answer = MAX;
		floyd();
		for(int i=1; i<=broker; i++){
			int all=0, m=0;
			for(int j=1;j<=broker;j++){
				if(map[i][j]==MAX)
					break;
				if(m < map[i][j])
					m=map[i][j];
				++all;
			}
			if(all == broker && m < answer){
				answer = m;
				num = i;
			}
		}
		if(answer < MAX)
			cout<<num<<' '<<answer<<endl;
		else
			cout<<"disjoint"<<endl;
	}
	return 0;
}
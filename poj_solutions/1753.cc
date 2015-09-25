#include<iostream>
using namespace std;

char s[4][4];
int flip[16] = {19,39,78,140,305,626,1252,2248,4880,8992,20032,35968,12544,29184,58368,51200};
int mask[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

int main()
{
	int i,j,temp,count,mincount,value = 0;
	char c;
	mincount = 17;
	for(i=0; i<16; i++)
	{
		cin>>c;
		if(c == 'b')
			value += mask[i];
	}
	for(i=0; i<65536; i++)
	{
		temp = value;
		count = 0;
		for(j=0; j<16; j++)
		{
			if(i & mask[j])
			{
				count++;
				temp ^= flip[j];
			}
		}
		if((temp == 65535 || temp == 0) && mincount > count)
			mincount = count;
		
	}
	if(mincount == 17)
		cout<<"Impossible"<<endl;
	else
		cout<<mincount<<endl;
	return 0;
}
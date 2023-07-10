#include<iostream>
using namespace std;

int g(int x)
{
	if(x==1)return 1;
	else return(x+g(x-1));
}
int main()
{
	int x;
	cin>>x;
	g(x);
	cout<<g(x)<<endl;
}


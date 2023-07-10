#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,b,c;
	float d,x1,x2;
	cin>>a>>b>>c;
	d=pow(b,2)-(4*a*c);
	if(d<0)
	{
		cout<<"µL¸Ñ"<<endl; 
	}
	if(d>0)
	{
		x1=(-b+sqrt(d))/(2*a);
		cout<<"x1="<<x1;
		x2=(-b-sqrt(d))/(2*a);
		cout<<"x2="<<x2;
	}
	if(d==0)
	{
		x1=(-b/2*a);
		cout<<"x="<<x1;
	}
 } 

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void poker(int&a,int d[])
{
	do
	{
		a=rand()%52;
		}while(d[a]!=0);
			d[a]=1;	
}
void color(int b)
{
	if(b%4==0)cout<<"�®�";
	if(b%4==1)cout<<"����";
	if(b%4==2)cout<<"���";
	if(b%4==3)cout<<"����"; 
}
void count(int c,float& x)
{
	if(((c/4)+1==11)||((c/4)+1==12)||((c/4)+1==13)){
		x=x+0.5;
	    cout<<x<<endl;
	} 
	else {
		x=x+((c/4)+1);
	    cout<<x<<endl;
	} 
}


int main()
{
		int i,comc;
		int youc1,c[52]={0};
		float x=0,y=0;
		srand(time(NULL));
	do
	{

		cout<<"�q�����aX"<<endl;
		cout<<"���a�A:"<<endl; 
		poker(youc1,c);
		color(youc1);
		cout<<(youc1/4)+1<<endl;
		count(youc1,x);
		if(x>10.5){
			cout<<"���a��"<<endl;
			return 0;
		}
		cout<<"�O�_�~��n�P?�O��0�_��1"<<endl;
		cin>>i;
	}while(i==0);
	do
	{

		cout<<"�q�����a"<<endl;
		poker(comc,c);
		color(comc);
		cout<<(comc/4)+1<<endl;
		count(comc,y);
		if(y>10.5){
			cout<<"���aĹ"<<endl;
			return 0;
		}

	}while(y<10.5&&y<=x);
	cout<<"���a��"; 

}

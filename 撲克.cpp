#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void card(int&a,int x[])
{
	do{
		a=rand()%52;
	}while(x[a]!=0);
		x[a]=1;
}
void color(int&b)
{
	if(b%4==0)cout<<"�®�";
	if(b%4==1)cout<<"����";
	if(b%4==2)cout<<"���";
	if(b%4==3)cout<<"����";
}
int main()
{
	cout<<"��J��j,��p(��j��9,��p��1)"<<endl;
	int i,myc,comc,x[52]={0};
	cin>>i;
	srand(time(NULL));
	for(int j=0;j<=26;j++){
	
	if(i==9)
	{
		cout<<"�A�n��j��!"<<endl;
		
			cout<<"�A���P��:";
			card(myc,x);
			color(myc);
			cout<<(myc/4)+1<<endl;
			cout<<"�q�����P��:";
			card(comc,x);
			color(comc);
			cout<<(comc/4)+1<<endl; 
			if(myc>comc)
			{
				cout<<"�AĹ�o!!"<<endl;
			}
			else
			{
				cout<<"�q��Ĺ��!"<<endl; 
			}
		}
	if(i==1)
	{
		cout<<"�A�n��p��!"<<endl;
		cout<<"�A���P��:";
		card(myc,x);
		color(myc);
		cout<<(myc/4)+1<<endl;
		cout<<"�q�����P��:";
		card(comc,x);
		color(comc);
		cout<<(comc/4)+1<<endl;
		
		if(myc<comc)
		{
			cout<<"�AĹ�o!!"<<endl; 
		}
		else
		{
			cout<<"�q��Ĺ��!"<<endl; 
		}
	}
}
}

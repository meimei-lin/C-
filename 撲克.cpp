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
	if(b%4==0)cout<<"黑桃";
	if(b%4==1)cout<<"紅心";
	if(b%4==2)cout<<"方塊";
	if(b%4==3)cout<<"梅花";
}
int main()
{
	cout<<"輸入比大,比小(比大輸9,比小輸1)"<<endl;
	int i,myc,comc,x[52]={0};
	cin>>i;
	srand(time(NULL));
	for(int j=0;j<=26;j++){
	
	if(i==9)
	{
		cout<<"你要比大喔!"<<endl;
		
			cout<<"你的牌為:";
			card(myc,x);
			color(myc);
			cout<<(myc/4)+1<<endl;
			cout<<"電腦的牌為:";
			card(comc,x);
			color(comc);
			cout<<(comc/4)+1<<endl; 
			if(myc>comc)
			{
				cout<<"你贏囉!!"<<endl;
			}
			else
			{
				cout<<"電腦贏喔!"<<endl; 
			}
		}
	if(i==1)
	{
		cout<<"你要比小喔!"<<endl;
		cout<<"你的牌為:";
		card(myc,x);
		color(myc);
		cout<<(myc/4)+1<<endl;
		cout<<"電腦的牌為:";
		card(comc,x);
		color(comc);
		cout<<(comc/4)+1<<endl;
		
		if(myc<comc)
		{
			cout<<"你贏囉!!"<<endl; 
		}
		else
		{
			cout<<"電腦贏喔!"<<endl; 
		}
	}
}
}

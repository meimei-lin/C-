#include<iostream>
#include<cstring> 
using namespace std;

class stnode{
	int no;
	char name[10];
	int score;
	stnode*st;
	public:
		void writeno(int a)
		{
			no=a;
		}
		void writename(char b[10])
		{
			strcpy(name,b);
		}
		void writescore(int c)
		{
			score=c;
		}
		int readno()
		{
			return no;
		}
		char*readname()
		{
			char*b=new char[10];
			strcpy(b,name);
			return b;
		}
		int readscore()
		{
			return score;
		}
		stnode*writest(stnode*e)
		{
			st=e;
		}
		stnode*readst()
		{
			return st;
		}
};
int main()
{
	stnode student;
	stnode*p;
	stnode*head;
	head=NULL;
	int a,c,e,n;
	char b[10];
	cout<<"是否要輸入學生資料,是打1,否打2"<<endl;
	cin>>n;
	while(n!=1&&n!=2)
	{
		cout<<"請輸入正確的號碼"<<endl;
		cout<<"是否要輸入學生資料,是打1,否打2"<<endl;
		cin>>n;
	}
	while(n==1)
	{
		p=new stnode;
		cout<<"座號:"<<endl;
		cin>>a;
		p->writeno(a);
		cin.get();
		cout<<"姓名:"<<endl;
		cin>>b;
		p->writename(b);
		cin.get();
		cout<<"成績:"<<endl;
		cin>>c;
		p->writescore(c);
		cin.get();
		cout<<"是否繼續輸入,是打1,否打2"<<endl;
		cin>>n;
		p->writest(head);
		head=p;
	}
	while(n!=1&&n!=2)
	{
		cout<<"請輸入正確的號碼"<<endl;
		cout<<"是否要輸入學生資料,是打1,否打2"<<endl;
		cin>>n;
	}
	cout<<"座號  |   姓名  |  成績"<<endl;
	while(p!=NULL)
	{
		cout.width(2);cout<<p->readno();
		cout.width(8);cout<<p->readname();
		cout.width(10);cout<<p->readscore();
		cout<<endl;
		p=p->readst();
	}
	
}

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

int MENU(){
	int i;
	cout<<"(1).�s�W�ǥ͸��"<<endl;
	cout<<"(2).�R�����"<<endl;
	cout<<"(3).�d�߸��"<<endl;
	cout<<"(4).�C�L��C���"<<endl;
	cout<<"(5).���}"<<endl;
	cout<<"�п�J��ܶ���?"<<endl;
	cin>>i;
	return i;
}
int main(){
	int s,i;
	while(s=MENU())
	{
		if(s==1)
		{
			cout<<"�s�W�ǥ͸�ư��椤"<<endl;
		}
		if(s==2)
		{
			cout<<"�R���ǥ͸�ư��椤"<<endl;
		}
		if(s==3)
		{
			cout<<"�d�߾ǥ͸�ư��椤"<<endl;
		}
		if(s==4)
		{
			cout<<"�C�L��C��ư��椤"<<endl;
		}
		if(s!=1&&s!=2&&s!=3&&s!=4&&s!=5)
		{
			cout<<"���~"<<endl;
		}
		if(s==5)
		{
			cout<<"���}"<<endl;break;
		}
	}

}

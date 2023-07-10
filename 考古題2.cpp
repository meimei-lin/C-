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
	cout<<"(1).新增學生資料"<<endl;
	cout<<"(2).刪除資料"<<endl;
	cout<<"(3).查詢資料"<<endl;
	cout<<"(4).列印串列資料"<<endl;
	cout<<"(5).離開"<<endl;
	cout<<"請輸入選擇項目?"<<endl;
	cin>>i;
	return i;
}
int main(){
	int s,i;
	while(s=MENU())
	{
		if(s==1)
		{
			cout<<"新增學生資料執行中"<<endl;
		}
		if(s==2)
		{
			cout<<"刪除學生資料執行中"<<endl;
		}
		if(s==3)
		{
			cout<<"查詢學生資料執行中"<<endl;
		}
		if(s==4)
		{
			cout<<"列印串列資料執行中"<<endl;
		}
		if(s!=1&&s!=2&&s!=3&&s!=4&&s!=5)
		{
			cout<<"錯誤"<<endl;
		}
		if(s==5)
		{
			cout<<"離開"<<endl;break;
		}
	}

}

#include<iostream>
#include<cstring>
using namespace std;

class stnode{
	
		int no;
		char name[10];
		int nor;
		int mid;
		int fin;
		stnode*ptr;
		public:
			void writeno(int a)
			{
				no=a;
			}
			void writename(char b[10])
			{
				strcpy(name,b);
			}
			void writenor(int g)
			{
				nor=g;
			}
			void writemid(int d)
			{
				mid=d;
			}
			void writefin(int e)
			{
				fin=e;
			}
			stnode writeptr(stnode*f)
			{
				ptr=f;
			}
			int readno()
			{
				return no;
			}
			char* readname()
			{
				char*b=new char[10];
				strcpy(b,name);
				return b;
			}
			int readnor()
			{
				return nor;
			}
			int readmid()
			{
				return mid;
			}
			int readfin()
			{
				return fin;
			}
			stnode*readptr()
			{
				return ptr;
			}
};
int menu(){
	int i;
	cout<<"(1).新增學生資料"<<endl;
	cout<<"(2).刪除學生資料"<<endl;
	cout<<"(3).查詢學生資料"<<endl;
	cout<<"(4).列印學生資料"<<endl;
	cout<<"(0).離開"<<endl;
	cout<<"請輸入選擇項目?"<<endl;
	cin>>i;
	return i;
}

int main()
{
	stnode student;
	stnode*p;
	stnode*head;
	stnode*x;
	stnode*y;
	head=NULL;
	int a,c,d,e,g,s,t,n;
	char b[10];
	while(s=menu()){
		switch(s){
			case 1:
					c=c+1;
					p=new stnode;
					cout<<"座號:"<<endl;
					cin>>a;
					p->writeno(a);
					cin.get();
	
					x=head;
					while(x!=NULL&&p->readno()!=x->readno())
					{
						x=x->readptr();
					}
					if(x!=NULL&&p->readno()==x->readno())
					{
						cout<<x->readno()<<"號學生輸入過了,請重新選擇"<<endl;
					}
					else
					{
						cout<<"姓名:"<<endl;
						cin>>b;
						p->writename(b);
						cout<<"平時成績:"<<endl;
						cin>>g;
						p->writenor(g);
						cout<<"期中成績:"<<endl;
						cin>>d;
						p->writemid(d);
						cin.get();
						cout<<"期末成績"<<endl;
						cin>>e;
						p->writefin(e) ;
						cin.get();
					
						if(head==NULL)
						{
							p->writeptr(head);
							head=p;
						}
						else if(head->readno()<p->readno())//head!=NULL
							{
								x=head;
								y=head;
								y=y->readptr();
								if(y==NULL)
								{
									p->writeptr(y);//p->ptr=y,把y寫進p->ptr 
									x->writeptr(p);
								}	
								else//y!=NULL
								{
									while(y!=NULL&&y->readno()<p->readno())
									{
										x=x->readptr();//x=x->ptr;
										y=y->readptr();
									}
			
									p->writeptr(y);	
									x->writeptr(p);
								}
							}
							else//head->no>p->no 
							{
								p->writeptr(head);//p->ptr=head;
								head=p;
							}
						}break;
			
			case 2:
					cout<<"請輸入要刪除學生的座號"<<endl;
					cin>>n;
					if(head==NULL)
					{
						cout<<"該筆資料不存在,無法刪除"<<endl;break;
					}
					if(head->readptr()==NULL&&n==head->readno())
					{
						head=NULL;
						cout<<"該筆資料已刪除"<<endl;break;
					}
					if(head->readptr()==NULL&&n!=head->readno())
					{
						cout<<"該筆資料不存在,無法刪除"<<endl;break; 
					}
					x=head;
					y=x->readptr();
					if(n==x->readno())//刪頭 
					{
						head=y;
						y=y->readptr();
						c--;
						cout<<"該筆資料已刪除"<<endl;break;
						
					}
					else if(n==y->readno()){
						
						x->writeptr(y->readptr());
						c--;
						cout<<"該筆資料已刪除"<<endl;break;
					}
					while(n!=y->readno())
					{
						x=y;
						y=y->readptr();
						if(y==NULL&&n!=x->readno())
						{
							cout<<"該筆資料不存在,無法刪除"<<endl;break;
						}
					}
					if(y!=NULL)
					{
						while(n!=y->readno())
						{
							x=y;
							y=y->readptr();
						}
						x->writeptr(y->readptr());
						cout<<"該筆資料已刪除"<<endl;c--;
					}break;
					
			case 3:
					cout<<"請輸入你要搜尋的座號"<<endl;
					cin>>t;
					if(head==NULL)
					{
						cout<<"錯誤,請輸入學生資料"<<endl;break;
					}
					if(head->readptr()==NULL&&t==head->readno())
					{
						cout<<"座號| 姓名 |平時成績|期中成績|期末成績"<<endl;
						cout.width(2);cout<<head->readno();
						cout.width(6);cout<<head->readname();
						cout.width(8);cout<<head->readnor();
						cout.width(10);cout<<head->readmid();
						cout.width(10);cout<<head->readfin();
						cout<<endl;break;
					}
					if(head->readptr()==NULL&&t!=head->readno())
					{
						cout<<"沒這位學生"<<endl;break;
					}
					x=head;
					y=x->readptr();
					for(int i=0;i<c;i++)
					{
						if(t!=x->readno())
						{
							x=y;
							y=y->readptr();
							if(y==NULL&&t!=x->readno())
							{
								cout<<"查無此人"<<endl;break;
								
							}
						}
					}
					if(t==x->readno())
					{
					
						cout<<"座號| 姓名 |平時成績|期中成績|期末成績"<<endl;
						cout.width(2);cout<<x->readno();
						cout.width(6);cout<<x->readname();
						cout.width(8);cout<<x->readnor();
						cout.width(10);cout<<x->readmid();
						cout.width(10);cout<<x->readfin();
						cout<<endl;
					}break;
					
					
					
					
			case 4: 
					cout<<"列印串列資料"<<endl;
					p=head;
					cout<<"head->";
					while(p!=0)
					{
						cout<<p->readno()<<"->";
						p=p->readptr();
					}
					cout<<"||"<<endl;break; 
			default:
				cout<<"輸入錯誤,再輸一次吧!"  <<endl;     
		}
	}
	cout<<"掰掰"<<endl;
}
	

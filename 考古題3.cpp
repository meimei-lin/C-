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
	cout<<"(1).�s�W�ǥ͸��"<<endl;
	cout<<"(2).�R���ǥ͸��"<<endl;
	cout<<"(3).�d�߾ǥ͸��"<<endl;
	cout<<"(4).�C�L�ǥ͸��"<<endl;
	cout<<"(0).���}"<<endl;
	cout<<"�п�J��ܶ���?"<<endl;
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
					cout<<"�y��:"<<endl;
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
						cout<<x->readno()<<"���ǥͿ�J�L�F,�Э��s���"<<endl;
					}
					else
					{
						cout<<"�m�W:"<<endl;
						cin>>b;
						p->writename(b);
						cout<<"���ɦ��Z:"<<endl;
						cin>>g;
						p->writenor(g);
						cout<<"�������Z:"<<endl;
						cin>>d;
						p->writemid(d);
						cin.get();
						cout<<"�������Z"<<endl;
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
									p->writeptr(y);//p->ptr=y,��y�g�ip->ptr 
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
					cout<<"�п�J�n�R���ǥͪ��y��"<<endl;
					cin>>n;
					if(head==NULL)
					{
						cout<<"�ӵ���Ƥ��s�b,�L�k�R��"<<endl;break;
					}
					if(head->readptr()==NULL&&n==head->readno())
					{
						head=NULL;
						cout<<"�ӵ���Ƥw�R��"<<endl;break;
					}
					if(head->readptr()==NULL&&n!=head->readno())
					{
						cout<<"�ӵ���Ƥ��s�b,�L�k�R��"<<endl;break; 
					}
					x=head;
					y=x->readptr();
					if(n==x->readno())//�R�Y 
					{
						head=y;
						y=y->readptr();
						c--;
						cout<<"�ӵ���Ƥw�R��"<<endl;break;
						
					}
					else if(n==y->readno()){
						
						x->writeptr(y->readptr());
						c--;
						cout<<"�ӵ���Ƥw�R��"<<endl;break;
					}
					while(n!=y->readno())
					{
						x=y;
						y=y->readptr();
						if(y==NULL&&n!=x->readno())
						{
							cout<<"�ӵ���Ƥ��s�b,�L�k�R��"<<endl;break;
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
						cout<<"�ӵ���Ƥw�R��"<<endl;c--;
					}break;
					
			case 3:
					cout<<"�п�J�A�n�j�M���y��"<<endl;
					cin>>t;
					if(head==NULL)
					{
						cout<<"���~,�п�J�ǥ͸��"<<endl;break;
					}
					if(head->readptr()==NULL&&t==head->readno())
					{
						cout<<"�y��| �m�W |���ɦ��Z|�������Z|�������Z"<<endl;
						cout.width(2);cout<<head->readno();
						cout.width(6);cout<<head->readname();
						cout.width(8);cout<<head->readnor();
						cout.width(10);cout<<head->readmid();
						cout.width(10);cout<<head->readfin();
						cout<<endl;break;
					}
					if(head->readptr()==NULL&&t!=head->readno())
					{
						cout<<"�S�o��ǥ�"<<endl;break;
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
								cout<<"�d�L���H"<<endl;break;
								
							}
						}
					}
					if(t==x->readno())
					{
					
						cout<<"�y��| �m�W |���ɦ��Z|�������Z|�������Z"<<endl;
						cout.width(2);cout<<x->readno();
						cout.width(6);cout<<x->readname();
						cout.width(8);cout<<x->readnor();
						cout.width(10);cout<<x->readmid();
						cout.width(10);cout<<x->readfin();
						cout<<endl;
					}break;
					
					
					
					
			case 4: 
					cout<<"�C�L��C���"<<endl;
					p=head;
					cout<<"head->";
					while(p!=0)
					{
						cout<<p->readno()<<"->";
						p=p->readptr();
					}
					cout<<"||"<<endl;break; 
			default:
				cout<<"��J���~,�A��@���a!"  <<endl;     
		}
	}
	cout<<"�T�T"<<endl;
}
	

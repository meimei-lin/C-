#include<iostream>
#include<ctime>
#include<cstdlib>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int menu(){
	int i;
	cout<<"�п�ܸ��X"<<endl;
	cout<<"     1.�q�Ʀr�C��"<<endl;
	cout<<"     2.�g���D�C��"<<endl;
	cout<<"     3.�Q�I�b�C��"<<endl;
	cout<<"     0.���}"<<endl;
	cin>>i;
	return i;
}
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
const int N = 23;

struct Point {
    int x,y;
    void set(int X, int Y) {x=X; y=Y;}
};

HANDLE hIn, hOut;                           //I/O ���
Point  body[32], cookie, v = {-2,0};        //���, ����, ���ʦV�q,
char   room[N][N*2+4];                      //�ж�
int    delay_time = 100;                    //����ɶ�
int    x1=2,y1=1,x2=(N-1)*2,y2=N-1, len=2;  //�ж����, ����
bool   bExit = false;                       //�O�_����C��

void gotoxy (int x, int y)
{
    static COORD c; 
    c.X = x; c.Y = y;
    SetConsoleCursorPosition (hOut, c);
}

void draw (int x, int y, char* s)
{
    gotoxy (x,y);
    cout << s;
}

void drawList (char* a, char* b, char* c, int w, int h=1)
{
    static char* p = room[0];
    for (int i; h--; *p++=*c, *p++=c[1], *p++=0, p++)
        for (*p++='\n', *p++=*a, *p++=a[1], *p++=a[2],
            i=w-2; i--;) *p++=*b, *p++=b[1]; 
}
void put_cookie ()
{
    cookie.x = 3 + rand()%(N-2) * 2;
    cookie.y = 2 + rand()%(N-3);
  
}

void init()
{
    srand (time(0));
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    if (hIn == err || hOut == err) {
        puts ("handle failed");
        getch ();
        exit (1);
    }
    drawList (" �z","�w","�{", N);  
    drawList (" �x","  ","�x", N, N-2);
    drawList (" �|","�w","�}", N);

    gotoxy (0,0);
    for (int i=0; i<N; i++) cout << room[i];
    put_cookie ();
  
    body[0].set ((x2-x1)/2, (y2-y1)/2);
    body[1].set (body[0].x+1, body[0].y);
}

void key_control()
{
    static DWORD count;
    static INPUT_RECORD ir;
       
    ReadConsoleInput (hIn, &ir, 1, &count);
    if (!ir.Event.KeyEvent.bKeyDown) return;                      
    switch (ir.Event.KeyEvent.wVirtualKeyCode) {                   
        case VK_UP   : if (v.y !=  1) v.set(0,-1); break;
        case VK_DOWN : if (v.y != -1) v.set(0, 1); break;
        case VK_LEFT : if (v.x !=  2) v.set(-2,0); break;                       
        case VK_RIGHT: if (v.x != -2) v.set( 2,0); break;
        case VK_ESCAPE: bExit = true;
    }       
}

void move_snack()
{  
    int i;
    int& x = body[0].x;
    int& y = body[0].y;
    for (i=1; i<len; i++)                   //�ˬd�ۨ��I��
        if (body[0].x == body[i].x &&
            body[0].y == body[i].y ) break;

    if (i!=len || x<=x1 || x>x2 || y<=y1 || y>y2) {
        draw (14,10,"G a m e    O v e r");
        getch(); bExit = true;
        return;
    }
    if (x == cookie.x && y == cookie.y) {   //�Y�쭹��
        delay_time -= 2;
        if (++len > 30) {
            draw (16,10, "Y o u    W i n");
            getch(); bExit = true;
            return;
        }put_cookie();
    }
    else draw (body[len-1].x, body[len-1].y, "  ");

    for (i=len-1; i>0; --i)
        body[i] = body[i-1];
    x += v.x;
    y += v.y;
    for (i=0; i<len; ++i)
        draw (body[i].x, body[i].y, "�i");
}
int main(){
	int num,s;
	int n,flag=1;
	srand(time(0));
	num=1+rand()%100;
	int a,comc;
	int youc1,c[52]={0};
	float x=0,y=0;
	srand(time(NULL));
	while(s=menu()){
		switch(s){
			case 1:
				
				cout<<"�w��Ө�q�Ʀr�C��"<<endl;
				   cout<<"�o�C���N�ѹq���X�@�ӼƦr���ϥΪ̲q"<<endl;
					while(flag){
						cout<<"�бz��J�@�Ӿ��:"<<endl;
						cin>>n;
						if(n>num){
							cout<<"�z���Ʀr�L�j"<<endl;
						}
						else if(n<num){
							cout<<"�z���Ʀr�L�p"<<endl; 
						}
						else{
							flag=0;
							cout<<"���߱z�q��F!"<<endl;
						}
					}break;
				
		case 2:
			 init();
				while (!bExit)
				{       
				    Sleep (delay_time); if (kbhit()) key_control();
				    draw (cookie.x, cookie.y, "��");
				    move_snack();
				    Sleep (delay_time); if (kbhit()) key_control();           
				    gotoxy (10,24);
				    printf ("cookie: (%2d,%2d)  head: (%2d,%2d)",
				    cookie.x, cookie.y, body[0].x, body[0].y);
				}break;
			
			
			
				
		case 3:
				do
					{
						cout<<"�q�����aX"<<endl;
						cout<<"���a�A:"<<endl; 
						poker(youc1,c);
						color(youc1);
						cout<<(youc1/4)+1<<endl;
						cout<<"�`�p";count(youc1,x);
						if(x>10.5){
							cout<<"���a��"<<endl;break;
							return 0;
							
						}
						else if(x==10.5){
							cout<<"���aĹ"<<endl;break;
							return 0;
							
						}
						cout<<"�O�_�~��n�P?�n���ܥ�0�A���n��1"<<endl;
						cin>>a; 
					
					
				}while(a==0);
				do
				{
					cout<<"�q�����a"<<endl;
					poker(comc,c);
					color(comc);
					cout<<(comc/4)+1<<endl;
					cout<<"�`�p";count(comc,y);
					if(y>10.5){
						cout<<"���aĹ"<<endl;break;
						return 0;
						
					}
					else if(y==10.5){
						cout<<"�q�����aĹ"<<endl;break;
						return 0;
					}
			
				}while(y<10.5&&y<=x);
				cout<<"���a��"<<endl;break;
				return 0;
				
				
			}
			}
}

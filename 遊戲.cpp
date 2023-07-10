#include<iostream>
#include<ctime>
#include<cstdlib>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int menu(){
	int i;
	cout<<"請選擇號碼"<<endl;
	cout<<"     1.猜數字遊戲"<<endl;
	cout<<"     2.貪食蛇遊戲"<<endl;
	cout<<"     3.十點半遊戲"<<endl;
	cout<<"     0.離開"<<endl;
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
	if(b%4==0)cout<<"黑桃";
	if(b%4==1)cout<<"紅心";
	if(b%4==2)cout<<"方塊";
	if(b%4==3)cout<<"梅花"; 
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

HANDLE hIn, hOut;                           //I/O 控制器
Point  body[32], cookie, v = {-2,0};        //體塊, 食物, 移動向量,
char   room[N][N*2+4];                      //房間
int    delay_time = 100;                    //延遲時間
int    x1=2,y1=1,x2=(N-1)*2,y2=N-1, len=2;  //房間邊界, 身長
bool   bExit = false;                       //是否持續遊戲

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
    drawList (" ┌","─","┐", N);  
    drawList (" │","  ","│", N, N-2);
    drawList (" └","─","┘", N);

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
    for (i=1; i<len; i++)                   //檢查自身碰撞
        if (body[0].x == body[i].x &&
            body[0].y == body[i].y ) break;

    if (i!=len || x<=x1 || x>x2 || y<=y1 || y>y2) {
        draw (14,10,"G a m e    O v e r");
        getch(); bExit = true;
        return;
    }
    if (x == cookie.x && y == cookie.y) {   //吃到食物
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
        draw (body[i].x, body[i].y, "█");
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
				
				cout<<"歡迎來到猜數字遊戲"<<endl;
				   cout<<"這遊戲將由電腦出一個數字讓使用者猜"<<endl;
					while(flag){
						cout<<"請您輸入一個整數:"<<endl;
						cin>>n;
						if(n>num){
							cout<<"您的數字過大"<<endl;
						}
						else if(n<num){
							cout<<"您的數字過小"<<endl; 
						}
						else{
							flag=0;
							cout<<"恭喜您猜對了!"<<endl;
						}
					}break;
				
		case 2:
			 init();
				while (!bExit)
				{       
				    Sleep (delay_time); if (kbhit()) key_control();
				    draw (cookie.x, cookie.y, "◎");
				    move_snack();
				    Sleep (delay_time); if (kbhit()) key_control();           
				    gotoxy (10,24);
				    printf ("cookie: (%2d,%2d)  head: (%2d,%2d)",
				    cookie.x, cookie.y, body[0].x, body[0].y);
				}break;
			
			
			
				
		case 3:
				do
					{
						cout<<"電腦莊家X"<<endl;
						cout<<"玩家你:"<<endl; 
						poker(youc1,c);
						color(youc1);
						cout<<(youc1/4)+1<<endl;
						cout<<"總計";count(youc1,x);
						if(x>10.5){
							cout<<"玩家輸"<<endl;break;
							return 0;
							
						}
						else if(x==10.5){
							cout<<"玩家贏"<<endl;break;
							return 0;
							
						}
						cout<<"是否繼續要牌?要的話打0，不要打1"<<endl;
						cin>>a; 
					
					
				}while(a==0);
				do
				{
					cout<<"電腦莊家"<<endl;
					poker(comc,c);
					color(comc);
					cout<<(comc/4)+1<<endl;
					cout<<"總計";count(comc,y);
					if(y>10.5){
						cout<<"玩家贏"<<endl;break;
						return 0;
						
					}
					else if(y==10.5){
						cout<<"電腦莊家贏"<<endl;break;
						return 0;
					}
			
				}while(y<10.5&&y<=x);
				cout<<"玩家輸"<<endl;break;
				return 0;
				
				
			}
			}
}

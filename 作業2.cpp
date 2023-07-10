#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cout<<"請輸入五位學生的座號,姓名,平時成績,期中成績,期末成績"<<endl;
	char name[5][10],n[5][10];
	int a[5][4];
	int s[5],s1[5],s2[5],s3[5],t,g,h,r,d;
	for(int i=0;i<5;i++)
	{
		cout<<"座號:"<<endl;
		cin>>a[i][0];
		cin.get();
		cout<<"姓名:"<<endl;
		cin.getline(name[i],10);
		cout<<"平時成績:"<<endl;
		cin>>a[i][1];
		cin.get();
		cout<<"期中成績:"<<endl;
		cin>>a[i][2];
		cin.get();
		cout<<"期末成績:"<<endl;
		cin>>a[i][3];
		cin.get();
	}
	cout<<"學生成績資料及排名"<<endl;
	for(int c=0;c<5;c++)
	{
		s[c]=a[c][3];//期末 
		s1[c]=a[c][0];//座號 
		s2[c]=a[c][1];//平時 
		s3[c]=a[c][2];//期中 
	}
	for(int j=4;j>0;j--)
	{
		for(int d=0;d<=j-1;d++)
		{
			if(s[d]<s[d+1])
			{
				t=s[d];
				s[d]=s[d+1];
				s[d+1]=t;
			
				g=s1[d];
				s1[d]=s1[d+1];
				s1[d+1]=g;
		
				h=s2[d];
				s2[d]=s2[d+1];
				s2[d+1]=h;
		
				r=s3[d];
				s3[d]=s3[d+1];
				s3[d+1]=r;
				
				for(int k=0;k<10;k++)
				{
					char n=name[d][k];
					name[d][k]=name[d+1][k];
					name[d+1][k]=n;
				}
			}
		}
	}
	cout<<"名次|座號|  姓名  |平時成績|期中成績|期末成績"<<endl;
	for(int i=0;i<5;i++)
	{
		cout.width(2);cout<<i+1;
		cout.width(6);cout<<s1[i];
		cout.width(8);cout<<name[i];
		cout.width(8);cout<<s2[i];
		cout.width(8);cout<<s3[i];
		cout.width(8);cout<<s[i];
		cout<<endl; 
	}
	
	
}

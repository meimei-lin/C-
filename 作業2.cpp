#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cout<<"�п�J����ǥͪ��y��,�m�W,���ɦ��Z,�������Z,�������Z"<<endl;
	char name[5][10],n[5][10];
	int a[5][4];
	int s[5],s1[5],s2[5],s3[5],t,g,h,r,d;
	for(int i=0;i<5;i++)
	{
		cout<<"�y��:"<<endl;
		cin>>a[i][0];
		cin.get();
		cout<<"�m�W:"<<endl;
		cin.getline(name[i],10);
		cout<<"���ɦ��Z:"<<endl;
		cin>>a[i][1];
		cin.get();
		cout<<"�������Z:"<<endl;
		cin>>a[i][2];
		cin.get();
		cout<<"�������Z:"<<endl;
		cin>>a[i][3];
		cin.get();
	}
	cout<<"�ǥͦ��Z��ƤαƦW"<<endl;
	for(int c=0;c<5;c++)
	{
		s[c]=a[c][3];//���� 
		s1[c]=a[c][0];//�y�� 
		s2[c]=a[c][1];//���� 
		s3[c]=a[c][2];//���� 
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
	cout<<"�W��|�y��|  �m�W  |���ɦ��Z|�������Z|�������Z"<<endl;
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

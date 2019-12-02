#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int const listsize=100;

typedef struct 
{
int data[listsize];
int length;
}SqList;//˳��������

void CreateSqList(SqList &L)//�����鴴��˳���
{
	int n;
    int x;
	fstream fp;
	fp.open("input.txt",ios::in);
    fp>>n;
    if(n>=12)
	{
		ofstream fp;
        fp.open("output.txt",ios::out);
        fp<<"ERROR"<<endl;
        exit(0);
	}
    L.length=0; 
    for(int i=0;i<n;i++)
    {
		fp>>x;
        L.data[L.length++]=x;
    }
	fp.close();
}

void Findvalue(SqList L,int x) //����x�Ƿ���˳����� 
{ 
	fstream fp;
    fp.open("output.txt",ios::out);
    int i;
    for(i=0;i<L.length;i++) 
	{ 
		if(L.data[i]==x)
		{ 
			fp<<i+1<<' ';break;
		} 
	} 
	if(L.data[i]!=x)
	{
		fp<<"null";
	    fp<<endl;
	}
	fp.close();
} 

void ListSearch(SqList *L,int x) 
{
	fstream fp;
    fp.open("output.txt",ios::app);
    int i=0,n; 
    L->data[L->length]=x;//��Ҫ���ҵ�Ԫ�ط�����±��
    n=L->length; 
    while(i!=n)//i��0��ʼ��һֱ������˳������һ��Ԫ��
	{
		if(L->data[i]==x) 
        fp<<i+1<<' ';//����i��ֵ���������жϸ���i��ֵ�ж��Ƿ���ҳɹ�����i!=L->last����˵�����Ҳ��ɹ�������ɹ�
		i++;
	}
	if(L->data[i]!=x) fp<<"null"<<' ';
    fp.close();
}

void search_bin(SqList L,int x)//�۰���������
{
	fstream fp;
    fp.open("output.txt",ios::app);
    int low=0;
    int high=L.length;
    int mid;
    int flag=0;
    while(low<=high)
	{ 
		flag++;
        mid=(low+high)/2;
		if(x==L.data[mid])
		{
			fp<<flag<<' ';
			return;
		}
        if(x<L.data[mid])high=mid-1;
        else low=mid+1;
	}
	if(low<=high) fp<<"null"<<' ';
	fp.close();
}

void main()
{
	char s[80];
	int h;
	SqList L1;
	ifstream fout1;
	fout1.open("input.txt",ios::in);
	fout1.getline(s,80);
	fout1.getline(s,80);
	fout1>>h;
	cout<<h;
	fout1.close();
    CreateSqList(L1);
    Findvalue(L1,h);
    ListSearch(&L1,h);
    search_bin(L1,h);
    fout1.close();
}

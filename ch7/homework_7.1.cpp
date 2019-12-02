#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;

#define MAX_VERTEX_NUM  20

typedef struct node  //��
{
	int adj;  // �û���ָ����λ��
	struct node *next; //ָ����һ������ָ��
}node;

typedef struct VNode   //����
{ 
	int data;           
	node *nexta;  //ָ���һ�������ö����ָ��
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList  A;
	int   vnum,anum; //������������ 
}ALGraph;



//������Ǳ�������

int visited[MAX_VERTEX_NUM];

 

//�����ڽӱ�ͼ

void CreatALGraph(ALGraph *&G)//��������ͼ�ڽӱ�
{
	char s[80];
    int i,j,k,a;
    node *p;
    fstream fp;
    fp.open("input.txt",ios::in);
    fp>>G->vnum>>G->anum;//���붥�����ͱ��� 
    if(G->vnum>=6)
	{
		ofstream f2;
		f2.open("output.txt",ios::out);
		f2<<"ERROR"<<endl;
		exit(0);
	}
    for(i=0;i<G->vnum;i++)//���붥����Ϣ
	{
		fp>>G->A[i].data>>a>>j;
		G->A[i].nexta=NULL;
	}
	fp.close();
    ifstream f1;
    f1.open("input.txt",ios::in);
    f1.getline(s,80);
    for(k=0;k<G->vnum;k++)
    {
	 f1>>a>>i>>j;
	 p=new node;//����߽��
	 p->adj=j;
	 p->next=G->A[i].nexta;
     G->A[i].nexta=p;//ͷ�巨������
  
  //��Ϊ������ͼ��������Ҫ�ټ���һ��㡣
     p=new node;//����߽��
     p->adj=i;
     p->next=G->A[j].nexta;
     G->A[j].nexta=p;//ͷ�巨������
     G->A[j].nexta->adj=i;
  }
  f1.close();
}

 

void DFS(ALGraph *&G,int v) //�����������
{
 int j;
 node *p;
 p=G->A[v].nexta;
 ofstream fout;
 fout.open("output.txt",ios::out);
 if(!visited[v])
 {
  fout<<G->A[v].nexta<<" ";//����
  visited[v]=1;//�Ѿ����ʹ����
 }
 fout<<endl;
 while(p)
 {j=p->adj;
  if (!visited[j])
  {
   DFS(G,j);   //�ݹ�
  }
  p=p->next;
 }
}

 

void BFS(ALGraph *&G,int v)//�����������
{
 queue<int> Q;
 int j;
 node *p;
 ofstream fout;
 fout.open("output.txt",ios::app);
 if (!visited[v])
 {
  fout<<G->A[v].nexta<<" ";
  visited[v]=1;
  Q.push(v); //�����ʶ������
 }
 
 while(!Q.empty()) //���в��ս�ѭ��
 {
  v=Q.front();//����ͷ
  Q.pop(); //����
  p=G->A[v].nexta;
  while(p)
  {
   j=p->adj;
   if(!visited[j])
   {
    fout<<G->A[j].nexta<<" ";
    visited[j]=1;
    Q.push(j);
   }
   p=p->next;
  }
 }
}


int main()
{
 ALGraph *G=new ALGraph;
 CreatALGraph(G);
 
 cout<<"�����������:";
 DFS(G,0); 
 memset(visited, 0, sizeof(visited));//���¸�ֵ
 cout<<"�����������:";
 BFS(G,0);
 return 0;
}

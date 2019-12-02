#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;

#define MAX_VERTEX_NUM  20

typedef struct node  //弧
{
	int adj;  // 该弧所指顶点位置
	struct node *next; //指向下一条弧的指针
}node;

typedef struct VNode   //顶点
{ 
	int data;           
	node *nexta;  //指向第一条依附该顶点的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList  A;
	int   vnum,anum; //顶点数，弧数 
}ALGraph;



//建立标记变量数组

int visited[MAX_VERTEX_NUM];

 

//创建邻接表图

void CreatALGraph(ALGraph *&G)//建立无向图邻接表
{
	char s[80];
    int i,j,k,a;
    node *p;
    fstream fp;
    fp.open("input.txt",ios::in);
    fp>>G->vnum>>G->anum;//读入顶点数和边数 
    if(G->vnum>=6)
	{
		ofstream f2;
		f2.open("output.txt",ios::out);
		f2<<"ERROR"<<endl;
		exit(0);
	}
    for(i=0;i<G->vnum;i++)//读入顶点信息
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
	 p=new node;//生点边结点
	 p->adj=j;
	 p->next=G->A[i].nexta;
     G->A[i].nexta=p;//头插法加入结点
  
  //因为是无向图，所以需要再加入一结点。
     p=new node;//生点边结点
     p->adj=i;
     p->next=G->A[j].nexta;
     G->A[j].nexta=p;//头插法加入结点
     G->A[j].nexta->adj=i;
  }
  f1.close();
}

 

void DFS(ALGraph *&G,int v) //深度优先搜索
{
 int j;
 node *p;
 p=G->A[v].nexta;
 ofstream fout;
 fout.open("output.txt",ios::out);
 if(!visited[v])
 {
  fout<<G->A[v].nexta<<" ";//访问
  visited[v]=1;//已经访问过标记
 }
 fout<<endl;
 while(p)
 {j=p->adj;
  if (!visited[j])
  {
   DFS(G,j);   //递归
  }
  p=p->next;
 }
}

 

void BFS(ALGraph *&G,int v)//广度优先搜索
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
  Q.push(v); //被访问顶点入队
 }
 
 while(!Q.empty()) //队列不空进循环
 {
  v=Q.front();//读队头
  Q.pop(); //出队
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
 
 cout<<"深度优先搜索:";
 DFS(G,0); 
 memset(visited, 0, sizeof(visited));//重新赋值
 cout<<"广度优先搜索:";
 BFS(G,0);
 return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct  LNode
{
	int data;
	struct LNode  *next;
}LNode,*LinkList;

void IniteList(LinkList L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	{
		printf("OVERFLOW\n");
		exit(0);
	}
	L->data=0;
}

int CreateLinkList(LinkList L)
{
	int a,i,c,b,d;
	struct LNode *p,*q;
	p=(LinkList)malloc(sizeof(LNode));
	q=(LinkList)malloc(sizeof(LNode));
	FILE*fp;
	if(!(fp=fopen("input.txt","r")))
	{
		printf("打开输入文件失败\n");
		exit(0);
	}
	if(!fscanf(fp,"%d",&a) || a < 1 || a > 19)
	{
		return 0;
	}
	q->next=L;//q=L;
	for(i=0,d=0;i<a;d++)
	{	c=fscanf(fp,"%d",&b);
		if(abs(b)>999)
		{
			return 0;
		}
		if(c==0||c==-1)
		{
			break;          
		}
		L->next=p;
		p->data=b;
		p->next=NULL;
		L=p;//
	}
	if(d!=a)
	{
		return 0;
	}
	else return 1;
}

void Convert(LinkList L)
{
	struct LNode *p,*k;
	k=(LinkList)malloc(sizeof(LNode));
	p=(LinkList)malloc(sizeof(LNode));
	int i;
	p->next=L->next;
	k=p->next;
	k->next=L;
	L->next=NULL;
	L=p->next;
	for(i=0;L->next!=NULL;i++)
	{
		p->next=L->next;
		k=p->next;
		k->next=L;
		L=p->next;
	}
}

void OutPut_Error()
{
	char a[6] = "ERROR";
	FILE*fp;
	if(!(fp=fopen("output.txt","w")))
	{
		printf("输出文件无法打开\n");
		exit(0);
	}
	fwrite(a,1,6,fp);
	fclose(fp);
	printf("输出错误");
}

void OutPut(LinkList &L)
{
	int i;
	FILE*fp;
	if(!(fp=fopen("output.txt","w")))
	{
		printf("输出文件无法打开\n");
		exit(0);
	}
	LinkList p;
	p=L;
	for(i=0;p->next!=NULL;i++)
	{
		fprintf(fp,"%d",p->data);
		p=p->next;
		fprintf(fp,"%c",' ');
	}
	fclose(fp);
}

void main()
{
	LinkList L=0;
	int a;
	IniteList(L);
	a=CreateLinkList(L);
	if(!a)
	{
		OutPut_Error();
		printf("\n");
		exit(0);
	}
	Convert(L);
	OutPut(L);
	printf("输出数据成功\n");
}

#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE  100

typedef struct//顺序表
{
	int *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList *L)//构造新的线性表
{
	L->elem=(int *)malloc( LIST_INIT_SIZE*sizeof(int));
	if(!L->elem)
{
	printf("OVERFLOW\n");
	    exit(0);
	}
	L->length=0;
	L->listsize= LIST_INIT_SIZE;
}

int CreateSqList(SqList*L,int *x)
{
	int i,a,b,c;
	FILE*fp;
	if(!(fp = fopen("input.txt","r")))
	{
		printf("打开输入文件错误\n");
		exit(0);
	}
	if(!fscanf(fp,"%d",&a) || a < 1 || a > 19 )
	{
		return 0;
	}
	for(i=0;i<a;i++,L->length++)
	{
		c=fscanf(fp,"%d",&b);
		if(abs(b)>999)
		{
			return 0;
		}
		if(c==0||c==-1)
		{
			break;         
		}
		L->elem[i]=b;
	}
	if(i!=a)
	{
		return 0;
	}
	c=fscanf(fp,"%d",x);
	if (c==0 ||c==-1)
		return 0;
	for (i=1;i<a && L->elem[i-1]<=L->elem[i];i++)
	{}
	if(i==a)
		return 1;
	else
	{
		for(i = 1; i < a && L->elem[i-1]>= L->elem[i]; i++)
		{}
		if(i == a)
			return -1;
		else return 0;
	}
		fclose(fp);
}

void InsertList(SqList *L,int x)
{
	int i,j;
	for(j=L->length-1,i=L->length;j>=0;j--,i--)
	{
		if(x>=L->elem[j])
		{
			L->elem[i]=x;
			break;
		}
		else
			L->elem[i]=L->elem[j];
	}
	L->elem[i]=x;
	L->length++;
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

void OutPut(SqList *L)
{
	int i;
	FILE*fp;
	if(!(fp=fopen("output.txt","w")))
	{
		printf("输出文件无法打开\n");
		exit(0);
	}
	for(i=0;i<L->length;i++)
	{
		fprintf(fp,"%d",L->elem[i]);
		fprintf(fp,"%c",' ');
	}
	fclose(fp);
}

void main()
{
	SqList L;
	int x,a;
	InitList(&L);
	a=CreateSqList(&L,&x);
	if(!a)
	{
		OutPut_Error();
		printf("\n");
		exit(0);
	}
	InsertList(&L,x);
	OutPut(&L);
	printf("输出数据成功\n");
}
#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE   200

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S)
{
	S.base=(char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if(!S.base)
	{
		exit(0);
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
}

void Push(SqStack &S,char e)
{
	*S.top++ = e;
}

void Pop(SqStack &S,char e)
{
	e = * --S.top;
}

int CreateSqStack(SqStack &S,int &q)
{
	int a,i,t=0,r=0;
	char b,c,m,n,e;
	char*p;
	FILE*fp;
	if(!(fp = fopen("input.txt","r")))
	{
		printf("打开输入文件错误\n");
		exit(0);
	}
	if(!fscanf(fp,"%d",&a) || a < 1 || a > 200 )
	{
		return 0;
	}
	for(i=0;i<a;i++)
	{
		c=fscanf(fp,"%c",&b);
		if(b=' ')
		{
			return 0;
		}
		if(S.top==S.base)
			{
				switch(b)
				{
				case '(': Push(S,c);t=1;break;
				case '[': Push(S,c);t=2;break;
				case '{': Push(S,c);t=3;break;
				case ')': q=1;return 0; break;
				case ']': q=1;return 0; break;
				case '}': q=1;return 0; break;
				default :;
				}
			}
		else
			{
				switch(b)
				{
				case '(': Push(S,c);t=1;break;
				case '[': Push(S,c);t=2;break;
				case '{': Push(S,c);t=3;break;
				case ')': r=1; break;
				case ']': r=2; break;
				case '}': r=3; break;
				default :;
				}
				if(r!=0)
				{
					if(S.top==S.base) {q=1;return 0;}
					if(t==r)
					{
						Pop(S,e);
						p=S.top;
						m=*--p;
						switch(m)
						{
				           case '(': t=1;break;
				           case '[': t=2;break;
				           case '{': t=3;break;
				           case ')': q=1;return 0; break;
				           case ']': q=1;return 0; break;
				           case '}': q=1;return 0; break;
						}
						r=0;
					}
				
				}
		}
	}
	if(S.base==S.top)
		return 1;
	else return 0;
	fclose(fp);
}

void OutPut_Error()
{
		char a[6]="ERROR";
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
	
void OutPut(SqStack &S,int q)
{
	int i;
	char a[5]="True";
	char b[6]="False";
	FILE*fp;
	if(!(fp=fopen("output.txt","w")))
	{
		printf("输出文件无法打开\n");
		exit(0);
	}
	if(q==1) { fwrite(b,1,6,fp);fwrite("\n",1,3,fp);}
	else {fwrite(a,1,5,fp);fwrite("\n",1,3,fp);}
	fclose(fp);
}

void main()
{
	SqStack S;
	int q=0,o;
	InitStack(S);
	o=CreateSqStack(S,q);
	if(q==1)
	{
		OutPut(S,q);
		printf("括号不匹配\n");
		exit(0);
	}
	if(!o)
	{
		OutPut_Error();
		printf("\n");
		exit(0);
	}
	if(q==0)
	{
		OutPut(S,q);
		printf("括号匹配\n");
	}
}
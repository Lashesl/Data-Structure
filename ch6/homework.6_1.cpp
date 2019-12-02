#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left,*right;
}Node;

int CreateTree(Node *N)
{
	int a,sum,sum_size;
	int root,leftc,rightc,front=0,back=0,temp,len=0;
	FILE*fpi;
	FILE*fpo;
	if(!(fpi = fopen("input.txt","r")))
	{
		printf("打开输入文件错误\n");
		exit(0);
	}
	if(!fscanf(fpi,"%d",&a) || a < 1)
	{
		return 0;
	}
	sum=a;
	if(!fscanf(fpi,"%d",&sum_size) || a <21)
	{
		printf("打开输入文件错误\n");
		exit(0);
	}
	N=(Node*)malloc(sizeof(Node)*sum_size);
	while(fscanf(fpi,"%d%d%d",&root,&leftc,&rightc)!=EOF)
	{
		if(front==0)
			N[back++].data=root;
		if(N[front].data!=root)
			{
				fpo=fopen("output.txt","w");
				fprintf(fpo,"ERROR\n");
				return 0;
			}
		else
		{
			temp=front;
			if(leftc==-1) N[temp].left=NULL;
			else
			{
				N[back].data=leftc;
				N[temp].left=&N[back];
				back++;
			}
		   if(rightc==-1) N[temp].right=NULL;
			else
			{
				N[back].data=rightc;
				N[temp].right=&N[back];
				back++;
			}
		   front++;
		}
	}
	fclose(fpi);
	fclose(fpo);
}

int s(int *a,int len)//求和
{
	int i=0,sum=0;
	for(;i<len;i++)
		sum+=a[i];
	return sum;
}

int Search(Node *N,int sum,int *now,int len )//递归搜索
{
	int i=0,t1=0,t2=0;
	if(N->left==NULL&&N->right==NULL)
	{
		now[len++]=N->data;
		if(s(now,len)==sum)
		{
			FILE*fp=fopen("output.txt","a+");
			for(i=0;i<len;i++)
				fprintf(fp,"%d",now[i]);
			fprintf(fp,"\n");
			fclose(fp);
			return 1;
		}
		else return 0;
	}
	else
	{
		now[len]=N->data;
		if(N->left!=NULL)  
			t1=Search(N->left,sum,now,len+1);
			t2=Search(N->right,sum,now,len+1);
			return  t1||t2;
	}
}

void OutPut_Error()
{
	char a[6] = "ERROR";
	FILE *fp;
	if(!(fp = fopen("output.txt","w"))){
		printf("输出文件无法打开!!!\n");
		exit(0);
	}
	fwrite(a, 1, 6, fp);
	fclose(fp);
	printf("输出错误!!!");
}

void main()
{
	Node N;
	int*now,a,sum,len;
	a=CreateTree(&N);
	if(!a)
	{
		OutPut_Error();
		printf("\n");
		exit(0);
	}
	if(Search(&N,sum,now,len)==0)
	{
		FILE*fp;
		fp=fopen("output.txt","w");
		fprintf(fp,"NULL\n");
		fclose(fp);
	}
}

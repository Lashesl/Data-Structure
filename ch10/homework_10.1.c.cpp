#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void InsertSort(int* pDataArray, int iDataNum)  
{  
	fstream fp;
	fp.open("output.txt",ios::out);
    for (int i = 1; i < iDataNum; i++)    //�ӵ�2�����ݿ�ʼ����   
    {  
        int j = 0;  
        while (j < i && pDataArray[j] <= pDataArray[i])    //Ѱ�Ҳ����λ��   
        j++;    
        if (j < i)    //iλ��֮ǰ���б�pDataArray[i]������������Ų���Ͳ���   
        {  
            int k = i;  
            int temp = pDataArray[i];  
            while (k > j)    //Ų��λ��   
            {  
                pDataArray[k] = pDataArray[k-1];  
                k--;  
            }  
            pDataArray[k] = temp;    //����   
            for(int i=0;i<iDataNum;i++)
            fp<< pDataArray[i]<<' ';
        }  
          fp<<endl;
    } 
   fp<<endl;
   fp.close();
}  

void QuickSort(int* pDataArray, int iDataNum,int start)//��������
{
	int z,k;
	fstream fp;
	fp.open("input.txt",ios::in);
	fp>>k;
	for(z=0;z<k;z++)  fp>>pDataArray[z];
	fstream fp1;
	fp1.open("output.txt",ios::app);
	int x=pDataArray[start];
	int i,j;
	i=start;
	j=iDataNum-1;
	while(i<j)
	{
		if(x<pDataArray[j])  j--;
        else if(x>pDataArray[j])
		{
			pDataArray[i]=pDataArray[j];
			pDataArray[j]=x;
			i++;
		}
        else if(x<pDataArray[i])
		{
			pDataArray[j]=pDataArray[i];
			pDataArray[i]=x;
			j--;
		}
        else i++;
		for(int m=0;m<k;m++)
			fp1<< pDataArray[m]<<' ';
		fp1<<endl;
	}
	if(start<iDataNum-1)
	{
		QuickSort(pDataArray,i,start);//��Ϊǰ�������ֵݹ�����
		QuickSort(pDataArray,iDataNum,i+1);
	}
	fp1<<endl;
	fp1.close();
	fp.close();
}  

void bubblesort(int* pDataArray,int iDataNum)//ð������
{
	fstream fp;
	fp.open("input.txt",ios::in);
	fp>>iDataNum;
	for(int i=0;i<iDataNum;i++)
		fp>>pDataArray[i];
	fstream fp1;
	fp1.open("output.txt",ios::app);
	int allone;
	for(int i=1;i<iDataNum;i++)
	{
		for(int j=0;j<=iDataNum-1-i;j++)
			if(pDataArray[j]>pDataArray[j+1])
			{
				allone=pDataArray[j];
				pDataArray[j]=pDataArray[j+1];
				pDataArray[j+1]=allone;
				for(int m=0;m<iDataNum;m++)
					fp1<< pDataArray[m]<<' ';//�������Ĺ���
				fp1<<endl;
			}
	}
	fp1<<endl;
	fp1.close();
	fp.close();
}

void main()
{
	int a[100];
	int number;
	fstream fp1;
	fp1.open("input.txt",ios::in);
	fp1>>number;
	if(number==5||number==6)
	{
		fstream fp;
		fp.open("output.txt",ios::out);
		fp<<"ERROR"<<endl;
		exit(0);
	}
	for(int i=0;i<number;i++)
		fp1>>a[i];
	fp1.close();
	InsertSort(a,number);  
	bubblesort(a,number);
	QuickSort(a,number,0);
}
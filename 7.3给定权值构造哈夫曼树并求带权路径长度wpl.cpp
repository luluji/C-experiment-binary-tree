#include<stdio.h>

typedef struct{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}Htnode;
//构造哈夫曼树 
void Createht1(Htnode h[],int n)
{
	int i,j,min1,min2,lnode,rnode;	
	for(i=0;i<2*n-1;i++)
	{
		h[i].parent=-1;
		h[i].lchild=-1;
		h[i].rchild=-1;
	}
	for(i=n;i<2*n-1;i++)
	{
		min1=min2=32767;
		lnode=rnode=-1;
		for(j=0;j<i;j++)
		{
			if(h[j].parent==-1)
			{
				if(h[j].weight<=min1)
				{
					min2=min1;
					min1=h[j].weight;
					rnode=lnode;
					lnode=j;
				}
				else if(h[j].weight<min2)
					{
						min2=h[j].weight;
						rnode=j;
					}
			}
		}
		h[lnode].parent=i;
		h[rnode].parent=i;
		h[i].lchild=lnode;
		h[i].rchild=rnode;
		h[i].weight=h[lnode].weight+h[rnode].weight;
	}
}

void Createht2(Htnode ht[],int n)
{
	int i,k,lnode,rnode;
	int min1,min2;
	for (i=0;i<2*n-1;i++)			//所有节点的相关域置初值-1
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n;i<2*n-1;i++)			//构造哈夫曼树
	{
		min1=min2=32767;			//lnode和rnode为最小权重的两个节点位置
		lnode=rnode=-1;
		for (k=0;k<=i-1;k++)
			if (ht[k].parent==-1)	//只在尚未构造二叉树的节点中查找
			{
				if (ht[k].weight<min1)
				{
					min2=min1;rnode=lnode;
					min1=ht[k].weight;lnode=k;
				}
				else if (ht[k].weight<min2)
				{
					min2=ht[k].weight;rnode=k;
				}
			}
		ht[lnode].parent=i;ht[rnode].parent=i;
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;
	}
}
//计算哈夫曼树带权路径长度wpl 
int Wpl(Htnode h[],int n)
{
	int i,dep,f,sumwpl=0;
	for(i=0;i<n;i++)
	{
		dep=0;
		f=i;
		while(h[f].parent!=-1)
		{
			dep++;
			f=h[f].parent;			
		} 
		sumwpl=sumwpl+dep*h[i].weight;
	}
	return sumwpl;
}

int main()
{
	int i,n=6;
	int m[6]={2,3,4,7,8,9};
	Htnode h[11];
	for(i=0;i<n;i++)
	{
		h[i].weight=m[i];
	}
	Createht2(h,n);
	printf("wpl:%d\n",Wpl(h,n));
}


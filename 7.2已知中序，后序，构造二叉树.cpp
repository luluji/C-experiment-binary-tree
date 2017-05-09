#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}Btnode;
//自己  中序，后序构造二叉树 
Btnode *Creabtree(char *in, char *post,int n)
{
	int k=0;
	Btnode *p;
	if(n>0)
	{
		p=(Btnode *)malloc(sizeof(Btnode));
		p->data=post[n-1];
		while(in[k]!=post[n-1]) k++;
		p->lchild=Creabtree(in,post,k);
		p->rchild=Creabtree(in+k+1,post+k,n-k-1);
		return p;
	}
	else
		return NULL;
 } 
 //书 
Btnode *Creabtree2(char *in,char *post,int n)
 {
 	Btnode *b;
 	char r,*p;
 	int k;
	if(n<=0) return NULL;
	r=*(post+n-1);
	b=(Btnode *)malloc(sizeof(Btnode));
	b->data=r;
	for(p=in;p<in+n;p++)
		if(*p==r) break;
	k=p-in;
	b->lchild=Creabtree(in,post,k);
	b->rchild=Creabtree(p+1,post+k,n-k-1);
	return b;
 }
 
void Dispbtree(Btnode *b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild!=NULL||b->rchild!=NULL)
		{
			printf("(");
			if(b->lchild!=NULL)
				Dispbtree(b->lchild);
			if(b->rchild!=NULL)
			{
				printf(",");
				Dispbtree(b->rchild);
			}
			printf(")");
		}
	}
}

int main()
{
	char in[]="cbedahgijf";
	char post[]="cedbhjigfa";
	Btnode *b;
	int n=10;
	b=Creabtree(in,post,n);
	Dispbtree(b);
}

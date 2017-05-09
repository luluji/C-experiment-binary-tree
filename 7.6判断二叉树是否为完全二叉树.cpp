#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}Btnode;

void CreateBtree(Btnode *&b,char *str)
{
 	Btnode *st[MAX],*p;
 	int top=-1,k,j=0;
 	char ch;
 	b=NULL;
 	ch=str[j];
 	while(ch!='\0')
 	{
 		switch(ch)
 		{
 			case '(':top++;st[top]=p;k=1;break;
 			case ')':top--;break;
 			case ',':k=2;break;
 			default:p=(Btnode *)malloc(sizeof(Btnode));
 				p->data=ch;
				p->lchild=p->rchild=NULL;
				if(b==NULL)
				{
					b=p;
				 } 
				else
				{
					switch(k)
					{
						case 1:st[top]->lchild=p;break;
						case 2:st[top]->rchild=p;break;
					}
				}
		 }
		 j++;
		 ch=str[j];
	 }
}

int Judge(Btnode *b)
{
	int l,r;
	if(b==NULL) return 1;
	else 
	{
		if(b->lchild==NULL&&b->rchild!=NULL||b->lchild!=NULL&&b->rchild==NULL)
			return 0;
		else 
		{
			l=Judge(b->lchild);
			r=Judge(b->rchild);
			return l==r?l+r:0;
		}
	}
 } 
 
int main()
{
 	char str[]="A(B(D,E),C(F,G))";
 	Btnode *b;
 	CreateBtree(b,str);
 	if(Judge(b)) printf("yes\n");
 	else printf("no\n");
}

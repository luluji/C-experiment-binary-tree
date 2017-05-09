#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
	char data;
	node *lchild;
	node *rchild;
}BTNode;

void CreateBtree1(BTNode *&b,char str[])
{
	int i=0,k=1;
	BTNode *p;
	BTNode *st[MAX];
	int top=-1;
	b=NULL;
	while(str[i]!='\0')
	{
		if(str[i]=='(')
		{
			top++;
			st[top]=p;
			k=1;	
		}
		else if(str[i]==',')
		{
			k=2;
		}
		else if(str[i]==')')
		{
			top--;
		}
		else
		{
			p=(BTNode *)malloc(sizeof(BTNode));
			p->data=str[i];
			p->lchild=p->rchild=NULL;
			if(b==NULL)
			{
				b=p;
			}
			else 
			{				
				if(k==1)
				{
					st[top]->lchild=p;
				}
				else
				{
					st[top]->rchild=p;
				}
			}
		}
		i++;
	}
	
 } 
 
 void CreateBtree2(BTNode * &b,char *str)
 {
 	BTNode *st[MAX],*p;
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
 			default:p=(BTNode *)malloc(sizeof(BTNode));
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
 
 void InOrder1(BTNode *b)		//µÝ¹é 
 {
 	if(b!=NULL)
 	{
		InOrder1(b->lchild);
 		printf("%c",b->data);
		InOrder1(b->rchild);
	 }
 }
 
void InOrder2(BTNode *b)		//·ÇµÝ¹é 
 {
 	BTNode *st[MAX],*p;
	int top=-1;
	if(b!=NULL)
	{
		p=b;
		while(top>-1||p!=NULL)
		{
		
			while(p!=NULL)
			{
				
				top++;
				st[top]=p;
				p=p->lchild;
			}
		
				p=st[top];
				printf("%c",p->data);
				top--;	
				p=p->rchild; 
			
		}
	}	
 }
 int main()
 {
 	BTNode *b;
 	char str[50]="A(B(D(,G)),C(E,F))";
 	CreateBtree2(b,str);
 	InOrder2(b);
 }

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}Btnode;

void Creabtree(Btnode *&b,char *str)
{
	Btnode *st[100],*p;
	int i=0,f,top=-1;
	char r;
	b=NULL;
	r=str[i];
	while(r!='\0')
	{
		switch(r)
		{
			case '(':f=1;
					 top++;
					 st[top]=p;
					 break;
			case ',':f=2;
					 break;
			case ')':top--;
					 break;
			default :p=(Btnode*)malloc(sizeof(Btnode));
				 	 p->data=r;
				 	 p->lchild=p->rchild=NULL;
					 if(b==NULL)
					 	 b=p;
					 else if(f==1) st[top]->lchild=p;
					   	 else st[top]->rchild=p;
					 break;
		}
		r=str[++i];
		
	}
}

void Exchange(Btnode *&b)
{
	Btnode *t;
	if(b!=NULL)
	{
		t=b->lchild;
		b->lchild=b->rchild;
		b->rchild=t;
		Exchange(b->lchild);
		Exchange(b->rchild);
	}
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
	char str[]="A(B(C,D(E)),F(G(H,I(,J))))";
	Btnode *b;
	Creabtree(b,str);
	Dispbtree(b);
	printf("\n");
	Exchange(b);
	Dispbtree(b);
}

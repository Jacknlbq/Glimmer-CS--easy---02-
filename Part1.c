#include<stdio.h>
#include<stdlib.h>
//构造链表
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//定义头尾指针
Node* head=NULL,*tail;
//头部插入
void inserthead(int a)
{
    Node* p=(Node*)malloc(sizeof(Node));
    p->next=head;
	head=p;
	p->data=a;
}
//尾部插入
void inserttail(int data)
{
    Node* p=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	head=p;

	if(tail!=NULL)
	tail->next=p;
    
	p->next=NULL;
	p->data=data;
	tail=p;
}
//删除
void delete(int i)
{
    Node* p=head,*q;
	if(i==1)
	{
		head=p->next;
		if(tail->next!=NULL)
		tail->next=head;
		free(p);
	}
	else{
		for(int j=1;j<i-1;j++)
		p=p->next;
        q=p->next;
		p->next=q->next;
       free(q);
		
	}
}
//输出
void putout()
{
    Node* p=head;
    while(p!=NULL)
    {
       printf("%d ",p->data);
	   if(p==tail)break;
       p=p->next;
    }
}//销毁
void destroy()
{
    Node* p=head,*q;
    while(p!=NULL)
    {
		q=p->next;
        free(p);
	    if(p==tail)break;
		p=q;
	}	
}
//转换
void C()
{
	tail->next=head;
}
int main()
{
    char c;
     while( (c=getchar()))
     {
         if(c=='H')//执行H操作
         {
            int d;
            while(scanf("%d",&d))
            {
                inserthead(d);
                if(getchar()=='\n')break;//判断输入终止
            }
			continue;
         }
         //执行T操作
          if(c=='T')
         {
            int d;
            while(scanf("%d",&d))
            {
                inserttail(d);
                if(getchar()=='\n')break;//判断输入终止
            }
			continue;
         }
		 //执行D操作
          if(c=='D')
         {
            int d;
            scanf("%d",&d);
            delete(d);
			getchar();
			continue;
         }
		 //执行C操作
        if(c=='c')
		{
			C();
			getchar();
			continue;
		}
         break;
     }
     putout();
     destroy();
     return 0;
}
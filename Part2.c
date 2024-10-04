#include<stdio.h>
#include<stdlib.h>
//长度
int length=1;
//构造链表
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//定义头尾指针
Node* head,*tail;
//头部插入
void inserthead(int a)
{
    Node* p=(Node*)malloc(sizeof(Node));
    p->next=head;
	head=p;
	p->data=a;
    length++;
}
//尾部插入
void inserttail(int data)
{
    Node* p=(Node*)malloc(sizeof(Node));
    tail->next=p;
	p->next=NULL;
	p->data=data;
	tail=p;
    length++;
}
//删除
Node* delete(int i,Node* h)
{
    length--;
    Node* p=h,*q;
        if(i==1)
	{
		head=p->next;
		free(p);
	}
	else{
		for(int j=1;j<i-1;j++)
		p=p->next;
        q=p->next;
        if(q!=tail)
		p->next=q->next;
        else {
            tail=p;
            p->next=NULL; 
        }
       free(q);
	}
}
 Node* delete1(int i,Node* h){
    Node* p=h,*q;
     for(int j=1;j<=i-1;j++)
		p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);
        return p;
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
        length--;
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
//查找
Node* find(int a)
{
    Node* p=head;
    while(1)
    {
        if(p->next->data==a)
        return p;
        p=p->next;
    }
}
int main()
{
    Node* d;
    FILE * fp;
    fp=fopen("D:\\vscodePro\\test2\\CS-EASY-02-1.txt","r");
    head=(Node*)malloc(sizeof(Node));
    head->data=1;
    head->next=NULL;
    tail=head;
    char c;
     while( (c=fgetc(fp)))
     {
         if(c=='H')//执行H操作
         {
            int d[3];
            for(int i=0;i<3;i++)
               fscanf(fp,"%d",&d[i]);
           for(int i=2;i>=0;i--)
           inserthead(d[i]);
            fgetc(fp);
            continue;
         }
         //执行T操作
          if(c=='T')
         {
            int d;
            for(int i=1;i<=3;i++)
            {
               fscanf(fp,"%d",&d);
               inserttail(d);
            }
            fgetc(fp);  
            continue;
         }
		 //执行D操作
          if(c=='D')
         {
            int d;
            fscanf(fp,"%d",&d);
            delete(d,head);
			fgetc(fp);
            continue;
         }
		 //执行C操作
        if(c=='C')
		{
			C();
            continue;
		}
         break;
     }
     fclose(fp);
     d=find(3);
     int l=length;
     FILE* J=fopen("D:\\vscodePro\\test2\\Josephus.out","w");
     for(int i=1;i<=l;i++)
     {
        Node* k=d;
        for(int m=1;m<=i;m++)
        k=k->next;
        fprintf(J,"%d ",k->data);
        d=delete1(i,d);
     }
     fclose(J);    
     return 0;
}//3 1 1 1 1 1 1 2 2 2 1 2 2 1 1 2 2 2 1 1 1 1 2 1 1 2 2 1 2 1 2 1 1 2
 //3 2 1 1 1 1 1 1 1 2 2 2 1 2 2 1 1 2 2 2 1 1 1 1 2 1 2 2 1 1 2 1 2 1
 //3 1 1 2 2 1 2 1 1 2 1 2 2 1 1 2 2 1 1 2 2 1 1 2 2 1 1 2 1 1 1 1 1 2 
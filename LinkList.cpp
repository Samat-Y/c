#include <stdio.h>
#include <string.h>
#define OK 1
#define ERROR 0

typedef struct{
	int ID;
	char name[20];
	float score;
}Student; 


typedef struct LNode{
	Student data;
	struct LNode *next;
}LNde,*LinkList;


int InitList_L(LinkList &L) { // 单链表的初始化
	L=new LNode;
	L->next=NULL;
	return OK;
}


void CreateList(LinkList &L,int n)//输入 
{
	LinkList r,p;
	r=L;
	for(int i=0;i<n;i++)
	{
		p=new LNode;
		printf("请输入第%d个学生信息（学号 姓名 成绩）：",i+1);
		scanf("%d %s %f",&p->data.ID,&p->data.name,&p->data.score);
		p->next=NULL;
		r->next=p;
		r=p;
	}    
	printf("输入完成！\n");                                                                     
}

LinkList GetElem(LinkList L,int i)//按位序查找 
{
	LinkList p=L;
	int j=0;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)
	{
		printf("查找失败！\n");return 0;
	}
	return p;
}

void get(LinkList L)//由地址查找
{
	
	printf("学号：%d 姓名：%s 成绩：%.2f\n",L->data.ID,L->data.name,L->data.score);
} 

int LocateElem_name(LinkList &L, char e[])//按姓名查找
{
	int end=0;
	LinkList p;
	p=L;
	while(p->next!=NULL)
	{
		if(strcmp(e,p->data.name)==0)
		{
			get(p);
			end=1;
		}
		p=p->next;
	}
	if(strcmp(e,p->data.name)==0)
	{ 
			end=1;
	}
	if(end=0)
	{
	printf("查找失败！\n");
	}
	printf("查找成功！\n");
	return end;
}

int LocateElem_score(LinkList L, float i)//按成绩查找
{
	int end=0;
	LinkList p;
	p=L;
	while(p->next!=NULL)
	{
		if(i==p->data.score)
		{ 
			get(p);
			end=1;
		}
		p=p->next;
	}
	if(i==p->data.score)
	{ 
		get(p);
		end=1;
	}
	if(end==0)
	{
	printf("查找失败！\n");
	}
	printf("查找成功！\n");
	return end;
}

int ListInsert_Sq(LinkList &L, int i, LinkList &e)//插入 
{
	LinkList p=L,ls;
	int j=1;
	if(i==1)
	{
		ls=L->next;
		L->next=e;
		L->next->next=ls;
		printf("插入成功！\n");return 1;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j>i)
	{
		printf("插入失败！\n");return 0;
	}
	e->next=p->next;
	p->next=e;
	printf("插入成功！\n");return 1;
}

int ListDelete(LinkList &L, int i)//删除 
{
	LinkList p=L,ls;
	int j=1;
	if(i==1)
	{
		ls=L->next->next;
		L->next=ls;
		printf("删除成功！\n");return 1;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j>i)
	{
		printf("删除失败！\n");return 0;
	}
	p->next=p->next->next;
	printf("删除成功！\n");return 1;
}

void bianli(LinkList L)
{	
	LinkList ls;
	int num=0;
	ls=L;
	if(ls->next==NULL)
	{
		printf("无\n");
	}
	while(ls->next!=NULL)
	{
		printf("第%d个学生： 学号：%d 姓名：%s 成绩：%.2f\n",num+1,ls->next->data.ID,ls->next->data.name,ls->next->data.score);
		ls=ls->next;
		num++;
	}
	printf("共有%d个学生信息。\n",num);
}

void prf()
{

	printf("_________________________________\n");
	printf("1. 建立\n");
	printf("2. 读取\n"); 
	printf("3. 输入\n");
	printf("4. 按序号查找\n");
	printf("5. 按姓名查找\n");
	printf("6. 按成绩查找\n");
	printf("7. 插入\n");
	printf("8. 删除\n");
	printf("9. 遍历\n");
	printf("10. 保存\n");
	printf("0. 退出\n");
	printf("_________________________________\n");
	printf("请选择：");
}
	



int main()
{
	Student stu;
	LinkList L,charu;
	charu=new LNode;
	charu->next=NULL;
	int choose=-1,i=0;//i计数 ,位序 
	char ming[20];
	float fenshu;
	while(choose!=0)
	{
		prf();
		scanf("%d",&choose);
		while(choose<0||choose>8)
		{
			printf("输入错位！\n");
			prf();
			scanf("%d",&choose);
		}
		switch(choose)
		{
			case 1:
			{
				if(InitList_L(L)==OK)
				{
					printf("建立成功！\n");break;
				}
				printf("建立失败！\n");break;
			}
			case 3:
			{
				printf("_______________输入_______________\n");
				printf("请输入学生个数：");
				scanf("%d",&i); 
				CreateList(L,i);break;
			}
			case 4:
			{
				printf("_______________按序号查询_______________\n");
				printf("请输入查询序号：");
				scanf("%d",&i);
				if(GetElem(L,i)==0)
				{
					break;
				}
				get(GetElem(L,i));break;
			}
			case 5:
			{
				printf("_______________按姓名查询_______________\n");
				printf("请输入要查找的姓名：");
				scanf("%s",&ming);
				if(LocateElem_name(L, ming)==0)
				{
					break;
				}
				LocateElem_name(L, ming);break;
			}
			case 6:
			{
				printf("_______________按分数查询_______________\n");
				printf("请输入要查找的分数：");
				scanf("%f",&fenshu);
				LocateElem_score(L, fenshu);break;
			}
			case 7:
			{
				printf("_______________插入_______________\n");
				printf("请输入（插入位置 学号 姓名 分数）：");
				scanf("%d %d %s %f",&i,&stu.ID,&stu.name,&stu.score);
				charu->data=stu;
				ListInsert_Sq(L, i, charu);break;
				
			}
			case 8:
			{
				printf("_______________删除_______________\n");
				printf("请输入要删除的序号：\n");
				scanf("%d",&i);
				ListDelete(L, i);break;
			}
			case 9:
			{
				bianli(L);break;
			}
		}
		
	}
	return 0;
}

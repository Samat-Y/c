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


int InitList_L(LinkList &L) { // ������ĳ�ʼ��
	L=new LNode;
	L->next=NULL;
	return OK;
}


void CreateList(LinkList &L,int n)//���� 
{
	LinkList r,p;
	r=L;
	for(int i=0;i<n;i++)
	{
		p=new LNode;
		printf("�������%d��ѧ����Ϣ��ѧ�� ���� �ɼ�����",i+1);
		scanf("%d %s %f",&p->data.ID,&p->data.name,&p->data.score);
		p->next=NULL;
		r->next=p;
		r=p;
	}    
	printf("������ɣ�\n");                                                                     
}

LinkList GetElem(LinkList L,int i)//��λ����� 
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
		printf("����ʧ�ܣ�\n");return 0;
	}
	return p;
}

void get(LinkList L)//�ɵ�ַ����
{
	
	printf("ѧ�ţ�%d ������%s �ɼ���%.2f\n",L->data.ID,L->data.name,L->data.score);
} 

int LocateElem_name(LinkList &L, char e[])//����������
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
	printf("����ʧ�ܣ�\n");
	}
	printf("���ҳɹ���\n");
	return end;
}

int LocateElem_score(LinkList L, float i)//���ɼ�����
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
	printf("����ʧ�ܣ�\n");
	}
	printf("���ҳɹ���\n");
	return end;
}

int ListInsert_Sq(LinkList &L, int i, LinkList &e)//���� 
{
	LinkList p=L,ls;
	int j=1;
	if(i==1)
	{
		ls=L->next;
		L->next=e;
		L->next->next=ls;
		printf("����ɹ���\n");return 1;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j>i)
	{
		printf("����ʧ�ܣ�\n");return 0;
	}
	e->next=p->next;
	p->next=e;
	printf("����ɹ���\n");return 1;
}

int ListDelete(LinkList &L, int i)//ɾ�� 
{
	LinkList p=L,ls;
	int j=1;
	if(i==1)
	{
		ls=L->next->next;
		L->next=ls;
		printf("ɾ���ɹ���\n");return 1;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j>i)
	{
		printf("ɾ��ʧ�ܣ�\n");return 0;
	}
	p->next=p->next->next;
	printf("ɾ���ɹ���\n");return 1;
}

void bianli(LinkList L)
{	
	LinkList ls;
	int num=0;
	ls=L;
	if(ls->next==NULL)
	{
		printf("��\n");
	}
	while(ls->next!=NULL)
	{
		printf("��%d��ѧ���� ѧ�ţ�%d ������%s �ɼ���%.2f\n",num+1,ls->next->data.ID,ls->next->data.name,ls->next->data.score);
		ls=ls->next;
		num++;
	}
	printf("����%d��ѧ����Ϣ��\n",num);
}

void prf()
{

	printf("_________________________________\n");
	printf("1. ����\n");
	printf("2. ��ȡ\n"); 
	printf("3. ����\n");
	printf("4. ����Ų���\n");
	printf("5. ����������\n");
	printf("6. ���ɼ�����\n");
	printf("7. ����\n");
	printf("8. ɾ��\n");
	printf("9. ����\n");
	printf("10. ����\n");
	printf("0. �˳�\n");
	printf("_________________________________\n");
	printf("��ѡ��");
}
	



int main()
{
	Student stu;
	LinkList L,charu;
	charu=new LNode;
	charu->next=NULL;
	int choose=-1,i=0;//i���� ,λ�� 
	char ming[20];
	float fenshu;
	while(choose!=0)
	{
		prf();
		scanf("%d",&choose);
		while(choose<0||choose>8)
		{
			printf("�����λ��\n");
			prf();
			scanf("%d",&choose);
		}
		switch(choose)
		{
			case 1:
			{
				if(InitList_L(L)==OK)
				{
					printf("�����ɹ���\n");break;
				}
				printf("����ʧ�ܣ�\n");break;
			}
			case 3:
			{
				printf("_______________����_______________\n");
				printf("������ѧ��������");
				scanf("%d",&i); 
				CreateList(L,i);break;
			}
			case 4:
			{
				printf("_______________����Ų�ѯ_______________\n");
				printf("�������ѯ��ţ�");
				scanf("%d",&i);
				if(GetElem(L,i)==0)
				{
					break;
				}
				get(GetElem(L,i));break;
			}
			case 5:
			{
				printf("_______________��������ѯ_______________\n");
				printf("������Ҫ���ҵ�������");
				scanf("%s",&ming);
				if(LocateElem_name(L, ming)==0)
				{
					break;
				}
				LocateElem_name(L, ming);break;
			}
			case 6:
			{
				printf("_______________��������ѯ_______________\n");
				printf("������Ҫ���ҵķ�����");
				scanf("%f",&fenshu);
				LocateElem_score(L, fenshu);break;
			}
			case 7:
			{
				printf("_______________����_______________\n");
				printf("�����루����λ�� ѧ�� ���� ��������");
				scanf("%d %d %s %f",&i,&stu.ID,&stu.name,&stu.score);
				charu->data=stu;
				ListInsert_Sq(L, i, charu);break;
				
			}
			case 8:
			{
				printf("_______________ɾ��_______________\n");
				printf("������Ҫɾ������ţ�\n");
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

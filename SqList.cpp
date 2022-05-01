#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef struct
{
	char no[9];   //8λѧ��
	char  name[100]; //����
	int  score;     //�ɼ�
} Student;

typedef struct
{
	Student *elem;
	int length;
} SqList;

int InitList_Sq(SqList &L)   //�㷨2.1 ˳���ĳ�ʼ��
{
	//����һ���յ�˳���L
	L.elem = new Student[MAXSIZE]; //Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem)
		return ERROR; //�洢����ʧ���˳�
	L.length = 0; //�ձ���Ϊ0
	return OK;
}

void input(SqList &L)//����
{
	int n=0,s=L.length;
	printf("������Ҫ�����ѧ����Ϣ������");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("�������%d��ѧ����Ϣ(ѧ�� ���� �ɼ�):",s+1+i);
		scanf("%s %s %d",&L.elem[s+i].no,&L.elem[s+i].name,&L.elem[s+i].score);
		L.length++;
	}

}

int  GetElem(SqList L, int i)//��˳��ȡֵ
{
	if(i>0&&i<=L.length)
	{
		printf("��%d��ͬѧ��ѧ�ţ�%s ����:%s �ɼ�:%d\n",i,L.elem[i-1].no,L.elem[i-1].name,L.elem[i-1].score);
		return OK;
	}
	return ERROR;
}

int LocateElem_name(SqList L, char e[])//����������
{
	int i=0;
	for(i; i<L.length; i++)
	{
		if(strcmp(e,L.elem[i].name) == 0)
		{
			return i+1;
		}
	}
	printf("\n%d\n",i);
	return ERROR;
}

int LocateElem_score(SqList L, int i)//���ɼ�����
{
	int b=0;
	for(int j=0; j<L.length; j++)
	{
		if(i==L.elem[j].score)
		{
			GetElem(L,j+1);
			b=1;
		}
	}
	return b;
}
int ListInsert_Sq(SqList &L, int i, Student e)//����
{
	if(i<1||i>L.length+1||i==MAXSIZE)
	{
		return ERROR;
	}
	for(int j=L.length-1; j>=i-1; j--)
	{
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	L.length++;
	return OK;
}

int ListDelete_Sq(SqList &L, int i)//ɾ��
{
	if(i<1||i>L.length)
	{
		return ERROR;
	}
	for(int j=i-1; j<=L.length; j++)
	{
		L.elem[j]=L.elem[j+1];
	}
	L.length--;
	return OK;
}

void pf()
{

	printf("_________________________________\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ����Ų���\n");
	printf("4. ����������\n");
	printf("5. ���ɼ�����\n");
	printf("6. ����\n");
	printf("7. ɾ��\n");
	printf("8. ����\n");
	printf("9. ͳ�Ƹ���\n");
	printf("10.����\n");
	printf("11.��ȡ\n");
	printf("0. �˳�\n");
	printf("_________________________________\n");
	printf("��ѡ��");
}


void bianli(SqList L)
{
	for(int i=0; i<L.length; i++)
	{
		printf("%d: %s %s %d\n",i+1,L.elem[i].no,L.elem[i].name,L.elem[i].score);
	}
}

void baocun(SqList &L)//���� 
{
	FILE *bc;
//	bc=fopen("C:\\Users\\Yang'wang\\Desktop\\���ݽṹ3.15\\˳�����Ա�\\data.txt","w+");
	
	char fname[100],a;
	int i=0;
	printf("�������ļ���:");
	scanf("%s",&fname);
	while(fname[i]!='\0')
	{
		i++;
	}
	fname[i]='.';
	fname[i+1]='t';
	fname[i+2]='x';
	fname[i+3]='t';
	fname[i+4]='\0';
	bc=fopen(fname,"w");
	for(int i=0; i<L.length; i++)
	{
		fprintf(bc,"%d: %s %s %d\n",i+1,L.elem[i].no,L.elem[i].name,L.elem[i].score);
		//if(i!=L.length-1)
	//	fprintf(bc,"\n");
	}
	fclose(bc);
	printf("����ɹ���\n");
}
int main()
{
	SqList L;
	Student e;//���� 
	int choose=-1,i=0,end=-1;//iΪ�������ֹ��ã�endΪ��������ֵ
	char chazhao[20];
	while(choose!=0)
	{
		pf();
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				break;
			case 1:
			{
				end=InitList_Sq(L);
				if(end=ERROR)
				{
					printf("����ʧ�ܣ�\n");
					break;
				}
				printf("�����ɹ���\n");
				break;
			}
			case 2:
			{
				input(L);
				printf("\n�������!\n");
				break;
			}
			case 3:
			{
				printf("��������Ҫ���ҵ�λ����");
				scanf("%d",&i);
				end=GetElem(L,i);
				if(end==ERROR)
				{
					printf("ȡֵʧ�ܣ�\n");
					break;
				}
				break;
			}
			case 4:
			{
				printf("������Ҫ���ҵ�ѧ��������");
				scanf("%s",&chazhao);
				end=LocateElem_name(L,chazhao);
				if(end==ERROR)
				{
					printf("�޴�ѧ��!\n");
					break;
				}
				GetElem(L,end);
				break;
			}
			case 5:
			{
				printf("������Ҫ���ҵĳɼ�:");
				scanf("%d",&i);
				end=LocateElem_score(L,i);
				if(end==0)
				{
					printf("�޴˳ɼ��ߣ�\n");
					break;
				}
				break;
			}
			case 6:
			{
				printf("__________________����____________________\n");
				printf("������Ҫ�����λ�ü�ѧ����Ϣ��λ�� ѧ�� ���� �ɼ���:");
				scanf("%d %s %s %d",&i,&e.no,&e.name,&e.score);
				end=ListInsert_Sq(L,i,e);
				if(end==ERROR)
				{
					printf("����ʧ��!\n");break;
				}
				printf("������ɣ�\n");break;
				printf("__________________����____________________\n");
			}
			case 7:
				{
					printf("__________________ɾ��____________________\n");
					printf("������Ҫɾ������ţ�");
					scanf("%d",&i);
					end=ListDelete_Sq(L,i);
					if(end==OK)
					{
						printf("ɾ����ɣ�\n");break;
					}
					printf("ɾ��ʧ�ܣ�\n");break;
					printf("__________________ɾ��____________________\n");
				}
			case 8:
			{
				bianli(L);
				break;
			}
			case 9:
			{
			printf("Ŀǰ����%dλѧ����Ϣ!\n",L.length);break;
			}
			case 10:
			{

				baocun(L);
				break;
			 } 
			default:
				{
					printf("������󣡣���\n");break;
				}
			
		}

	}
	return 0;
}

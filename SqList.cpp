#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef struct
{
	char no[9];   //8位学号
	char  name[100]; //姓名
	int  score;     //成绩
} Student;

typedef struct
{
	Student *elem;
	int length;
} SqList;

int InitList_Sq(SqList &L)   //算法2.1 顺序表的初始化
{
	//构造一个空的顺序表L
	L.elem = new Student[MAXSIZE]; //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
		return ERROR; //存储分配失败退出
	L.length = 0; //空表长度为0
	return OK;
}

void input(SqList &L)//输入
{
	int n=0,s=L.length;
	printf("请输入要输入的学生信息个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("请输入第%d个学生信息(学号 姓名 成绩):",s+1+i);
		scanf("%s %s %d",&L.elem[s+i].no,&L.elem[s+i].name,&L.elem[s+i].score);
		L.length++;
	}

}

int  GetElem(SqList L, int i)//按顺序取值
{
	if(i>0&&i<=L.length)
	{
		printf("第%d个同学：学号：%s 姓名:%s 成绩:%d\n",i,L.elem[i-1].no,L.elem[i-1].name,L.elem[i-1].score);
		return OK;
	}
	return ERROR;
}

int LocateElem_name(SqList L, char e[])//按姓名查找
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

int LocateElem_score(SqList L, int i)//按成绩查找
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
int ListInsert_Sq(SqList &L, int i, Student e)//插入
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

int ListDelete_Sq(SqList &L, int i)//删除
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
	printf("1. 建立\n");
	printf("2. 输入\n");
	printf("3. 按序号查找\n");
	printf("4. 按姓名查找\n");
	printf("5. 按成绩查找\n");
	printf("6. 插入\n");
	printf("7. 删除\n");
	printf("8. 遍历\n");
	printf("9. 统计个数\n");
	printf("10.保存\n");
	printf("11.读取\n");
	printf("0. 退出\n");
	printf("_________________________________\n");
	printf("请选择：");
}


void bianli(SqList L)
{
	for(int i=0; i<L.length; i++)
	{
		printf("%d: %s %s %d\n",i+1,L.elem[i].no,L.elem[i].name,L.elem[i].score);
	}
}

void baocun(SqList &L)//保存 
{
	FILE *bc;
//	bc=fopen("C:\\Users\\Yang'wang\\Desktop\\数据结构3.15\\顺序线性表\\data.txt","w+");
	
	char fname[100],a;
	int i=0;
	printf("请输入文件名:");
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
	printf("保存成功！\n");
}
int main()
{
	SqList L;
	Student e;//公用 
	int choose=-1,i=0,end=-1;//i为输入数字共用，end为函数返回值
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
					printf("建立失败！\n");
					break;
				}
				printf("建立成功！\n");
				break;
			}
			case 2:
			{
				input(L);
				printf("\n输入完毕!\n");
				break;
			}
			case 3:
			{
				printf("请输入需要查找的位数：");
				scanf("%d",&i);
				end=GetElem(L,i);
				if(end==ERROR)
				{
					printf("取值失败！\n");
					break;
				}
				break;
			}
			case 4:
			{
				printf("请输入要查找的学生姓名：");
				scanf("%s",&chazhao);
				end=LocateElem_name(L,chazhao);
				if(end==ERROR)
				{
					printf("无此学生!\n");
					break;
				}
				GetElem(L,end);
				break;
			}
			case 5:
			{
				printf("请输入要查找的成绩:");
				scanf("%d",&i);
				end=LocateElem_score(L,i);
				if(end==0)
				{
					printf("无此成绩者！\n");
					break;
				}
				break;
			}
			case 6:
			{
				printf("__________________插入____________________\n");
				printf("请输入要插入的位置及学生信息（位置 学号 姓名 成绩）:");
				scanf("%d %s %s %d",&i,&e.no,&e.name,&e.score);
				end=ListInsert_Sq(L,i,e);
				if(end==ERROR)
				{
					printf("插入失败!\n");break;
				}
				printf("插入完成！\n");break;
				printf("__________________插入____________________\n");
			}
			case 7:
				{
					printf("__________________删除____________________\n");
					printf("请输入要删除的序号：");
					scanf("%d",&i);
					end=ListDelete_Sq(L,i);
					if(end==OK)
					{
						printf("删除完成！\n");break;
					}
					printf("删除失败！\n");break;
					printf("__________________删除____________________\n");
				}
			case 8:
			{
				bianli(L);
				break;
			}
			case 9:
			{
			printf("目前共有%d位学生信息!\n",L.length);break;
			}
			case 10:
			{

				baocun(L);
				break;
			 } 
			default:
				{
					printf("输入错误！！！\n");break;
				}
			
		}

	}
	return 0;
}

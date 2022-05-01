#include <stdio.h>
#define OK 1
#define ERROR 0
#define YES 1
#define NO 0


char oper[7]={ '+', '-', '*', '/', '(', ')', '#' };

int operjb(char a)
{
	switch(a)
	{
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;	
		/*case '(':
			return 4;
		case ')':
			return 4;*/
		case '#':
			return 1;
	}
}


typedef struct Link
{
	int data;
	struct Link* NEXT;
}Link,*PLink;

int CreativeL(PLink &L)//初始化  
{
	L=new Link;
	L->data=-2;
	L->NEXT=NULL;
	return OK; 
}

int PUSH(PLink &L,PLink &e)//入栈 
{
	PLink a;
	a=L;
	while(a->NEXT!=NULL)
	{
		a=a->NEXT;
	}
	a->NEXT=e;
	e->NEXT=NULL;
}

int OUT(PLink &L,PLink &e)//出栈 
{
		PLink a;
	PLink a2;
	a=L;
	while(a->NEXT!=NULL)
	{
		if(a->NEXT->NEXT==NULL)
		{
			a2=a;
		}
		a=a->NEXT;	
	}
	e=a;
	a2->NEXT=NULL;
}

int In(char ch)//判断是否运算符 
{
	for (int i = 0; i < 7; i++) {
		if (ch == oper[i]) {
			return YES;
		}
	}
	return NO;
}

int Operate(int first,char ch,int second)
{
	switch (ch) {
	case '+':
		return first+second;
	case '-':
		return first-second;
	case '*':
		return first*second;
	case '/':
		return first/second;
	}
	return 0;
}
int rule(char ch[],PLink &s,PLink &c)
{
	int i=0,i1=0,i2,i3;
	char i4;
	while(ch[i1]!='\0')
	{
		i1++;
	}
	ch[i1+1]='#';
	ch[i1+2]='\0';
	for(i1;i1>0;i1--)
	{
		ch[i1]=ch[i1-1];
	}
	ch[0]='#';
	
	
//	printf("\n%s\n",ch);
	i=0;
	while(ch[i]!='\0')
	{	
	//	printf("\n%d\n",i);
		if(In(ch[i])!=YES && ch[i]<'0'||ch[i]>'9')
		{
			printf("\n输入错误!!!\n");
			break;
		}
		if(ch[i]>='0'&&ch[i]<='9')
		{
			if(i>0&&ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i]>='0'&&ch[i]<='9')
			{
				PLink ls;
				int n;
				OUT(s,ls);
				n=ls->data;
				ls->data=n*10+(ch[i]-'0');
				PUSH(s,ls);
			}
			else
			{
			PLink e=new Link;
			e->data=ch[i]-'0';
			PUSH(s,e);
			
			}
		}
		if(In(ch[i])==YES)
		{
			
			if(i==0)
			{
				PLink e2=new Link;
				e2->data=ch[i];
				PUSH(c,e2);//printf("\n66%c66\n",e2->data);
				i++;
				continue;
			}
		
			if(i!=0&&ch[i]=='#')
			{
				
				PLink e2;
				int end;
				OUT(c,e2);
				while(e2->data!='#')
				{
					i4=e2->data;//printf("\n%c\n",i4);
					OUT(s,e2);
					i2=e2->data;
					OUT(s,e2);
					i3=e2->data;
					e2->data=Operate(i3,i4,i2);	//printf("\n%d%c%d\n",i3,i4,i2);
					PUSH(s,e2);
				//	printf("\n66%c66\n",e2->data);
					OUT(c,e2);
				}
				OUT(s,e2);
				end=e2->data;//printf("\n%d\n",end);
				return end;
			}
		
			if(ch[i]=='(')
			{
				PLink e2=new Link;
				e2->data=ch[i];
				PUSH(c,e2);
				i++;
				continue;//printf("\n%c\n",ch[i]);
			}
			if(ch[i]==')')
			{
				PLink e2;
				int end;
				OUT(c,e2);
				while(e2->data!='(')
				{
					i4=e2->data;//printf("\n%c\n",i4);
					OUT(s,e2);
					i2=e2->data;
					OUT(s,e2);
					i3=e2->data;
					e2->data=Operate(i3,i4,i2);	//printf("\n%d%c%d\n",i3,i4,i2);
					PUSH(s,e2);
					//printf("\n66%c66\n",e2->data);
					OUT(c,e2);//printf("\n%c\n",e2->data);
				}
				i++;
				continue;
			}
			PLink e2;
			OUT(c,e2);//printf("\n%c,%c\n",e2->data,ch[i]);
			if(operjb(ch[i])>operjb(e2->data)||e2->data=='(')
			{
				PUSH(c,e2);
				PLink e3=new Link;
				e3->data=ch[i];//printf("\n%c\n",ch[i]);
				PUSH(c,e3);
				i++;
				continue;
			}
			if(operjb(ch[i])<=operjb(e2->data))
			{
				PLink e3;
				OUT(s,e3);
				i2=e3->data;//printf("\n%d\n",i2);
				OUT(s,e3);
				i3=e3->data;//printf("\n%d\n",i3);
				i4=e2->data;//printf("\n%c\n",i4); 
				e3->data=Operate(i3,i4,i2);//printf("\n%d\n",Operate(i3,i4,i2));
				PUSH(s,e3);
				e3=new Link;
				e3->data=ch[i];//printf("\n77%c77\n",e3->data);
				PUSH(c,e3);
				i++;
				continue;
			}
				
		}
		i++;
	}
	return -999;
	
}

//ջ��Ӧ��---���ʽ��ֵ(˳��ջʵ��) 
#include<bits/stdc++.h>
#define MAXSIZE 100
#define ElemType char
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SqStack;
void InitStack(SqStack *&s)
{
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(SqStack *&s)
{
	free(s);	
}
bool StackEmpty(SqStack *s)
{
	return (s->top==-1);
}
int Push(SqStack *&s,ElemType e)
{
	if(s->top==MAXSIZE-1)//ջ��
	    return 0;
	s->top++;
	s->data[s->top]=e;
	return 1; 
}
int Pop(SqStack *&s,ElemType &e)
{
	if(s->top==-1)//�ж�ջ��
	    return 0;
	e=s->data[s->top];
	s->top--;
	return 1; 
}
int GetTop(SqStack *s,ElemType &e)
{
	if(s->top==-1) 
	   return 0;
	e=s->data[s->top];
	return 1; 
} 
//----------------------
typedef struct
{
	double data[MAXSIZE];
	int top;
}SqStack1;
void InitStack1(SqStack1 *&s)
{
	s=(SqStack1*)malloc(sizeof(SqStack1));
	s->top=-1;
}
void DestroyStack1(SqStack1 *&s)
{
	free(s);	
}
bool StackEmpty1(SqStack1 *s)
{
	return (s->top==-1);
}
int Push1(SqStack1 *&s,double e)
{
	if(s->top==MAXSIZE-1)//ջ��
	    return 0;
	s->top++;
	s->data[s->top]=e;
	return 1; 
}
int Pop1(SqStack1 *&s,double &e)
{
	if(s->top==-1)//�ж�ջ��
	    return 0;
	e=s->data[s->top];
	s->top--;
	return 1; 
}
int GetTop1(SqStack1 *s,double &e)
{
	if(s->top==-1) 
	   return 0;
	e=s->data[s->top];
	return 1; 
}
//---------------------
void trans(char *exp,char postexp[])
{
	char e;
	SqStack *optr; 
	InitStack(optr);
	int i=0;//i��ʼ��Ϊpostexp���±� 
	while(*exp!='\0'){
		switch(*exp)
		{
			case '(':
				Push(optr,'(');
				exp++;
				break;
			case ')':
			    Pop(optr,e);
				while(e!='('){
					postexp[i++]=e;
					Pop(optr,e);
				}
				exp++;
				break;
			case '+':
			case '-':
			    while(!StackEmpty(optr)){
			    	GetTop(optr,e);
			    	if(e!='('){
			    		postexp[i++]=e;
			    		Pop(optr,e);
					}
					else
					 break;
				}
				Push(optr,*exp);
				exp++;
				break;
			case '*':
			case '/':
			     while(!StackEmpty(optr)){
			     	  GetTop(optr,e);
					  if(e=='*'||e=='/'){
					  	postexp[i++]=e;
					  	Pop(optr,e);
					  }
					  else break; 
				 }
				 Push(optr,*exp);
				 exp++;
				 break;
			default:
			    while(*exp>='0'&&*exp<='9'){
			    	postexp[i++]=*exp;
			    	exp++;
				}
				postexp[i++]='#';//��'#'��ʶһ�����ִ����� 
		}
	}
	while(!StackEmpty(optr)){
		Pop(optr,e);
		postexp[i++]=e;
	}
	postexp[i]='\0';//��postexp���ʽ��ӽ�����ʶ
	DestroyStack(optr); 
}
 
 
//--------------------------------

//�����׺���ʽ��ֵ 
double compvalue(char *postexp)
{
	double a,b,c,d,e;
	SqStack1 *opnd;
	InitStack1(opnd);
	while(*postexp!='\0'){
		switch(*postexp)
		{
			case '+':
				Pop1(opnd,a);
				Pop1(opnd,b);
				c=a+b;
				Push1(opnd,c);
				break;
			case '-':
				Pop1(opnd,a);
				Pop1(opnd,b);
				c=b-a;
				Push1(opnd,c);
				break;
			case '*':
				Pop1(opnd,a);
				Pop1(opnd,b);
				c=a*b;
				Push1(opnd,c);
				break;
			case '/':
				Pop1(opnd,a);
				Pop1(opnd,b);
				if(a!=0){
					c=b/a;
					Push1(opnd,c);
					break;
				}
				else{
					printf("\n\t�������!\n");
					exit(0);
				}
				break;
			default:
				d=0;
				while(*postexp>='0'&&*postexp<='9'){
					d=10*d+*postexp-'0';
					postexp++;
				}
				Push1(opnd,d);
				break;
		}
		postexp++;
	}
	GetTop1(opnd,e);
	DestroyStack1(opnd);
	return e;
}
int main()
{
	char exp[]="(56-20)/(4-2)";
	char postexp[MAXSIZE];
	trans(exp,postexp);
	printf("��׺���ʽ:%s\n",exp);
	printf("��׺���ʽ:%s\n",postexp);
	printf("���ʽ��ֵ:%g\n",compvalue(postexp));
	return 1;
} 

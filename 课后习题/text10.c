//��ĿҪ�󣺼�����ʽ�ɵ���ĸ������˫Ŀ���������
//��д��һ���㷨���������ı��ʽת�����沨��ʽ
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;


typedef struct{
    node *top;
    int size;
}stack;


stack *init(){
    stack *s;
    s=(stack *)malloc(sizeof(node));
    s->top=NULL;
    s->size=0;
    return s;
}

void push(stack *s,int val){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->next=s->top;
    s->top=p;
    s->size++;
}

int pop(stack *s){
    if(s->top==NULL){
        printf("ջ�գ��޷����г�ջ����\n");
        return 0;
    }
    node *p;
    p=s->top;
    s->top=s->top->next;
    return p->data;
}

//��ȡջ��Ԫ��
int get_top(stack *s){
    if(s->top==NULL){
        printf("��ջΪ��ջ\n");
        return -1;
    }
    return s->top->data;
}


//�ж�������������������
int is_operation(char p){
    switch(p){
        case '+':
        case '-':
        case '*':
        case '/':return 1;
        default :return 0;
    }
}



//�Ƚ�����������ȼ�
int priority(char p){
    switch(p){
        case '(':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        default :return -1;
    }
}

//ʵ�ֵĹ��ܺ���
void fun(stack *s,int data){

}



int fun(){

}



int main(){

    return 0;
}



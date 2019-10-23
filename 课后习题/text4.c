//Ҫ������ջ�Ļ������㷵��ջ��Ԫ��
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


int find_bottom(stack *s1,stack *s2){
    node *p;
    s2->top=NULL;
    while(s1->top!=NULL){
        push(s2,s1->top->data);
        pop(s1);
    }
    return s2->top->data;
}


int main(){
    stack *s1,*s2;
    int size,i,num;
    s1=init();
    s2=init();
    printf("������ջ�е�Ԫ�ظ�����\n");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&num);
        push(s1,num);
    }

    printf("ջ��Ԫ���ǣ�%d\n",find_bottom(s1,s2));
    return 0;
}




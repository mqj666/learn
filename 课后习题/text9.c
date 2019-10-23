//��ʮ����������ת��Ϊʮ��������
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char data;
    struct node *next;
}node;

typedef struct{
    node *top;
    int size;
}stack;


stack *init(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->top=NULL;
    s->size=0;
}


void push(stack *s,char data){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->next=s->top;
    s->top=p;
    s->size++;
}

char pop(stack *s){
    node *p;
    p=s->top;
    s->top=s->top->next;
    s->size--;
    return p->data;
}

//ʵ�ֽ���ת��
void convert(stack *s,int n,int r){
    int x;
    char tmp;
    while(n!=0){
        x=n%r;
        if(x<=9){
            tmp=x+48;
            push(s,tmp);
        }
        else{
            tmp=(x-10)+'A';
            push(s,tmp);
        }
        n=n/r;
    }
    printf("ת�����ʮ���������ǣ�\n");
    while(s->top!=NULL){
        printf("%c",pop(s));
    }
}

int main(){
    stack *s;
    int n,r;
    s=init();
    printf("������һ��ʮ��������\n");
    scanf("%d",&n);
    printf("������Ҫת���Ľ��ƣ�\n");
    scanf("%d",&r);
    convert(s,n,r);
    return 0;
}



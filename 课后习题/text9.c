//将十进制正整数转化为十六进制数
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

//实现进制转化
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
    printf("转换后的十六进制数是：\n");
    while(s->top!=NULL){
        printf("%c",pop(s));
    }
}

int main(){
    stack *s;
    int n,r;
    s=init();
    printf("请输入一个十进制数：\n");
    scanf("%d",&n);
    printf("请输入要转化的进制：\n");
    scanf("%d",&r);
    convert(s,n,r);
    return 0;
}



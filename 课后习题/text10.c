//题目要求：假设表达式由单字母变量和双目运算符构成
//试写出一个算法，将正常的表达式转化成逆波兰式
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
        printf("栈空，无法进行出栈操作\n");
        return 0;
    }
    node *p;
    p=s->top;
    s->top=s->top->next;
    return p->data;
}

//获取栈顶元素
int get_top(stack *s){
    if(s->top==NULL){
        printf("此栈为空栈\n");
        return -1;
    }
    return s->top->data;
}


//判断是运算符还是运算对象
int is_operation(char p){
    switch(p){
        case '+':
        case '-':
        case '*':
        case '/':return 1;
        default :return 0;
    }
}



//比较运算符的优先级
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

//实现的功能函数
void fun(stack *s,int data){

}



int fun(){

}



int main(){

    return 0;
}



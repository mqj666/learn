//题目要求：单链表中存放着N个字符，要求判断该字符串是否是回文的
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


node *init_linklist(){
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
}

stack *init_stack(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->top=NULL;
    s->size=0;
    return s;
}

node *create_linklist(int n){
    node *head,*r,*p;
    int i;
    char c;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    r=head;
    for(i=0;i<n;i++){
        p=(node *)malloc(sizeof(node));
        c=getchar();
        p->data=c;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return head;
}


void print_list(node *head){
    node *p;
    p=head->next;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}


void push(stack *s,char c){
    node *p;
    if(s==NULL){
        printf("该栈为空，不可操作\n");
        return ;
    }
    p=(node *)malloc(sizeof(node));
    p->data=c;
    p->next=s->top;
    s->top=p;
    s->size++;
}


char pop(stack *s){
    node *tmp;
    if(s==NULL||s->size==0){
        printf("该栈为空栈，无法进行操作\n");
        return '\0';
    }
    tmp=s->top;
    s->top=s->top->next;
    return tmp->data;
}




int main(){
    node *l,*tmp,*tmp1;
    stack *s;
    s=init_stack();
    int n,i;
    char stack_data,link_data;
    printf("请输入链表中的字符的个数:\n");
    scanf("%d",&n);
    getchar();    //此处的getchar()用来填补回车键
    l=create_linklist(n);
    printf("现在链表中的元素是：\n");
    print_list(l);

    //将链表中的元素赋给栈
    tmp=l->next;
    while(tmp!=NULL){
        push(s,tmp->data);
        tmp=tmp->next;
    }
    printf("成功将链表中的元素赋值给了栈\n");


    //进行字符比较
    tmp1=l->next;
    while(s->top!=NULL){
        stack_data=pop(s);
        link_data=tmp1->data;
        if(stack_data==link_data){
            tmp1=tmp1->next;
        }
        else{
            printf("该字符串不是回文\n");
            break;
        }
    }
    if(s->size==0||s->top==NULL){
        printf("该字符串是回文串\n");
    }
    printf("\n");
    return 0;
}






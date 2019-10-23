//有一个有序的单链表(从小到大)利用栈筛选出结点值大于给定值M的所有节点至栈中
//最后输出栈中的元素的名次(要求同值同名次，名次不空缺)
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
    s=(stack *)malloc(sizeof(stack));
    if(s==NULL){
        printf("创建栈失败\n");
        return NULL;
    }
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
    if(s->top==NULL||s->size==0){
        printf("栈空，无法进行出栈操作\n");
        return 0;
    }
    node *p;
    p=(node *)malloc(sizeof(node));
    p=s->top;
    s->top=s->top->next;
    return p->data;
}


node *create_list(int size){
    node *head,*s,*r;
    int i;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    r=head;
    for(i=0;i<size;i++){
        s=(node *)malloc(sizeof(node));
        scanf("%d",&s->data);
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return head;
}


void print_list(node *head){
    node *p;
    p=head->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


void fun(stack *s,node *head,int m){
    node *p;
    int data1,data2,count=1;
    p=head->next;
    while(p!=NULL){
        if(p->data>m){
            push(s,p->data);
        }
        p=p->next;
    }
    printf("排完序后的结果是：\n");
    while(s->top!=NULL){
        data1=pop(s);
        data2=pop(s);
        if(data1==data2){
            printf("名次为%d的数值是：%d\n",count,data1);
            printf("名次为%d的数值是：%d\n",count,data2);
        }
        else{
            printf("名次为%d的数值是：%d\n",count,data1);
            count++;
            printf("名次为%d的数值是：%d\n",count,data2);
        }
    }
}


int main(){
    node *la,*p;
    stack *s;
    s=init();
    int size,m;
    printf("请输入链表中的元素个数：\n");
    scanf("%d",&size);
    la=create_list(size);
    printf("现在查看该链表是：\n");
    print_list(la);


    printf("请输入定值M的数值：\n");
    scanf("%d",&m);
    fun(s,la,m);

    return 0;
}




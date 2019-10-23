//��һ����ͷ���ĵ�����������ջ�����нڵ�����
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


node *init_linklist(){
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
}

stack *init(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    if(s==NULL){
        printf("��������ʧ��\n");
    }
    s->top=NULL;
    s->size=0;
    return s;
}

//��ջ
void push(stack *s,int data){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->next=s->top;
    s->top=p;
    s->size++;
}


int pop(stack *s){
    node *tmp;
    tmp=(node *)malloc(sizeof(node));
    if(s==NULL){
        printf("��ջΪ�գ��޷����г�ջ����\n");
        return 0;
    }
    tmp=s->top;
    s->top=s->top->next;
    return tmp->data;
}



node *create_linklist(int n){
    node *head,*r,*p;
    int i,val;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    r=head;
    for(i=0;i<n;i++){
        p=(node *)malloc(sizeof(node));
        scanf("%d",&val);
        p->data=val;
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
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isempty(stack *s){
    if(s->top==NULL||s->size==0){
        return 1;
    }
    return 0;
}



//�������е�ÿһ���ڵ��Ԫ�ظ���ջ
node *fun(stack *s,node *head){
    node *tmp,*r;
    r=head;
    tmp=head->next;
    while(tmp!=NULL){
       push(s,tmp->data);
       tmp=tmp->next;
    }
    //β�巨����
    while(s->top!=NULL){
        r->next=s->top;
        r=s->top;
        pop(s);
    }
    return head;
}



int main(){
    stack *s;
    int n,i;
    node *head,*la;
    head=init_linklist();
    printf("������������Ԫ�صĸ����ǣ�\n");
    scanf("%d",&n);
    head=create_linklist(n);
    printf("���������е�Ԫ���ǣ�\n");
    print_list(head);

    s=init();
    if(isempty(s)){
        printf("ջ�ѿ�\n");
    }
    printf("ִ�й���Ӧ�ĺ����������Ϊ��\n");
    la=fun(s,head);
    print_list(la);
    return 0;
}



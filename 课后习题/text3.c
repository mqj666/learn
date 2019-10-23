//��һ������ĵ�����(��С����)����ջɸѡ�����ֵ���ڸ���ֵM�����нڵ���ջ��
//������ջ�е�Ԫ�ص�����(Ҫ��ֵͬͬ���Σ����β���ȱ)
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
        printf("����ջʧ��\n");
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
        printf("ջ�գ��޷����г�ջ����\n");
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
    printf("�������Ľ���ǣ�\n");
    while(s->top!=NULL){
        data1=pop(s);
        data2=pop(s);
        if(data1==data2){
            printf("����Ϊ%d����ֵ�ǣ�%d\n",count,data1);
            printf("����Ϊ%d����ֵ�ǣ�%d\n",count,data2);
        }
        else{
            printf("����Ϊ%d����ֵ�ǣ�%d\n",count,data1);
            count++;
            printf("����Ϊ%d����ֵ�ǣ�%d\n",count,data2);
        }
    }
}


int main(){
    node *la,*p;
    stack *s;
    s=init();
    int size,m;
    printf("�����������е�Ԫ�ظ�����\n");
    scanf("%d",&size);
    la=create_list(size);
    printf("���ڲ鿴�������ǣ�\n");
    print_list(la);


    printf("�����붨ֵM����ֵ��\n");
    scanf("%d",&m);
    fun(s,la,m);

    return 0;
}




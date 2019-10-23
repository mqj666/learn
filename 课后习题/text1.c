//��ĿҪ�󣺵������д����N���ַ���Ҫ���жϸ��ַ����Ƿ��ǻ��ĵ�
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
        printf("��ջΪ�գ����ɲ���\n");
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
        printf("��ջΪ��ջ���޷����в���\n");
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
    printf("�����������е��ַ��ĸ���:\n");
    scanf("%d",&n);
    getchar();    //�˴���getchar()������س���
    l=create_linklist(n);
    printf("���������е�Ԫ���ǣ�\n");
    print_list(l);

    //�������е�Ԫ�ظ���ջ
    tmp=l->next;
    while(tmp!=NULL){
        push(s,tmp->data);
        tmp=tmp->next;
    }
    printf("�ɹ��������е�Ԫ�ظ�ֵ����ջ\n");


    //�����ַ��Ƚ�
    tmp1=l->next;
    while(s->top!=NULL){
        stack_data=pop(s);
        link_data=tmp1->data;
        if(stack_data==link_data){
            tmp1=tmp1->next;
        }
        else{
            printf("���ַ������ǻ���\n");
            break;
        }
    }
    if(s->size==0||s->top==NULL){
        printf("���ַ����ǻ��Ĵ�\n");
    }
    printf("\n");
    return 0;
}






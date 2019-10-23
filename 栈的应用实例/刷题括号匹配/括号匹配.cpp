#include<bits/stdc++.h>

typedef struct node{
    char data;
    struct node *next;
}node;

typedef struct stack{
    node *top;
    int size;
}stack;


stack* init(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->top=NULL;
    s->size=0;
    return s;
}

void push(stack *s,char val){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->next=s->top;
    s->top=p;
    s->size++;
}

char pop(stack *s){
    node *p;
    p=(node *)malloc(sizeof(node));
    p=s->top;
    s->top=s->top->next;
    return p->data;
}

//ע���п�����
int isempty(stack *s){
    if(s->top==NULL){
        return 1;
    }
    return 0;
}




//����ƥ������
int is_correct(char str[]){
    stack *s;
    s=init();
    int i,flag=1;
    for(i=0;str[i]!='\0';i++){
        switch(str[i]){
            case '(':
            case '[':
            case '{':push(s,str[i]);break;
            case ')':if(s->size==0){
                        printf("������)����\n");
                        flag=0;
                     }
                     else{
                        char tmp=pop(s);
                        if(tmp!='('){
                            printf("ȡ��������������Ų�ƥ��\n");
                            flag=0;
                        }
                     }
                     break;
            case ']':if(s->size==0){
                        printf("������]����\n");
                        flag=0;
                     }
                     else{
                        char tmp=pop(s);
                        if(tmp!='['){
                            printf("ȡ��������������Ų�ƥ��\n");
                            flag=0;
                        }
                     }
                     break;
            case '}':if(s->size==0){
                        printf("������{����\n");
                        flag=0;
                     }
                     else{
                        char tmp=pop(s);
                        if(tmp!='{'){
                            printf("ȡ��������������Ų�ƥ��\n");
                            flag=0;
                        }
                     }
                     break;
        }
        if(flag==0){
            printf("���ַ��������Ų�ƥ��\n");
            break;
        }
    }
    if(flag==1&&s->top==NULL){
        printf("������ȫƥ��\n");
        return 1;
    }
    else
        return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    char ch[100];
    while(n--){
        scanf("%s",ch);
        if(is_correct(ch)){
            printf("Yes\n");
        }
        else
            printf("No\n");
    }

}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node *next;
}node;

typedef struct node_double{
    double data;
    struct node_double *next;
}node_double;


typedef struct stack_char{
    node *top;
    int size;
}stack_char;


typedef struct stack_double{
    node_double *top;
    int size;
}stack_double;



stack_char *init(){
    stack_char *s;
    s=(stack_char *)malloc(sizeof(stack_char));
    if(s==NULL){
        printf("创建栈失败\n");
        return NULL;
    }
    s->top=NULL;
    s->size=0;
    return s;
}


stack_double *init_dou(){
    stack_double *s;
    s=(stack_double *)malloc(sizeof(stack_double));
    if(s==NULL){
        printf("创建栈失败\n");
        return NULL;
    }
    s->top=NULL;
    s->size=0;
    return s;
}


void push(stack_char *s,char val){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->next=s->top;
    s->top=p;
    s->size++;
}


void push_dou(stack_double *s,double val){
    node_double *p;
    p=(node_double *)malloc(sizeof(node_double));
    p->data=val;
    p->next=s->top;
    s->top=p;
    s->size++;
}


char pop(stack_char *s){
    node *p;
    if(s->size==0){
        printf("栈空，无元素出栈\n");
        return NULL;
    }
    p=(node *)malloc(sizeof(node));
    p=s->top;
    s->top=p->next;
    s->size--;
    return p->data;
}



double pop_dou(stack_double *s){
    node_double *p;
    if(s->size==0){
        printf("找空，无元素出栈\n");
        return -10000;
    }
    p=(node_double *)malloc(sizeof(node_double));
    p=s->top;
    s->top=p->next;
    s->size--;
    return p->data;
}


//获取二维数组的下标
int get_index(char s){
    switch(s){
        case '+':return 0;
        case '-':return 1;
        case '*':return 2;
        case '/':return 3;
        case '(':return 4;
        case ')':return 5;
        case '#':return 6;
        default :return -1;
    }
}



//比较运算符的优先级
char get_priority(char s1,char s2){
    const char priority[][7]=
    {
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}
    };
    int i,j;
    i=get_index(s1);
    j=get_index(s2);
    return priority[i][j];
}



double get_result(stack_char *sc,stack_double *sd){
    int count=0;
    char c,tmp;
    double a,b;
    sc->size=0;
    sd->size=0;
    push(sc,'#');
    c=getchar();
    while(c!='#'){
        if(c>='0'&&c<='9'){
            if(count==1){
                double t=pop_dou(sd);
                push_dou(sd,t*10+(c-'0'));
                count=0;
            }
            else{
                push_dou(sd,c-'0');
                count++;
            }
            c=getchar();
        }
        else{         //说明是字符了
            count=0;
            tmp=pop(sc);
            switch(get_priority(tmp,c)){
                case '<':push(sc,c);c=getchar();break;
                case '=':pop(sc);c=getchar();break;
                case '>':a=pop_dou(sd);b=pop_dou(sd);tmp=pop(sc);
                        switch(tmp){
                            case '+':push_dou(sd,b+a);break;
                            case '-':push_dou(sd,b-a);break;
                            case '*':push_dou(sd,b*a);break;
                            case '/':push_dou(sd,b/a);break;
                            default :break;
                        }
                        break;
                default :break;
            }
        }
    }
    return pop_dou(sd);
}



int main(){
    int size;
    double result;
    printf("请输入要求得的表达式的个数:\n");
    scanf("%d",&size);
    while(size--){
        stack_char *sc=init();
        stack_double *sd=init_dou();
        result=get_result(sc,sd);
        printf("计算后的结果是：%lf\n",result);
    }
    return 0;
}





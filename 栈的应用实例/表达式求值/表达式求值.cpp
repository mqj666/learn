#include<bits/stdc++.h>
using namespace std;

stack<char> opter;
stack<double> opval;


//��ȡ�Ƚϵ������ַ��������ά���������
int get_index(char theta){
    int index=0;
    switch(theta){
        case '+': index=0;break;
        case '-': index=1;break;
        case '*': index=2;break;
        case '/': index=3;break;
        case '(': index=4;break;
        case ')': index=5;break;
        case '#': index=6;break;
        default:break;
    }
    return index;
}


//�Ƚ������ַ������ȼ�
char get_priority(char theta1,char theta2){
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
    int index1=0,index2=0;
    index1=get_index(theta1);
    index2=get_index(theta2);
    return priority[index1][index2];
}


//����������
double calculate(double b,double a,char theta){
    switch(theta){
        case '+':return b+a;
        case '-':return b-a;
        case '*':return b*a;
        case '/':return b/a;
        default :break;
    }
}

//���ʽ��ֵ
double getanswer(){
    opter.push('#');
    int count1=0;
    char c=getchar();
    while(c!='#'||opter.top()!='#'){
        if(c>='0'&&c<='9'){
            if(count1==1){
                double t=opval.top();
                opval.pop();
                opval.push(t*10+(c-'0'));
                count1=0;
            }
            else{
                opval.push(c-'0');
                count1++;
            }
            c=getchar();
        }
        else{
            count1=0;
            switch(get_priority(opter.top(),c)){
                case '<':opter.push(c);
                         c=getchar();
                         break;
                case '=':opter.pop();c=getchar();break;
                case '>':char theta=opter.top();
                         opter.pop();
                         double a=opval.top();
                         opval.pop();
                         double b=opval.top();
                         opval.pop();
                         opval.push(calculate(b,a,theta));
                         break;
            }
        }
    }
    return opval.top();
}



int main(){
    int t;  //��ʾ��Ҫ����ı��ʽ�ĸ���
    cout<<"������Ҫ����ı��ʽ�ĸ�����"<<endl;
    cin>>t;
    getchar();
    cout<<"������һ�����ʽ��(ע��Ҫ��ĩβ����#��ʾ�������)"<<endl;
    while(t--){
        while(!opter.empty())
            opter.pop();
        while(!opval.empty()){
            opval.pop();
        }
        double ans=getanswer();
        cout<<ans<<endl;
        getchar();
    }
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

stack<char> opter;
stack<double> opval;


//获取比较的两个字符再这个二维数组的索引
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


//比较两个字符的优先级
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


//计算两个数
double calculate(double b,double a,char theta){
    switch(theta){
        case '+':return b+a;
        case '-':return b-a;
        case '*':return b*a;
        case '/':return b/a;
        default :break;
    }
}

//表达式求值
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
    int t;  //表示需要计算的表达式的个数
    cout<<"请输入要计算的表达式的个数："<<endl;
    cin>>t;
    getchar();
    cout<<"请输入一个表达式：(注意要在末尾输入#表示输入结束)"<<endl;
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



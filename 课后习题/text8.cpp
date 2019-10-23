#include<bits/stdc++.h>
using namespace std;

//µİ¹éËã·¨
/*
long akm(int m,int n){
    long int tmp;
    if(m==0){
        return n+1;
    }
    else if(m!=0&&n==0){
        return akm(m-1,1);
    }
    else{
        tmp=akm(m,n-1);
        return akm(m-1,tmp);
    }
}
*/


//·Çµİ¹éËã·¨
int akm(int m,int n){
    stack<int> s1,s2;
    int res,flag=0;
    while(1){
        while(m&&n){
            s1.push(m-1);
            s2.push(1000);

            s1.push(m);
            s2.push(--n);
        }
        while(m&&!n){
            n=1;
            s1.push(--m);
            s2.push(n);
        }
        while(!m){
            res=s2.top()+1;
            while(!s1.empty()&&s2.top()!=1000){
                s1.pop();
                s2.pop();
            }
            if(s2.empty()){
                flag=1;
                break;
            }
            s2.pop();
            s2.push(res);
            m=s1.top();
            n=s2.top();
        }
        if(flag){
            break;
        }
    }
    return res;
}



int main(){
    int m,n;
    cin>>m>>n;
    cout<<akm(m,n)<<endl;
    return 0;
}






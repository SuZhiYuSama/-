#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	string a;
	int b[100000]={0},i=0,m,n=0;
	stack<int>stk;
	cin>>a;
	while(a[i]!='\0'){
		if(a[i]=='('||a[i]=='['||a[i]=='{'||a[i]==')'||a[i]==']'||a[i]=='}')
			b[i]=a[i];
		i++;
	}
	m=i,i=0;
	for(i=0;i<=m;i++)if(b[i]!=0)b[n]=b[i],n++;
	i=0;
	while(b[i]!=0){
		if(b[i]==40||b[i]==91||b[i]==123)
			stk.push(b[i]);
		else if(b[i]==41||b[i]==93||b[i]==125){
			if(stk.empty()){cout<<"Match false!"<<endl;return 1;}
			if(stk.top()==b[i]-1||stk.top()==b[i]-2)
				stk.pop();
			else {
				cout<<"Match false!"<<endl;return 1;
			}
		}
		i++;
	}
	if(stk.empty())cout<<"Match succeed!"<<endl;
	else cout<<"Match false!"<<endl;
	return 0;
}

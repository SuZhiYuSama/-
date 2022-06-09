#include<bits/stdc++.h>
using namespace std;
int a[131072]={0};
int main(){
	int n,k,m,out=0,num=1,i=0,b=1;
	scanf("%d,%d,%d",&n,&k,&m);
	if(n<0||k<0){
		cout<<"n,m,k must bigger than 0."<<endl;
		return 1;
	}
	else if(m<0)
	{
		cout<<"n,m,k must bigger than 0."<<endl;
		return 1;
	 } 
	if(k>n){
		cout<<"k should not bigger than n."<<endl;
		return 1;
	}
	i=k-1,num=k;
	while(out!=n){
		if(a[i]==0){
			if(b==m){
				a[i]=1;
				cout<<num;
				out++;
				if(out%10==0)cout<<endl;
				else cout<<" ";
				b=0;
			}
			b++;
		}
		if(num==n){
			i=0,num=1;
			continue;
		}
		i++,num++;
	}
	cout<<endl;
	return 0;
}

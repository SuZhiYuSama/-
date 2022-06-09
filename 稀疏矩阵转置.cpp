#include<iostream>
#include<cstdio>
using namespace std;
void CoutArry(int x[],int size);
int main(){
	int i=0,j=0,n=0,change;
	scanf("%d %d %d",&i,&j,&n);
	int a[i][j]={0},aZip[3][n]={0},num[i]={0},cpot[i]={1};
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			cin>>aZip[x][y];
			if(y==1)num[aZip[x][y]-1]++;
		}
	}
	cout<<"num=";
	CoutArry(num,i);
	for(int y=0;y<j;y++)cpot[y]=cpot[y-1]+num[y-1]+1;
	for(int y=0;y<n;y++)change=aZip[0][y],aZip[0][y]=aZip[1][y],aZip[1][y]=change;
	cout<<"copt=";
	CoutArry(cpot,i);
/* 	for(int y=0;y<n;y++){
		for(int x=0;x<2;x++){
			cout<<aZip[x][y]<<" ";
		}
		cout<<aZip[2][y]<<endl;
	}*/
	return 0;
}
void CoutArry(int x[],int size){
	for(int i=0;i<size;i++)cout<<x[i]<<",";
	cout<<endl;
}

#include<iostream>
#include<stdio.h>
using namespace std;
const int MaxSize=1000;
typedef struct HeadNode{
	char name;
	BehindNode *sonp;
};
typedef struct BehindNode{
	char name;
	BehindNode *nextp;
};
int main(){
	int adj[MaxSize][2]={0};
	HeadNode HNode[MaxSize];
	for(int i=0;i<MaxSize;i++)HNode
	return 0;
}

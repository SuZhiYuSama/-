#include<iostream>
#include<stdio.h>
using namespace std;
#define RIGHT 1024
const int MaxSize=100;
typedef int EdgeRightType;
typedef char NodeType;
int visited[MaxSize];
class Graph{
	public:
		Graph(){NodeNum=0;EdgeNum=0;}
		Graph(NodeType a[],int n);
		void CreateGraph(Graph *Gp);
		void BFS(int v);
	public:
		int NodeNum,EdgeNum;
		EdgeRightType adj[MaxSize][MaxSize];
		NodeType Node[MaxSize];
};
Graph::Graph(NodeType a[],int n){
	NodeNum=0;EdgeNum=0;
	for(int i=0;i<n;i++)Node[i]=a[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adj[i][j]=0;
}
void Graph::CreateGraph(Graph *Gp){
	int i=0;
	char chr;
	EdgeRightType edge[MaxSize][2];
	for(int i1=0;i1<MaxSize;i1++)Gp->Node[i1]='0';
	while(1){
		scanf("%c",&chr);
		if(chr=='*')break;
		else {Gp->Node[i]=chr;i++;}
	}
	Gp->NodeNum=i-6;i=0;
	for(int i1=0;i1<MaxSize;i1++)
		for(int j=0;j<2;j++)
			edge[i1][j]=-2;
	while(1){
		scanf("%d,%d",&edge[i][0],&edge[i][1]);
		if(edge[i][0]==-1)break;
		i++;
	}
	EdgeNum=i;i=0;
	for(int i1=0;i1<Gp->NodeNum;i1++)
		for(int j=0;j<Gp->NodeNum;j++)
			Gp->adj[i1][j]=0;
	for(int i1=0;i1<Gp->EdgeNum;i1++){
		Gp->adj[edge[i1][0]][edge[i1][1]]=1;
		Gp->adj[edge[i1][1]][edge[i1][0]]=1;
	}
	for(int i1=0;i1<Gp->NodeNum;i1++){
		for(int j=0;j<Gp->NodeNum;j++){
			cout<<Gp->adj[i1][j]<<" ";
		}
		cout<<endl;
	}
}
void Graph::BFS(int v){
	int tQ[NodeNum],ntQ[NodeNum]={0},itQ=0,intQ=0,flag=0,counter=0;
	for(int i1=0;i1<NodeNum;i1++)tQ[NodeNum]=-1;
	char chr;
	tQ[0]=v;
	cout<<Node[v];
	visited[v]=1;
	while(1){
		while(tQ[itQ]+1){
			for(int i1=0;i1<NodeNum;i1++){
				if(adj[i1][tQ[itQ]]!=0){
					chr=i1+97;
					cout<<chr;
					visited[i1]=1;
					ntQ[intQ]=i1;
					intQ++;
				}
			}
			itQ++;
		}
		for(int i1=0;i1<20;i1++)tQ[i1]=0;
		itQ=0;
		for(int i1=0;i1<intQ;i1++){
			if(visited[ntQ[i1]]==0){
			tQ[itQ]=ntQ[i1];
			itQ++;
			}
		}
		for(int i1=0;i1<20;i1++)ntQ[i1]=0;
		flag=0;
		for(int i1=0;i1<NodeNum;i1++){
			if(visited[i1]==1)flag++;
			if(flag==NodeNum)return ;
		}
	}
}
int main(){
	Graph graph;
	char chr;
	graph.CreateGraph(&graph);
	for(int i1=0;i1<MaxSize;i1++)visited[i1]=0;
	for(int i1=0;i1<graph.NodeNum;i1++){
		chr=i1+97;
		cout<<chr;
		for(int j=graph.NodeNum-1;j>=0;j--){
			if(graph.adj[i1][j]==1)cout<<" "<<j;
		}
		cout<<endl;
	}
	cout<<"the Breadth-First-Seacrh list:";
	graph.BFS(0);
	cout<<endl;
	return 0;
}

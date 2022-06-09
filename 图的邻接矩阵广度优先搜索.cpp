#include <iostream>
using namespace std;
#define INFINITY  65535 /* 表示权值的无穷*/
typedef int EdgeType;//边上的权值类型
typedef int VertexType;//顶点类型
const int MaxSize=100;
int visited[MaxSize];//全局标识数组
 
class MGraph//邻接矩阵类
{
    public:
        MGraph(){vertexNum=0;edgeNum=0;}
        MGraph(VertexType a[],int n);//构造函数，初始化具有n个顶点的零图
        void CreateMGraph1(MGraph *Gp);//建立无向图的邻接矩阵
        void BFS(int v);//从v出发广度优先遍历
    public:
        int vertexNum,edgeNum;//顶点数和边数
        EdgeType adj[MaxSize][MaxSize];//邻接矩阵
        VertexType vertex[MaxSize];//顶点表
};
//构造函数，初始化具有n个顶点的零图
MGraph::MGraph(VertexType a[],int n)
{
    vertexNum=n;edgeNum=0;
    for(int i=0;i<n;i++) vertex[i]=a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;
}
 
//建立无向图的邻接矩阵表示
void MGraph::CreateMGraph1(MGraph *Gp)
{
    int i, j, k;
    cout << "请输入顶点数和边数（空格分隔）：" << endl;
    cin >> Gp->vertexNum >> Gp->edgeNum;
    cout << "请输入顶点信息（空格分隔）：" << endl;
    for (i = 0; i < Gp->vertexNum; i++)
        cin >> Gp->vertex[i];
    for (i = 0; i < Gp->vertexNum; i++)
    {
        for (j = 0; j < Gp->vertexNum; j++)
            Gp->adj[i][j] = 0;
    }
    for (k = 0; k < Gp->edgeNum; k++)
    {
        cout << "请输入边（vi, vj)的上标i，下标j（空格分隔）:" << endl;
        cin >> i >> j;
        Gp->adj[i][j] = 1;
        Gp->adj[j][i] = 1;// 因为是无向图，矩阵对称
    }
}
//从v出发广度优先搜索遍历连通图
void MGraph::BFS(int v)
{
    int n=vertexNum,front,rear;
    int Q[MaxSize];//队列
    front=rear=-1;
    if(v<0||v>=n) throw "位置出错";
    cout<<vertex[v]<<"　";
    visited[v]=1;
    Q[++rear]=v;//被访问过的顶点进入队列
    while(front!=rear)
    {
        v=Q[++front];//队列首元素出队列
        for(int j=0;j<n;j++)
        {
            if(adj[v][j]==1&&visited[j]==0)
            {
                cout<<vertex[j]<<" ";
                visited[j]=1;
                Q[++rear]=j;
            }
        }
    }
}
int main()
{
    MGraph grph;
    grph.CreateMGraph1(&grph);
    for(int i=0;i<MaxSize;i++)
        visited[i]=0;
    for(int i=0;i<grph.vertexNum;i++)
    {
        for(int j=0;j<grph.vertexNum;j++)
            {cout<<grph.adj[i][j]<<" ";}
        cout<<endl;
    }
    cout<<"广度优先遍历结果："<<endl;
    grph.BFS(2);
    return 0;
}

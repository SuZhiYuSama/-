#include <iostream>
using namespace std;
#define INFINITY  65535 /* ��ʾȨֵ������*/
typedef int EdgeType;//���ϵ�Ȩֵ����
typedef int VertexType;//��������
const int MaxSize=100;
int visited[MaxSize];//ȫ�ֱ�ʶ����
 
class MGraph//�ڽӾ�����
{
    public:
        MGraph(){vertexNum=0;edgeNum=0;}
        MGraph(VertexType a[],int n);//���캯������ʼ������n���������ͼ
        void CreateMGraph1(MGraph *Gp);//��������ͼ���ڽӾ���
        void BFS(int v);//��v����������ȱ���
    public:
        int vertexNum,edgeNum;//�������ͱ���
        EdgeType adj[MaxSize][MaxSize];//�ڽӾ���
        VertexType vertex[MaxSize];//�����
};
//���캯������ʼ������n���������ͼ
MGraph::MGraph(VertexType a[],int n)
{
    vertexNum=n;edgeNum=0;
    for(int i=0;i<n;i++) vertex[i]=a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;
}
 
//��������ͼ���ڽӾ����ʾ
void MGraph::CreateMGraph1(MGraph *Gp)
{
    int i, j, k;
    cout << "�����붥�����ͱ������ո�ָ�����" << endl;
    cin >> Gp->vertexNum >> Gp->edgeNum;
    cout << "�����붥����Ϣ���ո�ָ�����" << endl;
    for (i = 0; i < Gp->vertexNum; i++)
        cin >> Gp->vertex[i];
    for (i = 0; i < Gp->vertexNum; i++)
    {
        for (j = 0; j < Gp->vertexNum; j++)
            Gp->adj[i][j] = 0;
    }
    for (k = 0; k < Gp->edgeNum; k++)
    {
        cout << "������ߣ�vi, vj)���ϱ�i���±�j���ո�ָ���:" << endl;
        cin >> i >> j;
        Gp->adj[i][j] = 1;
        Gp->adj[j][i] = 1;// ��Ϊ������ͼ������Գ�
    }
}
//��v���������������������ͨͼ
void MGraph::BFS(int v)
{
    int n=vertexNum,front,rear;
    int Q[MaxSize];//����
    front=rear=-1;
    if(v<0||v>=n) throw "λ�ó���";
    cout<<vertex[v]<<"��";
    visited[v]=1;
    Q[++rear]=v;//�����ʹ��Ķ���������
    while(front!=rear)
    {
        v=Q[++front];//������Ԫ�س�����
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
    cout<<"������ȱ��������"<<endl;
    grph.BFS(2);
    return 0;
}

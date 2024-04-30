#define MGraph_H
#include <iostream>
#include <iomanip>
using namespace std;
#define MaxSize 30
#define INFINITYN 65536   //表示权值无限大
 
struct shortEdge                    //辅助数组
{
    int lowcost;
    int adjvex;
};
 
template <class DataType>
class MGraph
{
private:
    DataType vertex[MaxSize];       //存放顶点的数组
    int arcs[MaxSize][MaxSize];     //存放图中边的数组
    int versNum, arcsNum;           //定点数和边数
    shortEdge shortEdge[MaxSize];
    
public:
    MGraph();                       //初始化邻接矩阵
    ~MGraph(){}
    void CreateMGraph();			//输出邻接矩阵 
    void printMGraph();
    void Prim();                    //Prim算法生成最小生成树
};
 
template <class DataType>
MGraph<DataType>::MGraph()
{
    cout << "请输入顶点数和边数:" << endl;
    cin >> versNum >> arcsNum;
    cout << "请输入顶点字符信息(" << versNum << "个):" << endl;
    for (int i = 0; i < versNum; i++)
    {
        cin >> vertex[i];
    }
    for (int i = 0; i < versNum; i++)
    {
        for (int j = 0; j < versNum; j++)
        {
            if (i == j)
                arcs[i][j] = 0;
            else
                arcs[i][j] = INFINITYN;
        }
    }
}
 
template <class DataType>
void MGraph<DataType>::CreateMGraph()
{
    int i, j, w;
    cout << "请输入边<Vi,Vj>对应的顶点序号(" << arcsNum << "对)，以及权值:" << endl;
    for (int k = 0; k < arcsNum; k++)
    {
        cin >> i >> j >> w;
        arcs[i][j] = w;
        arcs[j][i] = w;
    }
}
 
template <class DataType>
void MGraph<DataType>::printMGraph()
{
    cout << "邻接矩阵为:" << endl;
    for (int i = 0; i < versNum; i++)
    {
        for (int j = 0; j < versNum; j++)
        {
            if (arcs[i][j] == 65536)
                cout <<"  "<< setw(5) << "∞";
            else
                cout << setw(5) << arcs[i][j];
        }
        cout << endl;
        cout << endl;
    }
}
 
template <class DataType>
void MGraph<DataType>::Prim()
{
    int k, w, cost = 0;
    for (int i = 1; i < versNum; i++)
    {
        shortEdge[i].lowcost = arcs[0][i];
        shortEdge[i].adjvex = 0;
    }
    shortEdge[0].lowcost = 0;
    for (int i = 1; i < versNum; i++)
    {
        w = INFINITYN;
        for (int j = 1; j < versNum; j++)/* 在辅助数组closedge中选择权值最小的顶点*/
        {
            if (shortEdge[j].lowcost != 0 && shortEdge[j].lowcost < w)
            {
                w = shortEdge[j].lowcost;
                k = j;
            }    /* 求出生成树的下一个顶点k */
        }
        shortEdge[k].lowcost = 0;
        for (int j = 1; j < versNum; j++)
        {
            if (arcs[k][j] < shortEdge[j].lowcost) {
                shortEdge[j].lowcost = arcs[k][j];
                shortEdge[j].adjvex = k;
            }
        }
    }
    cout << "最小生成树为:" << endl;
    for (int i = 1; i < versNum; i++)
    {
        cout << i << "->" << shortEdge[i].adjvex << "," << arcs[i][shortEdge[i].adjvex] << endl;
        cost = cost + arcs[i][shortEdge[i].adjvex];
    }
    cout << "最小生成树代价为:" << cost << endl;
}
int main()  
{  
    MGraph<int> m1;  
    m1.CreateMGraph();  
    m1.printMGraph();  
    m1.Prim();  
}  

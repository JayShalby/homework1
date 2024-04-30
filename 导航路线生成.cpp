#define MGraph_H
#include <iostream>
#include <iomanip>
using namespace std;
#define MaxSize 30
#define INFINITYN 65536   //��ʾȨֵ���޴�
 
struct shortEdge                    //��������
{
    int lowcost;
    int adjvex;
};
 
template <class DataType>
class MGraph
{
private:
    DataType vertex[MaxSize];       //��Ŷ��������
    int arcs[MaxSize][MaxSize];     //���ͼ�бߵ�����
    int versNum, arcsNum;           //�������ͱ���
    shortEdge shortEdge[MaxSize];
    
public:
    MGraph();                       //��ʼ���ڽӾ���
    ~MGraph(){}
    void CreateMGraph();			//����ڽӾ��� 
    void printMGraph();
    void Prim();                    //Prim�㷨������С������
};
 
template <class DataType>
MGraph<DataType>::MGraph()
{
    cout << "�����붥�����ͱ���:" << endl;
    cin >> versNum >> arcsNum;
    cout << "�����붥���ַ���Ϣ(" << versNum << "��):" << endl;
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
    cout << "�������<Vi,Vj>��Ӧ�Ķ������(" << arcsNum << "��)���Լ�Ȩֵ:" << endl;
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
    cout << "�ڽӾ���Ϊ:" << endl;
    for (int i = 0; i < versNum; i++)
    {
        for (int j = 0; j < versNum; j++)
        {
            if (arcs[i][j] == 65536)
                cout <<"  "<< setw(5) << "��";
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
        for (int j = 1; j < versNum; j++)/* �ڸ�������closedge��ѡ��Ȩֵ��С�Ķ���*/
        {
            if (shortEdge[j].lowcost != 0 && shortEdge[j].lowcost < w)
            {
                w = shortEdge[j].lowcost;
                k = j;
            }    /* �������������һ������k */
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
    cout << "��С������Ϊ:" << endl;
    for (int i = 1; i < versNum; i++)
    {
        cout << i << "->" << shortEdge[i].adjvex << "," << arcs[i][shortEdge[i].adjvex] << endl;
        cost = cost + arcs[i][shortEdge[i].adjvex];
    }
    cout << "��С����������Ϊ:" << cost << endl;
}
int main()  
{  
    MGraph<int> m1;  
    m1.CreateMGraph();  
    m1.printMGraph();  
    m1.Prim();  
}  

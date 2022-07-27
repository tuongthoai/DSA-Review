#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// Kiểm tra một phần tử x có nằm trong tập s hay không?
#define In(x, s) (find((s).begin(), (s).end(), (x)) != (s).end())
// Duyệt tuần tự các phần tử của tập s với px là con trỏ tới phần tử hiện hành
#define Foreach(px, s) for (px = (s).begin(); px != (s).end(); px++)
typedef string TVertex;
typedef pair<TVertex, TVertex> TEdge;
typedef vector<TVertex>::iterator iTVertex;
typedef vector<TEdge>::iterator iTEdge;

struct Graph
{
    string m_kind;
    vector<TVertex> m_vertexes;
    vector<TEdge> m_edges;

    // Xác định kiểu đồ thị {direct, undirect}
    void Set_Kind(Graph &G, string kind)
    {
        G.m_kind = kind;
    }
    // Thêm đỉnh vào đồ thị
    void Add_Vertex(Graph &G, TVertex vertex)
    {
        if (!In(vertex, G.m_vertexes))
            G.m_vertexes.push_back(vertex);
    }
    // Thêm cạnh vào đồ thị
    void Add_Edge(Graph &G, TEdge edge)
    {
        Add_Vertex(G, edge.first);
        Add_Vertex(G, edge.second);
        if (!In(edge, G.m_edges))
            G.m_edges.push_back(edge);
    }
    // Lấy danh sách đỉnh kề(lấy neighbour)
    vector<TVertex> Get_adjVertexes(Graph &G, TVertex v)
    {
        vector<TVertex> vertexes;

        for (int i = 0; i < G.m_edges.size(); i++)
        {
            if (G.m_edges[i].first == v)
                if (!In(G.m_edges[i].second, vertexes))
                    vertexes.push_back(G.m_edges[i].second);
            if (G.m_edges[i].second == v)
                if (!In(G.m_edges[i].first, vertexes))
                    vertexes.push_back(G.m_edges[i].first);
        }
        return vertexes;
    }

    // In thông tin của đồ thị
    void Print_Graph(Graph &G)
    {
        cout << "Kieu do thi = " << G.m_kind << endl;

        cout << "Danh sach cac dinh" << endl;
        for (int i = 0; i < G.m_vertexes.size(); i++)
            cout << G.m_vertexes[i] << endl;

        cout << "Danh sach cac canh" << endl;
        for (int i = 0; i < G.m_edges.size(); i++)
            cout << G.m_edges[i].first << " -- "
                 << G.m_edges[i].second << endl;
    }
    //Đếm thành phần liên thông(Count Connected Components)
    void Count_Connected_Components(Graph &G)
    {
        int count=0;
        
    }
    // Hàm đọc tập tin đồ thị
    void Read_Graph(Graph &G, string const &filename)
    {
        ifstream f(filename.c_str());
        TVertex first, second;

        f >> G.m_kind;
        while (f.good())
        {
            f >> first >> second;
            if (f.good() || f.eof())
                Add_Edge(G, TEdge(first, second));
        }
    }
    // Hàm lưu tập tin đồ thị
    void Write_Graph(Graph &G, string const &filename)
    {
        ofstream f(filename.c_str());

        f << G.m_kind << endl;

        for (int i = 0; i < G.m_edges.size(); i++)
            f << G.m_edges[i].first << " "
              << G.m_edges[i].second << endl;
    }
};
// Hàm xuất thông tin của đỉnh
ostream &operator<<(ostream &os, const TVertex &v)
{
    os << v;
    return os;
}
// Hàm nhập thông tin của đỉnh
istream &operator>>(istream &is, TVertex &v)
{
    is >> v;
    return is;
}
#include "Graph.h"
Graph::~Graph()
{
    vers.clear();
    edges.clear();
}
Graph::Graph()
{
    
}
bool Graph::AddVertex(int vertex)
{
    auto result = vers.insert(vertex);
    return result.second;
}//加入点
bool Graph::RemoveVertex(int vertex)
{
    return vers.erase(vertex);
}//
bool Graph::AddEdge(int vertex1, int vertex2)
{
    if(ContainsVertex(vertex1) && ContainsVertex(vertex2))
    {
        auto result = edges.insert(Edge(vertex1,vertex2));
        return result.second;
    }
    return 0;
}
bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    return edges.erase(Edge(vertex1,vertex2));
}

int Graph::CountVertices() const
{
    return vers.size();
}
int Graph::CountEdges() const
{
    return edges.size();
}
bool Graph::ContainsVertex(int vertex) const
{
    auto search = vers.find(vertex);
    if(search == vers.end())
        return 0;
    return 1;
}
bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    auto search = edges.find(Edge(vertex1,vertex2));
    if(search == edges.end())
        return 0;
    return 1;
}
int Graph::CountSelfEdges() const
{
    int ans = 0;
    for(auto i = edges.begin(); i != edges.end(); i++)
    {
        if(i->GetSource() == i->GetDestination())
            ans ++;
    }
    return ans;
}
vector<int> Graph::GetVertices() const
{
    vector<int> result;
    for(auto i = vers.begin(); i != vers.end(); i++)
    {
        result.push_back(*i);
    }
    return result;
}
vector<Edge> Graph::GetEdges() const
{
    vector<Edge> result;
    for(auto i = edges.begin(); i != edges.end(); i++)
    {
        result.push_back(*i);
    }
    return result;
}
vector<Edge> Graph::GetSingleEdges() const
{
    vector<Edge> result;
    for(auto i = edges.begin(); i != edges.end(); i++)
    {
        if(i->GetSource() <= i->GetDestination())
            result.push_back(*i);
    }
    return result;
}
vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    vector<Edge> result;
    for(auto i = edges.begin(); i != edges.end(); i++)
    {
        if(i->GetDestination() == vertex)
            result.push_back(*i);
    }
    return result;
}
vector<Edge> Graph::GetOutgoingEdges(int vertex) const
{
    vector<Edge> result;
    auto i = edges.lower_bound(Edge(vertex,-2147483648));
    for(; i != edges.end() && i->GetSource() == vertex; i++)
    {
        result.push_back(*i);
    }
    return result;
}
int Graph::GetDegree(int vertex) const
{
    int cnt = 0;
    auto i = edges.lower_bound(Edge(vertex,-2147483648));
    for(; i != edges.end() && i->GetSource() == vertex; i++)
    {
        cnt++;
    }
    return cnt;
}
vector<int> Graph::GetNeighbors(int vertex) const
{
    vector<int> result;
    auto i = edges.lower_bound(Edge(vertex,-2147483648));
    for(; i != edges.end() && i->GetSource() == vertex; i++)
    {
        result.push_back(i->GetDestination());
    }
    return result;
}

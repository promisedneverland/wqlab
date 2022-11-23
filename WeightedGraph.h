#ifndef WeightedGraph_h
#define WeightedGraph_h
#include "Graph.h"
#include <map>
#include "WeightedEdge.h"
template<class T>
class WeightedGraph : virtual public Graph
{
public:
    
    typedef T value_type;
    
    WeightedGraph();
    ~WeightedGraph();
    bool AddEdge(int vertex1, int vertex2, T weight);
    bool RemoveEdge(int vertex1, int vertex2);
    //int CountEdges() const;
    //bool ContainsEdge(int vertex1, int vertex2) const;
    T GetWeight(int vertex1, int vertex2) const;
    vector<WeightedEdge<T>> GetEdges() const;
    vector<WeightedEdge<T>> GetSingleEdges() const;
    vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const;
    vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const;
private:
    map<Edge,T> wedges;
    
};


//#include "DataStructures/WeightedGraph.h"
template<class T>
WeightedGraph<T> :: WeightedGraph()
{

}
template<class T>
WeightedGraph<T> :: ~WeightedGraph()
{
    wedges.clear();
}

template<class T>
bool WeightedGraph<T> :: AddEdge(int vertex1, int vertex2, T weight)//其实没有重写基类的函数，因为参数不同
{
    if(Graph :: AddEdge(vertex1,vertex2))
    {
        wedges.insert(pair<Edge,T>(Edge(vertex1,vertex2),weight));
        return 1;
    }
    return 0;
//    if(ContainsVertex(vertex1) && ContainsVertex(vertex2))
//    {
//        pair<map<Edge, int>::iterator,bool> result;
//        result = wedges.insert(pair<Edge,int>(Edge(vertex1,vertex2),weight));
//        return result.second;
//    }
//    return 0;
    
//    if(ContainsVertex(vertex1) && ContainsVertex(vertex2))
//    {
//        auto result = wedges.insert(WeightedEdge(vertex1,vertex2,weight));
//        return result.second;
//    }
//    return 0;
}
template<class T>
bool WeightedGraph<T> :: RemoveEdge(int vertex1, int vertex2)
{
    Graph :: RemoveEdge(vertex1,vertex2);
    return wedges.erase(Edge(vertex1,vertex2));
}
//int WeightedGraph :: CountEdges() const
//{
//    return wedges.size();
//}

//bool WeightedGraph :: ContainsEdge(int vertex1, int vertex2) const
//{
//    auto search = wedges.find(Edge(vertex1,vertex2));
//    if(search == wedges.end())
//        return 0;
//    return 1;
//}
template<class T>
T WeightedGraph<T> :: GetWeight(int vertex1, int vertex2) const
{
    auto search = wedges.find(Edge(vertex1,vertex2));
    if(search != wedges.end())
        return search->second;
    return -1;
    
}
template<class T>
vector<WeightedEdge<T>> WeightedGraph<T>::GetEdges() const
{
    vector<WeightedEdge<T>> result;
    for(auto i = wedges.begin(); i != wedges.end(); i++)
    {
        result.push_back(WeightedEdge<T>(i->first,i->second));
    }
    return result;
}
template <class T>
vector<WeightedEdge<T>> WeightedGraph<T>::GetIncomingEdges(int vertex) const
{
    vector<WeightedEdge<T>> result;
    for(auto i = wedges.begin(); i != wedges.end(); i++)
    {
        if(i->first.GetDestination() == vertex)
            result.push_back(WeightedEdge<T>(i->first,i->second));
    }
    return result;
}
template <class T>
vector<WeightedEdge<T>> WeightedGraph<T>::GetOutgoingEdges(int vertex) const
{
    vector<WeightedEdge<T>> result;
    auto i = wedges.lower_bound(Edge(vertex,-2147483648));
    for(;i != wedges.end() && i->first.GetSource() == vertex; i++)
    {
        result.push_back(WeightedEdge<T>(i->first,i->second));
    }
    return result;
}

template <class T>
vector<WeightedEdge<T>> WeightedGraph<T>::GetSingleEdges() const
{
    vector<WeightedEdge<T>> result;
    for(auto i = wedges.begin(); i != wedges.end(); i++)
    {
        if(i->first.GetSource() <= i->first.GetDestination())
            result.push_back(WeightedEdge<T>(i->first,i->second));
    }
    return result;
}
//
#endif

#ifndef UndirectedWeightedGraph_h
#define UndirectedWeightedGraph_h
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
template<class T>
class UndirectedWeightedGraph : virtual public WeightedGraph<T>
{
public:
    UndirectedWeightedGraph();
    ~UndirectedWeightedGraph();
    bool AddEdge(int vertex1, int vertex2, T weight);
    bool RemoveEdge(int vertex1, int vertex2);
    int CountEdges() const;
    int GetDegree(int vertex) const;
    vector<WeightedEdge<T>> GetEdges() const;


};


//#include "DataStructures/UndirectedWeightedGraph.h"
template<class T>
UndirectedWeightedGraph<T> :: UndirectedWeightedGraph()
{
    
}
template<class T>
UndirectedWeightedGraph<T> :: ~UndirectedWeightedGraph()
{
    
}
template<class T>
bool UndirectedWeightedGraph<T> :: AddEdge(int vertex1, int vertex2,T weight)
{
    bool result = WeightedGraph<T>::AddEdge(vertex1,vertex2,weight);
    if(result && vertex2 != vertex1)
        WeightedGraph<T>::AddEdge(vertex2,vertex1,weight);
    return result;
}
template<class T>
bool UndirectedWeightedGraph<T>::RemoveEdge(int vertex1, int vertex2)
{
    bool result = WeightedGraph<T>::RemoveEdge(vertex1,vertex2);
    if(result && vertex2 != vertex1)
        WeightedGraph<T>::RemoveEdge(vertex2,vertex1);
    return result;

}
template<class T>
int UndirectedWeightedGraph<T>::CountEdges() const
{
    return (Graph::CountEdges() + Graph::CountSelfEdges())/2;
}
template<class T>
vector<WeightedEdge<T>> UndirectedWeightedGraph<T>::GetEdges() const
{
    return  WeightedGraph<T>::GetSingleEdges();
}
template<class T>
int UndirectedWeightedGraph<T>::GetDegree(int vertex) const
{
    int ans = Graph :: GetDegree(vertex) + Graph::ContainsEdge(vertex,vertex);
    return ans;
}
#endif

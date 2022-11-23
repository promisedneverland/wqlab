#include "DataStructures/UndirectedGraph.h"
UndirectedGraph :: UndirectedGraph()
{
    
}
UndirectedGraph :: ~UndirectedGraph()
{
    
}
bool UndirectedGraph :: AddEdge(int vertex1, int vertex2)
{
    bool result = Graph::AddEdge(vertex1,vertex2);
    if(result && vertex2 != vertex1)
        Graph::AddEdge(vertex2,vertex1);
    return result;
}
bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2)
{
    bool result = Graph::RemoveEdge(vertex1,vertex2);
    if(result && vertex2 != vertex1)
        Graph::RemoveEdge(vertex2,vertex1);
    return result;

}
int UndirectedGraph::CountEdges() const
{
    return (Graph::CountEdges() + Graph::CountSelfEdges())/2;
}
std::vector<Edge> UndirectedGraph::GetEdges() const
{
    return Graph::GetSingleEdges();
}
int UndirectedGraph::GetDegree(int vertex) const
{
    int ans = Graph :: GetDegree(vertex) + Graph::ContainsEdge(vertex,vertex);
    return ans;
}

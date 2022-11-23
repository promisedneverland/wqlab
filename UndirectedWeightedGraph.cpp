//#include "DataStructures/UndirectedWeightedGraph.h"
//UndirectedWeightedGraph :: UndirectedWeightedGraph()
//{
//    
//}
//UndirectedWeightedGraph :: ~UndirectedWeightedGraph()
//{
//    
//}
//bool UndirectedWeightedGraph :: AddEdge(int vertex1, int vertex2,int weight)
//{
//    bool result = WeightedGraph::AddEdge(vertex1,vertex2,weight);
//    if(result && vertex2 != vertex1)
//        WeightedGraph::AddEdge(vertex2,vertex1,weight);
//    return result;
//}
//bool UndirectedWeightedGraph::RemoveEdge(int vertex1, int vertex2)
//{
//    bool result = WeightedGraph::RemoveEdge(vertex1,vertex2);
//    if(result && vertex2 != vertex1)
//        WeightedGraph::RemoveEdge(vertex2,vertex1);
//    return result;
//
//}
//int UndirectedWeightedGraph::CountEdges() const
//{
//    return (Graph::CountEdges() + Graph::CountSelfEdges())/2;
//}
//vector<WeightedEdge> UndirectedWeightedGraph::GetEdges() const
//{
//  
//    return  WeightedGraph::GetSingleEdges();
//}
//int UndirectedWeightedGraph::GetDegree(int vertex) const
//{
//    int ans = Graph :: GetDegree(vertex) + Graph::ContainsEdge(vertex,vertex);
//    return ans;
//}

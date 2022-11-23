//#include "DataStructures/WeightedGraph.h"
//WeightedGraph :: WeightedGraph()
//{
//
//}
//WeightedGraph :: ~WeightedGraph()
//{
//    wedges.clear();
//}
//bool WeightedGraph :: AddEdge(int vertex1, int vertex2, int weight)//其实没有重写基类的函数，因为参数不同
//{
//    if(Graph :: AddEdge(vertex1,vertex2))
//    {
//        wedges.insert(pair<Edge,int>(Edge(vertex1,vertex2),weight));
//        return 1;
//    }
//    return 0;
////    if(ContainsVertex(vertex1) && ContainsVertex(vertex2))
////    {
////        pair<map<Edge, int>::iterator,bool> result;
////        result = wedges.insert(pair<Edge,int>(Edge(vertex1,vertex2),weight));
////        return result.second;
////    }
////    return 0;
//
////    if(ContainsVertex(vertex1) && ContainsVertex(vertex2))
////    {
////        auto result = wedges.insert(WeightedEdge(vertex1,vertex2,weight));
////        return result.second;
////    }
////    return 0;
//}
//bool WeightedGraph :: RemoveEdge(int vertex1, int vertex2)
//{
//    Graph :: RemoveEdge(vertex1,vertex2);
//    return wedges.erase(Edge(vertex1,vertex2));
//}
////int WeightedGraph :: CountEdges() const
////{
////    return wedges.size();
////}
//
////bool WeightedGraph :: ContainsEdge(int vertex1, int vertex2) const
////{
////    auto search = wedges.find(Edge(vertex1,vertex2));
////    if(search == wedges.end())
////        return 0;
////    return 1;
////}
//int WeightedGraph :: GetWeight(int vertex1, int vertex2) const
//{
//    auto search = wedges.find(Edge(vertex1,vertex2));
//    if(search != wedges.end())
//        return search->second;
//    return -1;
//
//}
//vector<WeightedEdge> WeightedGraph::GetEdges() const
//{
//    vector<WeightedEdge> result;
//    for(auto i = wedges.begin(); i != wedges.end(); i++)
//    {
//        result.push_back(WeightedEdge(i->first,i->second));
//    }
//    return result;
//}
//vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const
//{
//    vector<WeightedEdge> result;
//    for(auto i = wedges.begin(); i != wedges.end(); i++)
//    {
//        if(i->first.GetDestination() == vertex)
//            result.push_back(WeightedEdge(i->first,i->second));
//    }
//    return result;
//}
//vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const
//{
//    vector<WeightedEdge> result;
//    auto i = wedges.lower_bound(Edge(vertex,-2147483648));
//    for(;i != wedges.end() && i->first.GetSource() == vertex; i++)
//    {
//        result.push_back(WeightedEdge(i->first,i->second));
//    }
//    return result;
//}
//vector<WeightedEdge> WeightedGraph::GetSingleEdges() const
//{
//    vector<WeightedEdge> result;
//    for(auto i = wedges.begin(); i != wedges.end(); i++)
//    {
//        if(i->first.GetSource() <= i->first.GetDestination())
//            result.push_back(WeightedEdge(i->first,i->second));
//    }
//    return result;
//}
////

#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <queue>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};


template <typename TGraph>
void DFS_VISIT_ALL(const TGraph *graph, int parent, std::function<void(int)> action,set<int>* visited)
{
    action(parent);
    visited->insert(parent);
    for(vector<int> vertices = graph -> GetNeighbors(parent);auto iter : vertices)
    {
        if(visited->find(iter) == visited->end())
        {
            DFS_VISIT_ALL(graph,iter,action,visited);
        }
    }
}

template <typename TGraph>
void DepthFirstSearcher<TGraph> :: VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
    if(graph->ContainsVertex(start) == 0)
        return ;
    set<int> visited;
    
    DFS_VISIT_ALL(graph,start,action,&visited);
}
static optional<int> ret ;
template <typename TGraph>
void DFS_FIND_FIRST(const TGraph *graph, int parent, std::function<bool(int)> predicate,set<int>* visited,bool* find)
{
    if(ret.has_value())
        return;
    if(predicate(parent))
    {
        ret = parent;
        return ;
    }
        
    visited->insert(parent);
    for(vector<int> vertices = graph -> GetNeighbors(parent);auto iter : vertices)
    {
        if(visited->find(iter) == visited->end())
        {
            DFS_FIND_FIRST(graph,iter,predicate,visited,find);
        }
    }

}
template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph> :: TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
    ret = nullopt;
    if(graph->ContainsVertex(start) == 0)
        return ret;
    
    set<int> visited;
    bool find = 0;
    
    DFS_FIND_FIRST(graph,start,predicate,&visited,&find);
    return ret;
}
#endif

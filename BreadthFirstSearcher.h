#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <queue>
#include "WeightedGraph.h"
#include "Graph.h"
#include "UndirectedWeightedGraph.h"
#include "UndirectedGraph.h"
template <typename TGraph>
class BreadthFirstSearcher {
 public:

  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
    {
        
        if(graph->ContainsVertex(start) == 0)
            return ;
        
        set<int> visited;
        queue<int> q;
      
        q.push(start);
        visited.insert(start);
      
        int u;
        
        while(!q.empty())
        {
            u = q.front(); q.pop();
            
            action(u);
            vector<int> vertices = graph -> GetNeighbors(u);
            for(auto iter : vertices)
            {
                if(visited.find(iter) == visited.end())
                {
                    q.push(iter);
                    visited.insert(iter);
                }
            }
        }
    }
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
    {
        static optional<int> ret;
        if(graph->ContainsVertex(start) == 0)
          return ret;
      
        
        set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
      
        int u;
        
        while(!q.empty())
        {
            u = q.front(); q.pop();
            
            if(predicate(u) == true)
            {
                ret = u;
                return ret;
            }
                
            vector<int> vertices = graph -> GetNeighbors(u);
            
            for(auto iter : vertices)
            {
                if(visited.find(iter) == visited.end())
                {
                    q.push(iter);
                    visited.insert(iter);
                }
            }
        }
        return ret;
    }
    

};

#endif

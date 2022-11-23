#ifndef DijkstraShortestPaths_h
#define DijkstraShortestPaths_h

#include "ShortestPaths.h"

template<typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph>
{
 public:
    typedef typename TGraph::value_type value_type;
    struct cmp
    {
        bool operator()(pair<value_type,int> a,pair<value_type,int> b)
        {
            return a.first > b.first;
        }
    };
    DijkstraShortestPaths(const TGraph *graph, int source)
    {
       
        if(!graph->ContainsVertex(source))
            return;
        ShortestPaths<TGraph> :: valid = true;
        ShortestPaths<TGraph> :: source = source;
        vector<int> vertices = graph->GetVertices();
        for(auto iter : vertices)
        {
            ShortestPaths<TGraph> :: reachable.insert(make_pair(iter,false));
            ShortestPaths<TGraph> :: fa.insert(make_pair(iter,-1));
//            ShortestPaths<TGraph> :: dis.insert(make_pair(iter,value_type()));
        }
        ShortestPaths<TGraph> :: dis.insert(make_pair(source,value_type()));
        ShortestPaths<TGraph> :: fa.at(source) = source;
//        ShortestPaths<TGraph> :: dis.at(source) = value_type();
        priority_queue<pair<value_type,int>,vector<pair<value_type,int>>,cmp> pq;
    
        pq.push(make_pair(value_type(),source));
        
        int from,to;
        value_type value;
        vector<WeightedEdge<value_type>> outGoingEdge;
        while(!pq.empty())
        {
            from = pq.top().second;
            pq.pop();
            
            if(ShortestPaths<TGraph> :: reachable.at(from))
                continue;
            ShortestPaths<TGraph> :: reachable.at(from) = true;
            
            outGoingEdge = graph->GetOutgoingEdges(from);
            
            for(auto iter = outGoingEdge.begin(); iter != outGoingEdge.end(); iter++)
            {
                to = iter->GetDestination();
                value = iter->GetWeight();
                if(ShortestPaths<TGraph> :: dis.find(to) == ShortestPaths<TGraph> :: dis.end() ||
                   ShortestPaths<TGraph> :: dis.at(to) > ShortestPaths<TGraph> :: dis.at(from) + value)
                {
                    ShortestPaths<TGraph> :: dis[to] = ShortestPaths<TGraph> :: dis.at(from) + value;
                    ShortestPaths<TGraph> :: fa.at(to) = from;
                    pq.push(make_pair(ShortestPaths<TGraph> :: dis.at(to),to));
                }
                
            }
            
        }

    }
    virtual ~DijkstraShortestPaths(){}

    

};



#endif /* DijkstraShortestPaths_h */

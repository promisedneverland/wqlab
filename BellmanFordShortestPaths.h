#ifndef BellmanFordShortestPaths_h
#define BellmanFordShortestPaths_h

#include <Algorithms/ShortestPaths.h>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>
{
public:
    typedef typename TGraph::value_type value_type;
    BellmanFordShortestPaths(const TGraph *graph, int source)
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
        }
        ShortestPaths<TGraph> :: dis.insert(make_pair(source,value_type()));
        ShortestPaths<TGraph> :: fa.at(source) = source;
        ShortestPaths<TGraph> :: reachable.at(source) = true;
        
        for(int i = 1 ; i <= graph->CountVertices() - 1; i++)
        {
            for(auto e : graph->GetEdges())
            {
                int u = e.GetSource();
                int v = e.GetDestination();
                value_type w = e.GetWeight();
//                printf("u = %d,v = %d\n",u,v);
                if(!ShortestPaths<TGraph> :: reachable.at(u))
                    continue;
                else if(ShortestPaths<TGraph> :: reachable.at(v))
                {
                    if(ShortestPaths<TGraph> :: dis.at(v) > ShortestPaths<TGraph> :: dis.at(u) + w )
                    {
                        ShortestPaths<TGraph> :: dis.at(v) = ShortestPaths<TGraph> :: dis.at(u) + w;
                        ShortestPaths<TGraph> :: fa.at(v) = u;
                    }
                }
                else//v没被发现
                {
                    ShortestPaths<TGraph> :: reachable.at(v) = true;
                    ShortestPaths<TGraph> :: dis[v] = ShortestPaths<TGraph> :: dis.at(u) + w;
                    ShortestPaths<TGraph> :: fa.at(v) = u;
                }
                    
            }
        }
        printf("reach ");
        for(auto iter : ShortestPaths<TGraph> :: reachable)
        {
            printf("%d:%d ",iter.first,iter.second);
        }
    }
    virtual ~BellmanFordShortestPaths(){}
};



#endif 

#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <cassert>
#include <queue>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <unordered_map>
#include <type_traits>
//#include <iostream>
//using namespace std;
//const int N = 1e5;

template<typename TGraph>
class ShortestPaths {
 public:
    typedef typename TGraph::value_type value_type;
    ShortestPaths(){
        static_assert(std::is_default_constructible<value_type>::value,"TValue requires default constructor");
    }
    ShortestPaths(const TGraph *graph, int source){
 
       
    }
    virtual ~ShortestPaths(){}
 public:
    bool HasPathTo(int destination) const
    {
        if(valid == 0)
            return false;
        if(reachable.find(destination) == reachable.end())
            return false;
        if(reachable.at(destination) == false)
            return false;
        return true;
    }
    std::optional<value_type> TryGetDistanceTo(int destination) const
    {
        if(HasPathTo(destination) == 0)
            return nullopt;
        optional<value_type> ret;
        ret = dis.find(destination)->second;
        return ret;
    }
    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        if(HasPathTo(destination) == 0)
            return nullopt;
//        deque<int> dq;
        vector<int> v;
        while(destination != source)
        {
            v.push_back(destination);
            destination = fa.at(destination);
            
        }
        v.push_back(source);
        return v;
//        for(auto iter = fa.begin(); iter != fa.end(); iter++)
//        {
//            printf("id = %d, fa[id] = %d\n",iter->first,iter->second);
//        }
//        for(auto iter = dis.begin(); iter != dis.end(); iter++)
//        {
//            printf("id = %d, dis[id] = %d\n",iter->first,iter->second);
//        }
//        while(destination != source)
//        {
//            dq.push_front(destination);
//            destination = fa.at(destination);
//        }
//        dq.push_front(source);
//
//        for(auto iter = dq.begin() ; iter != dq.end(); iter++)
//        {
//            v.push_back(*iter);
//        }

//        optional<std::vector<int>> ret = v;
//        return ret;
    }

    unordered_map<int,value_type> dis;
    unordered_map<int,bool> reachable;
    unordered_map<int,int> fa;
    int source;
    bool valid = 0;
};

#endif

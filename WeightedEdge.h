#ifndef WeightedEdge_h
#define WeightedEdge_h
#include "Edge.h"
template<class T>
class WeightedEdge : public Edge
{
public:
    WeightedEdge(int s,int d,T w):
        Edge(s,d),w(w) {};
    WeightedEdge(Edge e,T w):
        Edge(e.GetSource(),e.GetDestination()),w(w) {};
    ~WeightedEdge();
    T GetWeight() const;
    
    bool operator <(const WeightedEdge &a) const//重构比较
    {
        if(GetSource() != a.GetSource())
            return GetSource() < a.GetSource();
        else return GetDestination() < a.GetDestination();
    }
private:
    T w;
};
template<class T>
T WeightedEdge<T> ::  GetWeight() const
{
    return w;
}
template<class T>
WeightedEdge<T> :: ~WeightedEdge()
{
    
}
#endif /* WeightedEdge_h */

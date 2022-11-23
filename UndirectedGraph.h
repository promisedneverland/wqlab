#ifndef UndirectedGraph_h
#define UndirectedGraph_h
#include "DataStructures/Graph.h"
class UndirectedGraph : virtual public Graph
{
public:
    UndirectedGraph();
    ~UndirectedGraph();
    bool AddEdge(int vertex1, int vertex2);
    bool RemoveEdge(int vertex1, int vertex2);
    int CountEdges() const;
    std::vector<Edge> GetEdges() const;
    int GetDegree(int vertex) const;
private:
    
};

#endif

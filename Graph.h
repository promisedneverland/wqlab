#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <vector>
#include <DataStructures/Edge.h>
using namespace std;
class Graph {
 public:
  Graph();
  ~Graph();
 public:
  bool AddVertex(int vertex);//加入点
  bool RemoveVertex(int vertex);//
  bool AddEdge(int vertex1, int vertex2);
  bool RemoveEdge(int vertex1, int vertex2);
 public:
  int CountVertices() const;
  int CountEdges() const;
  int CountSelfEdges() const;
  bool ContainsVertex(int vertex) const;
  bool ContainsEdge(int vertex1, int vertex2) const;
  std::vector<int> GetVertices() const;
  std::vector<Edge> GetEdges() const;
  std::vector<Edge> GetSingleEdges() const;
  std::vector<Edge> GetIncomingEdges(int vertex) const;
  std::vector<Edge> GetOutgoingEdges(int vertex) const;
  int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;
private:
    set<int> vers;
    set<Edge> edges;
};

#endif

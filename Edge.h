#ifndef EDGE_H
#define EDGE_H

class Edge {
  public:
    Edge(int source, int destination):
    s(source),d(destination) {}
    ~Edge();
  public:
   int GetSource() const;
   int GetDestination() const;
    
    bool operator <(const Edge &a) const//重构比较
    {
        if(s!=a.s)
            return s < a.s;
        else return d < a.d;
    }
private:
    int s;
    int d;
 };

#endif

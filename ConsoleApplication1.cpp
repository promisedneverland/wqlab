#include "WeightedGraph.h"
#include "Graph.h"
#include "UndirectedWeightedGraph.h"
#include "UndirectedGraph.h"
#include "BreadthFirstSearcher.h"
#include "DepthFirstSearcher.h"
#include "DijkstraShortestPaths.h"
#include "ShortestPaths.h"
#include "BellmanFordShortestPaths.h"
#include <iostream>
using namespace std;
class obj
{
    obj() {}
};
int main()
{

    //    WeightedGraph<obj> *g0 = new WeightedGraph<obj>();
    //    ShortestPaths<WeightedGraph<obj>> *p0 = new DijkstraShortestPaths<WeightedGraph<obj>>(g0, 1);
    UndirectedWeightedGraph<char>* g = new UndirectedWeightedGraph<char>();
    int i, j;
    for (i = 1; i <= 6; i++)
        g->AddVertex(i);
    g->AddEdge(1, 1, 1);
    g->AddEdge(1, 1, 2);
    g->AddEdge(1, 2, 3);
    g->AddEdge(1, 1, 3);
    g->AddEdge(4, 1, 4);
    g->AddEdge(5, 6, 5);
    g->AddEdge(6, 5, 6);
    g->AddEdge(2, 6, 0);
    g->AddEdge(2, 4, 1);
    g->AddEdge(5, 3, 0);

    printf("edge size : %d\n", g->GetEdges().size());
    //    ShortestPaths<WeightedGraph<char>> *p1 = new DijkstraShortestPaths<WeightedGraph<char>>(g, 1);
    ShortestPaths<UndirectedWeightedGraph<char>>* p2;
    for (int i = 1; i <= 6; ++i)
    {
        p2 = new BellmanFordShortestPaths<UndirectedWeightedGraph<char>>(g, i);
        for (int j = 1; j <= 6; ++j)
        {
            //            printf("source = %d,dest = %d\n",i,j);
            if (p2->HasPathTo(j))
            {
                //                  printf("%d ",p2->TryGetDistanceTo(j).value());
                printf("1 ");
                //                vector<int> v = p2->TryGetShortestPathTo(j).value();
                //                for(auto iter : v)
                //                    cout << iter << " ";
                //                  cout << endl;
            }
            else
                printf("0 ");

        }
        printf("\n");
        delete p2;
    }
    //
    //    for(i = 0 ; i <= 10; i++)
    //    {
    //        ShortestPaths<WeightedGraph, char>
    //          *p = new DijkstraShortestPaths<WeightedGraph, char>(g, i);
    ////        cout << p>TryGetDistanceTo(i).value_or(114514) << endl;
    ////        p>TryGetShortestPathTo(i);
    ////                        vector<int> v = p>TryGetShortestPathTo(0).value();
    ////                        for(auto iter : v)
    ////                            cout << iter << " ";
    //        //                cout << p>TryGetDistanceTo(j).value();
    //
    //        for(j=0 ; j<=10; j++)
    //        {
    ////            if(p>HasPathTo(j))
    ////            {
    ////                vector<int> v = p>TryGetShortestPathTo(j).value();
    ////                for(auto iter : v)
    ////                    cout << iter << " ";
    //                cout << p>TryGetDistanceTo(j).value_or(114514) << " ";
    ////            }
    ////            cout << endl;
    //        }
    //        cout << endl;
    //        delete p;
    //    }

//        delete g;
    return 0;
}

#ifndef _GRAPH_H
#define _GRAPH_H
#include <vector>
#include <assert.h>
#include <limits.h>
#include "heap.h"
#include "set"
#include "algorithm"
#include "functional"
#include <unordered_set>

namespace graph
{
  // edge: (u,v,w)
  struct edge
  {
    // (u,v,w) an edge from node u to node v, with distance value w
    int u;
    int v;
    int w;
    edge::edge(int u, int v, int w):u(u),v(v),w(w){};
  };
  
  // Graph, G(V,E)
  class G
  {
    private:
      std::vector<std::vector<edge>> list; // adjacency list
      int n; // # of nodes

      std::vector<bool> color;
      std::vector<int> distance;

  public:
      G()
      {
        buildDefaultGraph();
      }

      G(const std::vector<std::vector<edge>>& list):list(list), n(list.size()) {init();};

      void setGraph(const std::vector<std::vector<edge>> & list)
      { 
        this->list = list;
        this->n = list.size();
        init();
      }
      
      // init color and distance arrays
      void init()
      {
        color.clear();
        color.resize(n, false);
        distance.clear();
        distance.resize(n,0);
      }

      // Breadth Frist Search
      void bfs(int s) 
      {
        init();

        std::queue<int> q;
        q.push(s);
        
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          if (color[node] == false)
          {
            color[node] = true;
            cout << "bfs visited node: " << node << ", distance : " << distance[node] << endl;
            // add unvisited neighboring nodes to q
            for (int i=0; i<list[node].size(); i++)
            {
              int neighbor = list[node][i].v;
              if (color[neighbor] == false)
              {
                q.push(neighbor);
                distance[neighbor] = distance[node] + 1;
              } // if
            } // for
          } // if
        } // end of while

        init();
      }

      // depth first search
      void dfs(int node)
      {
        if (color[node])
          return;

        color[node] = true;
        cout << "dfs visited node " << node << ", distance " << distance[node] << endl;

        // dfs
        for (int i=0; i<list[node].size(); i++)
        {
          int neighbor = list[node][i].v;
          if (color[neighbor] == false)
          {
             distance[neighbor] = distance[node] + 1;
             dfs(neighbor);
          }
        }

        if (distance[node]==0)
          init();
      }

      // build a default graph, called by default constructor
      // callers can also call setGraph() to set up a graph
      void buildDefaultGraph()
      {
        /* 
            0     -->   1           2
            |           |      /    |
           \|          \|    \/     |/
            3           4           5---->
                                    ^    |
                                    |    |
                                     -----

          bfs: 0  1 3 4 (distance 0, 1, 1, 2)
          dfs: 0  1 4 3 (distance 0  1, 2, 1)
        */
        std::vector<edge> adjacentList;

        // adjacent list for node 0
        adjacentList.push_back(edge(0,1,1)); // (0,1) weight 1
        adjacentList.push_back(edge(0,3,1)); // (0,3) weight 1
        list.push_back(adjacentList);

        // adjacent list for node 1
        adjacentList.clear();
        adjacentList.push_back(edge(1,4,1));
        list.push_back(adjacentList);

        // adjacent list for node 2
        adjacentList.clear();
        adjacentList.push_back(edge(2,4,1));
        list.push_back(adjacentList);

        // adjacent list for node 3
        adjacentList.clear();
        adjacentList.push_back(edge(3,1,1));
        list.push_back(adjacentList);

        // adjacent list for node 4
        adjacentList.clear();
        list.push_back(adjacentList);

        // adjacent list for node 5
        adjacentList.clear();
        adjacentList.push_back(edge(5,5,1));
        
        list.push_back(adjacentList);

        assert(list.size() == 6);

        n = list.size();  // # of nodes
      }
      
      // compute dijkstra shortest paths from source node s to all nodes
      // implemented with adjacency list
      void dijkstra(int s)
      {
        //define and init distance array d
        std::vector<std::pair<int, std::pair<int,int>>> d(n); 
        for (int i=0; i<n; i++)
          d[i] =std::make_pair(std::numeric_limits<int>::max(), std::make_pair(s,i)); 
        /*
        for (int i=0; i<list[s].size(); i++)
        {
          const edge &e = list[s][i];
          d[e.v] = std::make_pair(e.w, std::make_pair(e.u, e.v));
        }*/

        d[s] = std::make_pair(0,std::make_pair(s,s));
        
        // define set S
        std::unordered_set<int> S;

        // define set Y = V-S
        std::unordered_set<int> Y;
        for(int i=0; i<n; i++)
            Y.insert(i);

        // choose a node u in V-S such that d(v) is minimum,
        // add the node v to visited set S
        // for each outgoing edge e:(u,v), update d(v)
        // repeat the above process until all reachable-nodes are reached.
        // Implemented with adjacency list and priority queue which is implemented as a min heap

        // heap comparison is based on the first component

        typedef std::pair<int, std::pair<int,int>> _cost; // <cost, <u,v>>
        std::shared_ptr<Heap::heap<_cost>> h(new Heap::heap<_cost>(d));

        for (int i=0; i<=n-1; i++)
        {
          _cost cost = h->pop();
         
          int dist = cost.first;
          int u = cost.second.second;
          cout << "minimum d: " << dist << " to node: " << u << " via edge ("<<cost.second.first << 
            ", " << cost.second.second << ")" << endl;

          // remove node u from V-S
          Y.erase(u);

          // add node u to S
          S.insert(u);

          // for each v of edge (u,v), that is in V-S
          for (int i=0; i<list[u].size(); i++)
          {
            struct edge& e = list[u].at(i);
            if (Y.find(e.v) != Y.end())
            {
              int oldD = d[e.v].first;
              int newD = d[u].first + e.w;
              if (newD < oldD)
              {
                _cost newCost = std::make_pair(newD, std::make_pair(e.u,e.v));
                d[e.v] = newCost;
                h->decrease(h->getIndex(e.v), newCost);
              }
            }
          }
        }
      }
  };
};
#endif
// Testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
using namespace std;
#include <array>
#include<vector>
#include<list>

class graph
{
    int v;
    list<int> *adj;
public:
    graph(int V) { v = V; adj = new list<int>[V]; };

    void addEdge(int u, int w)
    {
        adj[u].push_back(w);
    }
    void bfs(int s)
    {
        // number of vertices
        bool* visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while (!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            } 
        }
    }

};

class wgraph
{
    int v;
    vector<vector<int>> adj;
public:
    wgraph(int V) { v = V; adj[V][V]; };
    void addNode(int u, int v, int weight)
    {
        adj[u][v] = weight;
    }
    void dijkstra()
    {
        vector<int> sp;
        sp.resize(v);
        vector<int>::iterator k;
        for (k = sp.begin(); k != sp.end(); ++v)
        {
            *k = static_cast<int>(INFINITY);
        }
        sp[0] = 0;
        for (int i = 0; i <= v; i++)
        {
            
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.bfs(2);

    return 0;
}


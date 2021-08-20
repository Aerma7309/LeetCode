#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int size;
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int sz) : size(sz)
    {
        parent.resize(size, -1);
        rank.resize(size, 1);
    };
    int find(int node)
    {
        if (parent[node] == -1)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int node1, int node2)
    {
        if (rank[node1] > rank[node2])
        {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        }
        else
        {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
    }
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges)
    {
        DSU dsu(n);
        for (auto &edge : edges)
        {
            int leader1 = dsu.find(edge[0]);
            int leader2 = dsu.find(edge[1]);
            if (leader1 != leader2)
                dsu.unite(leader1, leader2);
            else //cycle found
                return false;
        }
        int leaderCount = 0;
        for (int node = 0; node < n; node++)
            if (dsu.find(node) == node)
                leaderCount++;
        if (leaderCount > 1)
            return false;
        return true;
    }
};


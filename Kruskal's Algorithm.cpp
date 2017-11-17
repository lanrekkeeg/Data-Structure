/*
*
*
* kruskal Algorithm implementation
* Author: Faisal kahn
*
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int find(int val,int *parent) {
    if (parent[val] != val)
        parent[val] = find(parent[val],parent); // use as a path compression
    return parent[val];
}
void uni(vector<int>&rank, int v, int u,int *parent) {
    int x = find(v, parent), y = find(u, parent);
    if (rank[x] > rank[y]) {
        parent[y] = x;
    }
    else parent[x] = y;
    if (rank[x] == rank[y]) {
        rank[y]++;
    }
}
void kruskal(vector<pair<int,pair<int,int>>>&adj, 
            vector <vector<int>>&fina, int *parent,int &cost) {

    vector<int>rank(adj.size(), -1);
    vector<bool>visited(adj.size(), 0);
    for (auto it = adj.begin(); it != adj.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;
        if (find(v, parent) != find(u, parent)) {
            fina[u].push_back(v);
            uni(rank, u, v,parent);
            cost += it->first;
        }

    }
}
int main() {
    ifstream in("data.txt");
    int n, m, c;
    in >> n >> m;
    int *parent = new int[n];
    int cost = 0;
    vector < pair<int, pair<int, int>>>adj_C;
    vector<vector<int>>fin(n, vector<int>());
    int x, y;
    for (int i = 0; i < m; i++) {
        in >> x >> y >> c;
        adj_C.push_back({ c,{x ,y } });

    }
    for (int i = 0; i < n; i++)parent[i] = i;

    sort(adj_C.begin(), adj_C.end());
    kruskal(adj_C, fin, parent,cost);
    for (int i = 0; i < n; i++) {
        for (auto it = fin[i].begin(); it != fin[i].end(); it++)
            cout << i<<" "<<*it <<endl;
    }
    cout << "Total cost is " << cost << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to store an edge
struct Edge {
int u, v, weight;
};
// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
return a.weight < b.weight;
}
// DSU arrays
int parent[1000];
int rankArr[1000];
// Find function with path compression
int findSet(int x) {
if(parent[x] != x)
parent[x] = findSet(parent[x]);
return parent[x];
}
// Union function by rank
void unionSet(int x, int y) {
int px = findSet(x);
int py = findSet(y);
if(px == py) return;
if(rankArr[px] < rankArr[py])
parent[px] = py;
else if(rankArr[px] > rankArr[py])
parent[py] = px;
else {
parent[py] = px;
rankArr[px]++;
}
}
int main() {
int V, E;
cin >> V >> E;
vector<Edge> edges(E);
// Input edges
 for(int i = 0; i < E; i++) {
 cin >> edges[i].u >> edges[i].v >> edges[i].weight;
 }
 // Sort edges by weight
 sort(edges.begin(), edges.end(), compare);
 // Initialize DSU
 for(int i = 0; i < V; i++) {
 parent[i] = i;
 rankArr[i] = 0;
 }
 int mstWeight = 0;
 int edgeCount = 0;
 // Kruskal's Algorithm
 for(int i = 0; i < E; i++) {
 int u = edges[i].u;
 int v = edges[i].v;
 int w = edges[i].weight;
 if(findSet(u) != findSet(v)) {
 unionSet(u, v);
 mstWeight += w;
 edgeCount++;
 if(edgeCount == V - 1)
 break;
 }
 }
 cout << "Minimum Spanning Tree Weight = " << mstWeight << endl;
 return 0;
}
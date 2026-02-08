#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
int V, E;
cin >> V >> E;
vector<pair<int,int>> adj[V];
for(int i = 0; i < E; i++) {
int u, v, w;
cin >> u >> v >> w;
adj[u].push_back({v, w});
adj[v].push_back({u, w});
}
priority_queue<
pair<int,int>, // what we store
vector<pair<int,int>>, // how we store
greater<pair<int,int>> // min heap rule
> pq;
vector<bool> visited(V, false);
int mstWeight = 0;
pq.push({0, 0});
while(!pq.empty()) {
auto [weight, node] = pq.top(); //get minimum edge
pq.pop();
if(visited[node]) continue;
visited[node] = true;
mstWeight += weight;
for(auto &edge : adj[node]) {
int neighbor = edge.first;
int edgeWeight = edge.second;
if(!visited[neighbor]) {
pq.push({edgeWeight, neighbor});
}
}
}
cout << "Minimum Spanning Tree Weight = " << mstWeight << endl;
return 0;
}
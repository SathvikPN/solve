// cses: graph_algorithms 
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

void traverse(int& node, vector<bool>& visited, vector<vector<int>>& adj){
    if(visited[node]) return;
    visited[node] = true;
    for(auto next:adj[node]){
        traverse(next, visited, adj);
    }
}

void solution(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    vector<int> componentStarters;

    for(int i=1; i<=m; ++i){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int node=1; node<=n; ++node){
        if(!visited[node]){
            componentStarters.push_back(node);
            traverse(node, visited, adj);
        }
    }

    cout << componentStarters.size() - 1 << "\n";
    for(int i=1; i<componentStarters.size(); ++i) 
        cout << componentStarters[i-1] << " " << componentStarters[i] << "\n";
}

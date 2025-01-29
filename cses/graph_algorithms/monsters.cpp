#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7; // 10^9 + 7
void print2D(int r,int c,vector<vector<char>>a){for(int y=0;y<r;++y){for(int x=0;x<c;++x){cout<<a[y][x]<<" ";}cout<<"\n";}} 
void print2Di(int r,int c,vector<vector<int>>a){for(int y=0;y<r;++y){for(int x=0;x<c;++x){if(a[y][x]==INT_MAX)cout<<"# ";else cout<<a[y][x]<<" ";}cout<<"\n";}} 
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}
 
int n,m; 
pair<int,int> a,b={-1,-1};
vector<pair<int,int>> msources;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string direction="DURL";
string opp_direction="UDLR";
bool inbound(int y,int x) {return y>=0 && x>=0 && y<n && x<m;}
bool boundary(int y,int x) {return (y==0 || x==0 || y==n-1 || x==m-1);}
 
void solution(){
    cin >> n >> m;
    vector<vector<char>> gmap(n, vector<char>(m));
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            cin >> gmap[y][x];
            if(gmap[y][x] == 'A') a={y,x};
            if(gmap[y][x] == 'M') msources.push_back({y,x});
        }
    }
 
    if(boundary(a.first, a.second)){cout << "YES\n" << 0; return;}
    // multi-source BFS 
    vector<vector<int>> mpaths(n, vector<int>(m, INT_MAX));
    bool visited[n][m]={};
    queue<pair<int,int>> q;
    for(auto m:msources) {mpaths[m.first][m.second]=0; q.push(m);}
    while(!q.empty()){
        auto[y,x] = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int my = y+dy[i];
            int mx = x+dx[i];
            if(visited[my][mx]) continue;
            if(!inbound(my,mx)) continue;
            if(gmap[my][mx]=='#') continue;
            if(mpaths[y][x]+1 <= mpaths[my][mx]){
                mpaths[my][mx] = mpaths[y][x]+1;
                q.push({my,mx});
            }
        }
    }
 
    // print2D(n,m,gmap);
    // print2Di(n,m,mpaths);
 
    vector<vector<int>> apath(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> aparent(n, vector<pair<int,int>>(m, {-1,-1}));
    visited[n][m]={};
    q.push(a); apath[a.first][a.second]=0;
    while(!q.empty()){
        auto[y,x] = q.front(); q.pop();
        visited[y][x]=true;
        for(int i=0; i<4; ++i){
            int my = y+dy[i];
            int mx = x+dx[i];
            if(visited[my][mx]) continue;
            if(!inbound(my,mx)) continue;
            if(gmap[my][mx]=='#') continue;
            if(apath[y][x]+1 < mpaths[my][mx]){
                apath[my][mx] = apath[y][x]+1;
                aparent[my][mx] = {y,x};
                if(boundary(my,mx)) {b={my,mx}; break;}
                q.push({my,mx});
            }
        }
    }
 
    // cout << "--------------------------------\n";
    // print2Di(n,m,apath);
    
    if(b.first<0) {cout << "NO"; return;}
 
    cout << "YES\n";
 
    vector<char> path_description;
    while(true){
        auto[y,x] = b;
        auto[ay,ax] = a;
        if(ay==y && ax==x) break;
        auto[py,px] = aparent[b.first][b.second];
            if(py+1==y) {path_description.push_back('D'); }
        else if(py-1==y) {path_description.push_back('U'); }
        else if(px+1==x) {path_description.push_back('R'); }
        else if(px-1==x) {path_description.push_back('L'); }
        b = {py,px};
    }
 
    cout << path_description.size() << "\n";
    for(auto it=path_description.rbegin(); it!=path_description.rend(); it++){
        cout << *it;
    }
}
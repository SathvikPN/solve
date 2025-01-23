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

// offsets{U,D, L,R}: directions
int dx[4]={0,0,-1,1}; 
int dy[4]={-1,1,0,0};

bool isValid(int y, int x, vector<vector<char>>& cell){
    if(y<0 || x<0) return false;
    if(y>=cell.size() || x>=cell[0].size()) return false;
    return true;
}

void visitRoomSpace(int y, int x, vector<vector<char>>& cell){
    // [TimeLimitExceeded]
    // Breadth-First search ---------------------------------------------------------
    // queue<pair<int,int>> q;
    // q.push({y,x});

    // while(!q.empty()){
    //     auto[y,x] = q.front(); q.pop();
    //     cell[y][x] = '#';
    //     for(int i=0; i<4; i++) {
    //         int ny = y + dy[i];
    //         int nx = x + dx[i];
    //         if(isValid(ny,nx,cell) && cell[ny][nx]=='.') q.push({ny, nx});
    //     }
    // }
    // -------------------------------------------------------------------------------

    // Depth-First search ------------------------------------------------------------
    cell[y][x] = '#';
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(isValid(ny,nx,cell) && cell[ny][nx]=='.') visitRoomSpace(ny,nx,cell);
    }
    // -------------------------------------------------------------------------------
}

void solution(){
    int n,m; cin >> n >> m;
    string s;
    vector<vector<char>> cell(n, vector<char>(m));
    for(int y=0; y<n; ++y){
        cin >> s;
        for(int x=0; x<m; ++x) cell[y][x] = s[x];
    }

    int roomCount=0;
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            if(cell[y][x] == '.'){
                roomCount+=1;
                visitRoomSpace(y,x,cell);
            }
        }
    }
    cout << roomCount;
}

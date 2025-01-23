// cses: graph_algorithms 
#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7; // 10^9 + 7
void print2D(int r,int c,vector<vector<char>>a){for(int y=0;y<r;++y){for(int x=0;x<c;++x){cout<<a[y][x]<<" ";}cout<<"\n";}}
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
string direction="UDLR";
string opp_direction="DURL";

// if y,x is within board limits
bool isValid(int y, int x, vector<vector<char>>& board){
    if(y<0 || x<0) return false;
    if(y>=board.size() || x>=board[0].size()) return false;
    return true;
}

bool search(pair<int,int>& start, pair<int,int>& end, vector<vector<char>>& board) {
    // Breadth-First search for shortest length ---------------------------
    queue<pair<int,int>> q;
    q.push({start.first, start.second});

    while(!q.empty()){
        auto[y,x] = q.front(); q.pop();

        for(int i=0; i<4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(!isValid(ny,nx,board)) continue;
            if(board[ny][nx]=='B') {
                board[ny][nx] = direction[i];
                end={ny,nx};  
                return true;
            }
            if(board[ny][nx]=='.') {
                board[ny][nx] = direction[i];
                q.push({ny,nx});
            }
        }
    }
    return false;
}

stack<char> getpath(pair<int,int>& start, pair<int,int>& end, vector<vector<char>> board){
    stack<char> path;
    auto[y,x] = end;
    auto[Ay,Ax] = start;
    while(1){
        if(x==Ax && y==Ay) break;
        for(int i=0; i<4; ++i){
            if(board[y][x] == direction[i]){
                path.push(direction[i]);
                y = y - dy[i];
                x = x - dx[i];
                break;
            }
        }
    }
    return path;
}

void solution(){
    int n,m; cin >> n >> m;
    string s;
    pair<int,int> start, end;
    vector<vector<char>> board(n, vector<char>(m));
    for(int y=0; y<n; ++y){
        cin >> s;
        for(int x=0; x<m; ++x) {
            board[y][x] = s[x];
            if(s[x] == 'A') start={y,x};
        }
    }
    
    if(!search(start, end, board)) {cout << "NO"; return;}
    // print2D(n,m,board);
    cout << "YES\n";
    stack<char> path = getpath(start, end, board);
    cout << path.size() << "\n";
    while(!path.empty()) {cout << path.top(); path.pop();}
}

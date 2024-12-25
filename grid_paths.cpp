// TODO: Time Limit Exceeded
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

void solution(){
    const int N = 3;
    string s; cin >> s;

    const int MAX_STEP = (N*N)-1;
    
    // debug
    if(s.size()!=MAX_STEP) {cout << "INVALID case"; exit(1);} 
    // optimisation notes:
    // 1. symmetric by middle horizontal line  
    // 2. destination cell before visiting all cells, not valid path, exit
    // 3. hit wall and has option to go either left or right, cannot visit all cell, exit
    // 4. hit tail and has option to go either left or right, cannot visit all cell, exit

    long long paths=0, step=0;
    auto inbound = [&](int y, int x) {
        return (y>=0 && y<N && x>=0 && x<N) ? 1:0;
    };

    bool visited[N][N] = {{}};
    char d[4] = {'U', 'D', 'L', 'R'};
    int dx[4] = { 0,   0,   -1,  1};
    int dy[4] = {-1,  1,    0,  0};


    function<void(int,int)> dfs = [&](int y, int x){
        if(y==(N-1) && x==0){
            if(step==(N*N)-1) paths++;
            return;
        }

        visited[y][x] = true;
        for(int i=0; i<4; i++){
            if(s[step]=='?' || s[step]==d[i]){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(!inbound(ny,nx)) continue;
                if(visited[ny][nx]) continue;

                step++;
                dfs(ny, nx);
                step--;
            }
        }
        visited[y][x] = false;
    };

    dfs(0,0); // only enter valid unvisited cell
    cout << paths;
}

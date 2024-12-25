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
    string s; cin >> s;

    const int N = 7;
    const int MAX_STEP = (N*N)-1;
    bool visited[N][N] = {{}};
    long long validPaths=0, step=0;

    // directions and offsets: Up, Down, Left, Right
    char d[4] = {'U', 'D', 'L', 'R'};
    int dy[4] = {-1,   1,   0,   0};
    int dx[4] = { 0,   0,  -1,   1};

    function<void(int,int)> dfs = [&](int y, int x){
        // dfs called only for valid pos 
        visited[y][x] = true;

        if(y==(N-1) && x==0){
            if(step==MAX_STEP) validPaths++;
            cout << "----------------\n";
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++) cout << visited[i][j] << " ";
                cout << "\n";
            }
            cout << step << " (reached) " << validPaths << " \n";
            visited[y][x] = false;
            return;
        }

        // all valid directional moves 
        for(int i=0; i<4; i++){
            if(s[step] == '?' || s[step] == d[i]){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(
                    ny >= 0 && ny < N &&
                    nx >= 0 && nx < N &&
                    !visited[ny][nx]
                ) {
                    // next pos is valid to visit 
                    step++;
                    dfs(ny, nx);
                    step--;
                }
            }
        }

        visited[y][x] = false;
    };

    dfs(0,0);
    cout << validPaths;
}

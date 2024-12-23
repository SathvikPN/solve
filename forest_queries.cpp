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
    // code here
    int n, q; cin >> n >> q;

    // forest grid
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    // zero row and col are empty zero val
    for(int y=1; y<=n; y++){
        string row; cin >> row;
        for(int x=1; x<=n; x++){
            grid[y][x] = (row[x - 1] == '*') ? 1 : 0;
        }
    }

    // precompute 2D prefix sum
    // sum of trees in (1,1) to (y,x) rectangle (see: https://www.techiedelight.com/wp-content/uploads/Result.png)
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            prefix[y][x] = grid[y][x] 
                + prefix[y-1][x]
                + prefix[y][x-1]
                - prefix[y-1][x-1];
        }
    }

    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int result = prefix[y2][x2]
            - prefix[y1-1][x2] 
            - prefix[y2]  [x1-1] 
            + prefix[y1-1][x1-1];

        cout << result << "\n";
    }
}

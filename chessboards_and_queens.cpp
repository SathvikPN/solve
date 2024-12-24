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
    string board[8];
    for(int i=0; i<8; i++) cin >> board[i];

    long long count = 0;
    bitset<8> col;
    bitset<15> diag1, diag2;

    // lambda function returnType(inputParams)
    // void(int) : signature of the lambda function
    // search = [&](int y)
    // [&] capture all local var by reference (col, diag1, diag2, count)
    // int y is the input parameter as described in function wrapper function<void(int)>
    function<void(int y)> search = [&](int y){
        if (y==8) { count++; return; }
        // diag2: 
        // 0 1 --- 5 6 7
        // ------------- 
        //         2 1 0
        //           2 1
        //             2
        for(int x=0; x<8; x++){
            if(board[y][x]=='*' || col[x] || diag1[x+y] || diag2[7-x+y]) continue;
            col[x] = diag1[x+y] = diag2[7-x+y] = 1;
            search(y+1); 
            // recursive call returns with all processing with current queen pos, so reset.
            col[x] = diag1[x+y] = diag2[7-x+y] = 0;
        }
    };

    search(0);
    cout << count << endl;
}

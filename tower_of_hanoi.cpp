#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7;

// top(n-1)    L -> M 
// nth(bottom) L -> R
// top(n-1)    M -> R
void towerOfHanoi(int disks, int source, int destination, int aux, vector<pair<int, int>> &movesLog){
    if(disks == 1){
        movesLog.push_back({source, destination});
        return;
    }
    towerOfHanoi(disks-1, source, aux, destination, movesLog);
    movesLog.push_back({source, destination});
    towerOfHanoi(disks-1, aux, destination, source, movesLog);
}

void solution(){
    // code here
    int n; cin >> n;
    vector<pair<int, int>> movesLog;
    towerOfHanoi(n, 1, 3, 2, movesLog);
    cout << movesLog.size() << endl;
    for(auto &move: movesLog){
        cout << move.first << " " << move.second << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

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

long long backtrack(vector<long long>& weight, int i, long long sum1, long long sum2){
    if(i == weight.size()) return abs(sum1 - sum2);
    // backtrack with current weight in group 1
    long long diff1 = backtrack(weight, i+1, sum1 + weight[i], sum2);
    // backtrack with current weight in group 2
    long long diff2 = backtrack(weight, i+1, sum1, sum2 + weight[i]);
    return min(diff1, diff2);
}

void solution(){
    // code here
    int n; cin >> n;
    vector<long long> weight(n);
    for(auto i = 0; i < n; i++) cin >> weight[i];
    cout << backtrack(weight, 0, 0, 0) << endl;
}

// sorting weights and iterate them greedily choosing either of the two groups does not work 
// 5 5 5 7 8

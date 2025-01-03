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
    long long n,a,b;
    cin >> n >> a >> b;

    vector<long long> arr(n+1,0), psum(n+1, 0);
    for(long long i=1; i<=n; ++i){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    long long ans = LLONG_MIN;
    multiset<long long> ms; // sorted state, psum from indices [j-b, j-a]

    for(long long end=a; end<=n; end++) {
        // subarray ending idx = end

        if(end > b) {
            ms.erase(ms.find(psum[end-b-1]));  // Remove prefix sum out of range
        }

        ms.insert(psum[end - a]); // Add new valid prefix sum
        ans = max(ans, psum[end]-(*ms.begin()));  // Calculate maximum sum
    }

    cout << ans;
}

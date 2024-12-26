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
    long n,x; cin >> n >> x;
    vector<pair<long, long>> a(n);
    for(auto i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1; // 1 based idx
    }
    
    sort(a.begin(), a.end()); // default first-elem basis for sort

    for(auto i=0; i<n; i++){
        long target = x - a[i].first;
        long left = i+1, right=n-1;
        while(left < right){
            int current_sum = a[left].first + a[right].first;
            if(current_sum == target){
                cout << a[i].second << " " << a[left].second << " " << a[right].second;
                return;
            }

            if(current_sum < target) left++;
            else right--;
        }
    }
    cout << "IMPOSSIBLE";
}

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
    int n,x; cin >> n >> x;
    vector<pair<int,int>> a(n);
    for(auto i=0; i<n; ++i){
        cin >> a[i].first; // item
        a[i].second = i+1; // idx
    }

    sort(a.begin(), a.end(), [](auto ai, auto aj){
        return ai.first < aj.first;
    });

    for(auto i=0; i<(n-3); ++i){
        for(auto j=i+1; j<(n-2); ++j){
            int target = x - a[j].first - a[i].first;
            int left=(j+1), right=(n-1);
            while(left<right){
                int current_sum = a[left].first + a[right].first;
                if(current_sum == target){
                    cout << a[i].second << " " << a[j].second << " " << a[left].second << " " << a[right].second;
                    return;
                }

                if(current_sum < target) left++;
                else right--;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

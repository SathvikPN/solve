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
    int n,k; cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; ++i) cin >> arr[i];

    long long subarray_count = 0;
    int left = 0;
    map<int,int> mp;
    for(int i=0; i<n; ++i){
        mp[arr[i]]++;
        while(mp.size() > k){
            mp[arr[left]]--;
            if(mp[arr[left]] == 0){
                mp.erase(arr[left]);
            }
            left++;
        }

        subarray_count = subarray_count + (i-left+1);
    }
    cout << subarray_count;
}

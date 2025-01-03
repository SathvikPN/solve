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

bool isValid(long long mid, vector<long long>& arr, long long k){
    long long subarray_count = 1;
    long long lastSum = 0;
    for(auto x:arr) {
        lastSum += x;
        if(lastSum > mid){
            lastSum = x;
            subarray_count++;
        }
    }
    return subarray_count <= k;
}

void solution(){
    long long n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(long long i=0; i<n;++i) cin >> arr[i];

    // among all subarray sections, min_sum = max(arr[])
    // among all subarray sections, max_sum = INFINITY (so far)
    long long min_subarray_sum = *max_element(arr.begin(), arr.end());
    long long max_subarray_sum = INFINITY; // OR from task, (10^9) * 2*(10^5)
    long long ans = max_subarray_sum;
    while(min_subarray_sum <= max_subarray_sum){
        long long mid = min_subarray_sum + ((max_subarray_sum-min_subarray_sum)/2);
        if (isValid(mid, arr, k)){
            ans = mid;
            max_subarray_sum = mid - 1;
        } else {
            min_subarray_sum = mid + 1;
        }
    }
    cout << ans;
}

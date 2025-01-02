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

// subarray_sum[i:j] i.e sum(i,j) = sum(0,j) - sum(0, i-1)
// build prefix sum 
// subarray_sum divisible by N mean, modulus is zero.
// sum(i,j)%N = sum(0,j)%N - sum(0, i-1)%N = 0 
// sum(0,j)%N = sum(0,i-1)%N
// for all same modulo reminder, say k
// all combinations kC2 contribute a subarray 
// kC2 = (k)(k-1)/2

void solution(){
    int n; cin >> n;
    int a[n]={0};
    long long psum=0;
    long long pmod[n]={0};  // subarraySum % N = {0,1 .... N-1}
    pmod[0] = 1; // learn

    for(int i=0; i<n; ++i){
        cin >> a[i];
        psum += a[i];
        pmod[(psum % n + n) % n] += 1; // handle negative reminder
    }

    long long subarrayCount = 0;
    for(auto x:pmod){
        subarrayCount = subarrayCount + x*(x-1)/2;
    }

    cout << subarrayCount;

}

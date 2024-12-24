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
    int q; cin >> q;
    long long k;
    while(q--){
        cin >> k;

        // (1digit) 1-9 ==> 9 x 1 = 9
        // (2digit) 10-99 ==> 90 x 2 = 180
        // (3digit) 100-999 ==> 900 x 3 = 2700

        // find the range this k belongs to
        long long length = 1, count = 9, start = 1;
        while(k > count * length){
            k = k - (count * length);
            length++;
            count *= 10;
            start *= 10;
        }

        // find the number
        long long num = start + (k-1) / length; // start already includes first number, hence k-1
        string s = to_string(num);
        cout << s[(k-1) % length] << endl; // k-1 because of 0-based index of string
    }
}

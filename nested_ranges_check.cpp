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
    int n,a,b; cin >> n;
    vector<tuple<int,int,int>> ranges(n); // {start,end,idx}
    for(auto i=0; i<n; ++i){
        cin >> a >> b;
        ranges[i] = {a,b,i};
    }

    sort(ranges.begin(), ranges.end(), [](auto &x, auto &y){
        // get<pos>(tuple) specific syntax for tuple positional elements
        // sort by increasing start
        // if equal, then sort by decreasing end values of range.
        if(get<0>(x) == get<0>(y)) {
            return get<1>(x) > get<1>(y);
        }
        return get<0>(x) < get<0>(y); 
    });

    int contained_by[n] = {0};
    int contains[n] = {0};

    // sweep left-right, check if current range contained by others so far
    int max_end=0;
    for(auto &[a,b,idx] : ranges){
        if(b<=max_end) contained_by[idx] = 1;
        max_end = max(max_end, b);
    }

    // sweep right-left, check if current range contains others
    int min_end = INFINITY;
    for(auto it = ranges.rbegin(); it != ranges.rend(); ++it){
        auto &[a,b,idx] = *it;
        if(b >= min_end) contains[idx] = 1;
        min_end = min(min_end, b);
    }

    // OUTPUT
    for(auto x:contains)     cout << x << " "; cout << "\n";
    for(auto x:contained_by) cout << x << " "; cout << "\n";
}

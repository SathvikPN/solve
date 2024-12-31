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
    int x,n; cin >> x >> n;
    set<int> pos; // position of traffic lights (ordered sequence)
    multiset<int> length; // length of passage without lights (maintain highest length as last value)

    // base case - boundary
    pos.insert(0);
    pos.insert(x);
    length.insert(x-0);

    int k; // partition position 
    while(n--){
        cin >> k;
        // set.insert(x) ==> pair(iterator, isSuccess)
        auto it = pos.insert(k).first;

        // nearest neighbours a..k..b (original range split into two)
        length.erase(length.find(*next(it) - *prev(it))); // learn: multiset.erase(x) deletes all occurences of x
        length.insert(k - *prev(it)); // k-a
        length.insert(*next(it) - k); // b-k

        cout << *length.rbegin() << " ";
    }
}

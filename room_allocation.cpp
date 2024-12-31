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
    int n; cin >> n; // customers
    int room[n];
    vector<tuple<int,int,int>> v(n); // {arrival, departure, customerIdx}
    for(int i=0; i<n; ++i){
        int a,b; cin >> a >> b;
        v[i] = {a,b,i};
    }

    sort(v.begin(), v.end()); // sort by v[i].arrival

    int last_room = 0;
    priority_queue<pair<int,int>> minPq; // minPq node = (departure, room)
    // for minPQ, use negated node (negate again to use externally)

    // v sorted by arrival time
    for(int i=0; i<n; ++i){
        int varrival = get<0>(v[i]);
        int vdeparture = get<1>(v[i]);
        int vCustomerIdx = get<2>(v[i]);
        int pqDeparture = 0;
        if(!minPq.empty()) {pqDeparture = (-1) * minPq.top().first;}

        if(minPq.empty() || pqDeparture >= varrival) {
            minPq.push({-vdeparture, ++last_room});
            room[vCustomerIdx] = last_room;
        } else {
            // reuse room and node
            auto node = minPq.top(); minPq.pop();
            minPq.push({-vdeparture, node.second});
            room[vCustomerIdx] = node.second;
        }

    }

    // output -------
    cout << last_room << "\n";
    for(auto r:room) cout << r << " ";

}

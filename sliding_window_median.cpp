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

void balance(multiset<int>& left, multiset<int>& right){
    while(left.size() > right.size()+1){
        // move max of left to right
        auto it = left.rbegin();
        right.insert(*it);
        left.erase(left.find(*it)); // erase only one occurence of elem
    }

    while(right.size() > left.size()){
        auto it = right.begin();
        left.insert(*it);
        right.erase(right.find(*it));
    }
}

void printMedian(multiset<int>&left, multiset<int>& right) {
    cout << *left.rbegin() << " ";
}

void solution(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) cin >> arr[i];

    multiset<int> left, right; // sorted k window, half to left half to right

    // init first window
    for(int i=0; i<k; ++i) left.insert(arr[i]);
    balance(left, right);
    printMedian(left, right);

    // subsequent sliding windows
    for(int i=k; i < n; ++i){
        int newElement = arr[i];
        int oldElement = arr[i-k];

        // remove old element
        if(left.count(oldElement)) left.erase(left.find(oldElement));
        else right.erase(right.find(oldElement));

        // add new element
        if(!left.empty() && newElement <= *left.rbegin()) left.insert(newElement);
        else right.insert(newElement);
        balance(left, right);
        printMedian(left, right);
    }

}

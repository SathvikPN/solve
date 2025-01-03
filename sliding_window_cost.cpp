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

void printMedianCost(multiset<int>&left, multiset<int>&right, long long&lsum, long long&rsum){
    long long lmax = *left.rbegin(); // lmax is the median
    long long leftCost = (lmax * left.size()) - lsum;
    long long rightCost = rsum - (lmax * right.size());
    cout << leftCost + rightCost << " ";
}

void balance(multiset<int>&left, multiset<int>&right, long long&lsum, long long&rsum){
    while(left.size() > right.size()+1){
        auto lmax = *left.rbegin();
        lsum = lsum - lmax;
        left.erase(left.find(lmax)); // learn: if used *it, 'it; after erase points to updated last elem
        rsum = rsum + lmax;
        right.insert(lmax);
    }

    while(left.size() < right.size()){
        auto rmin = *right.begin();
        rsum = rsum - rmin;
        right.erase(right.find(rmin));

        lsum = lsum + rmin;
        left.insert(rmin);
    }

    // for(auto x:left) cout << x << " "; cout << " left "; cout << lsum << " lsum\n";
    // for(auto x:right) cout << x << " "; cout << " right "; cout << rsum << " rsum\n";
}

void solution(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    multiset<int> left, right; // lower left half, upper right half  
    long long lsum=0, rsum=0;
    // first window
    for(int i=0; i<k; ++i) {
        left.insert(a[i]);
        lsum+=a[i];
    }

    balance(left, right, lsum, rsum);
    printMedianCost(left, right, lsum, rsum);

    // subsequent windows
    for(int i=k; i<n; ++i) {
        int newElem = a[i];
        int oldElem = a[i-k];

        // erase oldElem
        if(left.count(oldElem)) {left.erase(left.find(oldElem)); lsum -= oldElem;}
        else {right.erase(right.find(oldElem)); rsum -= oldElem;}

        // include newElem
        if(!left.empty() && newElem <= (*left.rbegin())) {
            left.insert(newElem);
            lsum += newElem;
        } else {
            right.insert(newElem);
            rsum += newElem;
        }

        balance(left, right, lsum, rsum);
        printMedianCost(left, right, lsum, rsum);
    }
}

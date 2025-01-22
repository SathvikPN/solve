#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7; // 10^9 + 7
 
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

void solution(){
    int n; cin >> n;
    
    // k=1
    cout << 0 << "\n"; 

    // rectangles(y,x) rect{2,3} rect{3,2} inside rect{k,k} square
    for(int k=2; k<=n; k++){
        long long n, allStates, attackStates, horizontalRectangles, verticalRectangles;
        
        // n cells
        n = k*k; 

        // nC2 == n-choose-2(disregard order) == n! / ((n-2)! * 2!)
        allStates = n*(n-1)/2; 

        // count 2x3 and 3x2 rectangles, each box has 2-combo of attack states
        // count order: left-to-right * top-to-bottom
        horizontalRectangles = (k-3+1) * (k-2+1); 
        verticalRectangles =   (k-2+1) * (k-3+1);
        attackStates = (horizontalRectangles + verticalRectangles) * 2;
        
        cout << allStates - attackStates << "\n";
    }
}

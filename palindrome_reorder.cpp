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
    string s; cin >> s;
    long long N = s.length();
    bool allowOdd = N%2 == 1 ? true:false;
    char oddChar = '-'; 
    int freq[26] = {0};
    for(auto x:s) freq[x-'A']++;

    for(int i=0; i<26; i++) {
        if(freq[i]&1) {
            if (allowOdd && oddChar=='-') oddChar = 'A'+i;
            else {cout << "NO SOLUTION"; return;}
        }
    }
    
    char result[N] = {"-"};
    if (allowOdd) result[N/2] = oddChar; freq[oddChar - 'A']--;
    
    long long x=0;
    for (int i=0; i<26; i++){
        for (int j=0; j<(freq[i]/2); j++){
            result[x++] = 'A' + i;
        }
    }

    if(allowOdd) x++;

    for (int i=25; i>=0; i--){
        for (int j=0; j<(freq[i]/2); j++){
            result[x++] = 'A' + i;
        }
    }

    for(auto x:result) cout << x;
}

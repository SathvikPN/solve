#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations
void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if (current.size() == s.size()) {
        // A valid permutation is constructed
        result.push_back(current);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        // Skip if character is already used
        if (used[i]) continue;
        // Skip duplicates (only use the first occurrence of each character at this recursion level)
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        // Choose the character
        used[i] = true;
        current.push_back(s[i]);

        // Recur to build the next level of permutation
        backtrack(s, used, current, result);

        // Backtrack: undo the choice
        used[i] = false;
        current.pop_back();
    }
}

int main() {
    string s;
    cin >> s;

    // Sort the string to ensure lexicographical order
    sort(s.begin(), s.end());

    vector<string> result;
    vector<bool> used(s.size(), false); // Tracks used characters
    string current = "";               // Current permutation being built

    // Generate permutations
    backtrack(s, used, current, result);

    // Output the results
    cout << result.size() << endl;
    for (const auto &perm : result) {
        cout << perm << endl;
    }

    return 0;
}

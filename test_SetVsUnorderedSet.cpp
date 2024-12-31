#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>
using namespace std;

void testSetErase() {
    set<int> s;
    for (int i = 0; i < 1e6; i++) {
        s.insert(i); // Populate with 1 million elements
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e6; i++) {
        s.erase(i); // Erase all elements one by one
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "set erase time: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count() 
         << " ms\n";
}

void testUnorderedSetErase() {
    unordered_set<int> us;
    for (int i = 0; i < 1e6; i++) {
        us.insert(i); // Populate with 1 million elements
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e6; i++) {
        us.erase(i); // Erase all elements one by one
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "unordered_set erase time: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count() 
         << " ms\n";
}

int main() {
    testSetErase();
    testUnorderedSetErase();
    return 0;
}

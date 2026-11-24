#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to pluck all apples from N trees.
 * In one minute, he can pick a subset of trees that have the same number of apples
 * and reduce them to a number of apples that exists on some other tree not in the subset.
 * 
 * Effectively, this means if we have a set of distinct apple counts {a1, a2, ..., ak},
 * each distinct value represents a group that must be processed.
 * If we have multiple trees with the same number of apples, they can all be 
 * processed together in one operation to match a smaller value or be cleared.
 * 
 * The problem reduces to finding the number of distinct values present in the input array.
 * Each distinct value requires at least one operation to be reduced or cleared.
 * Thus, the minimum time is simply the count of unique integers in the given array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    set<long long> distinct_apples;
    for (int i = 0; i < n; ++i) {
        long long apples;
        cin >> apples;
        distinct_apples.insert(apples);
    }
    
    // The number of distinct apple counts is the minimum time required.
    cout << distinct_apples.size() << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
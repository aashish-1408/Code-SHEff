#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ram wins if and only if every truth task Shyam asks is present in Ram's truth tasks
 * AND every dare task Shyam asks is present in Ram's dare tasks.
 * 
 * Since the constraints are small (up to 100), we can use a boolean array or 
 * a set to store Ram's tasks and check if all of Shyam's tasks exist in those sets.
 */

void solve() {
    int tr;
    cin >> tr;
    vector<int> tr_tasks(tr);
    set<int> ram_truth;
    for (int i = 0; i < tr; ++i) {
        cin >> tr_tasks[i];
        ram_truth.insert(tr_tasks[i]);
    }

    int dr;
    cin >> dr;
    vector<int> dr_tasks(dr);
    set<int> ram_dare;
    for (int i = 0; i < dr; ++i) {
        cin >> dr_tasks[i];
        ram_dare.insert(dr_tasks[i]);
    }

    int ts;
    cin >> ts;
    vector<int> ts_tasks(ts);
    for (int i = 0; i < ts; ++i) {
        cin >> ts_tasks[i];
    }

    int ds;
    cin >> ds;
    vector<int> ds_tasks(ds);
    for (int i = 0; i < ds; ++i) {
        cin >> ds_tasks[i];
    }

    bool ram_wins = true;

    // Check if all of Shyam's truth tasks are in Ram's truth tasks
    for (int task : ts_tasks) {
        if (ram_truth.find(task) == ram_truth.end()) {
            ram_wins = false;
            break;
        }
    }

    // Check if all of Shyam's dare tasks are in Ram's dare tasks
    if (ram_wins) {
        for (int task : ds_tasks) {
            if (ram_dare.find(task) == ram_dare.end()) {
                ram_wins = false;
                break;
            }
        }
    }

    if (ram_wins) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
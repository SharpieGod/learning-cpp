#include "bits/stdc++.h"

using namespace std;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    int n;

    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    cout << distance(a.begin(), unique(a.begin(), a.end())) << "\n";
}
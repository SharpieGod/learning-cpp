#include "bits/stdc++.h"

using namespace std;

int main() {
    size_t n, m;

    cin >> n >> m;

    vector<int> tickets(n);
    vector<int> customers(m);

    for (auto &t : tickets) {
        cin >> t;
    }

    multiset<int> s(tickets.begin(), tickets.end());

    for (auto &c : customers) {
        cin >> c;

        auto it = s.upper_bound(c);

        if (it != s.begin()) {
            it--;
            cout << *it << '\n';
            s.erase(it);
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
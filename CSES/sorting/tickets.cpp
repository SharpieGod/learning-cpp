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

    sort(tickets.rbegin(), tickets.rend());

    multiset<int> s(tickets.begin(), tickets.end());

    for (auto &c : customers) {
        cin >> c;

        size_t l = 0, r = tickets.size();

        while (l < r) {
            size_t m = l + (r - l) / 2;
            // cout << tickets[m] << '\n';

            if (tickets[m] > c) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l == tickets.size()) {
            cout << -1 << '\n';
        } else {
            cout << tickets[l] << '\n';
            tickets.erase(tickets.begin() + l);
        }
    }

    return 0;
}
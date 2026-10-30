#include "bits/stdc++.h"

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // cout << "here";
    string input;
    cin >> input;

    unordered_map<char, int> counts;
    for (auto ch : input) {
        if (counts.find(ch) == counts.end()) {
            counts[ch] = 1;
            continue;
        }

        counts[ch] += 1;
    }

    int odd_count = 0;
    char odd_ch = 0;

    for (auto [ch, count] : counts) {
        if (count % 2 == 1) {
            odd_count += 1;
            odd_ch = ch;
        }

        if (odd_count > 1) {
            break;
        }

        // cout << ch << " " << count;
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    list<char> ls;
    if (odd_count == 1) {
        ls.assign((size_t)counts[odd_ch], odd_ch);
        counts.erase(odd_ch);
    }

    for (auto [ch, count] : counts) {
        for (int i = 0; i < count; i += 2) {
            ls.push_front(ch);
            ls.push_back(ch);
        }
    }

    for (auto ch : ls) {
        cout << ch;
    }

    cout << "\n";

    return 0;
}
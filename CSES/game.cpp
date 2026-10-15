#include "bits/stdc++.h"

using namespace std;

vector<int> cards;

int n;
int a;
int b;

void game() {
    int ties = n - (a + b);

    for (int i = 0; i < ties; i++) {
        if (cards.size() >= n) {
            cout << "NO\n";
            return;
        }

        cards.push_back(cards.size());
    }

    // for (int i = 0; i < cards.size(); i++) {
    //     cout << (cards[i]) << (i == cards.size() - 1 ? "\n" : " ");
    // }

    for (int i = 0; i < b; i++) {
        if (cards.size() + 1 >= n) {
            cout << "NO\n";
            return;
        }

        cards.push_back(cards.size() + 1);
    }

    // for (int i = 0; i < cards.size(); i++) {
    //     cout << (cards[i]) << (i == cards.size() - 1 ? "\n" : " ");
    // }

    for (int i = 0; i < n; i++) {
        if (find(cards.begin(), cards.end(), i) != cards.end()) {
            continue;
        }

        if (i == cards.size()) {
            cout << "NO\n";
            return;
        }

        cards.push_back(i);
    }

    if (cards.size() != n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<int> p1_cards(n, 0);
    iota(p1_cards.begin(), p1_cards.end(), 0);

    for (int i = 0; i < p1_cards.size(); i++) {
        cout << (p1_cards[i] + 1) << " ";
    }
    cout << "\n";

    for (int i = 0; i < cards.size(); i++) {
        cout << (cards[i] + 1) << " ";
    }
    cout << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b;

        cards.clear();
        game();
    }
}
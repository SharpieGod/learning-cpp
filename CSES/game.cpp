#include "bits/stdc++.h"

using namespace std;

vector<int> p1_cards;
vector<int> p2_cards;

int n;
int a;
int b;

bool game(bool player_1_playing, int cur_a, int cur_b, int cur_ties) {
    if (!p1_cards.empty() && p1_cards.size() == p2_cards.size()) {
        if (p1_cards.back() > p2_cards.back()) {
            cur_a += 1;
        } else if (p1_cards.back() < p2_cards.back()) {
            cur_b += 1;
        } else {
            cur_ties += 1;
        }
    }

    int wanted_ties = n - (a + b);

    if (cur_a == a && cur_b == b && cur_ties == wanted_ties) {
        return true;
    }

    int max_score_gain = n - (cur_a + cur_b + cur_ties);

    if (cur_ties > wanted_ties || cur_a + max_score_gain < a ||
        cur_b + max_score_gain < b) {
        return false;
    }

    vector<int> &played = (player_1_playing ? p1_cards : p2_cards);

    for (int card = 0; card < n; card++) {
        if (find(played.begin(), played.end(), card) != played.end()) {
            continue;
        }

        played.push_back(card);
        if (game(!player_1_playing, cur_a, cur_b, cur_ties)) {
            return true;
        }

        played.pop_back();
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for (int _test = 0; _test < t; _test++) {
        cin >> n;
        cin >> a;
        cin >> b;
        p1_cards.clear();
        p2_cards.clear();

        if (game(true, 0, 0, 0)) {
            cout << "YES\n";

            for (int i = 0; i < p1_cards.size(); i++) {
                cout << p1_cards[i] + 1
                     << (i == p1_cards.size() - 1 ? "\n" : " ");
            }
            for (int i = 0; i < p2_cards.size(); i++) {
                cout << p2_cards[i] + 1
                     << (i == p2_cards.size() - 1 ? "\n" : " ");
            }
        }
    }
}
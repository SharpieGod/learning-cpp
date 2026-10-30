#include "bits/stdc++.h"

using namespace std;
int n, c;
vector<vector<int>> friendships;
vector<optional<bool>> team;

bool assign(int from, bool wanted_team) {
    if (team[from].has_value() && team[from].value() != wanted_team) {
        return false;
    } else if (team[from].has_value()) {
        return true;
    }

    // cout << "set wanted to " << (wanted_team ? '1' : '2') << '\n';
    team[from] = wanted_team;

    for (int to : friendships[from]) {
        if (!assign(to, !wanted_team)) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> c;

    friendships.assign(n, {});
    team.assign(n, nullopt);

    for (int i = 0; i < c; i++) {
        int from, to;
        cin >> from >> to;

        from--;
        to--;

        // if (from < to) {

        friendships[from].push_back(to);
        // } else {
        friendships[to].push_back(from);
        // }
    }

    for (int from = 0; from < n; from++) {
        if (team[from] == nullopt && !assign(from, true)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int from = 0; from < n; from++) {
        cout << (team[from].value() ? '1' : '2') << ' ';
    }

    cout << '\n';
}
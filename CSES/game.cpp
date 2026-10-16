#include "bits/stdc++.h"

using namespace std;

vector<int> cards;

int n;
int a;
int b;

void game() {

    if (a + b > n || (a == 0) != (b == 0)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int ties = n - (a + b);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << (i < ties ? i + 1 : (i - ties + a) % (n - ties) + ties + 1)
             << " ";
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
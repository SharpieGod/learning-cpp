#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string input;
    int count = 0;

    int dial = 50;

    while (cin >> input) {

        bool turn_right = input[0] == 'R';
        int amount = stoi(input.substr(1));

        if (turn_right) {
            dial += amount;
        } else {
            dial -= amount;
        }

        dial = (dial % 100 + 100) % 100;

        if (dial == 0) {
            count += 1;
        }

        // cout << dial << " ";
    }

    cout << count << '\n';
    return 0;
}
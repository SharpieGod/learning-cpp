#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        double a;
        double b;

        cin >> a;
        cin >> b;

        double m2 = (a - 2 * b) / -3;
        double m1 = b - 2 * m2;

        // cout << m1 << " " << m2 << " \n";
        bool condition =
            m2 >= 0 && m1 >= 0 && m2 == floor(m2) && m1 == floor(m1);

        cout << (condition ? "YES" : "NO") << "\n";
    }
}
#include <cmath>
#include <iostream>

using namespace std;

unsigned long long int spiral(unsigned long long x, unsigned long long y) {
    x -= 1;
    y -= 1;

    if (x == y) {
        x += 1;
        return x * x - x + 1;
    } else if (y > x) {
        // cout << "*";
        // cout << "(" << x << " " << y << ") ";
        unsigned long long int p = y;

        if (y % 2 == 1)
            p += 1;

        p *= p;

        if (y % 2 == 0)
            p += 1;

        if (y % 2 == 0) {
            p += x;
        } else {
            p -= x;
        }

        return p;
    } else if (y < x) {
        unsigned long long int p = x;

        if (x % 2 == 0)
            p += 1;

        p *= p;

        if (x % 2 == 1)
            p += 1;

        if (x % 2 == 0) {
            p -= y;
        } else {
            p += y;
        }

        return p;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // for (int y = 4; y < 10; y++) {
    //     for (int x = 4; x < 10; x++) {
    //         cout << spiral((unsigned long long int)x, (unsigned long long
    //         int)y)
    //              << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++) {
        unsigned long long int x;
        unsigned long long int y;

        cin >> y;
        cin >> x;

        cout << spiral(x, y) << "\n";
    }

    return 0;
}
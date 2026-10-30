#include <iostream>

using namespace std;
int n;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << "1\n";
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else if (n == 4) {
        cout << "2 4 1 3\n";
    } else {
        int m = 1;

        while (m <= n) {
            if (m != 1)
                cout << " ";
            cout << m;
            m += 2;
        }

        m = 2;

        while (m <= n) {
            if (m != 1)
                cout << " ";
            cout << m;
            m += 2;
        }

        cout << "\n";
    }

    return 0;
}

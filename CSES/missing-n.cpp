#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int n;
    cin >> n;

    long long int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << (n + 1) * n / 2 - sum << "\n";

    return 0;
}

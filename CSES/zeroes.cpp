#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long int;
int fives = 0;
int twos = 0;

int count_fives(int a) {
    // how many numbers less than a are a multiple of 5.

    if (a == 0) {
        return 0;
    }

    return a / 5 + count_fives(a / 5);
}

int main() {
    u64 n;
    cin >> n;

    // 19 -> 3 + count_fives(3) -> 0.

    // 20 -> 4 + count_fives(4) -> 0;

    // 25 -> 5 + count_fives(5) -> 6

    cout << count_fives(n) << "\n";
}
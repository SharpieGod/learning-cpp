#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    int events;
    cin >> events;

    for (int i = 0; i < events; i++) {
        char o;
        cin >> o;

        int amount;
        cin >> amount;

        if (o == '+') {
            s += amount;
        } else {
            s -= amount;
        }
    }

    cout << s << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        string product_code;

        cin >> product_code;

        int l = 0;
        int r = 0;

        string new_code = "";
        int sum = 0;

        while (l < product_code.length()) {
            char c = product_code.at(l);

            if (isdigit(c) || c == '-') {
                r = l + 1;

                while (r < product_code.length() &&
                       isdigit(product_code.at(r))) {

                    // cout << product_code.at(r) << " ";
                    r++;
                }

                r -= 1;

                // cout << product_code.substr(l, r - l + 1) << "\n";

                sum += stoi(product_code.substr(l, r - l + 1));
                l = r;
            } else if (isupper(c)) {
                new_code += c;
            }

            l++;
        }

        cout << new_code << sum << "\n";
    }
}
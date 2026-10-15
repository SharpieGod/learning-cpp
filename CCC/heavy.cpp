#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    int N;

    cin >> T >> N;

    while (T--) {
        int chr_count[26] = {0};
        string st = "";

        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ch;

            chr_count[ch - 'a']++;
            st.push_back(ch);
        }

        bool first_light = chr_count[st.front() - 'a'] == 1;
        bool good = true;

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0 && first_light == (chr_count[st[i] - 'a'] == 1)) {
                continue;
            }

            if (i % 2 == 1 && first_light != (chr_count[st[i] - 'a'] == 1)) {
                continue;
            }

            good = false;
            break;
        }

        cout << (good ? "T" : "F") << "\n";
    }
}
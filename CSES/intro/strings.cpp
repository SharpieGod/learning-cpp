#include "bits/stdc++.h"

using namespace std;
string input;
vector<string> out;
map<char, int> char_count;
map<char, int> building_char_count;
string building;
void generate() {
    // cout << "Bulding: " << building << "\n";

    if (building.size() == input.size()) {
        out.push_back(building);
        return;
    }

    for (auto [ch, count] : building_char_count) {
        int remaining = char_count[ch] - count;
        // cout << "For " << ch << " remaining: " << remaining << "\n";

        if (remaining > 0) {
            building.push_back(ch);
            building_char_count[ch] += 1;

            generate();

            building.pop_back();

            building_char_count[ch] -= 1;
        }
    }
}

int main() {
    cin >> input;

    for (auto ch : input) {
        char_count[ch] += 1;
        building_char_count[ch] = 0;
    }

    generate();

    cout << out.size() << "\n";

    for (auto s : out) {
        cout << s << "\n";
    }

    return 0;
}
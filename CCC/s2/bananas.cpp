#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;
bool is_monkey_word(string word);

int consume_A_word(string word) {
    if (word.empty()) {
        return 0;
    }

    if (word.at(0) == 'A') {
        return 1;
    }

    if (word.at(0) == 'B') {
        // B and S are like brackets.

        int level = 0;

        int j = 1;

        while (j < word.size()) {
            if (word.at(j) == 'S' && level == 0) {
                break;
            }

            if (word.at(j) == 'B') {
                level += 1;
            }

            else if (word.at(j) == 'S') {
                level -= 1;
            }

            j++;
        }

        if (is_monkey_word(word.substr(1, j - 1))) {
            return j + 1;
        }
    }

    return 0;
}

bool is_monkey_word(string word) {
    if (word.empty())
        return false;
    // cout << "Testing: " << word << "\n";

    int consumed = consume_A_word(word);
    // cout << "Consumed: " << consumed << "\n";
    // cout << word.at(consumed) << " " + word.substr(consumed + 1) << "\n";

    return consumed == word.size() ||
           (word.size() > consumed + 1 && word.at(consumed) == 'N' &&
            is_monkey_word(word.substr(consumed + 1)));
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        string input;
        cin >> input;

        if (input == "X")
            break;

        cout << (is_monkey_word(input) ? "YES" : "NO") << "\n";
    }

    return 0;
}

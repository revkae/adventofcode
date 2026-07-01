#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string print_vector(vector<int> vector) {
    string temp = "";
    for (auto i : vector) {
        temp += to_string(i);
    }
    return temp;
}

vector<int> get_all_combinations(vector<int> bank) {
    vector<int> combinations;
    for (int i = 0; i < bank.size() - 1; i++) {
        for (int j = i + 1; j < bank.size(); j++) {
            //cout << "Combination: " << (to_string(bank[i]) + to_string(bank[j])) << endl;
            combinations.emplace_back(stoi(to_string(bank[i]) + to_string(bank[j])));
        }
    }
    return combinations;
}

int get_max(vector<int> combinations) {
    int current = 0;
    for (int com : combinations) {
        current = max(com, current);
    }
    return current;
}

int main() {
    string str;
    vector<vector<int>> banks;

    while (getline(cin, str)) {
        if (str.empty()) break;

        vector<int> temp;
        for (int i = 0; i < str.length(); i++) {
            temp.emplace_back(str[i] - '0');
        }

        banks.emplace_back(temp);
    }

    int sum = 0;
    for (vector<int> bank : banks) {
        vector<int> combinations = get_all_combinations(bank);
        sum += get_max(combinations);
    }

    cout << "Sum: " << sum << endl;

    return 0;
}

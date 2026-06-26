#include <iostream>
#include <ranges>
#include <sstream>
#include <vector>
using namespace std;

bool is_valid(long long number);

int main() {
    string input;
    getline(std::cin, input);

    stringstream ss(input);
    string output;
    vector<string> tokens;
    vector<pair<long long, long long>> ranges;

    long long invalidids = 0;

    while (getline(ss, output, ',')) {
        tokens.emplace_back(output);
    }

    for (string & token : tokens) {
        auto pos = token.find('-');

        string first  = token.substr(0, pos);
        string second = token.substr(pos + 1);

        ranges.emplace_back(stoll(first), stoll(second));
    }

    for (auto range : ranges) {
        for (long long i = range.first; i <= range.second; i++) {
            bool result = is_valid(i);
            //cout << "ID: " << i << endl;
            if (!result) {
                //cout << "Invalid ID: " << i << endl;
                invalidids += i;
            }
        }
    }

    cout << invalidids << endl;

    return 0;
}

string get_part_of_string(string input, int number) {
    auto pos = number;

    return input.substr(0, pos);
}

int test_part_with_string(string input, string part) {
    if (input.length() % part.length() != 0) {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < input.length() / part.length(); i++) {
        auto pos = i * part.length();
        string result = input.substr(pos, part.length());

        if (result == part) {
            counter++;
        } else {
            counter = 0;
            return counter;
        }
    }
    return counter;
}

bool is_valid(long long number) {
    string test = to_string(number);

    for (int i = 1; i <= test.length() / 2; i++) {
        string part = get_part_of_string(test, i);
        int result = test_part_with_string(test, part);
        if (result >= 2) {
            return false;
        }
    }

    return true;
}

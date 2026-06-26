#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int current = 50;
    string str;
    vector<pair<char, int>> directions;
    int password = 0;

    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        char copy = str[0];
        str.erase(0, 1);
        password += (stoi(str) / 100);
        directions.emplace_back(copy, (stoi(str) % 100));
    }

    for (pair<char, int> & direction : directions) {
        if (direction.first == 'L') {
            if (current >= direction.second) {
                current -= direction.second;
            } else if (current == 0) {
                current = 100 + (current - direction.second);
            } else {
                current = 100 + (current - direction.second);
                password++;
            }
        } else {
            if (current + direction.second == 100) {
                current = 0;
            } else if (current + direction.second > 100) {
                current = (current + direction.second) - 100;
                password++;
            } else if (current + direction.second < 100) {
                current = current + direction.second;
            }
        }

        if (current == 0) {
            password++;
        }
    }
    cout << "Password: " << password << endl;
    return 0;
}
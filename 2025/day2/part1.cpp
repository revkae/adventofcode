// #include <iostream>
// #include <ranges>
// #include <sstream>
// #include <vector>
// using namespace std;
//
// bool is_valid(long long number);
//
// int main() {
//     string input;
//     getline(std::cin, input);
//
//     stringstream ss(input);
//     string output;
//     vector<string> tokens;
//     vector<pair<long long, long long>> ranges;
//
//     long long invalidids = 0;
//
//     while (getline(ss, output, ',')) {
//         tokens.emplace_back(output);
//     }
//
//     for (string & token : tokens) {
//         //cout << token << endl;
//         auto pos = token.find('-');
//
//         string first  = token.substr(0, pos);
//         string second = token.substr(pos + 1);
//
//         ranges.emplace_back(stoll(first), stoll(second));
//     }
//
//     for (auto range : ranges) {
//         cout << range.first << " " << range.second << endl;
//         for (long long i = range.first; i <= range.second; ++i) {
//             bool result = is_valid(i);
//             if (!result) {
//                 invalidids += i;
//             }
//         }
//     }
//
//     cout << invalidids << endl;
//
//     return 0;
// }
//
// bool is_valid(long long number) {
//     string test = to_string(number);
//     if (test.length() % 2 != 0) return true;
//
//     auto pos = test.length() / 2;
//
//     string first = test.substr(0, pos);
//     string second = test.substr(pos);
//
//     if (first == second) {
//         return false;
//     }
//     return true;
// }

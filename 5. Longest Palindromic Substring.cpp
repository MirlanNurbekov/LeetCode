#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }

    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

// Testing the function
int main() {
    string s = "babad";
    cout << "The longest palindromic substring is: " << longestPalindrome(s) << endl;
    return 0;
}
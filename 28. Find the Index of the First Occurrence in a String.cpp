#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // If needle is an empty string, return 0
        if (needle.empty()) {
            return 0;
        }

        // Iterate through haystack
        for (int i = 0; i <= static_cast<int>(haystack.size()) - static_cast<int>(needle.size()); ++i) {
            // Check if the substring of haystack from index i with the length of needle is equal to needle
            if (haystack.substr(i, needle.size()) == needle) {
                return i; // Return the index where the first occurrence starts
            }
        }

        // Return -1 if no occurrence is found
        return -1;
    }
};

int main() {
    Solution solution;
    int index = solution.strStr("hello", "ll");
    std::cout << "The first occurrence index is: " << index << std::endl; // Output should be 2
    
    return 0;
}
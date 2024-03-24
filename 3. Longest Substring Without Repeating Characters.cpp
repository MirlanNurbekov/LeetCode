//Given a string s, find the length of the longest 
//substring without repeating characters.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap; // Map to store the latest index of each character
    int maxLength = 0; // Variable to store the length of the longest substring without repeating characters
    int leftIndex = 0; // Left index of the current window

    for(int rightIndex = 0; rightIndex < s.size(); ++rightIndex) {
        char currentChar = s[rightIndex];

        // If the character is already in the map and its index is within the current window, move the left index
        if(charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= leftIndex) {
            leftIndex = charMap[currentChar] + 1;
        }

        charMap[currentChar] = rightIndex; // Update the latest index of the character
        maxLength = max(maxLength, rightIndex - leftIndex + 1); // Update the max length if necessary
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
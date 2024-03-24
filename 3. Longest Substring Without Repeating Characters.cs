using System;
using System.Collections.Generic;

class Program {
    public static int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> charMap = new Dictionary<char, int>();
        int maxLength = 0;
        int leftIndex = 0;

        for(int rightIndex = 0; rightIndex < s.Length; ++rightIndex) {
            char currentChar = s[rightIndex];

            if(charMap.ContainsKey(currentChar) && charMap[currentChar] >= leftIndex) {
                leftIndex = charMap[currentChar] + 1;
            }

            charMap[currentChar] = rightIndex;
            maxLength = Math.Max(maxLength, rightIndex - leftIndex + 1);
        }

        return maxLength;
    }

    static void Main() {
        Console.Write("Enter a string: ");
        string s = Console.ReadLine();
        Console.WriteLine("Length of the longest substring without repeating characters: " + LengthOfLongestSubstring(s));
    }
}

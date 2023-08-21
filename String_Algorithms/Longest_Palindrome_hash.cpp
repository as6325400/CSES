// C++ program to find the longest
// palindromic substring using hashing
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the longest
// palindromic substring
string longestPalindromicSubstring(string S)
{
 
    // Initialize a hash table H with size
    // n and fill it with 0
    int n = S.length();
    int hash_table[128];
    memset(hash_table, 0, sizeof(hash_table));
    bool isPalindrome = true;
 
    // Iterate through each character in the
    // string S and store its index in the
    // hash table H
    for (int i = 0; i < n; i++)
        hash_table[S[i] - 'a'] = i;
 
    // Initialize start and end indices of
    // the longest palindromic substring
    int start = 0, end = 0;
 
    // Iterate through each character
    // in the string S
    for (int i = 0; i < n; i++) {
 
        // Check if its corresponding index
        // in the hash table is greater than 0
        if (hash_table[S[i] - 'a'] > 0) {
            // Calculate the length of the palindrome
            int len = hash_table[S[i] - 'a'] - i;
               
            // Check if the substring between
            // the current character and the
            // corresponding index in the
            // hash table is a palindrome
            isPalindrome = true;
            for (int j = 0; j < len; j++) {
                if (S[i + j]
                    != S[hash_table[S[i] - 'a'] - j]) {
                      isPalindrome = false;
                    break;
                }
            }
 
            // If the substring between the
            // current character and the
            // corresponding index in the
            // hash table is a palindrome, then
            // update the start and end indices
            // of the longest palindromic
            // substring
            if (isPalindrome && len > end - start) {
                start = i;
                end = hash_table[S[i] - 'a'];
            }
        }
    }
 
    // Return the longest palindromic
    // substring
       
      if (isPalindrome) {
        return S.substr(start, end - start + 1);
    }
    else {
        return "not possible";
    }
}
 
// Driver code
int main()
{
    string s;
    cin >> s;
 
    // Function Call
    cout << longestPalindromicSubstring(s) << endl;
 
    return 0;
}
/*You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

 

Example 1:

Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
Add:    "2050"​​​​​
There is no way to obtain a string that is lexicographically smaller than "2050".
Example 2:

Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller than "24".
Example 3:

Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".
 

Constraints:

2 <= s.length <= 100
s.length is even.
s consists of digits from 0 to 9 only.
1 <= a <= 9
1 <= b <= s.length - 1*/
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        // Helper function to add 'a' to all odd indices of the string
        auto addToOddIndices = [&](string s, int a) -> string {
            for (int i = 1; i < s.length(); i += 2) {
                s[i] = ((s[i] - '0' + a) % 10) + '0';
            }
            return s;
        };
        
        // Helper function to rotate the string to the right by 'b' positions
        auto rotateString = [&](string s, int b) -> string {
            int n = s.length();
            b = b % n; // Ensure b is within the bounds of the string length
            return s.substr(n - b) + s.substr(0, n - b);
        };

        // BFS setup
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;
        
        q.push(s);
        visited.insert(s);
        
        // BFS traversal
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            // Update the smallest string encountered
            if (current < smallest) {
                smallest = current;
            }
            
            // Apply operation 1: Add 'a' to all odd indices
            string addResult = addToOddIndices(current, a);
            if (visited.find(addResult) == visited.end()) {
                visited.insert(addResult);
                q.push(addResult);
            }
            
            // Apply operation 2: Rotate the string by 'b' positions
            string rotateResult = rotateString(current, b);
            if (visited.find(rotateResult) == visited.end()) {
                visited.insert(rotateResult);
                q.push(rotateResult);
            }
        }
        
        return smallest;
    }
};

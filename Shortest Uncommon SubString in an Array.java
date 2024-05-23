/*You are given an array arr of size n consisting of non-empty strings.

Find a string array answer of size n such that:

answer[i] is the shortest 
substring
 of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the 
lexicographically smallest
. And if no such substring exists, answer[i] should be an empty string.
Return the array answer.

 

Example 1:

Input: arr = ["cab","ad","bad","c"]
Output: ["ab","","ba",""]
Explanation: We have the following:
- For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
- For the string "ad", there is no substring that does not occur in any other string.
- For the string "bad", the shortest substring that does not occur in any other string is "ba".
- For the string "c", there is no substring that does not occur in any other string.
Example 2:

Input: arr = ["abc","bcd","abcd"]
Output: ["","","abcd"]
Explanation: We have the following:
- For the string "abc", there is no substring that does not occur in any other string.
- For the string "bcd", there is no substring that does not occur in any other string.
- For the string "abcd", the shortest substring that does not occur in any other string is "abcd".
 

Constraints:

n == arr.length
2 <= n <= 100
1 <= arr[i].length <= 20
arr[i] consists only of lowercase English letters.*/

import java.util.HashSet;
import java.util.Set;

class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        String[] result = new String[n];

        // Create a set to store all substrings from all strings
        Set<String> allSubstrings = new HashSet<>();
        for (String s : arr) {
            for (int len = 1; len <= s.length(); len++) {
                for (int start = 0; start <= s.length() - len; start++) {
                    allSubstrings.add(s.substring(start, start + len));
                }
            }
        }

        // For each string, find the shortest unique substring
        for (int i = 0; i < n; i++) {
            String shortestUnique = null;
            String currentString = arr[i];
            outerLoop:
            for (int len = 1; len <= currentString.length(); len++) {
                for (int start = 0; start <= currentString.length() - len; start++) {
                    String candidate = currentString.substring(start, start + len);
                    if (isUnique(candidate, i, arr)) {
                        if (shortestUnique == null || candidate.compareTo(shortestUnique) < 0) {
                            shortestUnique = candidate;
                        }
                    }
                }
                if (shortestUnique != null) {
                    break;
                }
            }
            result[i] = shortestUnique == null ? "" : shortestUnique;
        }
        
        return result;
    }

    private boolean isUnique(String substring, int index, String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i != index && arr[i].contains(substring)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] arr1 = {"cab", "ad", "bad", "c"};
        String[] result1 = sol.shortestSubstrings(arr1);
        for (String s : result1) {
            System.out.println(s);
        }

        String[] arr2 = {"abc", "bcd", "abcd"};
        String[] result2 = sol.shortestSubstrings(arr2);
        for (String s : result2) {
            System.out.println(s);
        }
    }
}

/*iven three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

Example 1:

Input: 
n = 5
x = 3
y = 4
Output: 
1
Explanation:
There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. Now 2 coins will be left so his friend will pick one coin and now Geek can win by picking the last coin.
Example 2:
Input:
n = 2
x = 3
y = 4
Output:
0
Explanation: 
Geek picks 1 coin and then his friend picks 1 coin.
Your Task: 
You don't need to read input or print anything. Complete the function findWinner() which takes n, x, and y as input parameters and returns 1 if Geek can win otherwise 0.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 ≤ n, x, y ≤ 105*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findWinner(int n, int x, int y) {
        // dp[i] will be true if there is a winning strategy with i coins remaining
        vector<bool> dp(n + 1, false);
        
        // Base case
        dp[0] = false; // If no coins are left, the player to move loses

        for (int i = 1; i <= n; ++i) {
            // If picking 1 coin leaves the opponent in a losing position
            if (i >= 1 && !dp[i - 1]) {
                dp[i] = true;
            }
            // If picking x coins leaves the opponent in a losing position
            if (i >= x && !dp[i - x]) {
                dp[i] = true;
            }
            // If picking y coins leaves the opponent in a losing position
            if (i >= y && !dp[i - y]) {
                dp[i] = true;
            }
        }
        
        // The result for n coins
        return dp[n] ? 1 : 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends

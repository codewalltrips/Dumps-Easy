/* You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
 

Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000 */

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int count = 0;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, k, 0, freq, count);
        return count;
    }

private:
    void backtrack(const std::vector<int>& nums, int k, int index, std::unordered_map<int, int>& freq, int& count) {
        if (index >= nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            if (freq[nums[i] - k] > 0 || freq[nums[i] + k] > 0) {
                continue;
            }

            // Add nums[i] to the current subset
            freq[nums[i]]++;
            count++;
            backtrack(nums, k, i + 1, freq, count);

            // Backtrack by removing nums[i] from the current subset
            freq[nums[i]]--;
        }
    }
};

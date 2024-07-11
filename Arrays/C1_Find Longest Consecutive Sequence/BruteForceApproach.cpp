/*Find Longest Consecutive Sequence
Problem: Find the longest streak of consecutive numbers in an unsorted list.

Constraints: List size <= 100,000, numbers between -1 billion and 1 billion.

Solution (Simple Steps):

Loop through each number in the list.
Check if the next consecutive number exists in the list (using another loop is not ideal!).
If it exists, keep track of the count and update the longest sequence found so far.
Repeat for all numbers in the list.*/

#include <vector>
#include <algorithm> // for max

using namespace std;

int longestSuccessiveElements(vector<int>& nums) {
  int longest = 1;
  for (int num : nums) { // for each element "num" in nums
    if (binary_search(nums.begin(), nums.end(), num + 1)) { // check next consecutive number
      int count = 1;
      while (binary_search(nums.begin(), nums.end(), num + ++count)); // keep searching while consecutive
      longest = max(longest, count);
    }
  }
  return longest;
}

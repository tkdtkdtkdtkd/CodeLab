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

/*
vector -> unordered_set (to remove duplicates) -> for each x in set:
  - if x-1 not in set (x can start a sequence) -> count = 1
  - while x+1 in set:
    - x = x+1, count = count + 1
  - longest = max(longest, count)
*/

class Solution {
public:
  // This function finds the longest consecutive sequence in a vector of integers.
  int longestConsecutive(vector<int>& nums) {
    // Handle edge case: empty vector
    if (nums.size() == 0) return 0;

    // Create a set to store unique elements from the input vector
    unordered_set<int> st;
    for (auto x : nums) {
      st.insert(x);
    }

    int longest = 1;  // Initialize longest sequence to 1

    // Iterate through each element in the set
    for (auto it : st) {
      // Check if the element is the beginning of a sequence (no previous number)
      if (st.find(it - 1) == st.end()) {
        int count = 1;  // Initialize sequence count
        int x = it;     // Current element

        // Traverse the sequence by finding consecutive elements in the set
        while (st.find(x + 1) != st.end()) {
          count++;
          x++;
        }

        // Update longest sequence if the current sequence is longer
        longest = max(longest, count);
      }
    }

    return longest;
  }
};

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Replace all non-positive numbers and numbers > n with n+1
        // This is because the answer can only be in range [1, n+1]
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0 || arr[i] > n) {
                arr[i] = n + 1;
            }
        }
        
        // Step 2: Use array indices as hash map
        // For each number x in the array, mark arr[x-1] as negative
        // This indicates that number x is present in the original array
        for (int i = 0; i < n; i++) {
            int num = abs(arr[i]); // Get the actual number (ignore sign)
            
            // If this number is in valid range [1, n]
            if (num <= n) {
                // Mark the corresponding index as negative
                // We use abs() because it might already be negative
                arr[num - 1] = -abs(arr[num - 1]);
            }
        }
        
        // Step 3: Find the first positive element
        // The index of first positive element + 1 is our answer
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1; // +1 because we want 1-indexed result
            }
        }
        
        // Step 4: If all elements are negative, 
        // it means numbers 1 to n are all present
        // So the missing number is n+1
        return n + 1;
    }
};

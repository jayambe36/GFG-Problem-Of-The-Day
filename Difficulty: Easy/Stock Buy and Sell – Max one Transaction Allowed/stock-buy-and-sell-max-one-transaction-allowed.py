class Solution:
    def maximumProfit(self, prices):
        # Initialize variables to track the minimum price and maximum profit
        min_price = float('inf')  # A very large number initially
        max_profit = 0  # No profit at the beginning
        
        # Loop through the array of prices
        for price in prices:
            # Update the minimum price if the current price is lower
            if price < min_price:
                min_price = price
            # Calculate profit if we sell at the current price
            # Update the maximum profit if this profit is greater
            elif price - min_price > max_profit:
                max_profit = price - min_price
        
        return max_profit


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        # Read input and split it into a list of integers
        prices = list(map(int, input().split()))
        # Create a Solution object and calculate the result
        obj = Solution()
        result = obj.maximumProfit(prices)
        # Print the result
        print(result)

# } Driver Code Ends
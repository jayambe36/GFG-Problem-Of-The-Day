class Solution:
    def findMaxSum(self, root):
        def dfs(node):
            if not node:
                return 0
            left = max(0, dfs(node.left)) 
            right = max(0, dfs(node.right))

         
            self.max_sum = max(self.max_sum, node.data + left + right)
            return node.data + max(left, right)

        self.max_sum = float('-inf')
        dfs(root)
        return self.max_sum


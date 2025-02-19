#User function Template for python3
'''
class Node:
    def _init_(self,x):
        self.data = x
        self.next = None
'''
class Solution:
    def mergeKLists(self, arr):
        # code here
        head = arr[0]
        curr = head
        while curr.next:
            curr = curr.next
        for i in range(1,len(arr)):
            n = arr[i]
            curr.next = n
            while curr.next:
                curr = curr.next
        result = []
        curr = head
        while curr:
            result.append(curr.data)
            curr = curr.next
        result.sort()
        head1 = Node(-1)
        curr = head1
        i=0
        while i<len(result):
            temp = Node(result[i])
            curr.next = temp
            curr = curr.next
            i+=1
        return head1.next

        # return head of merged list


#{ 
 # Driver Code Starts
import heapq


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None

    # To compare nodes in the heap
    def __lt__(self, other):
        return self.data < other.data


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        lists = []
        for _ in range(n):
            values = list(map(int, input().split()))
            head = None
            temp = None
            for value in values:
                newNode = Node(value)
                if head is None:
                    head = newNode
                    temp = head
                else:
                    temp.next = newNode
                    temp = temp.next
            lists.append(head)

        sol = Solution()
        head = sol.mergeKLists(lists)
        printList(head)
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
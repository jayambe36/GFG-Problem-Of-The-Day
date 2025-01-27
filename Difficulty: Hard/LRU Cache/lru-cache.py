#User function Template for python3




class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.head = Node(0, 0)  # dummy node at the start
        self.tail = Node(0, 0)  # dummy node at the end
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node: Node):
        """Remove a node from the linked list."""
        node.prev.next = node.next
        node.next.prev = node.prev

    def _insert(self, node: Node):
        """Insert a node right before the tail (most recently used)."""
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev.next = node
        self.tail.prev = node

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            # Move the accessed node to the end (most recently used)
            self._remove(node)
            self._insert(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            # Remove the old node and insert the updated one
            self._remove(node)
            node.value = value
            self._insert(node)
        else:
            if len(self.cache) >= self.capacity:
                # Remove the least recently used (LRU) item
                lru = self.head.next
                self._remove(lru)
                del self.cache[lru.key]
            # Insert the new node
            node = Node(key, value)
            self._insert(node)
            self.cache[key] = node




#{ 
 # Driver Code Starts
#Initial Template for Python 3


def inputLine():
    return input().strip().split()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        capacity = int(input())
        cache = LRUCache(capacity)

        queries = int(input())
        for __ in range(queries):
            vec = inputLine()
            if vec[0] == "PUT":
                key = int(vec[1])
                value = int(vec[2])
                cache.put(key, value)
            else:
                key = int(vec[1])
                print(cache.get(key), end=" ")
        print()
        print("~")

# } Driver Code Ends
class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;
        int count = 0;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, now we start counting the length
                count = 1;  // takeing the current node we are on
                fast = fast->next;
                while (fast != slow) {
                    count++;
                    fast = fast->next;
                }
                break;
            }
        }

        return count;
    }
};

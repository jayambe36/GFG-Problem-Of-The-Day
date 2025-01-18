//{ Driver Code Starts
// Initial Template for C++
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;   // Initialize previous pointer as NULL
        Node* current = head;   // Start with the head of the list
        Node* next = nullptr;   // Initialize next pointer as NULL
        
        while (current != nullptr) {
            next = current->next;   // Store the next node
            current->next = prev;   // Reverse the current node's pointer
            prev = current;         // Move prev to the current node
            current = next;         // Move to the next node
        }
        
        return prev;   // New head of the reversed list
    }
};



//{ Driver Code Starts.

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main() {
    int T, n, l, firstdata;
    cin >> T;
    cin.ignore();
    while (T--) {
        Node *head = NULL, *tail = NULL;

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int index = 0;
        n = arr.size();
        if (n != 0) {
            head = new Node(arr[0]);
            tail = head;
        }

        for (int i = 1; i < n; i++) {
            l = arr[i];
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
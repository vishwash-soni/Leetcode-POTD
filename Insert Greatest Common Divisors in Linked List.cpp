/* 2807. Insert Greatest Common Divisors in Linked List

## Problem Description
- Given a singly linked list of integers, for each pair of adjacent nodes, insert a new node containing the greatest common divisor (GCD) of the values of these adjacent nodes. Return the modified linked list.

## Example:
- Input:
 head = [18,6,10]

= Output:
 [18, 6, 6, 2, 10]


## Approach
  - Traverse the List: Start from the head of the list and iterate through adjacent pairs of nodes.
  - Insert GCD Nodes: For each pair of adjacent nodes, calculate their GCD using the __gcd() function.
  - Create a New Node: Insert a new node with the GCD value between the two nodes.
  - Move Forward: After inserting the GCD node, move the current pointer to the next original node and repeat the process.
  - Return the Modified List: Once the traversal is complete, return the head of the modified list.

## Time Complexity
  - O(n): We traverse the list once, where n is the number of nodes in the original list.
## Space Complexity
  - O(1): No extra space is used apart from the space required for the new GCD nodes and the original list.

################################################## C++ #################################################################3  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = head->next;
        while(curr!=NULL && next!=NULL){
            ListNode* gcd = new ListNode(__gcd(curr->val,next->val));
            curr->next = gcd;
            gcd->next = next;
            curr= next;
            next = next->next;
        }
        return head;
    }
};

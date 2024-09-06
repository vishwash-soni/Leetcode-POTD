/* ## LeetCode Problem 125: Valid Palindrome

## Problem Description
Given a singly linked list, you are tasked with removing all nodes whose values are present in a given vector of integers (nums). The resulting linked list should contain only nodes with values not in nums.

## Approach

1. Input Conversion:
Convert the vector nums into an unordered set (st). This is done because checking for the existence of an element in an unordered set has an average time complexity of O(1), making the process more efficient.

2. Delete Nodes at the Head:
The function starts by removing nodes from the head of the linked list as long as the head node's value exists in the set st. Once we find a head node that is not in st, we stop deleting.

3. Traverse the List:
After adjusting the head, we traverse the remaining linked list, checking each node's next value.
If the next node's value is in the set st, we delete that node by updating the current node's next pointer to skip the deleted node and point to the subsequent node.
If the next node is not in st, we simply move to the next node.

4. Return the Modified List:
After traversing the entire list and performing deletions, the modified list is returned.

## Time Complexity
O(n + m), where n is the number of nodes in the linked list and m is the size of the nums vector.
Creating the set from the vector nums takes O(m).
Traversing the linked list and performing deletions takes O(n).

## Space Complexity
O(m), where m is the size of the vector nums, because we store the elements of nums in an unordered set for efficient lookups.

########################### C++ #######################################################################################\
*/
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        while(head!=NULL && st.find(head->val)!= st.end()){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }
        ListNode* curr = head;

        while(curr!=NULL && curr->next !=NULL){
            if(st.find(curr->next->val)!=st.end()){
                ListNode* prev = curr->next;
                curr->next = curr->next->next;
                delete(prev);
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

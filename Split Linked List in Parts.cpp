/* ## LeetCode Problem 725: Split Linked List in Parts
  
## Problem Description:
You are given the head of a singly linked list and an integer k. Your task is to split the linked list into k consecutive parts. Each part should have as equal a size as possible, and any extra nodes should be distributed one per part from left to right. If there are fewer nodes than k, some parts will be empty.

## Approach:
The approach used here involves calculating the total length of the linked list first and then distributing nodes across k parts:

## Calculate the Length:
- Traverse the linked list to count the total number of nodes (len).
- Determine Bucket Size and Extra Nodes:
- The number of nodes each part should ideally contain is calculated as len / k (let's call this noOFBuckets).
- The remaining nodes that cannot be evenly distributed are len % k (referred to as noOfExtraNode), and these extra nodes are distributed one by one into the first few parts.

## Splitting the List:
- For each part, start from the current node and create a sublist of size noOFBuckets. If there are extra nodes remaining, add one more node to that part.
- After processing the required nodes for each part, set the next pointer of the last node in the current part to NULL to split the list.

## Handle Empty Parts:
- If the number of parts k is greater than the length of the list, some parts will be empty. These are simply assigned as NULL in the result.

## Time Complexity:
- First, we traverse the list to calculate its length, which takes O(N) time, where N is the number of nodes in the linked list.
- We then traverse the list again to split it into parts, which also takes O(N) time.
  
## Overall Time Complexity: O(N).
  
## Space Complexity:
- The algorithm only uses a constant amount of extra space to track pointers (O(1)), except for the output vector, which stores k pointers.
## Overall Space Complexity: O(k) due to the result vector.

  ##################################################### C++ ############################################################################ */
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        int noOFBuckets = len/k;
        int noOfExtraNode = len%k;

        vector<ListNode*> ans(k);
        temp = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++){
            ans[i]=temp;
            for(int j=1 ; j<=noOFBuckets + (noOfExtraNode > 0 ? 1 : 0); j++){
                prev = temp;
                temp = temp -> next;
            }
            if(prev!=NULL){
                prev -> next = NULL;
            }
            noOfExtraNode--;

        }
        return ans;
    }
};

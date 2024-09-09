/* ## leetcode 2326. Spiral Matrix IV :

## Given the head of a singly linked list and two integers m and n, your task is to represent the values of the linked list as an m x n matrix. You should traverse the matrix in a spiral order, starting from the top left corner, and populate the matrix with the values of the linked list. If the linked list contains fewer than m * n values, the remaining cells should be filled with -1.

## Approach
  
## Matrix Initialization:
- We first create an m x n matrix initialized with -1 values.
  
## Define Boundaries:
- We maintain four boundaries: top, bottom, left, and right. These represent the current boundaries of the spiral traversal.

## Spiral Traversal:
- We simulate the process of moving in four possible directions: left-to-right, top-to-bottom, right-to-left, and bottom-to-top. This is controlled using a variable id that is cycled between 0, 1, 2, and 3, each representing a different direction.
- For each step, if there are still values in the linked list, we assign them to the matrix. Otherwise, the traversal stops.

## Boundary Adjustments:
- After filling in one direction, we adjust the respective boundary to reduce the traversable space.

## Termination:
- The process continues until either all cells are filled, or the linked list is fully consumed.

## Time Complexity :
 - O(m * n): The algorithm must visit each cell in the matrix once. Even though we stop early if the linked list is exhausted, the worst-case scenario involves visiting all m * n cells.
## Space Complexity :
 - O(m * n): The space required for the m x n matrix is proportional to the number of cells in the matrix.

  ################################################# C++ #######################################################################*/
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int id =0;
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(top<=down && left<=right){
            if(id == 0){
                for(int i = left ; i<= right && head!= NULL ; i++){
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                id = (id+1)%4;
                top++;
            }
            if(id == 1){
                for(int i = top ; i<= down && head!= NULL ; i++){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                id = (id+1)%4;
                right--;
            }
            if(id == 2){
                for(int i = right ; i>= left && head!= NULL ; i--){
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                id = (id+1)%4;
                down--;
            }
            if(id == 3){
                for(int i = down ; i>= top && head!= NULL ; i--){
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                id = (id+1)%4;
                left++;
            }
        }
        return matrix;
    }
};

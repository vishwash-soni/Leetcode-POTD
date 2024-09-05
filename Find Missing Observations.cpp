/* # LeetCode Problem 2028 - Find Missing Observations

## Approach

1. **Calculate Total Length**: The total number of rolls, including the missing ones, is determined by adding the length of the given `rolls` array and `n` (the number of missing observations).

2. **Sum of Given Rolls**: We first calculate the sum of the numbers in the given `rolls` array.

3. **Calculate Missing Sum**: The total expected sum from all rolls (including the missing ones) is `mean * len`, where `len` is the total number of rolls. The sum of the missing rolls can be obtained by subtracting the sum of the given rolls from this expected total.

4. **Divide Missing Sum**: The next step is to divide the missing sum equally across the `n` missing rolls. We calculate `num` as the integer division of the missing sum by `n`, and `remainder` as the remainder when dividing the missing sum by `n`.

5. **Check Feasibility**: Before filling the result array:
   - If the number `num` exceeds 6 (maximum face value of a dice), or if the missing sum is out of bounds, the result is invalid and an empty array is returned.
   - If feasible, we distribute `num + 1` to some of the elements in the result array based on the remainder, while ensuring that all values are valid dice rolls (between 1 and 6).

6. **Return Result**: The valid array of missing rolls is returned, or an empty array if the input conditions cannot be satisfied.

## Time Complexity

- **O(n)**: We iterate over the given `rolls` array once to calculate the sum, and then iterate `n` times to fill the missing rolls.

## Space Complexity

- **O(n)**: We use an additional result vector of size `n` to store the missing observations. 

#################################################### C++ #####################################################################################3
*/
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> result;
        int len = rolls.size()+n;
        int sum = 0;
        for(auto x : rolls){
            sum += x;
        }
        int miss = (mean*len)-sum;

        int remainder = miss%n;
        int num = miss/n;
        for(int i=0;i<n;i++){
            if(num>6 && remainder>0){
                return  {};
            }
            if(miss > n*6 || miss<1){
                return {};
            }
            if((num>0 && num<7) && remainder>0){
                result.push_back(num+1);
                remainder--;
                continue;
            }
            if(remainder<1){
                result.push_back(num);
            }
            
        }
    return result;
    }
};


// Time Complexity :O(2^n) where n in the number of nodes
// Space Complexity : O(m) where m is the space used in the call stack 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No
class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, vector<int> &slate, vector<vector<int>> &ans){

        if(i >= candidates.size() || target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(slate);
            return;
        }

        slate.push_back(candidates[i]);
        helper(candidates, target-candidates[i], i, slate, ans);
        slate.pop_back();

        helper(candidates, target, i+1, slate, ans);

    }
       
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> slate;
        vector<vector<int>> ans;
        
        helper(candidates, target, 0, slate, ans);
        return ans;
    }
};

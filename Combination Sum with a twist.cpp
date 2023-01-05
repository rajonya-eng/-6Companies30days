class Solution {
public:
    void combination(int p, int s, vector<int> nums, vector<int> &l, vector<vector<int>> &ans, int k){
        if(p>=9){
            if(s==0 && l.size()==k ){
                ans.push_back(l);
            }
            return;
        }

        if(nums[p]<=s){
            l.push_back(nums[p]);
            combination(p+1,s-nums[p],nums,l,ans,k);
            l.pop_back();
        }
        combination(p+1,s,nums,l,ans,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> l;
        combination(0,n,nums,l,ans,k);
        return ans;
    }
};
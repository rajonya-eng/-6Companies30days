class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int m=1,k=-1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(m<dp[i]){
                        m=dp[i];
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            if(dp[i]==m && (k==-1 || k%nums[i]==0)){
                ans.push_back(nums[i]);
                k=nums[i];
                m--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int n=nums.size(),ans;
       int s=0,prev=0;
       for(int i=0; i<n; i++){
           s=s+nums[i];
           prev=prev+i*nums[i];
       }
        ans=prev;
       for(int i=n-1; i>=0; i--){
           prev=prev+s-(nums[i]*n);
           ans=max(ans,prev);
       }
       return ans;
    }
};
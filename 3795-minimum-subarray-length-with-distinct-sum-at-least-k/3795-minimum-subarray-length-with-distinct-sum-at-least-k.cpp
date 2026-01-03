class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int ,int > mp ;
        
        int n = nums.size(); 
        int i= 0 ; 
        int sum = 0 ;
        int ans = INT_MAX;
        for(int j = 0;j<n;j++)
        {
            mp[nums[j]]++ ;
            if(mp[nums[j]]==1) sum+=nums[j];
            while(sum>=k)
            {   
                ans = min(ans , j-i+1) ;
                mp[nums[i]]-- ;
                if(mp[nums[i]]==0)
                {
                    sum-=nums[i] ;
                }
                i++;
            }
            
        }
        return (ans==INT_MAX) ? -1 : ans  ;
    }
};
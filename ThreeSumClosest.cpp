class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int diff = INT_MAX;
        int sum;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n && diff != 0; i++){
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                
                int curr_sum = nums[i] + nums[j] + nums[k];
                
                int curr_diff = abs(target - curr_sum);
                
                if(curr_diff < abs(diff)){
                    diff = target - curr_sum;
                }
                
                if(curr_sum < target){
                    j++;
                }
                else{
                    k--;
                }   
            }
        }
        
        return target - diff;
    }
};

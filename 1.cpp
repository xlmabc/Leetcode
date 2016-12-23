class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> tmp = nums;
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i = 0, j = len-1; i < len, j >= 0; ){
            if(nums[i]+nums[j] > target){
                    j--;
            }else if(nums[i]+nums[j] < target){
                i++;
            }else{
                int x,y;
                for(int a = 0; a < len; a++){
                    if(tmp[a] == nums[i]) {
                        x = a;
                        break;
                    }
                }
                for(int a = 0; a < len; a++){
                    if(tmp[a] == nums[j]&&a != x) {
                        y = a;
                        break;
                    }
                }
                res.push_back(x);
                res.push_back(y);
                break;
            }
        }
        return res;
    }
};
//����1~n���η���nums[0]~nums[n-1]��Ȼ��ɨһ�鿴�ĸ�����Ӧ�͵õ�����

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < nums.size();i++){
            if(nums[i] <= n && nums[i] > 0){
                if(nums[i] == i + 1)    continue;
                if(nums[nums[i]-1] != nums[i]){
                    swap(nums[nums[i]-1],nums[i]);
                    i--;
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(nums[i] != i + 1)    return i + 1;
        }
        return n + 1;
    }
};

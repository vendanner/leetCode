/**
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

解法：
	碰到0，后面数字往前移动；最后统计几个0，末尾就填充几个0
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if(nums.empty() || nums.size() == 1){
    		return;
    	}
        int count = 0;
        for(int i=0;i<nums.size();){
        	if(!nums[i]){
        		int j=i+1;
        		for(;j<nums.size();j++){
        			if(nums[j]){
        				break;
        			}
        		}
        		count += j-i ;
        		nums[j-count] = nums[j];
        		i = j+1;
        	}else{
        		nums[i-count] = nums[i];
        		i++;
        	}
        }
        for(int i=0;i<count;i++){
        	nums[nums.size()-1-i] = 0;
        }
    }
};
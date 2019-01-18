/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

解法：
	直接用异或，0^a^b^a = a,
	为什么能这么用是因为，元素出现2次，异或后刚好为0

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        if(nums.size() == 1){
        	return nums[0];
        }
        for(int i=0;i<nums.size();i++){
        	single = single ^ nums[i];
        }
        return single;
    }
};
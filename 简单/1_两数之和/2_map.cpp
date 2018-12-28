/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

解法二：
	将数组值hash(本例中没有hash计算)后存储map，计算找被加数不遍历数组，直接查询map 是否存在对应值
    时间：O(n)
    空间：O(n)  = map 空间

*/

#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numMap;

        for (int i=0;i<nums.size();i++){
            numMap.insert(pair<int,int>(nums[i],i));
        }

        for (int i=0;i<nums.size();i++){
            int targetNum = target - nums[i];
            if(numMap.find(targetNum) != numMap.end()){
                if(numMap[targetNum] !=i){
                    return {i,numMap[targetNum]};
                }
            }
        }
    }
    
};
/**
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

解法：
	考虑有进位的情况
	每次都是加1
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
		for(int i=digits.size()-1;i>-1;i--){
			if(digits[i] == 9){
				digits[i] = 0;
			}else{
				digits[i]++;
				// 直接返回
				return digits;
			}
    	}
	    
	    // 一直进位有规律
	    digits[0] = 1;
	    digits.push_back(0);
    	return digits;
    }
};
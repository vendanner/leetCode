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
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
    	int inc = 0;
		for(int i=digits.size()-1;i>-1;i--){
    		int tmp = digits[i] + 1	;
    		digits[i] = tmp%10;
			if(tmp/10){
					inc = 1;
				}else{
					inc = 0;
					break;
				}
			}
			if(inc > 0){
				digits.insert(digits.begin(),1);
			}
	    	
    	return digits;
    }
};
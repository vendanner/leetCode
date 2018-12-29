/**

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

解法：
	1、先排除绝对错误和绝对正确的情况
	2、与之前的数字逆转一样，不过这里需要再判断逆转后数值是否相等
**/

#include<vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
    		return false;
    	}    
        if(x == 0){
            return true;
        }
    	if(x%10 == 0){
    		return false;
    	}
    	int v=0;
    	int y = x;
    	while(x !=0){
    		int tmp = x %10 ;
    		x /=10;
    		v = v*10 + tmp;
    	}

    	if(v != y){
    		return false;
    	}
        return true;
    }
};
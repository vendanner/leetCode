/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

解法：
	char 存入map 来，利用map key 检测重复字符
*/

#include<map>
#include<math.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        map<char,int> maps;
        if(s.empty()){
        	return 0;
        }
        for(int i=0,j=0;i<s.length();i++ ){
        	if(maps.find(s[i]) != maps.end()){
        		// 已存在key
        		j = max(maps[s[i]],j);
        	}
        	// 为什么加1？ "b" 是1个字符,从0开始
        	size = max(size,i-j+1);
        	maps[s[i]] = i+1;
        }
        return size;
    }
};
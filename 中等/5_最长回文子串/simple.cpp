/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

解法：
	移动窗口原理，遍历字符串，以当前位置当作回文中心来判断前回文长度;
	若当前回文长度大于存储长度，则更新最长回文标识
*/
class Solution {
public:
string longestPalindrome(string s) {
	int max_len=1;
	int beingInd = 0;
  	if(s.empty()){
  		return "";
  	}
  	if(s.size() < 2){
  		return s;
  	}
  	for(int i=0;i< s.size();){
  		if((s.size() - i) <= max_len/2){
  			// 无须再做回文判断，就算s.size - i 都满足回文，也比max_len 短
  			break;
  		}
  		int j=i,k=i;
  		while((k<s.size()-1)&&(s[k+1] == s[k])){
  			// 跳过相同的字符，字符相同可以当作回文中心
  			++k;
  		}
  		i = k+1;
  		while((k< s.size()-1)&&(j > 0)&&(s[k+1] == s[j-1])){
  			++k;
  			--j;
  		}
  		// 新回文的长度
  		int new_len = k-j+1;
  		if(max_len < new_len){
  			// 更新回文
  			beingInd = j;
  			max_len = new_len;
  		}

  	}
  	return s.substr(beingInd,max_len);
}
};

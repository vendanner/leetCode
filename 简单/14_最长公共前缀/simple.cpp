/**

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string str = "";
    	if(strs.empty()){
    		return "";
    	}
        if(strs.size() == 1){
        	return strs[0];
        }

        int strMinLength = INT_MAX;
        for(int i=0;i<strs.size();i++){
        	int tmpSize = strs[i].length();
        	if(tmpSize < strMinLength){
        		strMinLength = tmpSize;
        	}
        }

        for(int i=0;i<strMinLength;i++){
        	for(int j=0;j<strs.size()-1;j++){
        		if(strs[j][i] != strs[j+1][i]){
        			return str;
        		}
        	}
        	str = str + (strs[0][i]);
        }
        return str;
    }
};
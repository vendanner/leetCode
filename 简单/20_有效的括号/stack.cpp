/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

解法：
	利用vector 实现栈，碰到左括号压入栈，碰到右括号则和栈顶比较(若括号类型不同则false)，遍历完string，若vector 为空才是有效

*/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        vector<char> vectors(1);
        vectors[0] = s[0];
        for(int i =1;i<s.length();i++){
            if((s[i] == '(') || (s[i] == '{') ||(s[i] == '[')){
                vectors.push_back(s[i]);
            }else if((vectors[vectors.size()-1] + 1 == s[i])||(vectors[vectors.size()-1] + 2 == s[i])){
            	vectors.pop_back();
            }else{
            	return false;
            }
        }
        if(vectors.empty()){
        	return true;
        }
        return false;
    }
};

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
	直接用Stack结构，遇到左括号时push 对应的右括号

*/
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        stack<char> stacks;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                stacks.push(')');
            }else if(s[i] == '{'){
                stacks.push('}');
            }else if(s[i] == '['){
                stacks.push(']');
            }else if((stacks.empty()) ||(stacks.top() != s[i])){
                return false;
            }else{
               stacks.pop(); 
            }

        }
        return stacks.empty();
    }
};

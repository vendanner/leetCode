/**

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
解法：
	不去计算char 该存入那行那列，而是遵循“Z”的存入顺序从上倒下再到上逐个压入，减少很大的计算量
*/
class Solution {
public:
    string convert(string s, int numRows) {
    	string retString ="";
        if(s.empty()){
        	return "";
        }
        if(s.size() < 2 || numRows == 1){
        	return s;
        }
        vector<string> strVector(numRows);
        int row = 0;
        bool flag = false;
        for(char c:s){
        	strVector[row] += c;
        	if((row == 0)||(row == numRows-1)){
        		flag = !flag;
        	}
        	row += flag ? 1:-1;
        }

        for(string row:strVector){
            retString += row;
        }
        return retString;
    }
};
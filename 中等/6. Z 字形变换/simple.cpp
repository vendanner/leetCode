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
	新建[numRows][column] 二维数组，按要求将string 存入数组，遍历完string 后将数组合成新的string
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
        int column = (s.size()/(numRows*2 -2))*(numRows-1) + (s.size()%(numRows*2 -2)?(numRows-1):0);
        char strVector[numRows][column];
        for(int i=0;i<numRows;i++){
        	for(int j=0;j<column;j++){
        		strVector[i][j] = 0;
        	}
        }
        for(int i=0;i<s.size();i++){
        	int tmpRow = 0;
        	int tmpColum = 0;
        	bool flag = i%(numRows*2 -2)/(numRows-1);

        	if(!flag){
        		tmpRow = (i)%(numRows*2 -2)%(numRows-1) ;
        		tmpColum = (i/(numRows*2 -2))*(numRows-1);
        	}else{
        		tmpRow =(numRows-1) - ((i)%(numRows*2 -2)%(numRows-1)) ; 
        		tmpColum = (i/(numRows*2 -2))*(numRows-1) + i%(numRows*2 -2)%(numRows-1);
        	}
        	strVector[tmpRow][tmpColum] = s[i];
        }

        for(int j=0;j<numRows;j++){
        	for(int z=0;z<column;z++){
        		if(strVector[j][z] > 0){
        			retString += strVector[j][z];
        		}
        	}
        }
        return retString;
    }
};
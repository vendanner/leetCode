/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

解法：
	逐个取出相加，进位
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <math.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *root = new ListNode(0);
    	int inc = 0;
    	ListNode *ptr = root;
    	while((l1 != NULL)||(l2 != NULL)){
    		int num1 = 0;
    		int num2 = 0;
    		if(l1 != NULL){
    			num1 = l1->val;
    			l1 = l1->next;
    		}
    		if(l2 != NULL){
    			num2 = l2->val;
    			l2 = l2->next;
    		}
    		int sum = num1 + num2 + inc ;

    		ListNode *tmpNode = new ListNode(sum%10);
    		ptr->next = tmpNode;
    		ptr = tmpNode;
    		inc = sum/10;
    	}
    	if(inc > 0){
    		ListNode *tmpNode = new ListNode(inc);
    		ptr->next = tmpNode;
    	}
    	ptr = root->next;
    	return ptr;
    }
};

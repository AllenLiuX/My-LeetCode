给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

---

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        while(n>0){
            first = first->next;
            n--;
        }
        while(first!=nullptr && first->next!=nullptr){
            first=first->next;
            second=second->next;
        }
        ListNode* temp = second->next;
        if(first == nullptr){   //special case!! when the deleted one is exactly the first node.
            head = head->next;
        }
        else if(temp!= nullptr){    //when the deleted one is in the mid of the list
            second->next = temp->next;
            delete temp;
        }
        else
            second->next = nullptr;
        return head;
    }
};
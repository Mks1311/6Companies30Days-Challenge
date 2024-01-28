/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergetwoLL(ListNode *L1,ListNode *L2){
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        while(L1 && L2){
            if(L2->val > L1->val){
                curr->next=L1;
                L1=L1->next;
            }else{
                curr->next=L2;
                L2=L2->next;
            }
            curr=curr->next;
        }
        if(L1!=nullptr) curr->next=L1;
        if(L2!=nullptr) curr->next=L2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode *temp=lists[0];
        for(int i=1;i<lists.size();i++){
            temp=mergetwoLL(temp,lists[i]);
        }
        return temp;
    }
};
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
    int pairSum(ListNode* head) {
        ListNode * temp=head;
        vector<int> ans;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int a=0;
        int i=0,j=ans.size()-1;
        while(i<j){
            a=max(a,ans[i]+ans[j]);
            i++,j--;
            
        }
        return a;
    }
};
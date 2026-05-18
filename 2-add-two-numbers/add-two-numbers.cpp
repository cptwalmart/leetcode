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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; //init carry
        ListNode* dummy = new ListNode(); //creates a dummy list for us to store our answer in
        ListNode* curr = dummy;

        while(l1 != nullptr || l2 != nullptr){
            int a, b;
            if(l1 != nullptr)//sets a and b to val, if end of list its treated as 0
                a = l1->val;
            else
                a= 0;
            if(l2 != nullptr)//sets a and b to val, if end of list its treated as 0
                b = l2->val;
            else
                b= 0; 

            int sum = a + b + carry; //sum of digit + potential carry
            int store = sum % 10; // The value to store back into the solution list
            carry = sum / 10; // Update carry value

            curr->next = new ListNode(store);
            curr = curr->next;

            if(l1 != nullptr)
                l1 = l1->next;//increment position in the lists
            if(l2 != nullptr)
                l2 = l2->next;
        }
        if (carry == 1) // Edge case for something like 9+1 = 10, where we have a 1's digit outside the original length of the lists
            curr->next = new ListNode(carry);
        return dummy->next; //returns list without the dummy node we attached at the front
    }
};
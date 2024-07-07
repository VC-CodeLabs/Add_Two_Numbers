#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::string listToString(ListNode* head) {
    std::string result;
    while (head) {
        result = std::to_string(head->val) + result;
        head = head->next;
    }
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* ref = result;
    int carry, val;
    carry = val = 0;
    while (true) {
        val = carry;    
        if (l1 != nullptr) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            val += l2->val;
            l2 = l2->next;
        }

        carry = val / 10;
        val = val % 10;
        ref->val = val;
        
        if (l1 != nullptr || l2 != nullptr || carry != 0) {
            ref->next = new ListNode();
            ref = ref->next;
        }
        else
            break; 
    }

    return result;
};

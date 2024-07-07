#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};


// Helper function to convert vector to linked list
ListNode* vectorToList(const vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : vec) {
        if (!head) {
            head = new ListNode();
            head->val = num;
            tail = head;
        } else {
            tail->next = new ListNode();
            tail->next->val = num;
            tail = tail->next;
        }
    }
    return head;
}

// Helper function to convert linked list to vector
vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

/**
 * Adds two numbers represented as linked lists.
 * 
 * This function takes two linked lists, `l1` and `l2`, where each node represents a digit of a number in reverse order.
 * The function adds the two numbers and returns the sum as a linked list, i also prints the final number as a string.
 * 
 * @param l1 The first linked list representing the first number.
 * @param l2 The second linked list representing the second number.
 * @return A linked list representing the sum of the two numbers.
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* ref = dummy;
    int carry = 0;

    // Use a stringstream to build the string backwards
    ostringstream oss;

    // While there are elements in l1 or l2, or there is a carry
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int val = carry;
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
        ref->next = new ListNode(val);
        ref = ref->next;

        // Insert the digit at the beginning of the stringstream
        oss << val;
    }

    // Remove the dummy node
    ListNode* result = dummy->next;
    delete dummy;

    // Convert the stringstream to a string and then reverse it
    string resultString = oss.str();
    reverse(resultString.begin(), resultString.end());

    cout << resultString << endl;

    return result;
}



#ifndef RUNNER
/*
* Example test case.
*/
int main() {
    vector<int> l1 = {2, 4, 3};
    vector<int> l2 = {5, 6, 4};
    ListNode* l1List = vectorToList(l1);
    ListNode* l2List = vectorToList(l2);
    cout << "String: ";
    ListNode* result = addTwoNumbers(l1List, l2List);
    vector<int> resultVec = listToVector(result);
    cout << "Linked List: [";
    for (int i = 0; i < resultVec.size(); i++) {
        cout << resultVec[i];
        if (i < resultVec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
#endif
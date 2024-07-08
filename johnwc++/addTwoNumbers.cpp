#include <cstddef>
#include <iostream>
#include <vector>

using namespace ::std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // walk the lists. For each digit pair, add the 2 numbers.
        // take the ones value and append to the list we're building
        // use the tens value as the carryover to the next number
        // repeat
        //
        // Ugh what if first number is 89 and second number is 12349
        // That's ok - numbers are in reverse order! If list runs out
        // use 0 as a place holder.
        int carry = 0;

        // result is the head of the list to return
        ListNode *result = nullptr;
        // tail is the end of the list. we always add to the end
        ListNode *tail = nullptr;

        // loop through the first list adding ints
        while (l1 != NULL)
        {
            int v1 = l1->val;
            int v2 = 0;
            if (l2 != NULL)
            {
                v2 = l2->val;
            }
            int sum = v1 + v2 + carry;
            int ones = sum % 10;
            if (tail != nullptr)
            {
                tail->next = new ListNode(ones);
                tail = tail->next;
            }
            else
            {
                result = new ListNode(ones);
                tail = result;
            }
            carry = sum / 10;
            l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // if l2 is not null yet, we have remaining digits to add
        // take each digit and add any remaining carry and append to our result
        // repeat until empty
        while (l2 != nullptr)
        {
            int sum = l2->val + carry;
            int v2 = sum % 10;
            carry = v2 / 10;
            tail->next = new ListNode(v2);
            tail = tail->next;
            l2 = l2->next;
        }
        // if there's still carryover, add it now
        if (carry != 0)
        {
            tail->next = new ListNode(carry);
        }
        return result;
    }

    ListNode *numToListNode(vector<int> &val)
    {
        ListNode *ln = nullptr;

        for (int i : val)
        {
            ln = new ListNode(i, ln);
        }
        return ln;
    }

    ListNode *reverseNumToListNode(vector<int> &val)
    {
        ListNode *ln = new ListNode(val[0]);
        ListNode *tail = ln;

        for (int i = 1; i < val.size(); i++)
        {
            tail->next = new ListNode(val[i]);
            tail = tail->next;
        }
        return ln;
    }

    void printListNode(ListNode *l1)
    {
        string num = "";
        cout << "Linked list: [";
        while (l1 != NULL)
        {
            cout << l1->val;
            string v1str = to_string(l1->val);
            num = v1str.append(num);

            l1 = l1->next;
            if (l1 != NULL)
            {
                cout << ",";
            }
        }
        cout << "]\n";
        cout << "String: " << num << "\n";
    }
};

int main(int argc, char *args[])
{
    Solution solution = Solution();

    // val1 and val2 are the numbers to add represented as an array of integers
    // I wasn't sure how you were going to represent the numbers so I took 2 paths.
    //
    // There are 2 ways to define the numbers:
    //  1. Forward order (highest to lowest)
    //  2. Reverse order (lowest to highest)
    //
    // If using Option 1, you can convert the array to a ListNode by calling
    //    numToListNode(val1);
    // For option 2, call:
    //    reverseNumToListNode(val1);
    //
    //

    // vector<int> val1 = {2,4,3};
    // vector<int> val2 = {5,6,4};
    // vector<int> val1 = {0};
    // vector<int> val2 = {0};
    vector<int> val1 = {0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,
        0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1};
    vector<int> val2 = {0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,
        0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1};

    // Convert numbers to ListNode list
    ListNode *l1 = solution.reverseNumToListNode(val1);
    ListNode *l2 = solution.reverseNumToListNode(val2);

    // solution.printListNode(l1);
    // solution.printListNode(l2);

    // Add the numbers
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // print the result
    solution.printListNode(result);

    return 0;
}
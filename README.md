# Add Two Reversed Numbers

LeetCode URL: [https://leetcode.com/problems/add-two-numbers/description/](https://leetcode.com/problems/add-two-numbers/description/)

**Description:**

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Your task is to add the two numbers and return the sum as a linked list. You'll also need to print out the linked list as a formatted string that shows the number in its normal order.

**Rules:**

- Your solution must use a **SINGLY LINKED LIST**
- Each input linked-list will represent a non-negative integer.
- Digits are stored in reverse order, so the least significant digit is at the head of the list.
- Each node in the linked list contains a single digit (0-9).
- The number of nodes in each linked list will be in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros, except the number 0 itself
- The output should be a linked list representing the sum of the two input numbers, also in reverse order.
- Print the resulting linked list as a string representing the number in its correct order.
- Please provide variables for me to use to hold the linked lists in your code
- Choose any programming language you like
- You can use any external libraries that you feel will help you
- Feel free to use AI to assist your development

**Examples:**

![add_linked_lists](https://github.com/VC-CodeLabs/Add_Two_Numbers/assets/154607214/c61b0320-7213-4be9-89e3-f2d6555e8a5c)

**Example 1:**
```
Input:
l1 = [2, 4, 3] (represents 342)
l2 = [5, 6, 4] (represents 465)
Output:
Linked list: [7, 0, 8]
String: "807"
```

**Example 2:**
```
Input:
l1 = [0]
l2 = [0]
Output:
Linked list: [0]
String: "0"
```

**Example 3:**
```
Input:
l1 = [9, 9, 9, 9, 9, 9, 9]
l2 = [9, 9, 9, 9]
Output:
Linked list: [8, 9, 9, 9, 0, 0, 0, 1]
String: "10009998"
```

**Scoring**</br>
- Solutions must pass all provided test cases, including edge cases.
 Fast execution times will be rewarded, but solutions must first and foremost be correct and complete.
- The fastest solution from each of the top three languages will be considered if more than three languages are submitted. So if I get 5 solutions in C++ that are all super fast, and I get one in Java that is slower than any solution in C++, and I get one in Python that is slower than C++ and Java, the winners are still C++, Java, and Python. The fastest solution from the top three languages will be considered if three or more languages are submitted.
- The fastest, correct solution will win if three or fewer languages are submitted.
- Performance will be measured by execution time.

**Due Date**</br>
Please have the solution emailed to me or a PR submitted to the GitHub repository by Sunday, July 7th, by midnight.

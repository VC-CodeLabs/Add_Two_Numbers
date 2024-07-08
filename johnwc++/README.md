The main (and only) class is addTwoNumbers.cpp.

In the main function, there are 2 variables that represent the numbers to add:
* val1
* val2

These are vectors of integers. They can store the number in forward (highest to lowest) order or 
reverse order (lowest to highest).

Depending on how you format your numbers, you can use one of two methods to convert to a ListNode.

```
// For Forward ordered numbers
numToListNode(vector<int> &val);

// For reverse ordered numbers
reverseNumToListNode(vector<int> &val);
```

The default implementation uses `reverseNumToListNode();`

# Building

This requires cmake to be installed.

To build:
```
make
```

# Execution

After building, run:
```
./addTwoNumbers
```

# Algorithm

For each number in ListNode 1:
  If ListNode 2 is not null:
     sum = ListNode 1 + ListNode 2
  else
     sum = ListNode 1

  Add any carry over from previous loop

  Append the ones digit of the sum onto the resulting list we're building.
  Determine if there's carry over (sum >= 10)

After finishing ListNode 1, and if ListNode 2 is still not null:
    While ListNode 2 is not null
        Add carry over to ListNode 2
        Append the ones digit of sum to result list
        Determine if there's carry over (sum >= 10)

Finally, if there's any remaining carry over, add that to the end of the list.


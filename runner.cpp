#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <cctype>  // For isspace
#include "main.cpp"

using namespace std;

// Helper function to convert vector to linked list
ListNode* vectorToList(const vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : vec) {
        if (!head) {
            head = new ListNode(num);
            tail = head;
        } else {
            tail->next = new ListNode(num);
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


// Helper function to parse input vectors
vector<int> parseVector(const string& line) {
    vector<int> result;
    stringstream ss(line.substr(line.find('[') + 1));
    int number;
    char ch;
    while (ss >> number) {
        result.push_back(number);
        ss >> ch; // To consume the comma
    }
    return result;
}


// Struct to store one test case
struct TestCase {
    vector<int> l1;
    vector<int> l2;
    vector<int> expectedOutput;
    string expectedString;
};


 vector<TestCase> getTestCases() {
    ifstream inputFile("Add_Two_Reversed_Linked_Lists_Tests.txt");
    string line;
    vector<TestCase> testCases;

    while (getline(inputFile, line)) {
        if (line.find("TEST") != string::npos) {
            TestCase testCase;
            
            // Read the input lines
            getline(inputFile, line);
            testCase.l1 = parseVector(line);

            getline(inputFile, line);
            testCase.l2 = parseVector(line);

            getline(inputFile, line); 
            while (line.empty() || all_of(line.begin(), line.end(), [](unsigned char c) { return isspace(c); })) {
                getline(inputFile, line);
            }

            // get correct output
            testCase.expectedOutput = parseVector(line);
            getline(inputFile, line);
            testCase.expectedString = line.substr(line.find('"') + 1, line.rfind('"') - line.find('"') - 1);
            testCases.push_back(testCase);
        }
    }

    inputFile.close();
    
    return testCases;
}

// Main function to process the file and run tests
int main() {
    vector<TestCase> testCases = getTestCases();
    for (const auto& testCase : testCases) {
        ListNode* list1 = vectorToList(testCase.l1);
        ListNode* list2 = vectorToList(testCase.l2);

        auto start = chrono::high_resolution_clock::now();
        ListNode* result = addTwoNumbers(list1, list2);
        string resultString = listToString(result);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        vector<int> resultVector = listToVector(result);

        bool passedTests = (testCase.expectedOutput == resultVector && resultString == testCase.expectedString);
        if (!passedTests) {
            cout << "Test case failed." << endl;
        }
        cout << "Execution time: " << duration.count() << " seconds" << endl;
    }
    return 0;
}

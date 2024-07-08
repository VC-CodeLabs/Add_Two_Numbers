#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <cctype>
#include "main.cpp"

using namespace std;

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


/**
 * Retrieves test cases from a file and returns them as a vector.
 * 
 * @return A vector of test cases.
 */
 vector<TestCase> getTestCases() {
    ifstream inputFile("../Add_Two_Reversed_Linked_Lists_Tests.txt");
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

/**
 * Runs a series of test cases for the addTwoNumbers function and measures the execution time.
 */
int main() {
    vector<TestCase> testCases = getTestCases();
    double totalTime = 0.0;
    int numRuns = 10000;


    for (int i = 0; i < numRuns; i++) {
        for (const auto& testCase : testCases) {
            ListNode* list1 = vectorToList(testCase.l1);
            ListNode* list2 = vectorToList(testCase.l2);

            auto start = chrono::high_resolution_clock::now();
            ListNode* result = addTwoNumbers(list1, list2);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;

            vector<int> resultVector = listToVector(result);

            bool passedTest = (testCase.expectedOutput == resultVector) ;
            if (!passedTest) {
                cout << "Test case failed." << endl;
            }
            totalTime += duration.count();
        }
    }

    cout << "AddTwoNumbers Total execution time for " << numRuns << " runs of " << testCases.size() << " test cases: " << totalTime << " seconds" << endl;
    return 0;
}

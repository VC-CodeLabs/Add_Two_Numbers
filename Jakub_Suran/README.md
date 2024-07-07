# Solution to Add Two Numbers CodeLab

- I solved the problem by iterating through both linked lists and adding the values from the current nodes, while keping track of the carry. I used ostringstream to build the string concurently (in the same loop) with adding the values and creating the new linked list. At the end I reversed the string to obtain the correct representation. 

- I created a runner file that consideres all test cases from the `Add_Two_Reversed_Linked_Lists_Tests.txt` file and runs them 10000 times to examine the performance.

### How to run
Use the following commands to compile and run either the `main.cpp` file with basic test case or `runner.cpp` with all provided test cases as described above.
I decided to use Profile-Guided Optimization (PGO) which is a compiler optimization technique that improves program performance by using data collected from running the program to inform and guide the optimization process.

- **main.cpp**
```
g++ -O3 -march=native -funroll-loops -fprofile-generate -o main_gen main.cpp
./main_gen
g++ -O3 -march=native -funroll-loops -fprofile-use -fprofile-correction -flto -fomit-frame-pointer -fstrict-aliasing -o main main.cpp
./main
```

- **runner.cpp**
```
g++ -DRUNNER -O3 -march=native -funroll-loops -fprofile-generate -o runner_gen runner.cpp 
./runner_gen
g++ -DRUNNER -O3 -march=native -funroll-loops -fprofile-use -fprofile-correction -flto -fomit-frame-pointer -fstrict-aliasing -o runner runner.cpp 
./runner
```
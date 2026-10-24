AP3 – C.A.L.S Credit Sorter

Student: Ahmad Alkhaldy

Student ID: 17218061

Module: 4010SCN – Software Engineering

Project overview

The AP3 programme adds the credit history functionality to the C.A.L.S system. It will generate the credit values, count how many times each value carries on, sort the history in both ascending and descending order and calculate the min, max, average and median. It's been made to function with a 20 numbers between 0 and 100.

Functions

- GenerateCredits() returns a vector of int with 20 randomly generated values. Each value is between 0 and 100 inclusive. The values are going to be the same every time the program is run because a fixed seed is being used.

- FoundAmount(int amount, vector<int> credits) 

It takes a number and calculates how many times it appears on the credits list; if the number is not  in the list then 0 is returned.

- SortCredits(bool ascend, vector<int> credits) sorts the credits. If ascend is true it's a sort from smallest to largest. If false it's a sort from largest to smallest. The original list is left unaltered as the function operates on a copy of the list.

The program also has a number of helper functions to display the credit values and to print out the min, max, the average and the median. The median function will work for both odd and even length lists.

How to compile and run

Open your terminal. CD into the root of your coursework repo. Run the next commands coming up:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic AP3/main.cpp -o ap3_program

./ap3_program
```

Each time you run it the generated numbers will be the same, so the sorting results and the statistics will also be the same.

Testing plan

Run the AP3 program prior to submission and note what you see. Check the following:

GenerateCredits() returns 20 numbers. All numbers should be between 0 and 100.

2. FoundAmount() does the job of counting duplicates. The example is looking for the first generated number, which is 51. It should appear once.

3. FoundAmount() returns 0 if the number isn't in the list. The example is looking for 101 which isn't in the generated range.

4. SortCredits(true, …) prints the numbers from smallest to largest.

5. SortCredits(false, …) prints the numbers from largest to smallest.

6. The min, max, mean and median all match the figures in the list.

Evidence: After running the program, on your Mac add a screenshot named Evidence.png.

Sorting approach

I used the std::sort to sort the numbers in ascending order. For descending order I used std::sort with greater<int>() to sort the numbers from largest to smallest.

AI usage

I used ChatGPT to support my understanding of the AP3 tasks, assist with writing the code and README, and help me solve and fix errors.
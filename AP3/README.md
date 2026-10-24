# AP3 – C.A.L.S Credit Sorter

**Student:** Ahmad Alkhaldy  
**Student ID:** 17218061  
**Module:** 4010SCN – Software Engineering

## Project overview

AP3 adds credit history features to the C.A.L.S system. The program generates simulated credit values, counts how often a value appears, sorts the history in both directions and calculates basic statistics.

## Functions

- `GenerateCredits()` returns a `vector<int>` containing 20 randomly generated values from 0 to 100 (inclusive).
- `FoundAmount(int amount, vector<int> credits)` returns the number of occurrences of `amount` in the vector, or 0 if it does not appear.
- `SortCredits(bool ascend, vector<int> unsorted)` returns a sorted copy. `true` gives ascending order; `false` gives descending order.

The program also includes helper functions for displaying credit values and printing the lowest value, highest value, average and median. The median calculation works for both odd and even vector sizes.

## How to compile and run

Open the terminal at the root of the coursework repository and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic AP3/main.cpp -o ap3_program
./ap3_program
```

The generated numbers change between runs, so the sorting results and statistics will also change.

## Testing plan

Before submission, run the program and record the observed results. Check the following:

1. `GenerateCredits()` produces at least 20 values, all between 0 and 100.
2. `FoundAmount()` counts duplicates: the built-in example checks that 10 occurs three times.
3. `FoundAmount()` returns 0 for a missing value: the example searches for 99.
4. `SortCredits(true, ...)` prints values from smallest to largest.
5. `SortCredits(false, ...)` prints values from largest to smallest.
6. The minimum, maximum, average and median match the generated values.

**Evidence:** Add your own screenshot and screen-recording link here after running the program on your Mac.

## Sorting approach

I used `std::sort` to put the numbers in ascending order. When descending order is requested, the function reverses the sorted copy. This keeps the original generated credit history unchanged. Comments in the code explain the steps.

## AI usage

ChatGPT assisted with writing and explaining the C++ implementation, preparing this README and planning tests. I will review and test the program before submitting it.

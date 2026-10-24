#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <iomanip>

using namespace std;

// Task 1: Generate at least 20 credit values between 0 and 100.
vector<int> GenerateCredits()
{
    vector<int> credits;

    // Fixed seed makes the generated results repeatable.
    mt19937 generator(42);
    uniform_int_distribution<int> distribution(0, 100);

    for (int i = 0; i < 20; i++)
    {
        credits.push_back(distribution(generator));
    }

    return credits;
}

// Task 2: Count how many times a value appears.
int FoundAmount(int target, vector<int> credits)
{
    int count = 0;

    for (int credit : credits)
    {
        if (credit == target)
        {
            count++;
        }
    }

    return count;
}

// Task 3: Sort credits in ascending or descending order.
vector<int> SortCredits(bool ascend, vector<int> unsorted)
{
    // std::sort is used because it is efficient and reliable.
    // Sorting a copy preserves the original credit history.
    if (ascend)
    {
        sort(unsorted.begin(), unsorted.end());
    }
    else
    {
        sort(unsorted.begin(), unsorted.end(), greater<int>());
    }

    return unsorted;
}

// Display the values in a vector.
void PrintCredits(const vector<int>& credits)
{
    for (size_t i = 0; i < credits.size(); i++)
    {
        cout << credits[i];

        if (i + 1 < credits.size())
        {
            cout << ", ";
        }
    }

    cout << endl;
}

// Calculate and display credit statistics.
void PrintStatistics(const vector<int>& credits)
{
    if (credits.empty())
    {
        cout << "No credits available." << endl;
        return;
    }

    vector<int> sorted = SortCredits(true, credits);

    int lowest = sorted.front();
    int highest = sorted.back();

    double total = accumulate(sorted.begin(), sorted.end(), 0.0);
    double average = total / sorted.size();

    double median;

    // For an even number of values, average the middle two.
    // For an odd number, use the middle value.
    size_t middle = sorted.size() / 2;

    if (sorted.size() % 2 == 0)
    {
        median = (sorted[middle - 1] + sorted[middle]) / 2.0;
    }
    else
    {
        median = sorted[middle];
    }

    cout << "The lowest is " << lowest
         << ", the highest is " << highest << endl;

    cout << "The average is " << average << endl;
    cout << "The median is " << median << endl;
}

int main()
{
    cout << "C.A.L.S Credit Sorter" << endl;

    // Generate the credit history.
    vector<int> credits = GenerateCredits();

    cout << "\nGenerated credit history ("
         << credits.size() << " values):" << endl;

    PrintCredits(credits);

    // Search for a value that definitely exists.
    // Using credits[0] ensures the result matches the generated data.
    int searchValue = credits[0];

    cout << "\nSearch example: " << searchValue
         << " appears "
         << FoundAmount(searchValue, credits)
         << " times." << endl;

    // Search for a value that is not in the generated history.
    int missingValue = 101;

    cout << "Search example: " << missingValue
         << " appears "
         << FoundAmount(missingValue, credits)
         << " times." << endl;

    // Sort in ascending order.
    vector<int> ascending = SortCredits(true, credits);

    cout << "\nAscending credit history:" << endl;
    PrintCredits(ascending);

    // Sort in descending order.
    vector<int> descending = SortCredits(false, credits);

    cout << "\nDescending credit history:" << endl;
    PrintCredits(descending);

    // Display minimum, maximum, average and median.
    cout << "\nCredit history statistics:" << endl;
    PrintStatistics(credits);

    return 0;
}
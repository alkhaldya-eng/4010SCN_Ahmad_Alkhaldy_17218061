#include <iostream>
#include <string>
using namespace std;

int main()
{
    // int main() is used because it is the starting point of the program.
    // return 0 means the program has finished successfully.

    string name;
    int A, B;

    // Ask the user for their name and capture their input.
    cout << "Enter your name: ";
    cin >> name;

    // Display the welcome message.
    cout << "Welcome " << name << " to C.A.L.S!" << endl;

    // Ask the user to enter two integer numbers.
    cout << "Enter number A: ";
    cin >> A;

    cout << "Enter number B: ";
    cin >> B;

    // Display the addition result.
    cout << "Addition: " << A + B << endl;

    // Display the multiplication result.
    cout << "Multiplication: " << A * B << endl;

    // Check that B is not zero before division and remainder.
    if (B != 0)
    {
        // Convert A to a float so division can produce a decimal answer.
        cout << "Division: " << static_cast<float>(A) / B << endl;

        // The % operator calculates the remainder.
        cout << "Remainder: " << A % B << endl;
    }
    else
    {
        cout << "Division and remainder cannot be calculated because B is zero." << endl;
    }

    // Display the goodbye message.
    cout << "Goodbye " << name
         << ", See you again at C.A.L.S!" << endl;

    return 0;
}

#include <iostream>
#include <limits>
using namespace std;

// Function 1: Convert points into C.A.L.S credits
int PointsConverter(int Points)
{
    if (Points < 0)
    {
        return 0;
    }

    return static_cast<int>(Points * 2.4 - 5);
}

// Function 2: Check Gold membership
bool GoldStatusChecker(int points, bool isVerified, float days)
{
    if (isVerified && points > 100)
    {
        return true;
    }

    if (days > points || days > 60)
    {
        return true;
    }

    return false;
}

// Function 3: User service menu
void UserService()
{
    int option = 0;
    int credits = 0;

    cout << "Hello. Welcome to the User service." << endl;

    while (true)
    {
        cout << "Please type in an option of 1, 2, or 3: ";

        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (option == 1)
        {
            int points = 0;

            cout << "Please enter your points: ";

            if (!(cin >> points))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number." << endl;
                continue;
            }

            credits = PointsConverter(points);

            cout << "Your current C.A.L.S credits are: "
                 << credits << endl;
        }
        else if (option == 2)
        {
            int verifiedInput = 0;
            float days = 0;

            cout << "Are you verified? (1 = Yes, 0 = No): ";

            if (!(cin >> verifiedInput) ||
                (verifiedInput != 0 && verifiedInput != 1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter 1 or 0." << endl;
                continue;
            }

            cout << "Please enter your number of days: ";

            if (!(cin >> days))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number." << endl;
                continue;
            }

            bool isVerified = (verifiedInput == 1);

            if (GoldStatusChecker(credits, isVerified, days))
            {
                cout << "You are a gold member." << endl;
            }
            else
            {
                cout << "You are not a gold member." << endl;
            }
        }
        else if (option == 3)
        {
            cout << "ending system, goodbye!" << endl;
            break;
        }
    }
}

int main()
{
    UserService();
    return 0;
}
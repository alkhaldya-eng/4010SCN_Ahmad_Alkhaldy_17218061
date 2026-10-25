AP4 – C.A.L.S Membership

Student: Ahmad Alkhaldy

Student ID: 17218061

Module: 4010SCN – Software Engineering

Project overview

The AP4 program adds a membership system to C.A.L.S using C++ classes. It stores member details, assigns a unique ID to each new membership, tracks credit balances and gives Gold members a credit multiplier.

Classes and methods

Member

- Private data: name (string), age (int), credit (float), counter (static int) and ID (int).
- The constructor accepts a name and age, starts credit at zero, assigns the current counter as the ID and then increases the counter.
- GetName() and SetName() read and update the member's name.
- GetAge() and SetAge() read and update the member's age.
- Details() prints the member's name, age and ID.
- AddCredits(float amount) adds the supplied amount to the credit balance.
- GetCredits() returns the current credit balance so the program can display and check it without accessing private data directly.
- MembershipAmount() is a static method returning the number of memberships created.

GoldMember

- GoldMember publicly inherits from Member.
- Its constructor passes the name and age to the Member constructor.
- Its overridden AddCredits(float amount) multiplies the supplied amount by 1.4 before adding it to the balance using Member::AddCredits().

How to compile and run

Open a terminal in the root of the coursework repository and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic AP4/main.cpp -o ap4_program
./ap4_program
```

Testing

The main() function creates two regular members and one Gold member. It prints their details and IDs, adds credits, updates a member's name and age, checks the getters and displays the total membership count.

Expected checks:

1. Three created memberships have IDs 0, 1 and 2.
2. A regular member given 100 credits has a balance of 100.00.
3. A second regular member given 50 credits has a balance of 50.00.
4. A Gold member given 100 credits has a balance of 140.00.
5. Updating a name and age is reflected in Details() and the getters.
6. MembershipAmount() returns 3.

The output from a successful run is saved in sample_output.txt. A screenshot of the terminal output can be saved as Evidence.png.

Design approach

The Member class keeps its data private, so other code uses public methods instead of changing the stored values directly. GoldMember inherits the shared member behaviour and changes only the credit calculation. Its AddCredits() method calls the base-class method after applying the multiplier, so it does not need direct access to the private credit attribute.

AI usage

ChatGPT assisted with drafting the code and README, explaining the implementation and checking compilation and test output. I will review and run the program myself before submission.

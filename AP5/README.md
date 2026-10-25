AP5 - C.A.L.S Employee System

Module: 4010SCN - Programming and Software Development

Overview
This is a reference implementation of the AP5 employee and payroll system. Review and adapt the implementation to your own understanding before using it in assessed work.

Features
Employee: name, annual salary, unique staff ID, getters and setters, salary validation, and virtual monthly pay calculation.
Manager: inherits Employee, assigns employees without duplicates, removes employees, searches by staff ID, calculates manager pay with a 10% increment per managed employee, and calculates total monthly team pay.
Admin: inherits Employee, calculates monthly pay with a 15% bonus, and compares two employees by annual salary, returning the first on ties.

Compile and run from the repository root

g++ -std=c++17 -Wall -Wextra -pedantic AP5/main.cpp -o ap5_program
./ap5_program

Testing
The example program demonstrates unique IDs, normal pay, admin bonus, manager bonus, duplicate prevention, searching, removal, negative salary rejection, getters/setters, salary comparison including ties, and polymorphic pay calculations. The accompanying sample_output.txt records output from a local run.

Design notes
Manager stores non-owning Employee pointers. The referenced Employee objects must stay alive for as long as the manager stores them. Virtual CalculatePay allows payroll logic to use the appropriate implementation for Employee, Manager, and Admin.

Evidence
Run the code on your own Mac and capture the actual output for your evidence. The sample output is illustrative and is not a substitute for your own evidence.

AI use
This reference implementation and README were generated with ChatGPT. Any assessed submission should accurately acknowledge AI assistance in accordance with your module's rules. Be prepared to explain and demonstrate your own work in the AP5 viva.

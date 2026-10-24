AP2 – Building C.A.L.S Functionality
Student Name: Ahmad Alkhaldy
Student ID: 17218061

Module: 4010SCN – Software Engineering

Project Overview

This project builds on AP1 by creating the C.A.L.S system in C++.

I am building the C.A.L.S system in C++ to let users convert points into credits check for Gold membership and use a menu.

Functions

1. PointsConverter()

The feature turns user points into C.A.L.S credits.

If the points are negative the C.A.L.S function returns 0.

If the points are not negative the calculation is points multiplied by 2.4.5.

The final number is returned as an integer.

2. GoldStatusChecker()

This function checks if a user can receive a Gold membership.

A user receives Gold membership if any of the following is true:

- The user has than 100 credits.

- The number of days the user has is greater than the user’s credits.

- The number of days the user has is greater than 60.

The C.A.L.S feature returns true or false.

3. UserService()

This function presents a menu with three options.

Option 1: Change points into credits.

Option 2: Check if the user is a Gold member.

Option 3: Stop the running programme

The menu repeats until the user selects option 3.

How to Run the Program

I opened the terminal, in the project folder.

Compile the code:

```bash

g++ -std=c++17 -Wall -Wextra -pedantic AP2/main.cpp -o ap2

```

Start the program:

```bash

./ap2

```

Testing

I used the VS Code terminal to test if the program works.

Test 1 – Points Conversion

Input: 50 points

I entered 50 points.

Expected result: 115 credits

Result: 115 credits

Status: Passed

Test 2 – Gold Membership

Credits: 115

I had 115 credits.

Verified: Yes (1)

Days: 10

I had 10 days.

Expected result: Gold member

Result: Gold member

Status: Passed

Test 3 – Exit Program

Input: 3

I entered 3.

Expected result: The program shows a goodbye message. Ends.

Actual result: The program showed `ending system, goodbye!`. Ended.

Status: Passed

Evidence

I recorded a video showing the program compiling and working in the terminal.
https://livecoventryac-my.sharepoint.com/:v:/g/personal/alkhaldya_uni_coventry_ac_uk/IQAAKEiDO8H-S78x1JVJiBQQAVGwSVRBEUOdNq-PHsHOlbA?email=ringt%40uni.coventry.ac.uk&e=mGDvVz&xsdata=MDV8MDJ8YWxraGFsZHlhQHVuaS5jb3ZlbnRyeS5hYy51a3wyNTQzMmMzM2IzNzk0NzI4NjlkZTA4ZGYzMWE5NDIxMXw0YjE4YWI5YTM3NjU0YWJlYWM3YzBlMGQzOThhZmQ0ZnwwfDB8NjM5Mjg0Mjc1MTg0MzEyNzAwfFVua25vd258VFdGcGJHWnNiM2Q4ZXlKRmJYQjBlVTFoY0draU9uUnlkV1VzSWxZaU9pSXdMakF1TURBd01DSXNJbEFpT2lKWGFXNHpNaUlzSWtGT0lqb2lUV0ZwYkNJc0lsZFVJam95ZlE9PXwwfHx8&sdata=Ui9ZaTlzb1M5cEhadXhCTzhMZXEzZUY1aFZKeFhqSkFqdnROY0liZDdIOD0%3d

The video shows converting points checking Gold membership and ending the program.

AI Usage

ChatGPT aided me with ideas and explained the C++ code and fix Git issues.
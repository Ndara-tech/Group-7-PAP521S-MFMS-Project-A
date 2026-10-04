# Municipal Financial Management System (MFMS)

# PAP521S – Programming in Practice
Project A – Municipal Financial Management System
Programming Language: ANSI C (C99)
Development Environment :Visual Studio Code + GCC

Group Number: 7

 Group Members
1. Elkana kamati 223093971
2. Silimbani Simwazi 225111713
3. Ndevahokwa Hangula 219091714
4. Bonifatius Haihambo 216011221
5. Liuma Ndara 225009390
6. Festus Shindume 226126110
7. Johannes Namupala 223017493

 Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application created to provide a foundation system for managing basic municipal financial and administrative information.
The system provides modules for employee management, departmental budgets, suppliers, municipal assets and reports.

# System Features

# 1. Employee Management
- Add employees
- Display employees
- Search for employees
- Store employee department and salary information
- Calculate employee salary information

# 2. Budget Management
- Add departmental budgets
- Record expenditure
- Calculate remaining budget
- Determine whether expenditure is within or over budget
- Display departmental budget information

# 3. Supplier Management
- Add suppliers
- Display suppliers
- Search suppliers by Supplier ID
- Store supplier name, email, telephone number and location
- Store supplied product/service information

# 4. Asset Management
- Register municipal assets
- Display registered assets
- Search assets by Asset ID
- Store asset name, type, purchase value, department and condition

# 5. Reports
The system produces:
- Employee Report
- Budget Report
- Supplier Report
- Asset Report

The Employee Report displays total employees, average salary, highest salary and lowest salary.
The Budget Report displays total allocated budget, total expenditure, remaining budget and departments exceeding their budgets.

# Login
The system contains a basic login feature before access to the main menu and if login credentials are not right you won't have access to the main menu

Test login credentials:

Username: admin
Password: admin123

# Compilation Instructions

Open the project folder in Visual Studio Code and open the terminal.
Compile the program using GCC:
gcc -std=c99 -Wall -Wextra main.c employees.c budget.c supplier.c assets.c reports.c login.c -o mfms

# How to run the system

On VSS in terminal , run:
.\mfms
i.e only after compilation

Log in and use the numbered menu options to navigate through the system.

# Project Files
- main.c
- employees.c
- employees.h
- budget.c
- budget.h
- supplier.c
- supplier.h
- assets.c
- assets.h
- reports.c
- reports.h
- login.c
- login.h
- README.md

# Individual Responsibilities

Group Member | Student Number | Responsibility

Elkana kamati 223093971 - Documenting and compiling
Silimbani Simwazi 225111713 - Supplier management
Ndevahokwa Hangula 219091714 - Budget Management
Bonifatius Haihambo 216011221 - Employee management
Liuma Ndara 225009390 - Reports
Festus Shindume 226126110 - Asset management
Johannes Namupala 223017493 Main Menu 

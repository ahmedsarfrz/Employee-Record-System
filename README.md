# Employee Record System

This is a simple Employee Record System implemented in C, allowing users to add, list, modify, and delete employee records. The program uses file handling to store employee data.

## Getting Started

### Prerequisites

To compile and run this program, you need a C compiler installed on your system (e.g., gcc) and a Windows environment to use some specific Windows API functions.


### Usage

1. Run the executable `EmployeeRecordSystem` to start the program.
2. Upon launching, you will be prompted to enter your user ID and password. The default user ID is "COMPANY" and the default password is "saffu".
3. You have a limited number of attempts to enter the correct user ID and password. After exceeding the limit, you won't be able to access the system.
4. Once logged in, the program will present a menu with the following options:
   - Add Record: Add a new employee record to the system.
   - List Record: Display the list of all employee records stored in the system.
   - Modify Record: Update an existing employee record by entering the employee's name.
   - Delete Record: Delete an existing employee record by entering the employee's name.
   - Exit: Close the program.

### File Storage

The employee data is stored in a binary file named "EMP.dat". Each employee record is stored as a structure containing name, age, and basic salary.

## Contributing

This project is developed as a simple educational exercise and contributions are not expected. However, if you find any issues or have suggestions for improvement, feel free to create a pull request or open an issue.



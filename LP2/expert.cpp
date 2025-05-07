#include <iostream>
#include <string>
#include <vector>
#include <limits> // Required for numeric_limits

using namespace std;

struct Employee {
    string name;
    string department;
    string position;
    int rating1;
    int rating2;
    int rating3;
    int rating4;
    int rating5;

    Employee(string n, string dept, string pos)
        : name(n), department(dept), position(pos), rating1(0), rating2(0),
          rating3(0), rating4(0), rating5(0) {}

    // Method to print performance summary with clear advice
    void printPerformanceSummary(const vector<string>& questions) {
        cout << "\nPerformance Summary for Employee: " << name << endl;
        cout << "Department: " << department << " | Position: " << position << endl;

        cout << questions[0] << ": " << rating1 << "/10" << endl;
        cout << questions[1] << ": " << rating2 << "/10" << endl;
        cout << questions[2] << ": " << rating3 << "/10" << endl;
        cout << questions[3] << ": " << rating4 << "/10" << endl;
        cout << questions[4] << ": " << rating5 << "/10" << endl;

        // Providing detailed advice for each factor
        analyzeFactor(questions[0], rating1);
        analyzeFactor(questions[1], rating2);
        analyzeFactor(questions[2], rating3);
        analyzeFactor(questions[3], rating4);
        analyzeFactor(questions[4], rating5);
    }

    // Method to provide clear and actionable advice based on the rating
    void analyzeFactor(const string& category, int rating) {
        cout << "\nAdvice for " << category << ":\n";

        if (rating >= 8) {
            cout << "Excellent! Keep up the great work! You are excelling in this area. Continue your efforts to maintain this high standard. Consider sharing your best practices with your team members." << endl;
        } else if (rating >= 6) {
            cout << "Good! You're performing well, but there's room to improve. Focus on areas where you can enhance your skills." << endl;
        } else if (rating >= 4) {
            cout << "Needs Improvement. Your performance in this area needs attention. Seek feedback or participate in training to improve." << endl;
        } else {
            cout << "Unsatisfactory. Immediate attention is required. Work with a mentor or take training to improve." << endl;
        }
    }
};

class EmployeePerformanceManagement {
private:
    vector<Employee> employees;

public:
    // Method to add employee and their performance ratings
    void addEmployee() {
        string name, department, position;
        cout << "Enter employee name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        // Select department
        cout << "Enter department (IT, Finance , Marketing): ";
        getline(cin, department);

        // Select position based on department
        cout << "Enter position within " << department << " (Manager, Developer, Customer Support): ";
        getline(cin, position);

        Employee newEmployee(name, department, position);
        vector<string> questions;

        // Get questions based on position
        if (position == "Manager") {
            questions = {"Leadership Skills", "Strategic Thinking", "Team Motivation", "Decision Making", "Delegation"};
        } else if (position == "Developer") {
            questions = {"Problem Solving", "Coding Skills", "Technical Knowledge", "Code Quality", "Team Collaboration"};
        } else if (position == "Customer Support") {
            questions = {"Communication Skills", "Problem Resolution", "Patience", "Product Knowledge", "Customer Satisfaction"};
        } else {
            cout << "Invalid position entered." << endl;
            return;
        }

        // Getting ratings for the selected questions
        newEmployee.rating1 = getRating(questions[0]);
        newEmployee.rating2 = getRating(questions[1]);
        newEmployee.rating3 = getRating(questions[2]);
        newEmployee.rating4 = getRating(questions[3]);
        newEmployee.rating5 = getRating(questions[4]);

        // Add the new employee to the vector
        employees.push_back(newEmployee);
        cout << "\nEmployee " << name << " added successfully!" << endl;
    }

    // Method to get rating for each category
    int getRating(const string& category) {
        int rating;
        do {
            cout << "Enter " << category << " Rating (1-10): ";
            cin >> rating;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                rating = 0; // Ensure loop continues
            } else if (rating < 1 || rating > 10) {
                cout << "Invalid rating. Please enter a number between 1 and 10." << endl;
            }
        } while (rating < 1 || rating > 10);
        return rating;
    }

    // Method to view all employee performances
    void viewAllEmployeePerformances() {
        if (employees.empty()) {
            cout << "No employees to display!" << endl;
            return;
        }

        for (size_t i = 0; i < employees.size(); ++i) {
            vector<string> questions;
            if (employees[i].position == "Manager") {
                questions = {"Leadership Skills", "Strategic Thinking", "Team Motivation", "Decision Making", "Delegation"};
            } else if (employees[i].position == "Developer") {
                questions = {"Problem Solving", "Coding Skills", "Technical Knowledge", "Code Quality", "Team Collaboration"};
            } else if (employees[i].position == "Customer Support") {
                questions = {"Communication Skills", "Problem Resolution", "Patience", "Product Knowledge", "Customer Satisfaction"};
            }
            employees[i].printPerformanceSummary(questions);
            cout << "---------------------------------------------" << endl;
        }
    }

    // Method to view a specific employee's performance
    void viewSpecificEmployeePerformance() {
        string name;
        cout << "Enter employee name to view performance: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        bool found = false;
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].name == name) {
                vector<string> questions;
                if (employees[i].position == "Manager") {
                    questions = {"Leadership Skills", "Strategic Thinking", "Team Motivation", "Decision Making", "Delegation"};
                } else if (employees[i].position == "Developer") {
                    questions = {"Problem Solving", "Coding Skills", "Technical Knowledge", "Code Quality", "Team Collaboration"};
                } else if (employees[i].position == "Customer Support") {
                    questions = {"Communication Skills", "Problem Resolution", "Patience", "Product Knowledge", "Customer Satisfaction"};
                }
                employees[i].printPerformanceSummary(questions);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Employee not found!" << endl;
        }
    }
};

int main() {
    EmployeePerformanceManagement system;
    int choice;

    while (true) {
        cout << "\nEmployee Performance Evaluation System" << endl;
        cout << "1. Add Employee and Evaluate Performance" << endl;
        cout << "2. View All Employees' Performance" << endl;
        cout << "3. View Specific Employee Performance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                system.addEmployee();
                break;
            case 2:
                system.viewAllEmployeePerformances();
                break;
            case 3:
                system.viewSpecificEmployeePerformance();
                break;
            case 4:
                cout << "Exiting the system..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}
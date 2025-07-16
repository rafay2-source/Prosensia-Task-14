#include <iostream>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
    float total, average;
    char grade;

public:
    // Parameterized constructor
    Student(int r, string n, float m1, float m2, float m3) {
        rollNumber = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculate();
    }

    // Calculate total, average, and grade
    void calculate() {
        total = marks[0] + marks[1] + marks[2];
        average = total / 3;

        if (average >= 90)
            grade = 'A';
        else if (average >= 75)
            grade = 'B';
        else if (average >= 60)
            grade = 'C';
        else if (average >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    // Display student details
    void display() const {
        cout << left << setw(10) << rollNumber
             << setw(15) << name
             << setw(10) << total
             << setw(10) << fixed << setprecision(2) << average
             << grade << "\n";
    }

    float getTotal() const {
        return total;
    }
};

// Function to sort students by total marks
void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (students[j].getTotal() < students[j + 1].getTotal())
                swap(students[j], students[j + 1]);
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students[n];

    for (int i = 0; i < n; ++i) {
        int r;
        string name;
        float m1, m2, m3;
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> r;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;
        students[i] = new Student(r, name, m1, m2, m3);
    }

    sortStudents(*students, n);

    cout << "\nSorted Student Results (by Total Marks):\n";
    cout << left << setw(10) << "Roll No"
         << setw(15) << "Name"
         << setw(10) << "Total"
         << setw(10) << "Average"
         << "Grade\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; ++i) {
        students[i]->display();
        delete students[i];
    }

    return 0;
}

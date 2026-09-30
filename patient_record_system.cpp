/*
 * Patient Record System
 * ---------------------
 * Programming Fundamentals Project
 * Name       : Ayesha Noor
 * Class      : BS-SE (Regular), 1st Semester
 * University : Lahore College for Women University
 * Submitted To: Miss Ayesha Rafiq
 *
 * Features:
 *   1. Add Patient
 *   2. Show All Patients
 *   3. Search Patient by Name
 *   4. Update Patient Record
 *   5. Delete Patient Record
 *   0. Exit
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_PATIENTS = 10;

// Parallel arrays to store patient data
string name[MAX_PATIENTS], disease[MAX_PATIENTS], doctor[MAX_PATIENTS];
int age[MAX_PATIENTS];
int patientCount = 0;

// ---------------------------------------------------------
// Helper: read an integer safely (no crash on wrong input)
// ---------------------------------------------------------
int readInt(string message, int minValue, int maxValue)
{
    int value;
    while (true)
    {
        cout << message;
        if (cin >> value && value >= minValue && value <= maxValue)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input! Enter a number between "
             << minValue << " and " << maxValue << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Helper: read a full line (allows spaces, e.g. "Ali Khan")
string readLine(string message)
{
    string text;
    do
    {
        cout << message;
        getline(cin, text);
        if (text.empty())
            cout << "This field cannot be empty!\n";
    } while (text.empty());
    return text;
}

// ---------------------------------------------------------
// Function to add patient
// ---------------------------------------------------------
void addPatient()
{
    if (patientCount < MAX_PATIENTS)
    {
        cout << "\n--- Add New Patient ---\n";
        name[patientCount]    = readLine("Enter Patient Name: ");
        age[patientCount]     = readInt("Enter Age: ", 0, 120);
        disease[patientCount] = readLine("Enter Disease: ");
        doctor[patientCount]  = readLine("Enter Doctor Name: ");

        patientCount++;
        cout << "\nPatient Added Successfully!\n";
    }
    else
    {
        cout << "\nPatient limit reached!\n";
    }
}

// ---------------------------------------------------------
// Function to show patients
// ---------------------------------------------------------
void showPatients()
{
    if (patientCount == 0)
    {
        cout << "\nNo Patient Record Found! Please first add a patient.\n";
    }
    else
    {
        for (int i = 0; i < patientCount; i++)
        {
            cout << "\nPatient " << i + 1 << endl;
            cout << "Name: "    << name[i]    << endl;
            cout << "Age: "     << age[i]     << endl;
            cout << "Disease: " << disease[i] << endl;
            cout << "Doctor: "  << doctor[i]  << endl;
        }
    }
}

// ---------------------------------------------------------
// Function to search a patient by name
// ---------------------------------------------------------
void searchPatient()
{
    if (patientCount == 0)
    {
        cout << "\nNo Patient Record Found! Please first add a patient.\n";
        return;
    }

    string searchName = readLine("\nEnter name to search: ");
    bool found = false;

    for (int i = 0; i < patientCount; i++)
    {
        if (name[i] == searchName)
        {
            cout << "\nPatient Found (Record " << i + 1 << ")\n";
            cout << "Name: "    << name[i]    << endl;
            cout << "Age: "     << age[i]     << endl;
            cout << "Disease: " << disease[i] << endl;
            cout << "Doctor: "  << doctor[i]  << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo patient found with name \"" << searchName << "\".\n";
    }
}

// ---------------------------------------------------------
// Function to update a patient record
// ---------------------------------------------------------
void updatePatient()
{
    if (patientCount == 0)
    {
        cout << "\nNo Patient Record Found! Please first add a patient.\n";
        return;
    }

    showPatients();
    int num = readInt("\nEnter patient number to update: ", 1, patientCount);
    int i = num - 1;

    cout << "\nEnter new details for patient " << num << ":\n";
    name[i]    = readLine("New Name: ");
    age[i]     = readInt("New Age: ", 0, 120);
    disease[i] = readLine("New Disease: ");
    doctor[i]  = readLine("New Doctor Name: ");

    cout << "\nRecord Updated Successfully!\n";
}

// ---------------------------------------------------------
// Function to delete a patient record
// ---------------------------------------------------------
void deletePatient()
{
    if (patientCount == 0)
    {
        cout << "\nNo Patient Record Found! Please first add a patient.\n";
        return;
    }

    showPatients();
    int num = readInt("\nEnter patient number to delete: ", 1, patientCount);
    int i = num - 1;

    // Shift all records after the deleted one to the left
    for (int j = i; j < patientCount - 1; j++)
    {
        name[j]    = name[j + 1];
        age[j]     = age[j + 1];
        disease[j] = disease[j + 1];
        doctor[j]  = doctor[j + 1];
    }
    patientCount--;

    cout << "\nRecord Deleted Successfully!\n";
}

// ---------------------------------------------------------
// Main function
// ---------------------------------------------------------
int main()
{
    int choice;

    while (true)
    {
        cout << "\n--- Patient Record System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Show Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Delete Patient\n";
        cout << "0. Exit\n";
        choice = readInt("Enter your choice: ", 0, 5);

        if (choice == 1)
        {
            addPatient();
        }
        else if (choice == 2)
        {
            showPatients();
        }
        else if (choice == 3)
        {
            searchPatient();
        }
        else if (choice == 4)
        {
            updatePatient();
        }
        else if (choice == 5)
        {
            deletePatient();
        }
        else if (choice == 0)
        {
            cout << "\nExiting Program. Thank you!\n";
            break;
        }
    }

    return 0;
}

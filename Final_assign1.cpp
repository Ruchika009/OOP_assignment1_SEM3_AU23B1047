#include<iostream>                  // Basic input-output operations are included
#include<string>                    // String operations are included
#include<limits>
using namespace std;

int main() {
    int marks[5];                       // Array to store marks of 5 subjects
    int count = 0;                      // Count subjects with marks below passing
    int sum = 0;                        // Total sum of marks
    int passcount = 0;                  // Count subjects passed
    int suppcount = 0;                  // Count subjects with supplementary
    int gracecount = 0;                 // Count subjects with grace marks
    string subject[5] = {"DCF", "UXD", "DBMS", "OOP", "WA"};  // Subject names
    string input;
    // Loop to input marks for each subject
    for(int i = 0; i < 5; i++) {
        cout << "Enter marks of " << subject[i] << ": ";  // Ask for marks


        //cin >> marks[i];  // Get marks from user
        if(!(cin >> marks[i])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid data entered, should be integer value."<<endl;
            cout << "Enter marks of " << subject[i] << ": ";
            cin>>marks[i];
        
        }

        else{
            // Check if marks are valid (between 0 and 100)
            if (marks[i] > 100 || marks[i] < 0 ) {
                cout << "Maximum number is 100 and minimum number is 0" << endl;
                cout << "Enter marks of " << subject[i] << ": ";
                cin >> marks[i];            // Ask for marks again if invalid
            }
        }
      
        sum += marks[i];                // Add marks to total
    }

    // Loop to analyze the marks and categorize the student's performance
    for (int i = 0; i < 5; i++) {
        if (marks[i] < 50) {            // Check if marks are less than 50
            count++;                    // Increment count for subjects below 50

            if (marks[i] == 47 || marks[i] == 48 || marks[i] == 49) {
                gracecount++;           // Count subjects that can be passed with grace marks
            }
            else {        // If marks are less than 47 , count as supplementary
                suppcount++;
            } 
        } 

        else if (marks[i] >= 50) {      // If marks are 50 or more
            passcount++;                // Increment count for passed subjects
        }   
    }

    // Final decision based on the counts
    if (count > 1) {                    // If more than 1 subject is below 50, student fails
        cout << "Fail" << endl;
    } 
    else if (suppcount == 1) {          // If exactly 1 subject is supplementary
        cout << "Supplementary" << endl;
    } 
    else if (gracecount == 1) {         // If exactly 1 subject can be passed with grace marks
        for (int i = 0; i < 5; i++) {
            int grace = 0;
            if (marks[i] == 47 || marks[i] == 48 || marks[i] == 49) {
                grace = 50 - marks[i];  // Calculate grace marks needed
                cout << "Pass with grace of " << grace << " marks in " << subject[i] << endl;
                break;
            }           
        } 
    } 
    else {  // If student passed all subjects
        if (passcount == 5) {
           cout << "Pass" << endl;
           int percentage = (sum / 5);  // Calculate percentage
           cout << "Total marks: " << sum << endl;
           cout << "Percentage: " << percentage << "%" << endl;
           if (percentage >= 70) {
               cout << "Division: First" << endl;           //criteria for divisions according to percentage. 
           } else if (percentage >= 60 && percentage < 70) {
               cout << "Division: Second" << endl;
           } else if (percentage >= 50 && percentage < 60) {
               cout << "Division: Third" << endl;
           }
       }              
    }        
    return 0;  // End of program
}

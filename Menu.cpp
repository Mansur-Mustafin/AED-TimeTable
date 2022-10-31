//
// Created by ianbe on 27/10/2022.
//

#include "SortFunctions.cpp"
#include "Menu.h"
#include <fstream>
#include <algorithm>

Menu::Menu() {

    cout << "File names are students_classes.csv, classes_per_uc.csv and classes.csv" << endl;
    cout << "Do you want to change file names?" << endl;
    cout << "y/n:";
    string file_choice;
    cin >> file_choice;

    if (file_choice == "y" || file_choice == "Y") {
        string students_classes, classes_per_uc, classes;
        cout << "Please enter the name of the file with students and classes (with .csv):";
        cin >> students_classes;
        cout << "Please enter the name of the file with classes and UCs (with .csv):";
        cin >> classes_per_uc;
        cout << "Please enter the name of the file with classes only (with .csv):";
        cin >> classes;
        cout << endl;

        op = Operations (students_classes, classes_per_uc,classes);

    }
    if (file_choice == "n" || file_choice == "N") {
        op = Operations();

    }
    else {
        cout << "Invalid input." << endl;
    }
}


void Menu::students_operations() {
    cout << "Enter an student code:";
    string studentCode;
    cin >> studentCode;

    cout << "Choose an option:" << endl;
    cout << "1 - Print time table" << endl;

    int choice;
    cin >> choice;



    switch (choice) {

        case 1:
            op.print_time_table(op.GetTimeTable(studentCode));
            break;
        default:
            cout << "Invalid choice" << endl;
            students_operations();
    }
}

void Menu::number_of_students_in_year() {
    cout << "Please enter the year (1, 2 or 3):";
    int year;
    cin >> year;

    if (year == 1 || year == 2 || year == 3) {
        cout << op.N_of_students_in_year(year) << endl;
    }
    else {
        cout << "Invalid input" << endl;
        number_of_students_in_year();
    }
}

void Menu::students_with_name() {
    cout << "Please enter the name you are searching (with first capital letter):";
    string name;
    cin >> name;

    list<Student> v = op.students_with_name(name);

    cout << "How would you like to sort the list?" << endl;
    cout << "1 - Sort by name ascending" << endl;
    cout << "2 - Sort by name descending" << endl;
    cout << "3 - Sort by student code ascending" << endl;
    cout << "4 - Sort by student code descending" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            v.sort(sortStudentsByNameAscending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 2:
            v.sort(sortStudentsByNameDescending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 3:
            v.sort(sortStudentsbyStCodeAscending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 4:
            v.sort(sortStudentsbyStCodeDescending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            show_students_in_year();
    }
}

void Menu::show_students_in_year() {
    cout << "Please enter the year (1, 2 or 3):";
    int year;
    cin >> year;

    if (year == 1 || year == 2 || year == 3) {
        list<Student> v = op.students_in_year(year);

        cout << "How would you like to sort the list?" << endl;
        cout << "1 - Sort by name ascending" << endl;
        cout << "2 - Sort by name descending" << endl;
        cout << "3 - Sort by student code ascending" << endl;
        cout << "4 - Sort by student code descending" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                v.sort(sortStudentsByNameAscending);
                for(auto s : v){
                    cout << s << endl;
                }
                break;
            case 2:
                v.sort(sortStudentsByNameDescending);
                for(auto s : v){
                    cout << s << endl;
                }
                break;
            case 3:
                v.sort(sortStudentsbyStCodeAscending);
                for(auto s : v){
                    cout << s << endl;
                }
                break;
            case 4:
                v.sort(sortStudentsbyStCodeDescending);
                for(auto s : v){
                    cout << s << endl;
                }
                break;
            default:
                cout << "Invalid input" << endl;
                show_students_in_year();
        }

    }
    else {
        cout << "Invalid input" << endl;
        show_students_in_year();
    }


}

void Menu::classes_operations() {
    cout << "Enter an class code:";
    string classCode;
    cin >> classCode;

    cout << "Enter an UC code:";
    string ucCode;
    cin >> ucCode;


    Subject s(ucCode + "," + classCode);

    cout << "Choose an option:" << endl;
    cout << "1 - Get number of students in class" << endl;
    cout << "2 - See students in class" << endl;

    int choice;
    cin >> choice;

    list<Student> v = op.students_in_class(s);

    switch (choice) {

        case 1:
            cout << op.N_of_students_in_class(s) << endl;
            break;
        case 2:
            cout << "How would you like to sort the list?" << endl;
            cout << "1 - Sort by name ascending" << endl;
            cout << "2 - Sort by name descending" << endl;
            cout << "3 - Sort by student code ascending" << endl;
            cout << "4 - Sort by student code descending" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    v.sort(sortStudentsByNameAscending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 2:
                    v.sort(sortStudentsByNameDescending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 3:
                    v.sort(sortStudentsbyStCodeAscending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 4:
                    v.sort(sortStudentsbyStCodeDescending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                default:
                    cout << "Invalid input" << endl;
                    classes_operations();
            }
            break;
        default:
            cout << "Invalid choice";
            classes_operations();
    }
}

void Menu::uc_operations() {
    string classCode = "1LEIC01";

    cout << "Enter an UC code:";
    string ucCode;
    cin >> ucCode;


    Subject s(ucCode + "," + classCode);

    cout << "Choose an option:" << endl;
    cout << "1 - Get number of students in UC" << endl;
    cout << "2 - See students in UC" << endl;

    int choice;
    cin >> choice;

    list<Student> v = op.students_in_UC(s);
    list<Subject> sub = op.N_of_students_in_UC(s);
    int R = 0;
    switch (choice) {

        case 1:
            for(auto i : sub){
                cout << i.get_UCcode() << ',' << i.get_ClassCode() << ' ' << i.get_number_of_student() << endl;
                R += i.get_number_of_student();
            }
            cout << "Total students in the UC: " << R;
            break;
        case 2:
            cout << "How would you like to sort the list?" << endl;
            cout << "1 - Sort by name ascending" << endl;
            cout << "2 - Sort by name descending" << endl;
            cout << "3 - Sort by student code ascending" << endl;
            cout << "4 - Sort by student code descending" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    v.sort(sortStudentsByNameAscending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 2:
                    v.sort(sortStudentsByNameDescending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 3:
                    v.sort(sortStudentsbyStCodeAscending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                case 4:
                    v.sort(sortStudentsbyStCodeDescending);
                    for(auto s : v){
                        cout << s << endl;
                    }
                    break;
                default:
                    cout << "Invalid input" << endl;
                    uc_operations();
            }
            break;
        default:
            cout << "Invalid choice";
            uc_operations();
    }
}

void Menu::students_with_more_uc() {
    cout << "Please enter base number of UC (the program will show students with more UCs than that number):" << endl;
    int n;
    cin >> n;

    list<Student> v = op.students_with_more_UC(n);

    cout << "How would you like to sort the list?" << endl;
    cout << "1 - Sort by name ascending" << endl;
    cout << "2 - Sort by name descending" << endl;
    cout << "3 - Sort by student code ascending" << endl;
    cout << "4 - Sort by student code descending" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            v.sort(sortStudentsByNameAscending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 2:
            v.sort(sortStudentsByNameDescending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 3:
            v.sort(sortStudentsbyStCodeAscending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        case 4:
            v.sort(sortStudentsbyStCodeDescending);
            for(auto s : v){
                cout << s << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            show_students_in_year();
    }
}



void Menu::request_change_class() {
    string current_class, uc_code, student_code, request_class, request_uc;

    cout << "Please enter the UC Code of the classes you want to change:";
    cin >> uc_code;
    cout << endl;

    cout << "Please enter your current class code:";
    cin >> current_class;
    cout << endl;

    cout << "Please enter your current student code:";
    cin >> student_code;
    cout << endl;

    cout << "Please enter the code of the class you want to go:";
    cin >> request_class;
    cout << endl;

    string choice;
    cout << "Would you like to create a new file? (y/n):";
    cin >> choice;

    if (choice == "y" || choice == "Y") {
        ofstream request_file("requests.csv");

        request_file << uc_code << "," << current_class << "," << student_code << "," << uc_code << "," << request_class << "\n";

        request_file.close();
    }
    else if (choice == "n" || choice == "N") {
        fstream request_file;

        request_file.open("requests.csv", ios::app);

        request_file << uc_code << "," << current_class << "," << student_code << "," << uc_code << "," << request_class << "\n";

        request_file.close();
    }else {
        cout << "Invalid input" << endl;
        request_change_class();
    }

}

void Menu::main_menu(){


    while (true) {
    cout << endl;
    cout << "|===========================================================================================|\n"
            "|                  Students                   |                    Classes                  |\n"
            "|=============================================|=============================================|\n"
            "|  See data from specific student        [11] |  See data from specific classes        [21] |\n"
            "|  Get number of students in a year      [12] |                                             |\n"
            "|  List Students with specific name      [13] |                                             |\n"
            "|  Show Students in year                 [14] |                                             |\n"
            "|=============================================|=============================================|\n"
            "|                    UC's                     |                   Requests                  |\n"
            "|=============================================|=============================================|\n"
            "|  See data from specific UC             [31] |  Request to change class               [41] |\n"
            "|  Show students with more than 'X' UCs  [32] |                                             |\n"
            "|=============================================|=============================================|\n"
            "|               Other operations              |                                              \n"
            "|=============================================|                                              \n"
            "|  Exit                                   [0] |                                              \n"
            "|=============================================|\n";

        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;

        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0: exit(0);
            case 11:
                students_operations();
                break;
            case 12:
                number_of_students_in_year();
                break;
            case 13:
                students_with_name();
                break;
            case 14:
                show_students_in_year();
                break;
            case 21:
                classes_operations();
                break;
            case 31:
                uc_operations();
                break;
            case 32:
                students_with_more_uc();
                break;
            case 41:
                request_change_class();
                break;
            default: cout << "Invalid input" << endl;

        }

    }



}
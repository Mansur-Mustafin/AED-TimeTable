//
// Created by ianbe on 27/10/2022.
//

#include "Menu.h"


Menu::Menu() {

    cout << "File names are students_classes.csv, classes_per_uc.csv and classes.csv" << endl;
    cout << "Do you want to change file names?" << endl;
    cout << "y/n: ";
    string file_choice;
    cin >> file_choice;

    if (file_choice == "y" || file_choice == "Y") {
        string students_classes, classes_per_uc, classes;
        cout << "Please enter the name of the file with students and classes (with .csv): ";
        cin >> students_classes;
        cout << "Please enter the name of the file with classes and UCs (with .csv): ";
        cin >> classes_per_uc;
        cout << "Please enter the name of the file with classes only (with .csv): ";
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
    cout << "Enter an student code: ";
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
    cout << "Please enter the year (1, 2 or 3): ";
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
    cout << "Please enter the name you are searching (with first capital letter): ";
    string name;
    cin >> name;

    vector<Student> v = op.students_with_name(name);
    for(auto s : v){
        cout << s << endl;
    }
}

void Menu::show_students_in_year() {
    cout << "Please enter the year (1, 2 or 3): ";
    int year;
    cin >> year;

    if (year == 1 || year == 2 || year == 3) {
        vector<Student> v = op.students_in_year(year);
        for(auto s : v){
            cout << s << endl;
        }
    }
    else {
        cout << "Invalid input" << endl;
        show_students_in_year();
    }

    //FALTA FAZER SORTS AQUI
}

void Menu::classes_operations() {
    cout << "Enter an class code: ";
    string classCode;
    cin >> classCode;

    cout << "Enter an UC code: ";
    string ucCode;
    cin >> ucCode;


    Subject s(ucCode + "," + classCode);

    cout << "Choose an option:" << endl;
    cout << "1 - Get number of students in class" << endl;
    cout << "2 - See students in class" << endl;

    int choice;
    cin >> choice;

    vector<Student> v = op.students_in_class(s);

    switch (choice) {

        case 1:
            cout << op.N_of_students_in_class(s) << endl;
            break;
        case 2:
            for (auto s : v){
                cout << s << endl;
            }
            break;
        default:
            cout << "Invalid choice";
            classes_operations();
    }
}

void Menu::uc_operations() {
    string classCode = "1LEIC01";

    cout << "Enter an UC code: ";
    string ucCode;
    cin >> ucCode;


    Subject s(ucCode + "," + classCode);

    cout << "Choose an option:" << endl;
    cout << "1 - Get number of students in UC" << endl;
    cout << "2 - See students in UC" << endl;

    int choice;
    cin >> choice;

    vector<Student> v = op.students_in_UC(s);

    switch (choice) {

        case 1:
            cout << op.N_of_students_in_UC(s) << endl;
            break;
        case 2:
            for (auto s : v){
                cout << s << endl;
            }
            break;
        default:
            cout << "Invalid choice";
            uc_operations();
    }
}

void Menu::students_with_more_uc() {
    cout << "Please enter base number of UC (the program will show students with more UCs than that number): " << endl;
    int n;
    cin >> n;

    vector<Student> v = op.students_with_more_UC(n);

    for (auto s : v) {
        cout << s << endl;
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
            "|  See data from specific UC             [31] |                                             |\n"
            "|  Show students with more than 'X' UCs  [32] |                                             |\n"
            "|=============================================|=============================================|\n"
            "|               Other operations              |                                              \n"
            "|=============================================|                                              \n"
            "|  Exit                                   [0] |                                              \n"
            "|=============================================|\n";

        cout << endl;
        cout << "Please choose an option: ";
        int option;
        cin >> option;

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
            default: cout << "Invalid input" << endl;

        }

    }



}
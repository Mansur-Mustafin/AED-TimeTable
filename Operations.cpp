//
// Created by Mansur on 16.10.2022.
//

#include <algorithm>
#include "Operations.h"
Operations::Operations(const std::string &fm_student, const std::string &UC_student, const std::string &fm_classes) {
    Read_classes rc = Read_classes (fm_classes);
    Read_student rs = Read_student (fm_student, UC_student);
    this->rs = rs;
    this->rc = rc;
}

vector<Class> Operations::GetTimeTable(const std::string &number)  {
    vector<Subject> subjects =  rs.Bynary_serch_of_student(number).getSubjects();

    //cout << rs.Bynary_serch_of_student(number).get_name() << endl;

    vector <Class> Aulas = {};
    for(const auto& subject : subjects){
        for(const auto& cT : rc.get_classes_T()){
            if(cT.get_Subject() == subject) Aulas.push_back(cT);
        }
        for(const auto& cTP : rc.get_classes_TP()){
            if(cTP.get_Subject() == subject) Aulas.push_back(cTP);
        }
        for(const auto& cPL : rc.get_classes_PL()){
            if(cPL.get_Subject() == subject) Aulas.push_back(cPL);
        }
    }
    return Aulas;
}

int Operations::N_of_students_in_class(Subject key) const{

    vector<Subject> subjects =  rs.get_subjects();
    int low = 0;
    int high = subjects.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < subjects[middle]) high = middle - 1;
        else if(key > subjects[middle]) low = middle + 1;
        else return subjects[middle].get_number_of_student();
    }
    return -1;


}

int Operations::N_of_students_in_UC(Subject key) const{
    int i,R = 0;
    vector<Subject> subjects =  rs.get_subjects();
    int low = 0;
    int high = subjects.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key.UC_is_less(subjects[middle])) high = middle - 1;
        else if(key.get_UCcode() > subjects[middle].get_UCcode()) low = middle + 1;
        else{
            i = middle;
            break;
        }
    }
    int m = i;
    for(m; subjects[m].UC_is_equal(key) ;m++){
        R+= subjects[m].get_number_of_student();
    }
    i--;
    for(i; subjects[i].UC_is_equal(key) ;i--){
        R+= subjects[i].get_number_of_student();
    }
    return R;
}

int Operations::N_of_students_in_year(int n) const {
    int R  = 0;
    vector<Subject> subjects =  rs.get_subjects();
    if(n == 1){

        for(int i = 0; subjects[i].get_year() == 1; i++){
            R+=subjects[i].get_number_of_student();
        }
        return R;
    }
    if(n == 3){

        for(int i = subjects.size() - 1; subjects[i].get_year() == 3; i--){
            R += subjects[i].get_number_of_student();
        }
        return R;
    }

    int low = 0;
    int high = subjects.size() - 1;
    int mid;
    while(low < high){
        mid = low + (high - low) / 2;
        //cout << low << ' ' << mid << ' ' << high << endl;
        if(n <= subjects[mid].get_year()){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    for(int i = low; subjects[i].get_year() == 2; i++){
        R += subjects[i].get_number_of_student();
    }


    return R;
}

bool check_overlapping(vector<Class> classes){

    for(int j = 0; j < classes.size(); j++){
        for(int k = j + 1; k < classes.size(); k++){
            if(classes[j].get_day_index() == classes[k].get_day_index() ){
                if(classes[k].is_equal(classes[j]) && classes[k].get_type() == classes[j].get_type()) continue;
                if(classes[k].get_hora_s() > classes[j].get_hora_f()){
                    cout << classes[j].get_hora_s() << '>' << classes[k].get_hora_f()<< endl;
                    return false;
                }
                if(classes[k].get_hora_f() > classes[j].get_hora_s()) {
                    cout << classes[j].get_hora_f() << '>' << classes[k].get_hora_s() << endl;
                    return false;
                }
            }
        }
    }

    return true;
}

void Operations::print_time_table(vector<Class> aulas) const {
    //sort(aulas.begin(),aulas.end(),[ ] (const Class& c1, class Class& c2) {return c1.get_hora_s() < c2.get_hora_s();});
    //sort(aulas.begin(),aulas.end(),[ ] (const Class& c1, class Class& c2) {return c1.get_day_index() < c2.get_day_index();});

    vector<Class> overlap;
    cout <<  setw(18) << "Monday" << setw(20) << "Tuesday" << setw(22) << "Wednesday" << setw(19) << "Thursday" << setw(19) << "Friday" << endl;
    for(int i = 0; i < 106; i++){cout << '_';}
    cout << endl;
    Hour h1(8);
    Hour max(23.5);
    Hour step(0.5);

    for(h1; h1 < max; h1 = h1 + step){
        if ( h1 < Hour(10)){
            cout << ' ' << h1;
        }else{
            cout << h1;
        }
        cout << '|';
        string Rs;
        for(int i = 0; i <= 4; i++){
            string R = "";
            bool f1 = true;

            for(const auto& aula: aulas){
                if(aula.get_day_index() == i && (aula.get_hora_s() == h1)){
                    f1 = false;
                    if(R.empty()){
                        if(aula.get_type() == "T"){
                            R += aula.get_Subject().get_UCcode() +";" + aula.get_Subject().get_ClassCode() + "  " + aula.get_type();
                        }else{
                            R += aula.get_Subject().get_UCcode() +";" + aula.get_Subject().get_ClassCode() + ' ' + aula.get_type();
                        }

                    }else{
                        overlap.push_back(aula);
                    }
                }
                if(aula.get_day_index() == i && (h1 > aula.get_hora_s() && h1 < aula.get_hora_f() - step ) ){
                    f1 = false;
                    if(R.empty()){
                        R += "...................";
                    }
                }
                if(aula.get_day_index() == i && ( h1 > aula.get_hora_s() && h1 == aula.get_hora_f() - step )){
                    f1 = false;
                    if(R != ""){
                        overlap.push_back(aula);
                        continue;
                    }
                    if(R.empty()){
                        R += "___________________";
                    }
                }
            }
            if(f1){
                if(R.empty()){
                    R += "                   ";
                }
            }
            Rs += R;
            Rs += '|';
        }
        cout << Rs;
        cout << endl;
    }

    for(const auto& aula : overlap){
        cout << aula << endl;
    }
}

vector<Student> Operations::students_in_class(Subject s) const {
    vector<Student> students = rs.get_students();
    vector<Student> R = {};
    for(auto st : students){
        vector<Subject> sub_st = st.getSubjects();
        int low = 0;
        int high = sub_st.size() - 1;
        while(low <= high){
            int middle = low + (high - low) / 2;
            if(s < sub_st[middle]) high = middle - 1;
            else if(s > sub_st[middle]) low = middle + 1;
            else{
                R.push_back(st);
                break;
            }
        }
    }
    return R;
}

vector<Student> Operations::students_in_year(int n) const{

    vector<Student> students = rs.get_students();
    vector<Student> R = {};
    for(auto p : students){
        vector<Subject> subjects = p.getSubjects();
        if(n == 1){
            if(subjects[0].get_year() == n){
                R.push_back(p);
                continue;
            }
            continue;
        }
        if(n == 3){
            if(subjects[subjects.size() - 1].get_year() == n){
                R.push_back(p);
                continue;
            }
            continue;
        }

        if(n == 2){
            int low = 0;
            int high = subjects.size() - 1;
            while(low <= high){
                int mid = low + (high - low ) / 2;
                if( n < subjects[mid].get_year()){
                    high = mid - 1;
                }
                else if(n > subjects[mid].get_year()){
                    low = mid + 1;
                }
                else{
                    R.push_back(p);
                    break;
                }
            }

        }

    }
    return R;
}

vector<Student> Operations::students_in_UC(Subject s) const {
    vector<Student> students = rs.get_students();
    vector<Student> R = {};
    for(auto st: students){
        vector<Subject> subjects = st.getSubjects();
        int low = 0;
        int high = subjects.size() - 1;
        while(low <= high){
            int middle = low + (high - low) / 2;
            if(s.get_UCcode() < subjects[middle].get_UCcode()) high = middle - 1;
            else if(s.get_UCcode() > subjects[middle].get_UCcode()) low = middle + 1;
            else{
                R.push_back(st);
                break;
            }
        }
    }
    return R;
}

vector<Student> Operations::students_with_more_UC(int n) const {
    vector<Student> students = rs.get_students();
    vector<Student> R = {};
    for(auto st : students){
        if(st.getSubjects().size() > n){
            R.push_back(st);
        }
    }
    return R;
}

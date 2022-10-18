//
// Created by musta on 16.10.2022.
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
        cout <<  setw(17) << "Monday" << setw(17) << "Tuesday" << setw(19) << "Wednesday" << setw(16) << "Thursday" << setw(16) << "Friday" << endl;
        for(int i = 0; i < 91; i++){cout << '_';}
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
            string Rs = "";
            for(int i = 0; i <= 4; i++){
                string R = "";
                bool f1 = true;

                for(auto aula: aulas){
                    if(aula.get_day_index() == i && (aula.get_hora_s() == h1)){
                        f1 = false;
                        if(R.empty()){
                            R += aula.get_Subject().get_UCcode() +";" + aula.get_Subject().get_ClassCode();
                        }else{
                            overlap.push_back(aula);
                        }
                    }
                    if(aula.get_day_index() == i && (h1 > aula.get_hora_s() && h1 < aula.get_hora_f() - step ) ){
                        f1 = false;
                        if(R.empty()){
                            R += "................";
                        }
                    }
                    if(aula.get_day_index() == i && ( h1 > aula.get_hora_s() && h1 == aula.get_hora_f() - step )){
                        f1 = false;
                        if(R != ""){
                            overlap.push_back(aula);
                            continue;
                        }
                        if(R.empty()){
                            R += "________________";
                        }
                    }
                }
                if(f1){
                    if(R.empty()){
                        R += "                ";
                    }
                }
                Rs += R;
                Rs += '|';
            }
            cout << Rs;
            cout << endl;
        }

        for(auto aula : overlap){
            cout << aula << endl;
        }
}



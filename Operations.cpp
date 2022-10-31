//
// Created by Mansur on 16.10.2022.
//

#include <algorithm>
#include <list>
#include "Operations.h"
#include <fstream>


Operations::Operations(const std::string &fm_student, const std::string &UC_student, const std::string &fm_classes) {
    Read_classes rc = Read_classes (fm_classes);
    Read_student rs = Read_student (fm_student, UC_student);
    this->rs = rs;
    this->rc = rc;
    ifstream in("Settings.csv");
    string line;
    getline(in, line);
    Cap = stoi(line);
}

Operations::Operations() {
    Read_classes rc = Read_classes ("classes.csv");
    Read_student rs = Read_student ("students_classes.csv", "classes_per_uc.csv");
    this->rs = rs;
    this->rc = rc;
}

int Operations::getCap() const {
    return Cap;
}

list<Class> Operations::GetTimeTable(const std::string &number)  {
    string str = number + ",Mansur,L.EIC001,1LEIC01";
    Student s (str);
    set<Subject> subjects = rs.get_students().find(s)->getSubjects();

    if(rs.get_students().find(s)->get_name() == "Mansur"){
        return {};
    }

    list<Class> Aulas = {};
    set<Class> T = rc.get_classes_T();
    set<Class> TP = rc.get_classes_TP();
    set<Class> PL = rc.get_classes_PL();
    for(const auto& subject : subjects){
        string str = subject.get_ClassCode()+',' + subject.get_UCcode()+ ",Monday,8.0,2,0";
        Class c (str);

        auto it = T.lower_bound(c);
        if(it != T.end()){
            if(it->get_Subject() == subject){
                Aulas.push_back(*it);
                it++;
                if(it != T.end()){
                    if( it->get_Subject() == subject){
                        Aulas.push_back(*it);
                    }
                }
            }
        }

        it = TP.lower_bound(c);
        if(it != TP.end()){
            if( it->get_Subject() == subject){
                Aulas.push_back(*it);
            }
        }

        it = PL.lower_bound(c);
        if(it != PL.end()){
            if(it->get_Subject() == subject){
                Aulas.push_back(*it);
            }
        }
    }
    return Aulas;
}

list<Class> Operations::GetTimeTableforUC(const std::string &UC)  {
    list<Class> Aulas = {};

    set<Class> T = rc.get_classes_T();
    set<Class> TP = rc.get_classes_TP();
    set<Class> PL = rc.get_classes_PL();

    Class s1 ("3LEIC01,"+ UC+ ",Monday,8.0,2,T");
    if(UC <= "L.EIC010"){
        s1 = Class  ("1LEIC01," + UC+ ",Monday,8.0,2,T");
    }
    else if(UC <= "L.EIC020"){
        s1 = Class ("2LEIC01,"+ UC+ ",Monday,8.0,2,T");
    }

    auto it = T.lower_bound(s1);
    if(it != T.end()){
        while(it->get_Subject().get_UCcode() == UC && it != T.end()){
            Aulas.push_back(*it);
            auto it_new = it;
            it_new++;
            while(it->get_day_index() == it_new->get_day_index() && it->get_hora_s() == it_new->get_hora_s() && it != T.end()){
                it_new++;
                it++;
            }
            it++;
        }
    }

    it = TP.lower_bound(s1);
    while(it->get_Subject().get_UCcode() == UC){

        Aulas.push_back(*it);
        it++;
    }

    it = PL.lower_bound(s1);
    while(it->get_Subject().get_UCcode() == UC){
        Aulas.push_back(*it);
        it++;
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

list<Subject> Operations::N_of_students_in_UC(Subject key) const{
    int i,R = 0;
    list<Subject> R_l = {};
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
    for(int m = i; subjects[m].UC_is_equal(key) ;m++){
        R+= subjects[m].get_number_of_student();
        R_l.push_back(subjects[m]);
    }
    i--;
    for(; subjects[i].UC_is_equal(key) ;i--){
        R+= subjects[i].get_number_of_student();
        R_l.push_back(subjects[i]);
    }
    return R_l;
}

int Operations::N_of_students_in_year(int n) const {
    list<pair<string,int>> R_l = {};
    int R  = 0;
    set<Student> students = rs.get_students();
    for(auto s : students){
        set<Subject> classes = s.getSubjects();
        auto it_e = classes.end();
        it_e --;
        auto it_i = classes.begin();
        if(it_i->get_year() == n){
            R++;
            continue;
        }
        if(it_e->get_year() == n){
            R++;
            continue;
        }
        for(it_i; it_i != it_e; it_i++){
            if(it_i->get_year() == n){
                R++;
                break;
            }
        }
    }

    vector<Subject> subjects =  rs.get_subjects();
    for(auto i : subjects) cout << i.get_UCcode() << ' ' << i.get_ClassCode() << endl;
    if(n == 1){
        for(int i = 0; subjects[i].get_year()==1; i++ ){
            //
        }
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

void Operations::print_time_table(list<Class> aulas) const {

    vector<Class> overlap;
    cout << "            Monday             Tuesday             Wednesday           Thursday             Friday" << endl;
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

list<Student> Operations::students_in_class(Subject s) const {
    set<Student> students = rs.get_students();
    list<Student> R = {};
    for(auto st : students){
        set<Subject> sub_st = st.getSubjects();
        auto src = sub_st.find(s);
        if(src != sub_st.end()){
            R.push_back(st);
        }
    }
    return R;
}

list<Student> Operations::students_in_year(int n) const{
    set<Student> students = rs.get_students();
    list<Student> R = {};
    for(auto s : students){
        set<Subject> classes = s.getSubjects();
        auto it_e = classes.end();
        it_e --;
        auto it_i = classes.begin();
        if(it_i->get_year() == n){
            R.push_back(s);
            continue;
        }
        if(it_e->get_year() == n){
            R.push_back(s);
            continue;
        }
        for(it_i; it_i != it_e; it_i++){
            if(it_i->get_year() == n){
                R.push_back(s);
                break;
            }
        }
    }
    return R;
}

list<Student> Operations::students_in_UC(Subject s) const {
    Subject s1;
    if(s.get_UCcode() <= "L.EIC010"){
        s1 = Subject  (s.get_UCcode(), "1LEIC01");
    }
    else if(s.get_UCcode() <= "L.EIC020"){
         s1 = Subject (s.get_UCcode(), "2LEIC01");
    } else{
         s1 = Subject (s.get_UCcode(), "3LEIC01");
    }
    set<Student> students = rs.get_students();
    list<Student> R = {};
    for(auto st: students){
        set<Subject> subjects = st.getSubjects();
        auto it = subjects.lower_bound(s1);
        if(it != subjects.end() && it->get_UCcode() == s.get_UCcode()){
            R.push_back(st);
        }
    }
    return R;
}

list<Student> Operations::students_with_more_UC(int n) const {
    set<Student> students = rs.get_students();
    list<Student> R = {};
    for(auto st : students){
        if(st.getSubjects().size() > n){
            R.push_back(st);
        }
    }
    return R;
}

list<Student> Operations::students_with_name(const std::string &name) const {
    set<Student> students = rs.get_students();
    list<Student> R = {};
    for(auto st : students){
        string temp = "";
        for(int i = 0; i < st.get_name().length(); i++){
            if(st.get_name()[i] == ' '){
                if(name == temp){
                    R.push_back(st);
                    temp = "";
                    break;
                }else{
                    temp = "";
                }
            }
            else{
                temp += st.get_name()[i];
            }
        }
        if(name == temp){
            R.push_back(st);
            temp = "";
        }
    }
    return R;
}


void Operations::processChanges(const std::string &fn) const {
    vector<Subject> subjects =  rs.get_subjects();   // aqui todos turmas com cap de cada
    ofstream log_file("LOGS.txt");
    ReadRequests rq (fn);
    queue<Change> Changes = rq.getChanges();  // fila de pedidos de mudanca


    while(!Changes.empty()){

        Subject cur = Changes.front().getCurSub();
        Subject next = Changes.front().getNextSub();
        Student st = Changes.front().getStudent();

        // test para numero numa turma.
        int low = 0;
        int high = subjects.size() - 1;
        while(low <= high){
            int middle = low + (high - low) / 2;
            if(next < subjects[middle]) high = middle - 1;
            else if(next > subjects[middle]) low = middle + 1;
            else if(subjects[middle].get_number_of_student() > Cap){
                log_file << "Estudante com numero: " << st.get_StudentCode() << " o pedido foi rejetado porque na turma " << '(' << next.get_UCcode() << ',' << next.get_ClassCode() << ')' << " valor atual de estudantes: " << subjects[middle].get_number_of_student() <<  "\n" ;
                log_file << "WARNING " << "turma " << '(' << next.get_UCcode() << ',' << next.get_ClassCode() << ')' << " tem valor max de estudantes: " << subjects[middle].get_number_of_student() <<  "\n" ;
                return;
            }else if(subjects[middle].get_number_of_student() == Cap){
                log_file << "Estudante com numero: " << st.get_StudentCode() << " o pedido foi rejetado porque na turma " << '(' << next.get_UCcode() << ',' << next.get_ClassCode() << ')' << " valor atual de estudantes: " << subjects[middle].get_number_of_student() <<  "\n" ;
            }else break;
        }






        log_file << "Estudante com numero: " << st.get_StudentCode() << ": " << '(' << cur.get_UCcode() << ',' << cur.get_ClassCode() << ')' << " --> " << '(' << next.get_UCcode() << ',' << next.get_ClassCode() << ')' << "\n";


        Changes.pop();
    }

    log_file.close();

}


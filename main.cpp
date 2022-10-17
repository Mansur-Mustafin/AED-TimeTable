#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
int main() {

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    vector<Class> aulas =  op.GetTimeTable("202055237");


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
        string R = "";
        for(int i = 0; i <= 4; i++){
            bool f1 = true;
            for(auto aula: aulas){
                if(aula.get_day_index() == i && (aula.get_hora_s() == h1)){
                    f1 = false;
                    R += aula.get_Subject().get_UCcode() +";" + aula.get_Subject().get_ClassCode();
                }
                if(aula.get_day_index() == i && (h1 > aula.get_hora_s() && h1 < aula.get_hora_f() - step ) ){
                    f1 = false;
                    R += "................";
                }
                if(aula.get_day_index() == i && ( h1 > aula.get_hora_s() && h1 == aula.get_hora_f() - step )){
                    f1 = false;
                    R += "________________";
                }
            }
            if(f1){
                R += "                ";
            }
            R += '|';
        }
        cout << R;
        cout << endl;
    }



    return 0;
}



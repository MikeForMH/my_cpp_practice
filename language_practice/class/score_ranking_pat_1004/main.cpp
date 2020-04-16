//
//  main.cpp
//  score_ranking_pat_1004
//
//  Created by Michael Hui on 20/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cmath>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::swap;

class Student{
private:
    static int _number_of_student;
    string _name;
    string _student_number;
    int _score;
public:
    static vector <Student> _student_info;
    Student(const string &name, const string student_number, const int &score){
        _name = name;
        _student_number = student_number;
        _score = score;
        _student_info.push_back(*this);
        ++_number_of_student;
        return;
    }
    Student(const Student &obj){
        _name = obj._name;
        _student_number = obj._student_number;
        _score = obj._score;
        ++_number_of_student;
    }
    ~Student(){
        --_number_of_student;
    }
    static void quick_sort_ascending(vector <Student> &list, const int &left, const int &right){
        //cout << "testing 2" << endl;
        if(left < right){
            int i = left, j = left, pivot = list[right]._score;
            while(j < right){
                if(list[j]._score < pivot){
                    swap(list[i], list[j]);
                    ++i;
                }
                ++j;
            }
            swap(list[i], list[j]);
            quick_sort_ascending(list, left, i - 1);
            quick_sort_ascending(list, i + 1, right);
        }
        return;
    }
    static void ascending_sort(){
        //cout << "testing" << endl;
        quick_sort_ascending(_student_info, 0, _number_of_student - 1);
    }
    static void output_student_info(const int &index){
        cout << _student_info[index]._name << " " << _student_info[index]._student_number << endl;
    }
};

vector <Student> Student::_student_info;
int Student::_number_of_student = 0;

int main(){
    int number_of_student, score;
    string student_name, student_number;
    cin >> number_of_student;
    for(int i = 0; i < number_of_student; ++i){
        cin >> student_name >> student_number >> score;
        Student(student_name, student_number, score);
    }
    Student::ascending_sort();
    Student::output_student_info(number_of_student - 1);
    Student::output_student_info(0);
    return 0;
}

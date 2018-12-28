//
//  main.cpp
//  virtue_and_talent_pat_1015
//
//  Created by Michael Hui on 27/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Student{
public:
    int _exam_number;
    int _virtue_score;
    int _talent_score;
    int _sum;
    Student(int &exam_number, int &virtue_score, int &talent_score){
        _exam_number = exam_number;
        _virtue_score = virtue_score;
        _talent_score = talent_score;
        _sum = _virtue_score + _talent_score;
    }
    Student(const Student &obj){
        _exam_number = obj._exam_number;
        _virtue_score = obj._virtue_score;
        _talent_score = obj._talent_score;
        _sum = obj._sum;
    }
    Student(){
        _exam_number = -1;
        _virtue_score = -1;
        _talent_score = -1;
        _sum = -1;
    }
};

class Exam{
private:
    int _candidate;
    int _lower_bound;
    int _premium_bound;
    int _pass_student;
    vector <Student> tier_1, tier_2, tier_3, tier_4;
    void quick_sort(vector <Student> &input, const int &left, const int &right){
        if(left < right){
            int i = left, j = left;
            int sum_pivot = input[right]._sum, virtue_pivot = input[right]._virtue_score, number_pivot = input[right]._exam_number;
            while(j < right){
                if(input[j]._sum > sum_pivot){
                    swap(input[i], input[j]);
                    ++i;
                }
                else if(input[j]._sum == sum_pivot){
                    if(input[j]._virtue_score > virtue_pivot){
                        swap(input[i], input[j]);
                        ++i;
                    }
                    else if(input[j]._virtue_score == virtue_pivot){
                        if(input[j]._exam_number < number_pivot){
                            swap(input[i], input[j]);
                            ++i;
                        }
                    }
                }
                ++j;
            }
            swap(input[i], input[j]);
            quick_sort(input, left, i - 1);
            quick_sort(input, i + 1, right);
        }
    }
public:
    Exam(int &n, int &lower_bound, int &premium_bound){
        _candidate = n;
        _lower_bound = lower_bound;
        _premium_bound = premium_bound;
        _pass_student = 0;
    }
    ~Exam(){
    }
    void insert(int &exam_number, int &virtue_score, int &talent_score){
        if(virtue_score >= _premium_bound && talent_score >= _premium_bound){
            tier_1.push_back(Student(exam_number, virtue_score, talent_score));
            ++_pass_student;
            return;
        }
        else if(virtue_score >= _premium_bound && talent_score >= _lower_bound){
            tier_2.push_back(Student(exam_number, virtue_score, talent_score));
            ++_pass_student;
            return;
        }
        else if(talent_score >= _lower_bound && virtue_score >= talent_score){
            tier_3.push_back(Student(exam_number, virtue_score, talent_score));
            ++_pass_student;
            return;
        }
        else if(virtue_score >= _lower_bound && talent_score >= _lower_bound){
            tier_4.push_back(Student(exam_number, virtue_score, talent_score));
            ++_pass_student;
            return;
        }
        else{
            return;
        }
    }
    void output(){
        cout << _pass_student << endl;
        quick_sort(tier_1, 0, int(tier_1.size() - 1));
        quick_sort(tier_2, 0, int(tier_2.size() - 1));
        quick_sort(tier_3, 0, int(tier_3.size() - 1));
        quick_sort(tier_4, 0, int(tier_4.size() - 1));
        for(auto var: tier_1){
            cout << var._exam_number << " " << var._virtue_score << " " << var._talent_score << endl;
        }
        for(auto var: tier_2){
            cout << var._exam_number << " " << var._virtue_score << " " << var._talent_score << endl;
        }
        for(auto var: tier_3){
            cout << var._exam_number << " " << var._virtue_score << " " << var._talent_score << endl;
        }
        for(auto var: tier_4){
            cout << var._exam_number << " " << var._virtue_score << " " << var._talent_score << endl;
        }
        return;
    }
};

int main(){
    int n, lower_bound, premium_bound;
    int exam_number, virtue_score, talent_score;
    cin >> n >> lower_bound >> premium_bound;
    Exam exam_result(n, lower_bound, premium_bound);
    for(int i = 0; i < n; ++i){
        cin >> exam_number >> virtue_score >> talent_score;
        exam_result.insert(exam_number, virtue_score, talent_score);
    }
    exam_result.output();
    return 0;
}

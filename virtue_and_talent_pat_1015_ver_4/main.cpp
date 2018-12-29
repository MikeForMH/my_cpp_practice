//
//  main.cpp
//  virtue_and_talent_pat_1015_ver_4
//
//  Created by Michael Hui on 29/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

# define MAX 100001

class Candidate{
public:
    int _candidate_number;
    int _virtue_score;
    int _talent_score;
    int _sum;
    Candidate(int &candidate_number, int &virtue_score, int &talent_score){
        _candidate_number = candidate_number;
        _virtue_score = virtue_score;
        _talent_score = talent_score;
        _sum = _virtue_score + _talent_score;
    }
    Candidate(const Candidate &obj){
        _candidate_number = obj._candidate_number;
        _virtue_score = obj._virtue_score;
        _talent_score = obj._talent_score;
        _sum = obj._sum;
    }
    Candidate(){
        _candidate_number = 0;
        _virtue_score = 0;
        _talent_score = 0;
        _sum = 0;
    }
};

class Exam{
private:
    int _candidate;
    int _premium_bound;
    int _lower_bound;
    int _pass_student = 0;
    int _tier_1_count = 0; int _tier_2_count = 0; int _tier_3_count = 0; int _tier_4_count = 0;
    Candidate *_tier_1[MAX] = {}, *_tier_2[MAX] = {}, *_tier_3[MAX] = {}, *_tier_4[MAX] = {}, *_temp[MAX] = {};
    void quick_sort(Candidate **input, const int &left, const int &right){
        if(left < right){
            int i = left, j = left;
            int sum_pivot = input[right]->_sum, virtue_pivot = input[right]->_virtue_score, number_pivot = input[right]->_candidate_number;
            while(j < right){
                if(input[j]->_sum > sum_pivot){
                    swap(input[i], input[j]);
                    ++i;
                    ++j;
                    continue;
                }
                else if(input[j]->_sum == sum_pivot){
                    if(input[j]->_virtue_score > virtue_pivot){
                        swap(input[i], input[j]);
                        ++i;
                        ++j;
                        continue;
                    }
                    else if(input[j]->_virtue_score == virtue_pivot){
                        if(input[j]->_candidate_number < number_pivot){
                            swap(input[i], input[j]);
                            ++i;
                            ++j;
                            continue;
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
    Exam(int &candiate, int &lower_bound, int &premium_bound){
        _candidate = candiate;
        _lower_bound = lower_bound;
        _premium_bound = premium_bound;
    }
    void insert(int &exam_number, int &virtue_score, int &talent_score){
        if(virtue_score >= _premium_bound && talent_score >= _premium_bound){
            _tier_1[_tier_1_count] = new Candidate(exam_number, virtue_score, talent_score);
            ++_tier_1_count;
            ++_pass_student;
            return;
        }
        else if(virtue_score >= _premium_bound && talent_score >= _lower_bound){
            _tier_2[_tier_2_count] = new Candidate(exam_number, virtue_score, talent_score);
            ++_tier_2_count;
            ++_pass_student;
            return;
        }
        else if(talent_score >= _lower_bound && virtue_score >= talent_score){
            _tier_3[_tier_3_count] = new Candidate(exam_number, virtue_score, talent_score);
            ++_tier_3_count;
            ++_pass_student;
            return;
        }
        else if(virtue_score >= _lower_bound && talent_score >= _lower_bound){
            //Candidate *input = Candidate(exam_number, virtue_score, talent_score);
            _tier_4[_tier_4_count] = new Candidate(exam_number, virtue_score, talent_score);
            ++_tier_4_count;
            ++_pass_student;
            return;
        }
        else{
            return;
        }
    }
    void output(){
        cout << _pass_student << endl;
        quick_sort(_tier_1, 0, _tier_1_count - 1);
        quick_sort(_tier_2, 0, _tier_2_count - 1);
        quick_sort(_tier_3, 0, _tier_3_count - 1);
        quick_sort(_tier_4, 0, _tier_4_count - 1);
        for(int i = 0; i < _tier_1_count; ++i){
            cout << _tier_1[i]->_candidate_number << " " << _tier_1[i]->_virtue_score << " " << _tier_1[i]->_talent_score << endl;
        }
        for(int i = 0; i < _tier_2_count; ++i){
            cout << _tier_2[i]->_candidate_number << " " << _tier_2[i]->_virtue_score << " " << _tier_2[i]->_talent_score << endl;
        }
        for(int i = 0; i < _tier_3_count; ++i){
            cout << _tier_3[i]->_candidate_number << " " << _tier_3[i]->_virtue_score << " " << _tier_3[i]->_talent_score << endl;
        }
        for(int i = 0; i < _tier_4_count; ++i){
            cout << _tier_4[i]->_candidate_number << " " << _tier_4[i]->_virtue_score << " " << _tier_4[i]->_talent_score << endl;
        }
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

//
//  main.cpp
//  virtue_and_talent_pat_1015_ver_4
//
//  Created by Michael Hui on 29/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
    /*
    Candidate& operator=(const Candidate &obj){
        if(this != &obj){
            this->_candidate_number = obj._candidate_number;
            this->_virtue_score = obj._virtue_score;
            this->_talent_score = obj._talent_score;
            this->_sum = obj._sum;
        }
        return *this;
    }
     */
    ~Candidate(){
        cout << "Candidat" << endl;
    }
};

class Exam{
private:
    int _candidate = 0;
    int _premium_bound = 0;
    int _lower_bound = 0;
    int _pass_student = 0;
    int _tier_1_count = 0; int _tier_2_count = 0; int _tier_3_count = 0; int _tier_4_count = 0;
    Candidate _tier_1[MAX] = {}, _tier_2[MAX] = {}, _tier_3[MAX] = {}, _tier_4[MAX] = {};
    Candidate _temp[MAX] = {};
    void sort(Candidate *tier, const int &left, const int &right){
        merge_sort_candidate_number(tier, left, right);
        merge_sort_virtue_score(tier, left, right);
        merge_sort_sum(tier, left, right);
        return;
    }
    void merge_sort_candidate_number(Candidate *tier, const int &left, const int &right){
        if(left == right){
            return;
        }
        int mid = (left + right) / 2;
        merge_sort_candidate_number(tier, left, mid);
        merge_sort_candidate_number(tier, mid + 1, right);
        int x = left, y = mid + 1, loc = left;
        while(x <= mid || y <= right){
            if(x <= mid && (y > right || tier[x]._candidate_number < tier[y]._candidate_number)){
                _temp[loc] = tier[x];
                ++x;
            }
            else{
                _temp[loc] = tier[y];
                ++y;
            }
            ++loc;
        }
        for(int i = left; i <= right; ++i){
            tier[i] = _temp[i];
        }
        return;
    }
    void merge_sort_virtue_score(Candidate *&tier, const int &left, const int &right){
        if(left == right){
            return;
        }
        int mid = (left + right) / 2;
        merge_sort_virtue_score(tier, left, mid);
        merge_sort_virtue_score(tier, mid + 1, right);
        int x = left, y = mid + 1, loc = left;
        while(x <= mid || y <= right){
            if(x <= mid && (y > right || tier[x]._virtue_score >= tier[y]._virtue_score)){
                _temp[loc] = tier[x];
                ++x;
            }
            else{
                _temp[loc] = tier[y];
                ++y;
            }
            ++loc;
        }
        for(int i = left; i <= right; ++i){
            tier[i] = _temp[i];
        }
        return;
    }
    void merge_sort_sum(Candidate *tier, const int &left, const int &right){
        if(left == right){
            return;
        }
        int mid = (left + right) / 2;
        merge_sort_sum(tier, left, mid);
        merge_sort_sum(tier, mid + 1, right);
        int x = left, y = mid + 1, loc = left;
        while(x <= mid || y <= right){
            if(x <= mid && (y > right || tier[x]._sum >= tier[y]._sum)){
                _temp[loc] = tier[x];
                ++x;
            }
            else{
                _temp[loc] = tier[y];
                ++y;
            }
            ++loc;
        }
        for(int i = left; i <= right; ++i){
            tier[i] = _temp[i];
        }
        return;
    }
public:
    Exam(int &candiate, int &lower_bound, int &premium_bound){
        _candidate = candiate;
        _lower_bound = lower_bound;
        _premium_bound = premium_bound;
    }
    ~Exam(){
        cout << "Exam" << endl;
    }
    void insert(const Candidate &input){
        if(input._virtue_score >= _premium_bound && input._talent_score >= _premium_bound){
            _tier_1[_tier_1_count] = input;
            ++_tier_1_count;
            ++_pass_student;
            return;
        }
        else if(input._virtue_score >= _premium_bound && input._talent_score >= _lower_bound){
            _tier_2[_tier_2_count] = input;
            ++_tier_2_count;
            ++_pass_student;
            return;
        }
        else if(input._talent_score >= _lower_bound && input._virtue_score >= input._talent_score){
            _tier_3[_tier_3_count] = input;
            ++_tier_3_count;
            ++_pass_student;
            return;
        }
        else if(input._virtue_score >= _lower_bound && input._talent_score >= _lower_bound){
            _tier_4[_tier_4_count] = input;
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
        sort(_tier_1, 0, _tier_1_count - 1);
        sort(_tier_2, 0, _tier_2_count - 1);
        sort(_tier_3, 0, _tier_3_count - 1);
        sort(_tier_4, 0, _tier_4_count - 1);
        for(int i = 0; i < _tier_1_count; ++i){
            cout << _tier_1[i]._candidate_number << " " << _tier_1[i]._virtue_score << " " << _tier_1[i]._talent_score << endl;
        }
        for(int i = 0; i < _tier_2_count; ++i){
            cout << _tier_2[i]._candidate_number << " " << _tier_2[i]._virtue_score << " " << _tier_2[i]._talent_score << endl;
        }
        for(int i = 0; i < _tier_3_count; ++i){
            cout << _tier_3[i]._candidate_number << " " << _tier_3[i]._virtue_score << " " << _tier_3[i]._talent_score << endl;
        }
        for(int i = 0; i < _tier_4_count; ++i){
            cout << _tier_4[i]._candidate_number << " " << _tier_4[i]._virtue_score << " " << _tier_4[i]._talent_score << endl;
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
        exam_result.insert(Candidate(exam_number, virtue_score, talent_score));
    }
    exam_result.output();
    return 0;
}

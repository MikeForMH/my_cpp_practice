//
//  main.cpp
//  population_statics_pat_1028
//
//  Created by Michael Hui on 11/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

struct Birth_Date{
    int _year;
    int _month;
    int _day;
    Birth_Date(const string &input){
        _year = stoi(input.substr(0, 4));
        _month = stoi(input.substr(5, 2));
        _day = stoi(input.substr(8, 2));
    }
    Birth_Date(){
        _year = -1;
        _month = -1;
        _day = -1;
    }
    Birth_Date(const Birth_Date &obj){
        _year = obj._year;
        _month = obj._month;
        _day = obj._day;
    }
    bool operator>(const Birth_Date &input) const{
        if(_year < input._year){
            return true;
        }else if(_year == input._year){
            if(_month < input._month){
                return true;
            }else if(_month == input._month){
                if(_day < input._day){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    bool operator<(const Birth_Date &input) const{
        if(_year > input._year){
            return true;
        }else if(_year == input._year){
            if(_month > input._month){
                return true;
            }else if(_month == input._month){
                if(_day > input._day){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    static const Birth_Date lower_bound;
    static const Birth_Date upper_bound;
    static bool is_valid_date(Birth_Date &input){
        if(!(input > lower_bound) && !(input < upper_bound)){
            return true;
        }else{
            return false;
        }
    }
};

const Birth_Date Birth_Date::lower_bound = Birth_Date("1814/09/06");
const Birth_Date Birth_Date::upper_bound = Birth_Date("2014/09/06");

int main(){
    int n, count = 0;
    cin >> n;
    string name, birth_date;
    string max_name, min_name;
    Birth_Date max_date("2014/09/07"), min_date("1814/09/05");
    for(int i = 0; i < n; ++i){
        cin >> name >> birth_date;
        Birth_Date temp = Birth_Date(birth_date);
        if(Birth_Date::is_valid_date(temp)){
            ++count;
            if(temp > max_date){
                max_date = temp;
                max_name = name;
            }
            if(temp < min_date){
                min_date = temp;
                min_name = name;
            }
        }
    }
    if(count == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << count << " " << max_name << " " << min_name << endl;
    return 0;
}

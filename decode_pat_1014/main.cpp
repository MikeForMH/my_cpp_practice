//
//  main.cpp
//  decode_pat_1014
//
//  Created by Michael Hui on 26/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::isalpha;
using std::isdigit;

int search(string &input_string, char &input_char){
    for(size_t i = 0; i < input_string.length(); ++i){
        if(input_string[i] == input_char){
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool is_a_to_n(const char& input){
    if(int(input) >= 65 && int(input) <= 78){
        return true;
    }
    else{
        return false;
    }
}

void decode(string &day_hour_1, string &day_hour_2, string &minute_1, string &minute_2){
    string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int day_pos;
    bool flag = true;
    for(size_t i = 0; ;++i){
        if(flag){
            if(int(day_hour_1[i]) >= 65 && int(day_hour_1[i]) <= 71){
                day_pos = search(day_hour_2, day_hour_1[i]);
                if(day_pos != -1){
                    cout << day[int(day_hour_1[i]) - 65] << " ";
                    flag = false;
                    continue;
                }
            }
        }
        if(!flag){
            if((is_a_to_n(day_hour_1[i]) || isdigit(day_hour_1[i])) && day_hour_1[i] == day_hour_2[i]){
                int temp = int(day_hour_1[i]);
                if(temp <= 57){
                    cout << 0 << temp - 48 << ":";
                    break;
                }
                else{
                    cout << temp - 55 << ":";
                    break;
                }
            }
        }
    }
    for(size_t i = 0; i < minute_1.length(); ++i){
        if(minute_1[i] == minute_2[i] && isalpha(minute_1[i])){
            if(i < 10){
                cout << 0 << i << endl;
                break;
            }
            else{
                cout << i << endl;
                break;
            }
        }
    }
    return;
}

int main(){
    string day_hour_1, day_hour_2, minute_1, minute_2;
    cin >> day_hour_1 >> day_hour_2 >> minute_1 >> minute_2;
    decode(day_hour_1, day_hour_2, minute_1, minute_2);
    return 0;
}

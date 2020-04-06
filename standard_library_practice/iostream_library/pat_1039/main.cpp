//
//  main.cpp
//  pat_1039
//
//  Created by Michael Hui on 6/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;


int main() {
    std::map<char, int> given_ball;
    std::map<char, int> required_ball;
    char temp;
    int given_count = 0;
    int having_count = 0;
    int missing_count = 0;
    bool is_fulfill = true;
    while(true){
        temp = cin.get();
        if(temp == '\n'){
            break;
        }
        auto iter = given_ball.find(temp);
        if(iter == given_ball.end()){
            given_ball.insert({temp, 1});
        }else{
            ++iter->second;
        }
        ++given_count;
    }
    while(true){
        temp = cin.get();
        if(temp == '\n'){
            break;
        }
        auto iter = required_ball.find(temp);
        if(iter == required_ball.end()){
            required_ball.insert({temp, 1});
        }else{
            ++iter->second;
        }
        ++having_count;
    }
    for(auto const& i: required_ball){
        auto iter = given_ball.find(i.first);
        if(iter == given_ball.end()){
            is_fulfill = false;
            missing_count += i.second;
        }else{
            int have = iter->second;
            int need = i.second;
            if(have < need){
                is_fulfill = false;
                missing_count += need - have;
            }
        }
    }
    if(is_fulfill){
        cout << "Yes " << given_count - having_count << endl;
    }else{
        cout << "No " << missing_count << endl;
    }
    return 0;
}

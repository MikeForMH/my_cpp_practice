//
//  main.cpp
//  pat_1038
//
//  Created by Michael Hui on 5/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

int main(){
    std::map<int, int> records;
    int record_num = 0;
    int input = 0;
    cin >> record_num;
    for(int i = 0; i < record_num; ++i){
        cin >> input;
        auto iter = records.find(input);
        if(iter == records.end()){
            records.insert({input, 1});
        }else{
            ++iter->second;
        }
    }
    std::queue<int> to_check;
    cin >> record_num;
    for(int i = 0; i < record_num; ++i){
        cin >> input;
        to_check.push(input);
    }
    for(int i = 0; i < record_num; ++i){
        if(i != 0){
            cout << ' ';
        }
        cout << records[to_check.front()];
        to_check.pop();
    }
    cout << endl;
    return 0;
}

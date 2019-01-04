//
//  main.cpp
//  biggest_number_pat_1023
//
//  Created by Michael Hui on 4/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    int list[10];
    for(int i = 0; i < 10; ++i){
        cin >> list[i];
    }
    for(int i = 1; ; ++i){
        if(list[i] != 0){
            cout << i;
            --list[i];
            break;
        }
    }
    for(int i = 0; i < 10; ++i){
        if(list[i] != 0){
            for(; list[i] > 0;){
                cout << i;
                --list[i];
            }
        }
    }
    cout << endl;
    return 0;
}

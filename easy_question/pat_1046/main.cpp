//
//  main.cpp
//  pat_1046
//
//  Created by Michael Hui on 8/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int input_count;
    int a_count = 0;
    int b_count = 0;
    int a_call = 0;
    int a_show = 0;
    int b_call = 0;
    int b_show = 0;
    bool a_win = true;
    bool b_win = true;
    cin >> input_count;
    for(int i = 0; i < input_count; ++i){
        cin >> a_call >> a_show >> b_call >> b_show;
        a_win = (a_show == a_call + b_call);
        b_win = (b_show == a_call + b_call);
        if((a_win && b_win) || (!a_win && !b_win)){
            continue;
        }else if(a_win){
            ++b_count;
        }else{
            ++a_count;
        }
    }
    cout << a_count << ' ' << b_count << endl;
    return 0;
}

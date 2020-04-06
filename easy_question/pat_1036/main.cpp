//
//  main.cpp
//  pat_1036
//
//  Created by Michael Hui on 24/2/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void draw_square(int &size_input, char &sqr_char){
    int row_num = size_input / 2 + size_input % 2;
    int column_num = size_input;
    for(int i = 0; i < row_num; ++i){
        if(i == 0 || i == row_num - 1){
            for(int j = 0; j < column_num; ++j){
                cout << sqr_char;
            }
            cout << endl;
            continue;
        }
        cout << sqr_char;
        for(int j = column_num - 2; j > 0; --j){
            cout << ' ';
        }
        cout << sqr_char << endl;
    }
    
}

int main(){
    int size_input = 0;
    char sqr_char = ' ';
    cin >> size_input >> sqr_char;
    draw_square(size_input, sqr_char);
    return 0;
}

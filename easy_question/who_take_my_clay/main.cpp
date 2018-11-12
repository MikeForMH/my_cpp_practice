//
//  main.cpp
//  who take my clay
//
//  Created by Michael Hui on 8/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    int student_numbers;
    cin >> student_numbers;
    while (student_numbers > 0){
        int *amount_of_clay = new int [student_numbers];
        string *student_names = new string [student_numbers];
        int length, width, height;
        string name;
        for (int i = 0; i < student_numbers; ++i){
            cin >> length >> width >> height >> name;
            amount_of_clay[i] = length * width * height;
            student_names[i] = name;
        }
        int average_clay = 0, sum = 0;
        for (int i = 0; i < student_numbers; ++i){
            sum += amount_of_clay[i];
        }
        average_clay = sum / student_numbers;
        int taker_index, giver_index;
        for (int i = 0; ; ++i){
            if (amount_of_clay[i] > average_clay){
                taker_index = i;
                break;
            }
        }
        for (int i = 0; ; ++i){
            if (amount_of_clay[i] < average_clay){
                giver_index = i;
                break;
            }
        }
        cout << student_names[taker_index] << " took clay from " << student_names[giver_index] << "." << endl;
        cin >> student_numbers;
    }
    return 0;
}

//
//  main.cpp
//  reverse a matrix
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

void print_Reversed_Matrix (const int rows, const int columns, const bool reflect_by_x_or_y, int **input_matrix){
    if(reflect_by_x_or_y){
        for (int i = 0; i < rows / 2; ++i){
            for (int j = 0; j < columns; ++j){
                swap(input_matrix[i][j], input_matrix[rows - 1 - i][j]);
            }
        }
    }
    else {
        for (int j = 0; j < columns / 2; ++j){
            for (int i = 0; i < rows; ++i){
                swap(input_matrix[i][j], input_matrix[i][columns - 1 - j]);
            }
        }
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            cout << input_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int rows, columns;
    bool reflect_by_x_or_y; //0 -> reflect by Y, 1 -> reflect by X.
    cin >> rows >> columns >> reflect_by_x_or_y;
    int **input_matrix = new int *[rows];
    for (int i = 0; i < columns; ++i){
        input_matrix [i] = new int [columns];
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0 ;j < columns; ++j){
            cin >> input_matrix[i][j];
        }
    }
    print_Reversed_Matrix(rows, columns, reflect_by_x_or_y, input_matrix);
    return 0;
}

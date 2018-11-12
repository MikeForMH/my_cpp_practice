//
//  main.cpp
//  Print numerical trapezium
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <iomanip>
# include <cmath>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printNumericalTrapezium (int const &StartingNumber, int const &SizeOfTrapezium){
    cout << std::setiosflags(std::ios::left);
    string OneToTen = "0123456789";
    
    if (SizeOfTrapezium > 0){
        for (int i = 3 * SizeOfTrapezium - 2, j = i, k = 0; j > 0; --j, ++k){ //Upper base
            double f = i;
            int h = (f - 1)/2 - fabs (k - (f - 1)/2);
            //int h = i/2 - abs (k - i/2);// original, which only works in odd size
            
            cout << std::setw (2) << OneToTen [(h + StartingNumber) % 10];
        }
        cout << endl;
    }
    if (SizeOfTrapezium > 2){
        for (int i = 1; i < SizeOfTrapezium - 1; ++i){
            for (int k = i; k > 0; --k){
                cout << "  ";
            }
            cout << std::setw (2) << OneToTen [(i + StartingNumber) % 10];
            for (int k = 3 * SizeOfTrapezium - 4 - i * 2; k > 0; --k){
                cout << "  ";
            }
            cout << std::setw (2) << OneToTen [(i + StartingNumber) % 10];
            cout << endl;
        }
    }
    if (SizeOfTrapezium > 1){
        for (int i = SizeOfTrapezium - 1; i > 0; --i){
            cout << "  ";
        }
        for (int i = SizeOfTrapezium , j = i, k = 0; j > 0; --j, ++k){
            float f = i;
            int h = (f - 1)/2 - fabs(k - (f - 1)/2);
            //int h = i/2 - abs (k - i/2);// original, which only works in odd size
            cout << std::setw (2) << OneToTen [(h + StartingNumber + SizeOfTrapezium - 1) % 10];
        }
        cout << endl;
    }
    
}

int main (){
    int StartingNumber, SizeOfTrapezium;
    cin >> StartingNumber >> SizeOfTrapezium;
    printNumericalTrapezium (StartingNumber, SizeOfTrapezium);
    return 0;
}

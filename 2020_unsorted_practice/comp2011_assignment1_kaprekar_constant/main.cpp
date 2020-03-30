/*
 * COMP2011 (Spring 2020) Assignment 1: Kaprekar's Constant
 *
 * Student name: FILL YOUR NAME HERE
 * Student ID: FILL YOUR STUDENT ID NUMBER HERE
 * Student email: FILL YOUR EMAIL HERE
 *
 * Note:
 * 1. Add your code ONLY in the corresponding "TODO" area.
 * 2. DO NOT change the function header of the given functions.
 * 3. DO NOT add additional libraries.
 * 4. DO NOT use array, otherwise ZERO marks for the assignment.
 * 5. You can add helper function(s) if needed.
 */
#include <iostream>
#include <math.h>
using namespace std;

const bool ASCENDING = 0;
const bool DESCENDING = 1;
const bool DEBUG = true;

/**
 *  Task 1: selectDigit() returns one digit from a given index location of an arbitrary positive integer
 *  The index starts from 0 at the rightmost digit
 *  The function return -1 if index is invalid
 *  Examples: selectDigit(123, 0) = 3, selectDigit(1234, 3) = 1, selectDigit(123, 3) = -1, selectDigit(123, -1) = -1
 */
int selectDigit(int number, int index){

//TODO: start your coding here
    if(index < 0){
        return -1;
    }
    int temp = number;
    int result = 0;
    for(int i = 0; i <= index; ++i){
        if(temp == 0){
            return -1;
        }
        result = temp % 10;
        temp /= 10;
    }
    return result;
}

/**
 *  Task 2: isRepdigit() checks whether all digits in a positive integer are the same
 *  It returns true if Yes, false otherwise
 *  Examples: isRepdigit(222) = true, isRepdigit(212) = false, isRepdigit(2) = true
 */
bool isRepdigit(int number){

//TODO: start your coding here
    int last = number % 10;
    int current = 0;
    int temp = number;
    while(true){
        temp /= 10;
        if(temp == 0){
            break;
        }
        current = temp % 10;
        if(current != last){
            return false;
        }
        last = current;
    }
    return true;
}

/**
 *  Task 3: sortDigit() takes an arbitrary positive integer number,
 *  and returns a new integer with all digits in number arranged in ascending or descending order
 *  Examples: sortDigit(16845, ASCENDING) = 14568, sortDigit(16845, DESCENDING) = 86541
 *  The function should be able to handle number consists 0s
 *  Examples: sortDigit(500, ASCENDING) = 5, sortDigit(100250, DESCENDING) = 521000, sortDigit(100250, ASCENDING) = 125
 */
int sortDigit(int number, bool order){
    
//TODO: start your coding here
    
    int new_digit = 0;
    for(int i = 9; i > -1; --i){
        int temp = number;
        for(; temp != 0;){
            if(temp % 10 == i){
                new_digit = new_digit * 10 + i;
            }
            temp /= 10;
        }
    }
    if(!order){ // if is ascending
        int temp = new_digit;
        new_digit = 0;
        for(; temp != 0;){
            new_digit = new_digit * 10 + temp % 10;
            temp /= 10;
        }
    }
    return new_digit;
}

/**
 * Task 4: isKaprekar6174() takes an arbitrary positive integer,
 * and returns the number of steps needed to reach Kaprekar's constant 6174
 * The function returns -1 if the number can't reach 6174
 * when DEBUG is true, calculation details needs to be printed out
 * Output format for the calculation details: Each row represents a subtraction calculation
 * There is no space between the number and minus sign. There is no space between the number and equal sign
 */
int isKaprekar6174(int number, bool debug){

//TODO: start your coding here
    if(number / 10000 > 0 || number / 1000 < 1){
        if(debug){
            cout << "can't reach Kaprekar's constant 6174" << endl;
        }
        return -1;
    }
    bool is_repeated = true;
    for(int temp = number / 10, last = number % 10; temp != 0; temp /= 10){
        if(temp % 10 != last){
            is_repeated = false;
            break;
        }
        last = temp % 10;
    }
    if(is_repeated){
        if(debug){
            cout << "can't reach Kaprekar's constant 6174" << endl;
        }
        return -1;
    }
    int result = number;
    int count = 0;
    while(true){
        ++count;
        int a = sortDigit(result, DESCENDING);
        int b = sortDigit(result, ASCENDING);
        if(debug){
            cout << a << '-' << b << '=' << a - b << endl;
        }
        result = a - b;
        if(result / 1000 < 1){
            result *= 10;
        }
        if(result == 6174){
            return count;
        }
    }
}

/**
 * Task 5: printStat() bincounts #steps to reach Kaprekar's constant 6174 for numbers in a given range from m to n (both inclusive)
 * Then print the bar chart (*)
 * For simplicity, you can assume that m and n are positive integers and there is always a valid range
 * 8 bins are used, which count the numbers with 1 to 7 steps to reach Kaprekar's constant 6174, or fail to do so
 * A * is printed for every 50 counted
 * Print a * if there is remainder
 * For example if bincount = 350, print 7 stars; bincount = 351, print 8 stars
 * Output format: For each row, starts with the bin number (i.e. 1 to 7) and immediately followed by the star. Do not leave any spaces between them
 * Output format: The last row (eighth row) of the output represents the failure case (started with -1 and immediately followed by the star, do not leave any spaces between them)
 */
void print_asterisk(const int &count){
    for(int i = 0; i < count; ++i){
        cout << '*';
    }
}

void printStat(int m, int n){

//TODO: start your coding here
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int negative_one = 0;
    for(int i = m; i <= n; ++i){
        switch (isKaprekar6174(i, !DEBUG)) {
            case 1:
                ++one;
                break;
            case 2:
                ++two;
                break;
            case 3:
                ++three;
                break;
            case 4:
                ++four;
                break;
            case 5:
                ++five;
                break;
            case 6:
                ++six;
                break;
            case 7:
                ++seven;
                break;
            case -1:
                ++negative_one;
                break;
        }
    }
    cout << '1';
    print_asterisk(one / 50 + ((one % 50)?1:0));
    cout << endl << '2';
    print_asterisk(two / 50 + ((two % 50)?1:0));
    cout << endl << '3';
    print_asterisk(three / 50 + ((three % 50)?1:0));
    cout << endl << '4';
    print_asterisk(four / 50 + ((four % 50)?1:0));
    cout << endl << '5';
    print_asterisk(five / 50 + ((five % 50)?1:0));
    cout << endl << '6';
    print_asterisk(six / 50 + ((six % 50)?1:0));
    cout << endl << '7';
    print_asterisk(seven / 50 + ((seven % 50)?1:0));
    cout << endl << "-1";
    print_asterisk(negative_one / 50 + ((negative_one % 50)?1:0));
    cout << endl;
    return;
}

// This is the main function. It is already done. Please DO NOT make any modification.
int main()
{
cout << "Task 1:" << endl;
cout << "selectDigit(896543,0) = " << selectDigit(896543,0) << endl;
cout << "selectDigit(896543,5) = " << selectDigit(896543,5) << endl;
cout << "selectDigit(896543,-1) = " << selectDigit(896543,-1) << endl;
cout << "selectDigit(896543,6) = " << selectDigit(896543,6) << endl;

cout << endl << "Task 2:" << endl;
cout << "isRepdigit(2999) " << boolalpha << isRepdigit(2999) << endl;
cout << "isRepdigit(888888) " << boolalpha << isRepdigit(888888) << endl;
cout << "isRepdigit(1) " << boolalpha << isRepdigit(1) << endl;

cout << endl << "Task 3:" << endl;
cout << "sortDigit(54321, ASCENDING) = " << sortDigit(54321, ASCENDING) << endl;
cout << "sortDigit(794621, ASCENDING) = " << sortDigit(794621, ASCENDING) << endl;
cout << "sortDigit(794621, DESCENDING) = " << sortDigit(794621, DESCENDING) << endl;
cout << "sortDigit(100250, ASCENDING) = " << sortDigit(100250, ASCENDING) << endl;
cout << "sortDigit(100250, DESCENDING) = " << sortDigit(100250, DESCENDING) << endl;
cout << "sortDigit(500, ASCENDING) = " << sortDigit(500, ASCENDING) << endl;

cout << endl << "Task 4:" << endl;
cout << "isKaprekar6174(546, DEBUG) = " << isKaprekar6174(546, !DEBUG) << endl;
isKaprekar6174(546, DEBUG);
cout << "isKaprekar6174(18604, DEBUG) = " << isKaprekar6174(18604, !DEBUG)<< endl;
isKaprekar6174(18604, DEBUG);
cout << "isKaprekar6174(8888, DEBUG) = " << isKaprekar6174(8888, !DEBUG) << endl;
isKaprekar6174(8888, DEBUG);
cout << "isKaprekar6174(2894, DEBUG) = " << isKaprekar6174(2894, !DEBUG)<< endl;
isKaprekar6174(2894, DEBUG);
cout << "isKaprekar6174(6174, DEBUG) = " << isKaprekar6174(6174, !DEBUG)<< endl;
isKaprekar6174(6174, DEBUG);

cout << endl << "Task 5: " << endl;
cout << "Statistic for range from 1000 to 9999" << endl;
printStat(1000,9999);
cout << "Statistic for range from 500 to 10500" << endl;
printStat(500,10500);

return 0;
}

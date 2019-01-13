//
//  main.cpp
//  arithmetic_operation_pat_1034
//
//  Created by Michael Hui on 13/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  1. use long long int

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::ostream;
using std::swap;
using std::ios;


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void simply_fraction(long &numerator, long &denominator){
    long long var_1 = numerator, var_2 = denominator;
    long long temp = gcd(var_1, var_2);
    numerator = numerator / temp;
    denominator = denominator / temp;
    return;
}

struct Fraction{
    long numerator = 1;
    long denominator = 1;
    long integer = 0;
    bool is_negative = false;
    Fraction(string input){
        integer = 0;
        if(input[0] == '-'){
            numerator *= -1;
            input.erase(0, 1);
        }
        size_t slash_pos = -1;
        for(size_t i = 0; i < input.length(); ++i){
            if(input[i] == '/'){
                slash_pos = i;
            }
        }
        if(slash_pos != -1){
            numerator *= stoi(input.substr(0, slash_pos));
            denominator *= stoi(input.substr(slash_pos + 1, input.length() - slash_pos - 1));
        }else{
            numerator = stoi(input);
            denominator = 1;
        }
    }
    Fraction(const Fraction &obj){
        numerator = obj.numerator;
        denominator = obj.denominator;
        integer = obj.integer;
        is_negative = obj.is_negative;
    }
    Fraction(){
        numerator = 0;
        denominator = 0;
        integer = 0;
        is_negative = false;
    }
    Fraction operator+(const Fraction &input) const{
        Fraction result;
        result.denominator = denominator * input.denominator;
        result.numerator = numerator * input.denominator + input.numerator * denominator;
        return result;
    }
    Fraction operator-(const Fraction &input) const{
        Fraction result;
        result.denominator = denominator * input.denominator;
        result.numerator = numerator * input.denominator - input.numerator * denominator;
        return result;
    }
    Fraction operator*(const Fraction &input) const{
        Fraction result;
        result.numerator = numerator * input.numerator;
        result.denominator = denominator * input.denominator;
        return result;
    }
    Fraction operator/(const Fraction &input) const{
        Fraction result;
        result.numerator = numerator * input.denominator;
        result.denominator = denominator * input.numerator;
        return result;
    }
    void to_mixed_fraction(){
        if(denominator == 0){
            return;
        }
        if(numerator < 0){
            numerator *= -1;
            is_negative = !is_negative;
        }
        if(denominator < 0){
            denominator *= -1;
            is_negative = !is_negative;
        }
        integer = numerator / denominator;
        numerator = numerator % denominator;
        simply_fraction(numerator, denominator);
        return;
    }
    friend ostream & operator<< (ostream &out, const Fraction &input);
};

ostream & operator<< (ostream &out, const Fraction &input){
    if(input.denominator == 0){
        cout << "Inf";
        return out;
    }else if(input.integer == 0 && input.numerator == 0){
        cout << 0;
        return out;
    }
    if(input.is_negative){
        cout << "(-";
    }
    if(input.integer != 0){
        cout << input.integer;
        if(input.numerator != 0){
            cout << ' ';
        }
    }
    if(input.numerator != 0){
        cout << input.numerator << '/' << input.denominator;
    }
    if(input.is_negative){
        cout << ')';
    }
    return out;
}

void arithmetic_operation_for_fraction(const string &input_1, const string &input_2){
    Fraction var_1(input_1), var_2(input_2);
    Fraction addition_result = var_1 + var_2;
    addition_result.to_mixed_fraction();
    Fraction subtraction_result = var_1 - var_2;
    subtraction_result.to_mixed_fraction();
    Fraction multiplication_result = var_1 * var_2;
    multiplication_result.to_mixed_fraction();
    Fraction division_result = var_1 / var_2;
    division_result.to_mixed_fraction();
    var_1.to_mixed_fraction();
    var_2.to_mixed_fraction();
    cout << var_1 << " + " << var_2 << " = " << addition_result << endl;
    cout << var_1 << " - " << var_2 << " = " << subtraction_result << endl;
    cout << var_1 << " * " << var_2 << " = " << multiplication_result << endl;
    cout << var_1 << " / " << var_2 << " = " << division_result << endl;
    return;
}

int main(){
    string var_1, var_2;
    cin >> var_1 >> var_2;
    arithmetic_operation_for_fraction(var_1, var_2);
    return 0;
}

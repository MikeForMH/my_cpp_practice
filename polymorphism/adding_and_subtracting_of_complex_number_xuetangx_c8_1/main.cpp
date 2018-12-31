//
//  main.cpp
//  adding_and_subtracting_of_complex_number_xuetangx_c8_1
//
//  Created by Michael Hui on 31/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0): real(r), imag(i){};
    Complex operator+ (const Complex &c2) const;
    Complex operator- (const Complex &c2) const;
    
    /*实现下面三个函数*/
    Complex operator* (const Complex &c2) const;
    Complex operator/ (const Complex &c2) const;
    friend ostream & operator<< (ostream &out, const Complex &c);
    
private:
    double real;
    double imag;
};

Complex Complex::operator+ (const Complex &c2) const {
    return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator- (const Complex &c2) const {
    return Complex(real - c2.real, imag - c2.imag);
}

Complex Complex::operator* (const Complex &c2) const{
    double temp_real = real * c2.real - imag * c2.imag;
    double temp_imag = real * c2.imag + c2.real * imag;
    return Complex(temp_real, temp_imag);
}

Complex Complex::operator/ (const Complex &c2) const{
    double temp_denominator = c2.real * c2.real + c2.imag * c2.imag;
    Complex temp_complex = (*this) * Complex(c2.real, -c2.imag);
    return Complex(temp_complex.real / temp_denominator, temp_complex.imag / temp_denominator);
}

ostream & operator<< (ostream &out, const Complex &c){
    out << c.real << " " << c.imag << endl;
    return out;
}

int main() {
    double real, imag;
    cin >> real >> imag;
    Complex c1(real, imag);
    cin >> real >> imag;
    Complex c2(real, imag);
    cout << c1 + c2;
    cout << c1 - c2;
    cout << c1 * c2;
    cout << c1 / c2;
}

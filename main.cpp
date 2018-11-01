/**
Course:  CS213 - Programming II  - 2018
Title:   Assignment 2 - Task 1 - Problem 0
Program: CS213-2018-A2-T1
Purpose: Mathematics operations on Matrices
Authors: 1- Name :- Nada Nasser Al-Said El-Azab .................. ID :- 20170369
         2- Name :- Hanan Mohamed Abd-El-Rahim  .................. ID :- 20170375
         3- Name :- Farah Mohamed Osama Mostafa .................. ID :- 20170351
Date:    31 November 2018
Version: 2.0
*/
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{

    Matrix mat1;
    Matrix mat2;

    cin >> mat1 >> mat2;

    Matrix mat3 = mat2;
    cout << "Sum mat1+=mat2 " << endl;
    cout << (mat1+=mat2)<< endl;

    cout << "Matrix 1 = " << endl;
    cout << mat1;

    cout << "Matrix 2 = " << endl;
    cout << mat2;

    cout << "Matrix 3 = " << endl;
    cout << mat3;


    cout << "mat1-=mat2 " << endl;
    cout << (mat1-=mat2) << endl;

    cout << "++mat1 " << endl;
    cout << ++mat1 << endl;

    cout << "--mat1 " << endl;
    cout << --mat1 << endl;

    cout << "mat1+=4 " << endl;
    cout <<  (mat1+=4) << endl;

    cout << "mat1-=3 " << endl;
    cout << (mat1-=3) << endl;


    cout << "Transpose mat2 : " << endl;
    cout << mat2.transpose()    << endl;

    cout << "IS The Matrix Square       :- " << endl
         << mat2.isSquare()                  << endl;
    cout << "IS The Matrix Identity     :- " << endl
         << mat2.isIdentity()                << endl;
    cout << "IS The Matrix Symmetric    :- " << endl
         << mat2.isSymetric()                << endl;

    cout << "Is mat1 equal to mat2?     : " << (mat1 == mat2) << endl;
    cout << "Is mat1 not equal to mat2? : " << (mat1 != mat2) << endl;

    return 0;
}

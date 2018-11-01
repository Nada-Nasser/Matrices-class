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
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
    private:
        int** data;       // Pointer to 2-D array that will simulate matrix
        int row, col;

//*************************************************************************************************

    public:
        Matrix(); // Instead of CreateMatrix Function.
        Matrix(int row , int col , int num[]); // Instead of CreateMatrix Function.
        Matrix( const Matrix &mat );

        void operator=(Matrix&);

        // virtual ~Matrix(); // For Deleting The Matrix from the memory

        ///---------------------------------------------------------------------------------------

        // Student #1 with the smallest ID (e.g., 20170080)
        // All these operations return a new matrix with the calculation result
        Matrix operator+  (Matrix); // Add if same dimensions
        Matrix operator-  (Matrix); // Sub if same dimensions
        Matrix operator*  (Matrix); // Multi if col1 == row2
        Matrix operator+  (int scalar);  // Add a scalar
        Matrix operator-  (int scalar);  // Subtract a scalar
        Matrix operator*  (int scalar);  // Multiple by scalar

        ///--------------------------------------------------------------------------------------

        // Student #2 with the middle ID (e.g., 20170082)
        // The last operator >> takes an istream and a matrix and return the
        // the same istream so it is possible to cascade input like
        // cin >> matrix1 >> matrix2 << endl;
        Matrix operator+= (Matrix); // mat1 changes & return new matrix with the sum
        Matrix operator-= (Matrix); // mat1 changes + return new matrix with difference
        Matrix operator+= (int scalar);   // change mat & return new matrix
        Matrix operator-= (int scalar);   // change mat & return new matrix
        Matrix operator++ ();   	// Add 1 to each element ++mat
        Matrix operator-- ();    	// Sub 1 from each element --mat

        ///---------------------------------------------------------------------------------------
        //Student #3 with the biggest ID (e.g., 20170089)

        bool   operator== (Matrix);	// True if identical
        bool   operator!= (Matrix); 	// True if not same
        bool   isSquare   ();  // True if square matrix
        bool   isSymetric ();  // True if square and symmetric
        bool   isIdentity ();  // True if square and identity
        Matrix transpose();    // Return new matrix with the transpose

        ///---------------------------------------------------------------------------------------

        friend istream& operator>> (istream& in , Matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

        friend ostream& operator<< (ostream& out , Matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12    123

};


istream& operator>> (istream& in  , Matrix& mat);

ostream& operator<< (ostream& out , Matrix mat);

void drowLine();

#endif // MATRIX_H



#include "Matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(int r , int c , int num[])
{
    row  = r;
    col  = c;
    data = new int* [r];

    for (int i = 0; i < r; i++)
        data[i] = new int [c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            data[i][j] = num[i * c + j];
}

Matrix::Matrix( const Matrix &mat )
{
    row = mat.row ;
    col = mat.col;

    data = new int* [row];

    for (int i = 0; i < row; i++)
        data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = mat.data[i][j] ;

}


//________________________________________________________________________________________________

istream& operator>> (istream& in  , Matrix& mat)
{
    int r , c ;

    cout << "Enter number of rows    : ";
    in  >> r;
    cout << "Enter number of columns : ";
    in  >> c;

    int InputData [r*c];

    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i = 0 ; i < r*c ; i++)
        in >> InputData[i];
    Matrix mat2(r,c,InputData);
    mat=mat2;
    return in;
}
//________________________________________________________________________________________________

ostream& operator<< (ostream& out , Matrix mat)
{
    out << "\nThe Matrix is : " << endl;

    for(int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
            out << setw(5)  << mat.data[i][j] ;
        out << endl;
    }

    drowLine(); // just to separate between matrices printed .

    return out;// return ostream to be able to print the matrix using the same (cout) Ex : cout << mat1 << mat2 << ...;

}
//________________________________________________________________________________________________
/*
Matrix::~Matrix()
{
    for(int i = 0 ; i < row ; i++){
        delete data[i];
    }
    delete[] data;
}
*/
void Matrix::operator=(Matrix& mat){

    this ->col = mat.col;
    this ->row = mat.row;

    this ->data = new int* [mat.row];

    for (int i = 0; i < mat.row; i++)
        this->data[i] = new int [mat.col];


    for(int i = 0 ; i < mat.row ; i++) {
        for(int j = 0 ; j < mat.col ; j++){

            this ->data[i][j] = mat.data[i][j];
        }
    }
}

///--------------------------------------------------------------------------------------
/// Student #1:
//with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result

Matrix Matrix:: operator+  (Matrix mat2) // Add if same dimensions
{
    if (col == mat2.col && row == mat2.row)
    {
        //to check of they have the same dimensions
        int *data1=new int[col * mat2.row];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data1[i * col + j] = data[i][j] + mat2.data[i][j];//adds elements in the matrices
            }
        }
        Matrix mat3(col,mat2.row,data1);
        delete data1;
        return mat3;

    }
    else{
        cout << "these matrices don't have the same dimensions\n";//if not the same dimensions
        system("pause");

    }

}
//________________________________________________________________________________________________

Matrix Matrix:: operator-  (Matrix mat2) // Sub if same dimensions
{
    if (col == mat2.col && row == mat2.row)
    {
        //to check of they have the same dimensions
        int *data1=new int [col * mat2.row];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data1[i * col + j] = data[i][j] - mat2.data[i][j];//adds elements in the matrices
            }
        }
        Matrix mat3(col,mat2.row,data1);
        delete data1;
        return mat3;
    }
    else{
        cout << "these matrices don't have the same dimensions\n";//if not the same dimensions
        system("pause");
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator*  (Matrix mat2) // Multi if col1 == row2
{
     if (col == mat2.row) //to check if they are the right dimensions (nxm&mxk)
    {
        int *data1=new int[row * mat2.col];

        for (int i = 0; i < row*mat2.col; i++)
        {
            data1[i] = 0;    // Initialize all elements to zero.
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int h = 0; h < mat2.col; h++)
                {
                    data1[i * mat2.col + h] += data[i][j] * mat2.data[j][h];//we created an array that
                }//stores the multiplied elements of the new matrix
            }
        }

        Matrix mat3(row,mat2.col,data1);//we'll then use the array we made in the createMatrix function.
        delete data1;
        return mat3;
    }
    else{
        cout << "these matrices dont have the right dimensions\n";//if the dimensions were not right
        system("pause");
    }

}
//________________________________________________________________________________________________

Matrix Matrix:: operator+  (int scalar) // Add a scalar
{
    int *data1=new int[col*row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data1[i * col + j] = data[i][j] + scalar;//we created an array that stores the matrix which
        }//we added the scaler to
    }
    Matrix mat2(row,col, data1);//then we use the array to create the new matrix
    return mat2;
}
//________________________________________________________________________________________________

Matrix Matrix:: operator-  (int scalar)  // Subtract a scalar
{
    int *data1=new int[col*row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data1[i * col + j] = data[i][j] - scalar;//we created an array that stores the matrix which
        }//we added the scaler to
    }
    Matrix mat2(row,col, data1);//then we use the array to create the new matrix
    delete data1;
    return mat2;
}
//________________________________________________________________________________________________

Matrix Matrix:: operator*  (int scalar){
    int data1[col*row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data1[i * col + j] = data[i][j] * scalar;//we created an array that stores the matrix which
        }//we added the scaler to
    }
    Matrix mat2(row,col, data1);//then we use the array to create the new matrix
    delete data1;
    return mat2;
}  // Multiple by scalar

///--------------------------------------------------------------------------------------
/// Student #2
//with the middle ID (e.g., 20170082)
Matrix Matrix:: operator+= (Matrix M) // mat1 changes & return new matrix with the sum
{
    int dta[row*col];
    if(row == M.row && col == M.col)
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                data[i][j] += M.data[i][j];

                dta[i * col + j] = data[i][j];
            }
        }
        Matrix sum(row , col, dta);

        return sum;
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator-= (Matrix M) // mat1 changes + return new matrix with difference
{
    //assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

    int dta[row*col];
    if(row == M.row && col == M.col)
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                data[i][j] -= M.data[i][j]; // subtract each element from the second matrix to its corresponding element from the first matrix
                dta[i * col + j] = data[i][j]; // convert the 1D matrix to 2D matrix
            }
        }
        Matrix diff(row , col, dta); //new matrix to hold the result

        return diff;
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator+= (int scalar)   // change mat & return new matrix
{
  int dta[row*col];
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                data[i][j] += scalar; //add a scalar to each element on the matrix
                dta[i * col + j] = data[i][j]; // convert the 1D matrix to 2D matrix
            }
        }
        Matrix newMat(row , col, dta); //new matrix to hold the result

        return newMat;
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator-= (int scalar)  // change mat & return new matrix
{
    int dta[row*col];

    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                data[i][j] -= scalar; //subtract a scalar to each element on the matrix
                dta[i * col + j] = data[i][j]; // convert the 1D matrix to 2D matrix
            }
        }
        Matrix newMat2(row , col, dta); //new matrix to hold the result

        return newMat2;
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator++ ()   	// Add 1 to each element ++mat
{
 int dta[row*col];
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                ++data[i][j]; //increment each element on the matrix by one
                dta[i * col + j] = data[i][j]; // convert the 1D matrix to 2D matrix
            }
        }
        Matrix incrMat(row , col, dta); //new matrix to hold the result


        return incrMat;
    }
}
//________________________________________________________________________________________________

Matrix Matrix:: operator-- ()   	// Sub 1 from each element --mat
{
 int dta[row*col];
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                --data[i][j]; //decrement each element on the matrix by one
                dta[i * col + j] = data[i][j]; // convert the 1D matrix to 2D matrix
            }
        }
        Matrix decrMat(row , col, dta); //new matrix to hold the result


        return decrMat;
    }
}
///---------------------------------------------------------------------------------------
///Student #3
//with the biggest ID (e.g., 20170089)

bool Matrix :: operator== (Matrix mat2)	// True if identical
{
    if(this->row != mat2.row && this->col != mat2.col) // if same dimension or not
        return (0);
    for(int i = 0 ; i < this->row ; i++)
    {
        for(int j = 0 ; j < this->col ; j++)
        {
            if(this->data[i][j] != mat2.data[i][j])  // if same element or not
            {
                return (0);
            }
        }
    }
    return (1);
}
//________________________________________________________________________________________________

bool Matrix :: operator!= (Matrix mat2) 	// True if not same
{
    if(this->row != mat2.row || this->col != mat2.col) // if same dimension or not
        return 1;
    bool diff = false;
    for(int i = 0 ; i < this->row ; i++)
    {
        for(int j = 0 ; j < this->col ; j++)
        {
            if( this->data[i][j] != mat2.data[i][j] )  // if same element or not
            {
                diff = true;
            }
        }
    }
    return diff;
}
//________________________________________________________________________________________________

bool Matrix :: isSquare()  // True if square matrix
{
    return (row == col ? 1 : 0 );
}
//________________________________________________________________________________________________

bool Matrix :: isSymetric ()  // True if square and symmetric
{
    if(Matrix::isSquare())
    {
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                // data[i][j] is the corresponding element of data[j][i].
                if(data[i][j] != data[j][i])
                    return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}
//________________________________________________________________________________________________

bool Matrix :: isIdentity ()  // True if square and identity
{
    if(Matrix::isSquare())
    {
        for(int i = 0 ; i < this->row ; i++)
        {
            for(int j = 0 ; j < this->col ; j++)
                // The elements in the main diagonal (row = column (i = j)) should not = 1 .
                // and the other elements (row != column (i != j)) should not = 0 .
                if( (i != j && this->data[i][j] != 0 )  || (i == j && this->data[i][j] != 1))
                    return 0;
        }

    }
    else
        return 0;

    return 1;
}
//________________________________________________________________________________________________

Matrix Matrix:: transpose()    // Return new matrix with the transpose
{
    // create a new matrix to save the transpose in it :-

    int *TranposedData = new int [(col) * (row)];

    for(int i = 0 ; i < col ; i++)
    {
        for(int j = 0 ; j < row ; j++)
        {
            TranposedData[i * row + j] = data[j][i]; // the row in real matrix = the column in the transpose.
        }
    }
    Matrix t_mat(col , row , TranposedData);


    delete[] TranposedData;

    return t_mat;
}


///-------------------------------------------------------------------------
void drowLine(){
    cout << "----------------------------------------" << endl;
}

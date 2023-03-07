//*******************************************************************
//
//  matrix.h
//  CSCI 241 Assignment 6
//
//  Created by Noah Allen (z1888906)
//
//*******************************************************************
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class matrix
{
    // Declares overloaded operator<<() function to be a friend of class matrix
    friend std::ostream& operator<<(std::ostream& stream_print, const matrix& obj);
    // Declares the overloaded operator* to be a friend of class matrix
    friend matrix operator*(int scalar_int, const matrix& r_operand);

    private:
        int matrix_array[2][2] = {{1, 0}, {0, 1}};

    public:
        matrix() = default; // identity matrix constructor
        matrix(int [2][2]); // Array initialization constructor
        int determinant() const;
        matrix operator+(const matrix& rhs) const;
        matrix operator*(int rhs) const;
        matrix operator*(const matrix& rhs) const;
        bool operator==(const matrix& rhs) const;
        bool operator!=(const matrix& rhs) const;
};

#endif
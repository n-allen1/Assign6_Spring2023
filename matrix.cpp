//*******************************************************************
//
//  matrix.cpp
//  CSCI 241 Assignment 6
//
//  Created by Noah Allen (z1888906)
//
//*******************************************************************
#include "matrix.h"
#include <iostream>

/**
 * @brief Construct a new matrix::matrix object
 *  As a matrix array
 * 
 * @param Array 
 */
matrix::matrix(int Array[2][2])
{
   matrix_array[0][0] = Array[0][0];
   matrix_array[0][1] = Array[0][1];
   matrix_array[1][0] = Array[1][0]; 
   matrix_array[1][1] = Array[1][1];
}

/**
 * @return int determinant of the *matrix* object
 */
int matrix::determinant() const
{
    return matrix_array[0][0] * matrix_array[1][1] 
            - matrix_array[0][1] * matrix_array[1][0];
}

/**
 * @brief This member function takes a paramater a reference to a const matrix object (which is the right operand of a matrix addition expression). Then adds the left operand which is represented by *this* which points to the matrix object that called the member function.
 * 
 * @param rhs right hand side
 * @return matrix object created from the addition expression
 */
matrix matrix::operator+(const matrix& rhs) const
{
    matrix result;

    // Position [0][0]
    result.matrix_array[0][0] = matrix_array[0][0] + rhs.matrix_array[0][0];

    // Position [0][1]
    result.matrix_array[0][1] = matrix_array[0][1] + rhs.matrix_array[0][1];

    // Position [1][0]
    result.matrix_array[1][0] = matrix_array[1][0] + rhs.matrix_array[1][0];

    // Position [1][1]
    result.matrix_array[1][1] = matrix_array[1][1] + rhs.matrix_array[1][1];

    return result;
}

/**
 * @param rhs right hand side
 * @return matrix of the result from multiplying the left hand side by the rhs matrix.
 */
matrix matrix::operator*(int rhs) const
{
    matrix result;

    // Position [0][0]
    result.matrix_array[0][0] = matrix_array[0][0] * rhs;

    // Position [0][1]
    result.matrix_array[0][1] = matrix_array[0][1] * rhs;

    // Position [1][0]
    result.matrix_array[1][0] = matrix_array[1][0] * rhs;

    // Position [1][1]
    result.matrix_array[1][1] = matrix_array[1][1] * rhs;

    return result;
}

/**
 * @brief Performing matrix multiplication (which is not commutative).
 * |a b| * |e f| = |(a * b + b * g)  (a * f + b * h)|
 * |c d|   |g h|   |(c * e + d * g)  (c * f + d * h)|
 * 
 * @param rhs right hand side
 * @return matrix after matrix multiplication
 */
matrix matrix::operator*(const matrix& rhs) const
{
    matrix result;

    // Position [0][0]
    result.matrix_array[0][0] = matrix_array[0][0] * rhs.matrix_array[0][0] + matrix_array[0][1] * rhs.matrix_array[1][0];

    // Position [0][1]
    result.matrix_array[0][1] = matrix_array[0][0] * rhs.matrix_array[0][1] + matrix_array[0][1] * rhs.matrix_array[1][1];

    // Position [1][0]
	result.matrix_array[1][0] = matrix_array[1][0] * rhs.matrix_array[0][0] + matrix_array[1][1] * rhs.matrix_array[1][0];

    // Position [1][1]
    result.matrix_array[1][1] = matrix_array[1][0] * rhs.matrix_array[0][1] + matrix_array[1][1] * rhs.matrix_array[1][1];

    return result;

}

/**
 * @brief Returns true if all the elements of the left operand equal all the elements of the right operand (rhs).
 */
bool matrix::operator==(const matrix& rhs) const
{
    return matrix_array[0][0] == rhs.matrix_array[0][0] // Position [0][0]
    && matrix_array[0][1] == rhs.matrix_array[0][1] // Position [0][1]
    && matrix_array[1][0] == rhs.matrix_array[1][0] // Position [1][0]
    && matrix_array[1][1] == rhs.matrix_array[1][1]; // Position [1][1]
}

/**
 * @brief Returns false if the left operand equals the right operand (rhs)... otherwise returns true.
 */
bool matrix::operator!=(const matrix& rhs) const
{
    return !(matrix_array[0][0] == rhs.matrix_array[0][0] // Position [0][0]
            && matrix_array[0][1] == rhs.matrix_array[0][1] // Position [0][1]
            && matrix_array[1][0] == rhs.matrix_array[1][0] // Position [1][0]
            && matrix_array[1][1] == rhs.matrix_array[1][1]); // Position [1][1]
}

/**
 * @brief Prints the elements of the matrix
 * 
 * @param stream_print will be used similar as a "cout", when using class objects 
 * @param obj will be the matrix object
 * @return std::ostream& Printing
 */
std::ostream& operator<<(std::ostream& stream_print, const matrix& obj)
{
    stream_print << "[[" << obj.matrix_array[0][0] << ", ";
    stream_print << obj.matrix_array[0][1] << "], [";
    stream_print << obj.matrix_array[1][0] << ", ";
    stream_print << obj.matrix_array[1][1] << "]]";

    return stream_print;
}

/**
 * @brief Multiplying a matrix (r_operand) by a scalar.
 * 
 * @param scalar_int 
 * @param r_operand 
 * @return matrix from the outcome of doing the scalar multiplication
 */
matrix operator*(int scalar_int, const matrix& r_operand)
{
    matrix result;

    // Position [0][0]
    result.matrix_array[0][0] = r_operand.matrix_array[0][0] * scalar_int;
    
    // Position [0][1]
    result.matrix_array[0][1] = r_operand.matrix_array[0][1] * scalar_int;

    // Position [1][0]
    result.matrix_array[1][0] = r_operand.matrix_array[1][0] * scalar_int;

    // Position [1][1]
    result.matrix_array[1][1] = r_operand.matrix_array[1][1] * scalar_int;

    return result;
}
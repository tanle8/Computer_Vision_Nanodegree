#include "matrix.h"

/* TODO: Define the default constructor. Remember the syntax is
**      Classname::ClassName() {
**
**          initialize variables
**
**       }
**
**
**      You need to initialize the grid variable to a default value such as
**      a 4x4 matrix with all zeros.
**
**      Then initialize the rows variable, and the cols variable using the
**      vector size method. For example myvector.size() will give the size of
**      a vector. For a 2-dimensional vector, myvector.size() would be the
**      number of rows in a matrix.
**
*/
Matrix::Matrix()
{
	std::vector< std::vector<float>> init_grid(10, std::vector<float> (4, 0.0));
	grid = init_grid;
	rows = init_grid.size();
	cols = init_grid[0].size();
}


/* TODO: Define a constructor that receives a 2-Dimensional vector
**       and assigns the vector to the grid variable.
**
**      Remember the syntax is
**      Classname::ClassName(datatype inputvariablename) {
**
**          classvariable = inputvariablename
**
**       }
**
**      Then initialize the rows variable, and the cols variable exactly
**      as you did for the default constructor.
**
*/
Matrix::Matrix(std::vector<std::vector<float>> init_grid)
{
	grid = init_grid;
	rows = init_grid.size();
	cols = init_grid[0].size();
}


/*
** TODO: Define a function setGrid()
**   INPUTS: a 2-D vector
**   OUPUTS: void
**
**   This function receives a 2-D vector reprenting a matrix, and then
**    updates the grid, rows, and cols variables
**
*/
void Matrix::setGrid(std::vector<std::vector<float>> new_grid)
{
	grid = new_grid;
	rows = new_grid.size();
	cols = new_grid[0].size();
}


/*
** TODO: Define getGrid(), getRows(), and getCols() functions.
**    INPUTS: None of these functions have inputs
**    OUPUTS: Each function should return its respective variable
**            For example, getRows returns the rows variable
*/
std::vector<std::vector<float>> Matrix::getGrid()
{
	return grid;
}

std::vector<float>::size_type Matrix::getRows()
{
	return rows;
}

std::vector<float>::size_type Matrix::getCols()
{
	return cols;
}


/* TODO: Define a matrix_transpose function
* INPUT: a matrix
* OUTPUT: the transpose of the grid variable 
*/
Matrix Matrix::matrix_transpose() {
	std::vector<std::vector<float>> result;
	std::vector<float> row;
	
	for (int i = 0; i < cols; i++) {
		row.clear();
		for (int j = 0; j < rows; j++) {
			row.push_back(grid[j][i]);
		}
		result.push_back(row);
	}

	return Matrix(result);
}



/* TODO: Define a matrix_addition function
**   INPUT: a matrix
**   OUPUT: the sum of the grid variable and the input matrix
**
** STEPS:
**  1. check that the matrix in the grid variable
**     and the input matrix have the same size
**
**     if not, throw an error like
**         throw std::invalid_argument("matrices are not the same size");
**
** 2. add the matrices together and return
**       the result as a Matrix. You can do this part
**       with nested for loops. If you use an intermediate
**       vector to store a row, the vector.clear()
**       method might be useful.
**
*/
Matrix Matrix::matrix_addition(Matrix other)
{
	if (rows != other.getRows() || cols != other.getCols()) {
		throw std::invalid_argument("matrices are not the same size");
	}

	// Create a 2D immediate vector to store value of input matrix
	std::vector<std::vector<float>> other_grid = other.getGrid();
	// Create a 2D vector to store the result
	std::vector<std::vector<float>> result;
	// create a row to store the additing results
	std::vector<float> new_row;

	// Add element-wise
	for (int i = 0; i < rows; i++) {
		new_row.clear();
		for (int j = 0; j < cols; j++) {
			new_row.push_back(grid[i][j] + other_grid[i][j]);
		}
		
		result.push_back(new_row);
	}

	return Matrix(result);
}


/* TODO: Define a matrix_print function
** This function has no inputs and no outputs
** The purpose of the function is to display the matrix in
** the terminal using std::cout.
**
**
** The output should look something like:
** 4    9   1   10
** 5    11  6   17
** 8    4   15  2
*/
void Matrix::matrix_print() 
{
	std::cout << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

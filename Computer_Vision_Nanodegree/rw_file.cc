#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


void read_file() {
    // initialize string variables for reading in text file lines
    string line;
    stringstream ss;

    // initialize the variables to hold the matrix
    vector<vector<float>> matrix;
    vector<float> row;

    // counter for characters in a text file line
    float i;

    // read in the file
    // reads in the file "matrix.txt" and then creates
    // an object called "matrixfile" that you can use
    // for reading in the text file
    ifstream matrixfile("matrix.txt");

    // read in the matrix file line by line parse the file
    // the if statement below checks that the file opened correctly
    if (matrixfile.is_open()) {
        while (getline(matrixfile, line)) {
            // this while loop reads the file one line at a time.
            // Each line is placed into a variable called "line"
            // parse the text line with a stringstream
            // clear the string stream to hold the next line
            ss.clear();
            ss.str("");
            ss.str(line);
            row.clear();

            // parse each line and push to the end of the row vector
            while (ss >> i) {
                row.push_back(i);

                if (ss.peek() == ',' || ss.peek() == ' ') {
                    ss.ignore();
                }
            }

            // push the row to the end of the matrix
            matrix.push_back(row);
        }

        matrixfile.close();

        // print out the matrix
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                cout << matrix[row][column] << " ";
            }
            cout << endl;
        }
    }
    else cout << "Unable to open file" << endl;

}

void write_file() {
    // create the vector that will be outputted
    vector <vector<int>> matrix(5, vector<int>(3, 2));
    vector<int> row;

    // open a file for outputting the matrix
    ofstream outputfile;
    outputfile.open("matrix_output.txt");

    // output the matrix to the file
    if (outputfile.is_open()) {
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (column != matrix[row].size() - 1) {
                    outputfile << matrix[row][column] << ", ";
                }
                else {
                    outputfile << matrix[row][column];
                }
            }
            outputfile << endl;
        }
    }

    outputfile.close();
    cout << "completed...";
}
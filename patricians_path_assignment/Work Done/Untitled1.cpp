#include <vector>
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("maze.txt");

    int ROWS, COLS;
    file >> ROWS >> COLS;

    file.ignore();

    std::vector<std::vector<char>> matrix(ROWS, std::vector<char>(COLS));

This will save those first two numbers in the file as the rows and columns (the ignore bit is just to get the file reading to ignore those parts when we add the rest to the vectors). I just chose the name matrix for the array just because that's how I think of it (you can call it whatever you want). I also chose char for the vector type, since we really just care about the individual symbols, and not so much the whole string.

for (int i = 0; i < ROWS; ++i) {
    std::string line;
    std::getline(file, line);

    for (int j = 0; j < COLS; ++j) {
    matrix[i][j] = line[j];
    }
}

This part should actually add the values into the vector. It saves each line as a string, then goes through each individual value of the string and saves it in a separate box.

for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
        std::cout << matrix[i][j];
        }
    std::cout << '\n';
    }
}

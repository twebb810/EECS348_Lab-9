#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./lab9 <input_file>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::size_t N;
    int type_flag;
    infile >> N >> type_flag;

    if (type_flag == 0) {
        // Integer matrix
        Matrix<int> A = read_matrix_from_file<int>(infile, N);
        Matrix<int> B = read_matrix_from_file<int>(infile, N);

        std::cout << "Matrix A:\n";
        A.print_matrix();
        std::cout << "\nMatrix B:\n";
        B.print_matrix();

        std::cout << "\nA + B:\n";
        (A + B).print_matrix();

        std::cout << "\nA * B:\n";
        (A * B).print_matrix();

        std::cout << "\nMain diagonal sum (A): " << A.sum_diagonal_major() << '\n';
        std::cout << "Minor diagonal sum (A): " << A.sum_diagonal_minor() << '\n';

        A.swap_rows(0, 1);
        std::cout << "\nA after swapping rows 0 and 1:\n";
        A.print_matrix();

        A.swap_cols(0, 1);
        std::cout << "\nA after swapping cols 0 and 1:\n";
        A.print_matrix();

        A.set_value(0, 0, 999);
        std::cout << "\nA after setting (0,0) to 999:\n";
        A.print_matrix();

        std::vector<std::vector<int>> raw_matrix = {
            {1, 2},
            {3, 4}
        };
        update_matrix_element(raw_matrix, 0, 1, 42);
        std::cout << "\nUpdated vector<int> matrix[0][1] to 42: " << raw_matrix[0][1] << "\n";

    } else if (type_flag == 1) {
        // Double matrix
        Matrix<double> A = read_matrix_from_file<double>(infile, N);
        Matrix<double> B = read_matrix_from_file<double>(infile, N);

        std::cout << "Matrix A:\n";
        A.print_matrix();
        std::cout << "\nMatrix B:\n";
        B.print_matrix();

        std::cout << "\nA + B:\n";
        (A + B).print_matrix();

        std::cout << "\nA * B:\n";
        (A * B).print_matrix();

        std::cout << "\nMain diagonal sum (A): " << A.sum_diagonal_major() << '\n';
        std::cout << "Minor diagonal sum (A): " << A.sum_diagonal_minor() << '\n';

        A.swap_rows(0, 1);
        std::cout << "\nA after swapping rows 0 and 1:\n";
        A.print_matrix();

        A.swap_cols(0, 1);
        std::cout << "\nA after swapping cols 0 and 1:\n";
        A.print_matrix();

        A.set_value(0, 0, 999.99);
        std::cout << "\nA after setting (0,0) to 999.99:\n";
        A.print_matrix();

        std::vector<std::vector<double>> raw_matrix = {
            {1.1, 2.2},
            {3.3, 4.4}
        };
        update_matrix_element(raw_matrix, 1, 0, 99.9);
        std::cout << "\nUpdated vector<double> matrix[1][0] to 99.9: " << raw_matrix[1][0] << "\n";
    } else {
        std::cerr << "Invalid type flag. Use 0 for int, 1 for double.\n";
        return 1;
    }

    return 0;
}

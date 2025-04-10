// matrix.hpp
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(std::size_t N) : data(N, std::vector<T>(N, 0)) {}
    Matrix(std::vector<std::vector<T>> nums) : data(std::move(nums)) {}

    Matrix<T> operator+(const Matrix<T> &rhs) const {
        std::size_t N = data.size();
        Matrix<T> result(N);
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &rhs) const {
        std::size_t N = data.size();
        Matrix<T> result(N);
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                for (std::size_t k = 0; k < N; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    void set_value(std::size_t i, std::size_t j, T n) {
        data[i][j] = n;
    }

    T get_value(std::size_t i, std::size_t j) const {
        return data[i][j];
    }

    int get_size() const {
        return data.size();
    }

    T sum_diagonal_major() const {
        T sum = 0;
        for (std::size_t i = 0; i < data.size(); ++i)
            sum += data[i][i];
        return sum;
    }

    T sum_diagonal_minor() const {
        T sum = 0;
        for (std::size_t i = 0; i < data.size(); ++i)
            sum += data[i][data.size() - 1 - i];
        return sum;
    }

    void swap_rows(std::size_t r1, std::size_t r2) {
        std::swap(data[r1], data[r2]);
    }

    void swap_cols(std::size_t c1, std::size_t c2) {
        for (auto &row : data)
            std::swap(row[c1], row[c2]);
    }

    void print_matrix() const {
        for (const auto &row : data) {
            for (const auto &val : row)
                std::cout << std::setw(8) << val;
            std::cout << '\n';
        }
    }
};

// Template function to update an element of a matrix (polymorphic for int or double)
template <typename T>
void update_matrix_element(std::vector<std::vector<T>> &matrix, std::size_t row, std::size_t col, T value) {
    if (row < matrix.size() && col < matrix[row].size()) {
        matrix[row][col] = value;
    }
}

// Template function to read matrix from file
template <typename T>
Matrix<T> read_matrix_from_file(std::ifstream &file, std::size_t N) {
    std::vector<std::vector<T>> nums(N, std::vector<T>(N));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            file >> nums[i][j];
    return Matrix<T>(nums);
}

#endif // __MATRIX_HPP__

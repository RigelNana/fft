//
// Created by RigelShrimp on 2025/1/18.
//
#include "fft.h"
#include <stdexcept>

namespace fft_library {
Eigen::VectorXcd fft(const Eigen::VectorXd& X, int n) {
    if (X.size() == 0 || n <= 0) {
        return Eigen::VectorXcd(0);
    }

    Eigen::VectorXcd x_complex = Eigen::VectorXcd::Zero(n);


    for (int i = 0; i < std::min(static_cast<int>(X.size()), n); ++i) {
        x_complex(i) = std::complex<double>(X(i), 0.0);
    }

    thread_local Eigen::FFT<double> fft_processor;
    Eigen::VectorXcd result(n);
    fft_processor.fwd(result, x_complex);



    return result;
}


Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n, int dim) {
    if (X.size() == 0 || n == 0) {
        return Eigen::MatrixXcd{0, 0};
    }

    if (n < 0) {
        throw std::invalid_argument("FFT size n cannot be negative");
    }

    if (dim != 1 && dim != 2) {
        throw std::invalid_argument("Dimension must be 1 (rows) or 2 (columns)");
    }

    thread_local Eigen::FFT<double> fft_processor;

    Eigen::MatrixXcd result{X};

    if (dim == 1) {
        result.conservativeResize(n, Eigen::NoChange);
        if (n > X.rows()) {
            result.bottomRows(n - X.rows()).setZero();
        }

        for (Eigen::Index i = 0; i < result.cols(); ++i) {
            Eigen::VectorXcd col {result.col(i)};
            fft_processor.fwd(col, col);
            result.col(i) = col;
        }
    } else {
        result.conservativeResize(Eigen::NoChange, n);
        if (n > X.cols()) {
            result.rightCols(n - X.cols()).setZero();
        }

        for (Eigen::Index i = 0; i < result.rows(); ++i) {
            Eigen::VectorXcd row {result.row(i)};
            fft_processor.fwd(row, row);
            result.row(i) = row;
        }
    }

    return result;
}

} // namespace fft_library


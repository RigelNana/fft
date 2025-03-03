//
// Created by RigelShrimp on 2025/1/18.
//
#include "fft.h"
#include <stdexcept>

namespace fft_library {
Eigen::VectorXcd fft(const Eigen::VectorXd& X, int n) {
    if (X.size() == 0 || n == 0) {
        return Eigen::VectorXcd(0);
    }
    thread_local Eigen::FFT<double> fft_processor;
    if (n == -1) {
        Eigen::VectorXcd result(X.rows());
        fft_processor.fwd(result, X);
        return result;
    }

    Eigen::VectorXcd x_complex = Eigen::VectorXcd::Zero(n);


    for (int i = 0; i < std::min(static_cast<int>(X.size()), n); ++i) {
        x_complex(i) = std::complex<double>(X(i), 0.0);
    }


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

    thread_local Eigen::FFT<double> f;
    Eigen::MatrixXcd result{X};

    if (dim == 1) {
        int orig_rows = X.rows();
        result.conservativeResize(n, Eigen::NoChange);

        if (n > orig_rows) {
            result.bottomRows(n - orig_rows).setZero();
        }

        for (Eigen::Index i = 0; i < result.cols(); ++i) {
            Eigen::VectorXcd col = result.col(i);
            Eigen::VectorXcd ct(n);
            f.fwd(ct, col, n);
            result.col(i) = ct;
        }
    } else {
        int orig_cols = X.cols();
        result.conservativeResize(Eigen::NoChange, n);

        if (n > orig_cols) {
            result.rightCols(n - orig_cols).setZero();
        }

        for (Eigen::Index i = 0; i < result.rows(); ++i) {
            Eigen::VectorXcd row = result.row(i);
            Eigen::VectorXcd rt(n);
            f.fwd(rt, row, n);
            result.row(i) = rt;
        }
    }

    return result;
}



} // namespace fft_library


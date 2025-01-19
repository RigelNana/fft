//
// Created by RigelShrimp on 2025/1/18.
//
#include "fft.h"

namespace fft_library {
Eigen::MatrixXcd fft(Eigen::MatrixXcd const &X, int n, int dim) {
    if (X.size() == 0 || n == 0) {
        return Eigen::MatrixXd(0, 0);
    }
    Eigen::FFT<double> f;
    Eigen::MatrixXcd Y = X;
    long long const rows = Y.rows();
    long long const cols = Y.cols();
    if (n > -1) {
        switch (dim) {
        case 1: {
            Y.conservativeResize(n, Eigen::NoChange);
            if (n > rows) {
                Y.bottomRows(n - rows).setZero();
            }
            break;
        }
        case 2: {
            Y.conservativeResize(Eigen::NoChange, n);
            if (n > cols) {
                Y.rightCols(n - cols).setZero();
            }
            break;
        }
        default: {
            return X;
        };
        }
    }
    Eigen::MatrixXcd result(Y.rows(), Y.cols());
    if (dim == 1 || dim > Y.cols()) {
        for (auto i = 0; i < Y.cols(); i++) {
            Eigen::VectorXcd temp = Y.col(i);
            f.fwd(temp, temp);
            result.col(i) = temp;
        }
    } else if (dim == 2) {
        for (auto i = 0; i < Y.rows(); i++) {
            Eigen::VectorXcd temp = Y.row(i);
            f.fwd(temp, temp);
            result.row(i) = temp;
        }
    }
    return result;
}
} // namespace fft_library

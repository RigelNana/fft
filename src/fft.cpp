//
// Created by RigelShrimp on 2025/1/18.
//
#include "fft.h"

namespace fft_library {
    Eigen::VectorXcd fft(const Eigen::VectorXcd &X) {
        const auto N = X.size();
        if (N < 2) {
            return X;
        }
        if (N & (N - 1)) {
            throw std::invalid_argument("N must be power of 2");
        }
        Eigen::VectorXcd even(N / 2);
        Eigen::VectorXcd odd(N / 2);
        for (int i = 0; i < N / 2; ++i) {
            even[i] = X[2 * i];
            odd[i]  = X[2 * i + 1];
        }

        Eigen::VectorXcd fft_even = fft(even);
        Eigen::VectorXcd fft_odd = fft(odd);
        Eigen::VectorXcd total(N);
        for (auto i = 0; i < N / 2; i++) {
            std::complex<double> t = std::polar(1.0, -2.0 * M_PI * static_cast<double>(i) / static_cast<double>(N)) * fft_odd[i];
            total[i] = fft_even[i] + t;
            total[i + N / 2] = fft_even[i] - t;
        }
        return total;

    }

    Eigen::VectorXcd fft(const Eigen::VectorXcd &X, long long n) {
    }

    Eigen::VectorXcd fft(const Eigen::VectorXcd &X, long long n, int dim) {
    }

    Eigen::MatrixXcd fft(const Eigen::MatrixXcd &X) {
    }

    Eigen::MatrixXcd fft(const Eigen::MatrixXcd &X, long long n) {
    }

    Eigen::MatrixXcd fft(const Eigen::MatrixXcd &X, long long n, int dim) {
    }
}

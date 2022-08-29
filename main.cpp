#include <iostream>
#include <gmpxx.h>
#include <chrono>
#include <random>
//#include <gmp.h>

const long LENGTH = 800;

void taylor_expansion()
{
    mpz_class x; // x in the Taylor Expansion
    gmp_randstate_t state;
    gmp_randinit_default(state);
    mpz_urandomb(x.get_mpz_t(), state, LENGTH);

    mpz_class sum = 0;
    for (unsigned long i=0; i<27; ++i)
    {
        mpz_class power, coefficient;
        mpz_pow_ui(power.get_mpz_t(), x.get_mpz_t(), i);
        gmp_randseed_ui (state, i);
        mpz_urandomb(coefficient.get_mpz_t(), state, LENGTH);
        mpz_class temp_sum = power * coefficient;

        sum += temp_sum;

        std::cout << "Iteration: " << i << " Sum: " << sum;
        //mpz_out_str(stdout,10,sum.get_mpz_t());
        std::cout << std::endl;
    }
    gmp_randclear(state);
}

double ReLU(double num)
{
    if (num > 0) return num;
    return 0;
}


int main() {
    using namespace std::chrono;
    time_point<high_resolution_clock> start, end;
    start = high_resolution_clock::now();
    taylor_expansion();
    end = high_resolution_clock::now();
    duration<double, std::nano> elapsed_seconds_taylor = end-start;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    start = high_resolution_clock::now();
    double res = ReLU(dist(mt));
    end = high_resolution_clock::now();
    duration<double, std::nano> elapsed_seconds_relu = end-start;

    std::cout << "Finish Simulation!" << std::endl;
    std::cout << "Taylor Series Latency(ns): " << elapsed_seconds_taylor.count() << std::endl;
    std::cout << "ReLU Latency(ns): " << elapsed_seconds_relu.count();
    return 0;
}

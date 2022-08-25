#include <iostream>
#include <gmpxx.h>
//#include <gmp.h>

const long LENGTH = 400;

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

int main() {
    taylor_expansion();
    std::cout << "Finish Simulation!" << std::endl;
    return 0;
}

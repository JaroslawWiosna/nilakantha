/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */


#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>
int main()
{
    long double decExp{};
    long double eps = std::numeric_limits<long double>::epsilon() * 10;
    std::cout << "eps = "<< eps << std::endl;

    std::cout 
        << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
        << "M_PI ="
        << "\t"
        << M_PI
        << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();
    for (long double i = 0 ; i < 1800000 ; ++i)
    {
        auto now = std::chrono::high_resolution_clock::now();
        long double tmp = pow(-1,i) * 4.0L / ((2*i+2)*(2*i+3)*(2*i+4));
        auto stoper = std::chrono::duration_cast<std::chrono::seconds>(now - begin);
        std::cout 
            << "\r"
            << stoper.count()
            << " sec"
            << "\t"
	        << 3+decExp; 

        decExp += tmp;
        if (std::abs(tmp) < eps)
            break;
    }

    std::cout << std::endl;

}

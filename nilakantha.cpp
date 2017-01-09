/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */


#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>

const std::string pi() 
{
    std::ostringstream str;
    str << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
    str << std::atan(1)*4; 
    return str.str();
}

std::string printDecExpColor(double value)
{
    const char* CLEAR = "\x1B[0m";
    const char* RED = "\x1B[31m";

    std::string piStr = pi();

    std::ostringstream str;
    str << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
    str << value;
    std::string valueS = str.str();

    std::ostringstream retStr;
    retStr << RED;
    for(std::string::size_type  i = 0; i < piStr.size(); ++i)
    {
        if (valueS[i] != piStr[i])
	{
	    retStr << CLEAR;
	}
	retStr << valueS[i];
    }
    retStr << CLEAR;

    std::string retValue = retStr.str();
    return retValue;
}
int main()
{
    auto lambdaNilakantha = [](long double i) -> long double
    {
        return pow(-1,i) * 4.0L / ((2*i+2)*(2*i+3)*(2*i+4));
    };
    auto lambdaLeibnitz = [](long double i) -> long double
    {
        return pow(-1,i) * 4.0L / (2*i+1);
    };


    long double decExp{};
    long double decExpLeibnitz{};
    long double eps = std::numeric_limits<long double>::epsilon() * 100;
    std::cout << "          eps = "<< eps << std::endl;

    std::cout 
        << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
        << "         M_PI = "
        << M_PI
        << std::endl
        << "    atan(1)*4 = "
        << pi()
        << std::endl
        << std::endl
        << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();
    for (long double i = 0 ; i < 5000000 ; ++i)
    {
        auto now = std::chrono::high_resolution_clock::now();
        long double tmp = lambdaNilakantha(i);
        long double tmpLeibnitz = lambdaLeibnitz(i);
        auto stoper = std::chrono::duration_cast<std::chrono::seconds>(now - begin);
        std::cout 
            << "\e[A"
            << "\e[A"
            << "\r"
            << stoper.count()
            << " sec"
            << "\n"
            << "Nilakantha "
            << "\t"
	        << printDecExpColor(3+decExp);

        std::cout 
	    << "\n"
            << "Leibnitz   "
            << "\t"
	        << printDecExpColor(decExpLeibnitz);

        decExp += tmp;
        decExpLeibnitz += tmpLeibnitz;
        if (std::abs(tmp) < eps)
            break;
    }

    std::cout << std::endl;

}

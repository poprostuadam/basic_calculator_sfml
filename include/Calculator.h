//
// Created by adam on 1/16/25.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

class Calculator {
public:
    using PrecisionFloat = boost::multiprecision::cpp_dec_float_50;

    Calculator();
    void calculate(const std::string& expression);
    const std::string& getResult() const;
    bool hasError() const;

private:
    std::vector<std::string> tokenize(const std::string& expression) const;
    std::vector<std::string> convertToRPN(const std::vector<std::string>& tokens) const;
    PrecisionFloat evaluateRPN(const std::vector<std::string>& tokens) const;

    bool isOperator(const std::string& token) const;

    std::string lastResult;
    bool errorFlag;

};



#endif //CALCULATOR_H

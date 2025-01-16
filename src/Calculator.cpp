//
// Created by adam on 1/16/25.
//

#include "../include/Calculator.h"

#include <config.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <stdexcept>


Calculator::Calculator(): lastResult("0"), errorFlag(false) {
}

void Calculator::calculate(const std::string &expression) {
    try {
        auto tokens = tokenize(expression);
        auto rpn = convertToRPN(tokens);

        PrecisionFloat result = evaluateRPN(rpn);

        std::ostringstream oss;
        oss << std::setprecision(config::DisplayMaxChars) << result;

        lastResult = oss.str();
        errorFlag = false;
    } catch (const std::exception& e) {
        errorFlag = true;
        lastResult = "ERROR";
    }
}

const std::string & Calculator::getResult() const {
    return lastResult;
}

bool Calculator::hasError() const {
    return errorFlag;
}

std::vector<std::string> Calculator::tokenize(const std::string &expression) const {
    std::vector<std::string> tokens;
    std::string currentToken;

    for (char c : expression) {
        if (std::isdigit(c) || c == '.') {
            currentToken += c;
        } else if (isOperator(std::string(1,c))) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
            tokens.push_back(std::string(1,c));
        } else if (c == ' ' || !currentToken.empty()) {
            tokens.push_back(std::string(1,c));
            currentToken.clear();
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    // Debug
    if (config::isDebug) {
        std::cout << "[DEBUG] Tokens: ";
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }

    return tokens;
}

std::vector<std::string> Calculator::convertToRPN(const std::vector<std::string> &tokens) const {
    std::vector<std::string> output;
    std::stack<std::string> operators;

    std::unordered_map<std::string, int> precedence = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };

    for (const auto& token : tokens) {
        if (std::isdigit(token[0]) || token.find('.') != std::string::npos) {
            output.push_back(token);
        } else if (isOperator(token)) {
            while (!operators.empty() && precedence[operators.top()] >= precedence[token]) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    // Debug
    if (config::isDebug) {
        std::cout << "[DEBUG] RPN: ";
        for (const auto& token : output) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }

    return output;
}

Calculator::PrecisionFloat Calculator::evaluateRPN(const std::vector<std::string>& tokens) const {
    std::stack<PrecisionFloat> values;

    for (const auto& token : tokens) {
        if (std::isdigit(token[0]) || token.find('.') != std::string::npos) {
            PrecisionFloat value(token);
            values.push(value);
            if (config::isDebug) {
                std::cout << "[DEBUG] Pushed to stack: " << value.str() << std::endl;
            }
        } else if (isOperator(token)) {
            if (values.size() < 2) {
                throw std::runtime_error("Invalid expression: Not enough operands for operator");
            }

            PrecisionFloat b = values.top(); values.pop();
            PrecisionFloat a = values.top(); values.pop();

            if (config::isDebug) {
                std::cout << "[DEBUG] Popped a: " << a.str() << ", b: " << b.str() << std::endl;
            }

            PrecisionFloat result;

            if (token == "+") {
                result = a + b;
                if (config::isDebug) {
                    std::cout << "[DEBUG] Result of a + b: " << result.str() << std::endl;
                }
            } else if (token == "-") {
                result = a - b;
                if (config::isDebug) {
                    std::cout << "[DEBUG] Result of a - b: " << result.str() << std::endl;
                }
            } else if (token == "*") {
                result = a * b;
                if (config::isDebug) {
                    std::cout << "[DEBUG] Result of a * b: " << result.str() << std::endl;
                }
            } else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("Division by zero");
                }
                result = a / b;
                if (config::isDebug) {
                    std::cout << "[DEBUG] Result of a / b: " << result.str() << std::endl;
                }
            } else {
                throw std::runtime_error("Invalid operator: " + token);
            }

            values.push(result);
            if (config::isDebug) {
                std::cout << "[DEBUG] Pushed result to stack: " << result.str() << std::endl;
            }
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (values.size() != 1) {
        throw std::runtime_error("Invalid expression: More than one value left on stack");
    }

    if (config::isDebug) {
        std::cout << "[DEBUG] Final result on stack: " << values.top().str() << std::endl;
    }

    return values.top();
}


bool Calculator::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}


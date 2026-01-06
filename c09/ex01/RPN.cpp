#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) : stack(other.stack) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        stack = other.stack;
    return *this;
}

bool RPN::isOperand(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool RPN::isOperator(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    return false;
}

int RPN::calcOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/':
            if (a == 0)
                throw std::runtime_error("Error");
            return b / a;
    }
    throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string& expr)
{
    for (size_t i = 0; i < expr.size(); ++i)
    {
        char c = expr[i];
        if (isspace(c))
            continue;
        if (isOperand(c))
            stack.push(c - '0');
        else if (isOperator(c))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(calcOperation(a, b, c));
        }
        else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}


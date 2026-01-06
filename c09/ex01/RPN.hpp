#pragma once

#include <stack>
#include <iostream>
#include <cstdlib>
#include <cctype>

class RPN {
    private:
        std::stack<int> stack;
        bool isOperand(char c);
        bool isOperator(char c);
        int calcOperation(int a, int b, char op) const;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        int evaluate(const std::string& expr);

};
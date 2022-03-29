#pragma once
#include <cmath>
#include <string>
#include <vector>
#include <fmt/format.h>

class Term {
public:
    enum expression {
        num = 0,
        sin,
        cos,
    };

    Term() {}
    Term(double coef, expression expr, double power);
    ~Term();

    double get_at(double x);
    double evaluate(int x);
    std::string to_string();

private:
    double m_coef;
    expression m_expr;
    double m_power;

    std::vector<std::string> expression_string = {"", "sin", "cos"};
};
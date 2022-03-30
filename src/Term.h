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

    /* Constructors and Destructors */
    Term(double coef, expression expr, double power);
    ~Term();

    /* Public Functions*/
    double get_at(double x); // Evaluates a term using the expression e.g. sin, cos
    double evaluate(int x); // Evaluates a term using the get_at function, power and coefficient
    std::string to_string();

private:
    double m_coef;
    expression m_expr;
    double m_power;

    std::vector<std::string> expression_string = {"", "sin", "cos"}; // Used for printing term
};
#include "Term.h"

Term::~Term() = default;

Term::Term(double coef, expression expr, double power)
    : m_coef{coef}, m_expr{expr}, m_power{power} {}

double Term::get_at(double x) {
    return m_coef*std::pow(evaluate(x), m_power);
}

double Term::evaluate(int x) {
    if(m_expr == expression::num) {
        return x;
    }
    else if(m_expr == expression::sin) {
        return std::sin(x);
    }
    else if(m_expr == expression::cos) {
        return std::cos(x);
    }
    return 0;
}

    std::string Term::to_string() {
        std::string s = fmt::format("{}{}(x)^{}", m_coef, expression_string[m_expr], m_power);
        return s;
    }
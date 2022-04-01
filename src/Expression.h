#pragma once
#include "Term.h"
#include <vector>
#include <string>
#include <fmt/format.h>
#include <cassert>

class Expr {
public:
    enum signs {
        PLUS = 0,
        MINUS,
        MULTIPLY,
        DIVIDE
    };

private:
    /* m_signs must always be exactly 1 less than m_terms */
    std::vector<Term> m_terms; // Contain terms
    std::vector<signs> m_signs; // Contain signs

    // Used when printing out the expression, these
    // must match up with the index of the signs enum
    std::vector<std::string> signs_string = {"+", "-", "*", "/"};

    void check(); // Used to check something I don't remember what
    void print(std::vector<double> v, std::vector<signs> s); // Used for debugging
public:
    /* Constructors and Destructor */
    Expr();
    explicit Expr(const Term& term);
    ~Expr();

    /* Public Functions */
    void add(signs sign, const Term& term); // Adds a term and sign to the current expression
    void add(const Term& term); // Adds a term and sign to the current expression

    double get_at(double x); // Evaluates the expression at some value x
    std::string to_string(); // Prints the expression
};
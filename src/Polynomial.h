#pragma once
#include "Term.h"
#include <vector>
#include <string>
#include <fmt/format.h>

class Poly {
public:
    enum signs {
        PLUS = 0,
        MINUS,
        MULTIPLY,
        DIVIDE
    };

private:
    std::vector<Term> m_terms;
    std::vector<signs> m_signs;
    
    std::vector<std::string> signs_string = {"+", "-", "*", "/"};

public:
    Poly(Term term);
    ~Poly();

    void add(signs sign, Term term);
    double get_at(double x);

    std::string to_string();
};
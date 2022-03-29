#include "Polynomial.h"

Poly::Poly(Term term) {
    m_terms.push_back(term);
}
Poly::~Poly() = default;

void Poly::add(signs sign, Term term) {
    m_terms.push_back(term);
    m_signs.push_back(sign);
}

double Poly::get_at(double x) { return 0; }

std::string Poly::to_string() {
    std::string s;
    for(int i=0; i<m_terms.size()-1; i++) {
        s += fmt::format("{} {} ", m_terms[i].to_string(), signs_string[m_signs[i]]);
    }
    s += fmt::format("{}", m_terms[m_terms.size()-1].to_string() );
    
    return s;
}

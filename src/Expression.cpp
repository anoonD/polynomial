#include "Expression.h"

/* Constructors and destructors */
Expr::Expr() = default;

Expr::Expr(const Term& term) {
    m_terms.push_back(term);
}

Expr::~Expr() = default;

void Expr::add(signs sign, const Term& term) {
    m_terms.push_back(term);
    m_signs.push_back(sign);

    check();
}
void Expr::add(const Term& term) {
    m_terms.push_back(term);

    check();
}

double Expr::get_at(double x) {
    std::vector<double> values;
    std::vector<signs> l_signs = m_signs;

    values.reserve(m_terms.size());
    for(auto & m_term : m_terms) {
        values.push_back(m_term.get_at(x));
    }

    /* Multiplication & Division */
    for(int i=0; i<l_signs.size(); ) {

        if(l_signs[i] == signs::MULTIPLY) {
            values[i] = values[i] * values[i+1];

            values.erase(values.begin() + i + 1);
            l_signs.erase(l_signs.begin() + i);

        }
        else if(l_signs[i] == signs::DIVIDE) {
            values[i] = values[i] / values[i+1];

            values.erase(values.begin() + i + 1);
            l_signs.erase(l_signs.begin() + i);
        }
        else {
            i++;
        }

    }

    /* Adding & Subtracting */
    for(int i=0; i<l_signs.size(); ) {

        if (l_signs[i] == signs::PLUS) {

            values[i] = values[i] + values[i + 1];

            values.erase(values.begin() + i + 1);
            l_signs.erase(l_signs.begin() + i);
            i = 0;
        } else if (l_signs[i] == signs::MINUS) {
            values[i] = values[i] - values[i + 1];

            values.erase(values.begin() + i + 1);
            l_signs.erase(l_signs.begin() + i);
            i=0;
        }
        else {
            i++;
        }
    }

    return values[0];
}

std::string Expr::to_string() {
    check();

    std::string s;
    for(int i=0; i<m_terms.size()-1; i++) {
        s += fmt::format("{} {} ", m_terms[i].to_string(), signs_string[m_signs[i]]);
    }
    s += fmt::format("{}", m_terms[m_terms.size()-1].to_string() );
    
    return s;
}

void Expr::check() {
    bool check = m_terms.size()-1 == m_signs.size();
    if(!check) {
        fmt::print( "There has to be exactly 1 more term than there are signs.\n");
        assert(m_terms.size()-1 == m_signs.size());
    }
}

void Expr::print(std::vector<double> v, std::vector<signs> s) {
    for(int i=0; i<s.size(); i++) {
        fmt::print("{} {} ", v[i], signs_string[s[i]]);
    }
    fmt::print("{}\n", v[v.size()-1]);
}
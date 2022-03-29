#include <iostream>
#include "Polynomial.h"

int main() {
    Term term1(1, Term::expression::num, 1);
    Poly poly1(term1);
    Term term2(2, Term::expression::num, 2);
    Term term3(3, Term::expression::num, 3);
    Term term4(4, Term::expression::num, 4);

    
    poly1.add(Poly::signs::DIVIDE, term2);
    poly1.add(Poly::signs::PLUS, term3);
    poly1.add(Poly::signs::MINUS, term4);
    
    fmt::print("{}\n", poly1.to_string());
}
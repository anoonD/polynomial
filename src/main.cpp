#include "Polynomial.h"

int main() {
    Poly poly1(Term(1, Term::expression::num, 1));
    Term term2(2, Term::expression::cos, 2);
    Term term3(3, Term::expression::num, 3);
    Term term4(4, Term::expression::sin, 4);

    poly1.add(Poly::signs::PLUS, term3);
    poly1.add(Poly::signs::DIVIDE, term2);
    poly1.add(Poly::signs::MINUS, term4);
    poly1.add(Poly::signs::PLUS, term4);
    poly1.add(Poly::signs::MULTIPLY, term2);

    fmt::print("{}\n", poly1.to_string());
    fmt::print("{}\n", poly1.get_at(4));

}
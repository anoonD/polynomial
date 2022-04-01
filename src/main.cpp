#include "Expression.h"


void demo1() {
    Term t1(1, Term::expression::x, 2); // x^2
    Term t2(10, Term::expression::num, 12); // 10
    Term t3(2, Term::expression::cos, 2); // cos(x)

    Expr p(t1);
    p.add(Expr::signs::PLUS, t2);
    p.add(Expr::signs::MINUS, t3);

    fmt::print("f(x) = {}\n", p.to_string());
    fmt::print("f(5) = {}\n", p.get_at(t1.get_at(12)));
}

int main() {
    demo1();
}
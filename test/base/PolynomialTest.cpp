#include <gtest/gtest.h>
#include <base/Polynomial.h>

using namespace base;

TEST(Polynomial, inputCheck){
    try{
        PolynomialSet s;
        s.insert(new PolynomialPair(1, (RationalFraction)4));
        s.insert(new PolynomialPair(0, RationalFraction::empty()));

        Polynomial p(s);

        FAIL() << "Polynomial shouldn't accept zero coefficient at first element";
    }catch(base::BaseException &exception){
        if((std::string)exception.what() == "first element must not be zero (or just dont specify it)") {
            SUCCEED();
        }else{
            FAIL() << "Wrong exception message: " << exception.what();
        }
    }

    try{
        PolynomialSet s;
        s.insert(new PolynomialPair(1, RationalFraction::empty()));

        Polynomial p(s);

        FAIL() << "Polynomial shouldn't accept list with size 1 and element in this list is zero";
    } catch (base::BaseException &exception) {
        if((std::string)exception.what() == "if you want to get empty Polynomial just use Polynomial()"){
            SUCCEED();
        }else{
            FAIL() << "Wrong exception message: " << exception.what();
        }
    }
}

TEST(Polynomial, addElement){
    PolynomialSet s;
    s.insert(new PolynomialPair(3, (RationalFraction)4)); // 4 * x^3
    Polynomial p(s); // для проверки

    p.addElement(new PolynomialPair(1, RationalFraction::fromTwoInt(3, 4))); // 3/4 * x^1

    // проверяем, добавились ли элементы
    EXPECT_EQ(p.getCoefficient(0).toString(), "0");
    EXPECT_EQ(p.getCoefficient(1).toString(), "3/4");
    EXPECT_EQ(p.getCoefficient(3).toString(), "4");

    // проверяем, сортирован ли список коэффициентов (сортирует он по степени X, рядом с которым стоит данный коэффициент)
    for(auto i = p.coefficients.begin(); i != std::prev(p.coefficients.end()); ++i){
        auto el = *i;
        auto nextEl = *std::next(i);

        if(el->degree >= nextEl->degree){
            FAIL() << "Degrees are not sorted";
        }
    }

    SUCCEED();
}

TEST(Polynomial, lastElement){
    PolynomialSet s;
    s.insert(new PolynomialPair(3, (RationalFraction)4)); // 4 * x^3
    Polynomial p(s); // для проверки

    p.addElement(
            new PolynomialPair(
                    1,
                    RationalFraction::fromTwoInt(3, 4)
            ) // 3/4 * x^1
    );

    EXPECT_EQ(p.lastElement()->degree, 3);
}

TEST(Polynomial, toString){
    PolynomialSet s;
    s.insert(new PolynomialPair(3, (RationalFraction)4)); // 4 * x^3

    Polynomial p(s); // для проверки
    p.addElement(new PolynomialPair(1, RationalFraction::fromTwoInt(3, 4))); // 3/4 * x^1
    EXPECT_EQ(p.toString(), "4*x^3 3/4*x^1");

    PolynomialSet s2;
    s2.insert(new PolynomialPair(0, (RationalFraction)3));
    Polynomial zeroDegreePolynomial(s2);
    EXPECT_EQ(zeroDegreePolynomial.toString(), "3");

    PolynomialSet s3;
    s3.insert(new PolynomialPair(0, (RationalFraction)4));
    Polynomial withConstPolynomial(s3);

    withConstPolynomial.addElement(new PolynomialPair(1, (RationalFraction)1));
    withConstPolynomial.addElement(new PolynomialPair(255, RationalFraction::fromTwoInt(3, 4)));
    withConstPolynomial.addElement(new PolynomialPair(4, RationalFraction::fromTwoInt(5, 6)));
    EXPECT_EQ(withConstPolynomial.toString(), "3/4*x^255 5/6*x^4 1*x^1 4");
}

TEST(Polynomial, remove){
    PolynomialSet s;
    s.insert(new PolynomialPair(0, (RationalFraction)5));
    Polynomial p(s);
    p.addElement(1, (RationalFraction)4);
    p.addElement(2, (RationalFraction)3);
    p.addElement(3, (RationalFraction)2);
    p.addElement(4, (RationalFraction)1);

    p.remove(3);

    EXPECT_EQ(p.toString(), "1*x^4 3*x^2 4*x^1 5");

    p.remove(0);

    EXPECT_EQ(p.firstElement()->degree, 1);
    EXPECT_EQ(p.toString(), "1*x^4 3*x^2 4*x^1");

    p.remove(4);
    p.remove(2); // удаление остальных элементов, чтобы получить нулевой полином
    p.remove(1);

    EXPECT_EQ(p.toString(), "0");

    p.remove(1); // удаление несуществующего элемента
    EXPECT_EQ(p.toString(), "0");
}

TEST(Polynomial, set){
    PolynomialSet s;
    s.insert(new PolynomialPair(0, (RationalFraction)5));
    Polynomial p(s);
    p.addElement(new PolynomialPair(1, (RationalFraction)4));
    p.addElement(new PolynomialPair(2, (RationalFraction)3));
    p.addElement(new PolynomialPair(3, (RationalFraction)2));
    p.addElement(new PolynomialPair(4, (RationalFraction)1));

    auto t = (RationalFraction)90;
    p.set(3, t);
    EXPECT_EQ(p.toString(), "1*x^4 90*x^3 3*x^2 4*x^1 5");

    t = (RationalFraction)55;
    p.set(10, t);
    EXPECT_EQ(p.toString(), "55*x^10 1*x^4 90*x^3 3*x^2 4*x^1 5");

    t = RationalFraction::empty();
    p.set(10, t);
    EXPECT_EQ(p.toString(), "1*x^4 90*x^3 3*x^2 4*x^1 5");
}
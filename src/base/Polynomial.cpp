#include "Polynomial.h"
#include <module/p.h>
#include <module/n.h>
#include <module/z.h>
#include <utility>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>

using namespace base;

Polynomial::Polynomial(PolynomialSet& coefficients) : coefficients(coefficients) {
    // проверим,
    if(coefficients.size() > 1) {
        // чистка списка коэффициентов от нулевых (потому что их нет смысла хранить)
        for (auto k = coefficients.begin(); k != coefficients.end(); ++k) {
            auto i = *k;
            if (i->value.numerator.isZero()) {
                if (k == coefficients.begin()) { // к сожалению я не могу из конструктора вернуть указатель на следующий элемент
                    throw BaseException("first element must not be zero (or just dont specify it)");
                }

                coefficients.erase(i);
            }
        }

    }else{
        if(firstElement()->degree != 0 && firstElement()->value.numerator.isZero()){
            throw BaseException("if you want to get empty Polynomial just use Polynomial()");
        }
    }
}

Polynomial::Polynomial(){}

PolynomialPair* Polynomial::firstElement() {
    return *coefficients.begin();
}
PolynomialPair* Polynomial::lastElement() {
    return *coefficients.rbegin();
}

void Polynomial::addElement(PolynomialPair *element) {
    coefficients.insert(element);
}

// ВНИМАНИЕ! Оно может вернуть nullptr (что может привести к полному *** программы если вы не уследите за этим)
PolynomialPair* Polynomial::get(size_t index) {
    auto t = coefficients.find(new PolynomialPair(index, RationalFraction::empty()));
    if(t == coefficients.end()) return nullptr; // элемент не найден
    return *t;
}

RationalFraction Polynomial::getCoefficient(size_t index){
    auto t = this->get(index);
    if(t == nullptr) return RationalFraction::empty();

    return t->value;
}

void Polynomial::set(size_t index, RationalFraction val) {
    if(index != this->firstElement()->degree && val.numerator.isZero()) {
        this->remove(index);
    }else{
        auto l = this->get(index);
        if (l == nullptr) {
            this->addElement(new PolynomialPair(index, val));
            return;
        }

        l->value = val;
    }
}

void Polynomial::remove(size_t index) {
    auto t = this->get(index);
    if(t == nullptr) return;
    this->coefficients.erase(t);
    if(this->coefficients.empty()){
        this->coefficients.insert(new PolynomialPair(0, RationalFraction::empty()));
    }
}

std::string Polynomial::toString() {
    // todo это временно, потом заменим на DEG_P_N если будет необходимо
    auto j = lastElement()->degree;
    //auto j = module::DEG_P_N(p);

    const auto end = this->coefficients.rend();
    const auto prevEnd = std::prev(end);

	std::string result;
	for(auto i = this->coefficients.rbegin(); i != end; ++i, j = i != end ? (*i)->degree : 0){
		result += (*i)->value.toString();
		if(j != 0) {
            result += "*x^" + std::to_string(j);
        }
		if(i != prevEnd){
		    result += " ";
		}
	}

	return result;
}

void Polynomial::addElement(size_t degree, RationalFraction val) {
    this->addElement(new PolynomialPair(degree, std::move(val)));
}

//todo make tests
Polynomial Polynomial::fromString(std::string val) {
	Polynomial p;
	std::stringstream ss;

	std::istringstream f(val);
	std::string s;

	size_t degree;

	while(std::getline(f, s, ' ')){
		auto endOfCoefficient = s.find('*');
		if(endOfCoefficient == std::string::npos){
			auto coefficient = RationalFraction::fromString(s);
			p.addElement(0, coefficient);
		}else{
			auto coefficientStr = s.substr(0, endOfCoefficient);
			auto coefficient = RationalFraction::fromString(coefficientStr);

			auto startOfDegree = s.find('^')+1;
			auto degreeStr = s.substr(startOfDegree);

			ss << degreeStr;
			ss >> degree;

			p.addElement(degree, coefficient);
		}

		ss.clear();
	}

	return p;
}

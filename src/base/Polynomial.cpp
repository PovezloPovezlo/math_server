#include "Polynomial.h"
#include <module/p.h>
#include <module/n.h>
#include <module/z.h>
#include <utility>

using namespace base;

Polynomial::Polynomial(PolynomialList* coefficients) : coefficients(coefficients) {
    // чистка списка коэффициентов от нулевых (потому что их нет смысла хранить)

    for(auto i = coefficients; i != nullptr; i = i->next){
        if(i->value.numerator.toString() == "0"){ // todo заменить на NZER_N_B
            if(i->prev == nullptr){ // к сожалению я не могу из конструктора вернуть указатель на следующий элемент
                throw BaseException("Coefficient at x^0 must not be zero (or just not specify it)");
            }
            i->prev = i->next; // удаляем элемент i
        }
    }
}

Polynomial::Polynomial(): coefficients(new PolynomialList(ULongNumber::empty(), RationalFraction::empty())){}

std::string Polynomial::toString() const {
	std::string result;
	const auto one = NLongNumber::fromInt(1);
	auto j = module::DEG_P_N(*this);
	for(auto i = coefficients->lastElement(); i != nullptr; i = i->prev, j = module::SUB_NN_N(j, one)){
		result += i->value.toString() + "*x^" + j.toString() + " ";
	}

	return result;
}
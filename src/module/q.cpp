#include "q.h"
#include <base/RationalFraction.h>
#include <base/NotImplementedException.h>
#include <base/BaseException.h>
#include <module/n.h>
#include <module/p.h>
#include <module/z.h>

using namespace base;
using namespace module;

// Рациональные числа (дроби)

/**
 * @authors Басин Илья, Петрова Алиса (правки)
 * Q-1
 * Требуется: ABS_Z_N, GCF_NN_N, DIV_ZZ_Z
 *
 * Сокращение дроби
 * @param a
 * @return
 */
RationalFraction module::RED_Q_Q(RationalFraction& a) {

    auto num_n = ABS_Z_N(a.numerator); //создаём натуральные копии числителя и знаменателя
    auto den_n = ABS_Z_N(a.denominator);

    auto nod = (LongNumber)GCF_NN_N(num_n, den_n);

    a.numerator = DIV_ZZ_Z(a.numerator, nod); //делим числитель и знаменатель на нод
    a.numerator = DIV_ZZ_Z(a.numerator, nod); //делим числитель и знаменатель на нод
    auto den_z = (LongNumber)a.denominator; //копия нужна тк знаменатель NLongNumber
    auto t = DIV_ZZ_Z(den_z, nod);
    a.denominator = NLongNumber::fromLongNumber(t);

    return a;
}

/**
 * @authors Глеб Лях
 * Q-2
 *
 * Проверка на целое
 * @param a
 * @return если рациональное число является целым, то «да», иначе «нет»
 */
bool module::INT_Q_B(base::RationalFraction& a) {
	if(module::MOD_ZZ_Z(a.numerator, a.denominator) == LongNumber::empty()){
		return true;
	}
	else return false;
	
	//throw NotImplementedException();
}

/**
 * @authors Анастасия Аверьянова
 * Q-3
 *
 * Преобразование целого в дробное
 * @param a
 * @return
 */
RationalFraction module::TRANS_Z_Q(LongNumber& a) {
	
	return RationalFraction(a, NLongNumber(1));
	
	//throw NotImplementedException();
}

/**
 * @authors Денис Медведев
 * Q-4
 *
 * Преобразование дробного в целое (если знаменатель равен 1)
 * Комментарий от архитектора: полагаю, что имелось в виду под "если знаменатель равен 1" 
 * уже после выполнения сокращения дробей. А то иначе у нас эта функция не сможет обработать например 6/2
 * @param a
 * @return
 */
LongNumber module::TRANS_Q_Z(RationalFraction& a) {
	
	module::RED_Q_Q(a);
	if (a.denominator == NLongNumber(1)) return a.numerator;
	throw BaseException("Denominator != 1");

	//throw NotImplementedException();
}

/**
 * @authors Береза Кирилл
 * Q-5
 * Требуется: LCM_NN_N, MUL_ZZ_Z, ADD_ZZ_Z
 *
 * Сложение дробей
 * @param a
 * @param b
 * @return
 */
RationalFraction module::ADD_QQ_Q(RationalFraction& a, RationalFraction& b) {
	RationalFraction res = RationalFraction::empty();
	LongNumber res_denom = MUL_ZZ_Z(a.denominator, b.denominator);
	res.denominator = NLongNumber::fromLongNumber(res_denom);

	auto t1 = MUL_ZZ_Z(a.numerator, b.denominator);
	auto t2 = MUL_ZZ_Z(b.numerator, a.denominator);

	LongNumber res_num = ADD_ZZ_Z(t1, t2);
	res.numerator = res_num;
	RED_Q_Q(res);
	return res;
}

/**
 * @authors Береза Кирилл
 * Q-6
 * Требуется: LCM_NN_N, MUL_ZZ_Z, SUB_ZZ_Z
 *
 * Вычитание дробей
 * @param a
 * @param b
 * @return
 */
RationalFraction module::SUB_QQ_Q(RationalFraction& a, RationalFraction& b) {
	RationalFraction res = RationalFraction::empty();
	LongNumber res_denom = MUL_ZZ_Z(a.denominator, b.denominator);
	res.denominator = NLongNumber::fromLongNumber(res_denom);

	auto t1 = MUL_ZZ_Z(a.numerator, b.denominator);
	auto t2 = MUL_ZZ_Z(b.numerator, a.denominator);

	LongNumber res_num = SUB_ZZ_Z(t1, t2);
	res.numerator = res_num;
	RED_Q_Q(res);
	return res;
}

/**
 * @authors Анастасия Аверьянова
 * Q-7
 * Требуется: MUL_ZZ_Z
 *
 * Умножение дробей
 * @param a
 * @param b
 * @return
 */
RationalFraction module::MUL_QQ_Q(RationalFraction& a, RationalFraction& b) {
	auto t = module::MUL_NN_N(a.denominator, b.denominator);
	auto res = RationalFraction(module::MUL_ZZ_Z(a.numerator, b.numerator),
	                           (NLongNumber)module::TRANS_Z_N(t));
	RED_Q_Q(res);
	return res;
	
	//throw NotImplementedException();
}

/**
 * @authors Анастасия Аверьянова
 * Q-8
 * Требуется: MUL_ZZ_Z
 *
 * Деление дробей (делитель отличен от нуля)
 * Комментарий от архитектора: разработчику вручную проверять придется на то, чтобы делитель не равнялся нулю
 * @param a
 * @param b
 * @return
 */
RationalFraction module::DIV_QQ_Q(RationalFraction& a, RationalFraction& b) {
	
	if (b.numerator != LongNumber(0)) {
		if (module::POZ_Z_D(b.numerator) == 1){
			b.numerator = module::MUL_ZM_Z(b.numerator);
		}
		auto additional = (ULongNumber)module::TRANS_Z_N(b.numerator);
		auto t = module::MUL_NN_N(a.denominator, additional);
		auto res = RationalFraction(module::MUL_ZZ_Z(a.numerator, b.denominator),
		                            (NLongNumber)module::TRANS_Z_N(t));
		RED_Q_Q(res);
		return res;
	}

	throw BaseException("Cant divide by zero");
}

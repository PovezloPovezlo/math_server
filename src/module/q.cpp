#include "q.h"
#include <base/RationalFraction.h>
#include <base/NotImplementedException.h>
#include <module/n.h>
#include <module/p.h>
#include <module/z.h>

using namespace base;
using namespace module;

// Рациональные числа (дроби)

/**
 * @authors Имя Фамилия авторов
 * Q-1
 * Требуется: ABS_Z_N, GCF_NN_N, DIV_ZZ_Z
 *
 * Сокращение дроби
 * @param a
 * @return
 */
RationalFraction module::RED_Q_Q(RationalFraction& a) {
	throw NotImplementedException();
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

	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-5
 * Требуется: LCM_NN_N, MUL_ZZ_Z, ADD_ZZ_Z
 *
 * Сложение дробей
 * @param a
 * @param b
 * @return
 */
RationalFraction module::ADD_QQ_Q(RationalFraction& a, RationalFraction& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-6
 * Требуется: LCM_NN_N, MUL_ZZ_Z, SUB_ZZ_Z
 *
 * Вычитание дробей
 * @param a
 * @param b
 * @return
 */
RationalFraction module::SUB_QQ_Q(RationalFraction& a, RationalFraction& b) {
	throw NotImplementedException();
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
	return RationalFraction(module::MUL_ZZ_Z(a.numerator, b.numerator),
		(NLongNumber)module::TRANS_Z_N(t));
	
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
RationalFraction module::DIV_QQ_Q(RationalFraction& a, RationalFraction& b) {\
	
	if (b.numerator != LongNumber(0)) {
		if (module::POZ_Z_D(b.numerator) == '1'){
			b.numerator = module::MUL_ZM_Z(b.numerator);
		}
		auto additional = (ULongNumber)module::TRANS_Z_N(b.numerator);
		auto t = module::MUL_NN_N(a.denominator, additional);
		return RationalFraction(module::MUL_ZZ_Z(a.numerator, b.denominator), 
			(NLongNumber)module::TRANS_Z_N(t));
	}
	
	throw NotImplementedException();
}

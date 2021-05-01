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
base::RationalFraction module::RED_Q_Q(const base::RationalFraction& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-2
 *
 * Проверка на целое
 * @param a
 * @return если рациональное число является целым, то «да», иначе «нет»
 */
bool module::INT_Q_B(const base::RationalFraction& a) {
	if(module::MOD_ZZ_Z(a.numerator, a.denominator) == LongNumber::empty()){
		return true;
	}
	else return false;
	
	//throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-3
 *
 * Преобразование целого в дробное
 * @param a
 * @return
 */
base::RationalFraction module::TRANS_Z_Q(const base::LongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-4
 *
 * Преобразование дробного в целое (если знаменатель равен 1)
 * Комментарий от архитектора: полагаю, что имелось в виду под "если знаменатель равен 1" 
 * уже после выполнения сокращения дробей. А то иначе у нас эта функция не сможет обработать например 6/2
 * @param a
 * @return
 */
base::LongNumber module::TRANS_Q_Z(const base::RationalFraction& a) {
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
base::RationalFraction module::ADD_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b) {
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
base::RationalFraction module::SUB_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-7
 * Требуется: MUL_ZZ_Z
 *
 * Умножение дробей
 * @param a
 * @param b
 * @return
 */
base::RationalFraction module::MUL_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Q-8
 * Требуется: MUL_ZZ_Z
 *
 * Деление дробей (делитель отличен от нуля)
 * Комментарий от архитектора: разработчику вручную проверять придется на то, чтобы делитель не равнялся нулю
 * @param a
 * @param b
 * @return
 */
base::RationalFraction module::DIV_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b) {
	throw NotImplementedException();
}

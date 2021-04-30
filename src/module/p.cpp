#include "p.h"
#include <base/Polynomial.h>
#include <base/NotImplementedException.h>

using namespace base;
using namespace module;

// Многочлен с рациональными коэффициентами

/**
 * @authors Имя Фамилия авторов
 * P-1
 * Требуется: ADD_QQ_Q
 *
 * Сложение многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::ADD_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-2
 * Требуется: SUB_QQ_Q
 *
 * Вычитание многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::SUB_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-3
 * Требуется: MUL_QQ_Q
 *
 * Умножение многочлена на рациональное число
 * @param a
 * @param b
 * @return
 */
Polynomial module::MUL_PQ_P(const Polynomial& a, const RationalFraction& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-4
 *
 * Умножение многочлена на x^k
 * @param a
 * @param k
 * @return
 */
Polynomial module::MUL_Pxk_P(const Polynomial& a, const ULongNumber& k) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-5
 *
 * Старший коэффициент многочлена
 * @param a
 * @return
 */
RationalFraction module::LED_P_Q(const Polynomial& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-6
 *
 * Степень многочлена
 * @param a
 * @return
 */
ULongNumber module::DEG_P_N(const Polynomial& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-7
 * Требуется: ABS_Z_N, TRANS_Z_N, LCM_NN_N, GCF_NN_N, TRANS_N_Z, DIV_ZZ_Z
 *
 * Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
 * @param a
 * @return
 */
RationalFraction module::FAC_P_Q(const Polynomial& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-8
 * Требуется: MUL_PQ_P, MUL_Pxk_P, ADD_PP_P
 *
 * Умножение многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::MUL_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-9
 * Требуется: DIV_QQ_Q, DEG_P_N, MUL_Pxk_P, SUB_PP_P, ADD_PP_P
 *
 * Частное от деления многочлена на многочлен при делении с остатком
 * @param a
 * @param b
 * @return
 */
Polynomial module::DIV_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-10
 * Требуется: DIV_PP_P, MUL_PP_P, SUB_PP_P
 *
 * Остаток от деления многочлена на многочлен при делении с остатком
 * @param a
 * @param b
 * @return
 */
Polynomial module::MOD_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-11
 * Требуется: DEG_P_N, MOD_PP_P
 *
 * НОД многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::GCF_PP_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-12
 *
 * Производная многочлена
 * @param a
 * @param b
 * @return
 */
Polynomial module::DER_P_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * P-13
 * Требуется: GCF_PP_P, DER_P_P, DIV_PP_P
 *
 * Преобразование многочлена — кратные корни в простые
 * @param a
 * @param b
 * @return
 */
Polynomial module::NMR_P_P(const Polynomial& a, const Polynomial& b) {
	throw NotImplementedException();
}

#pragma once

#include <base/Polynomial.h>

namespace module {
	// Многочлен с рациональными коэффициентами

	/**
	 * P-1
	 * Требуется: ADD_QQ_Q
	 *
	 * Сложение многочленов
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial ADD_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-2
	 * Требуется: SUB_QQ_Q
	 *
	 * Вычитание многочленов
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial SUB_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-3
	 * Требуется: MUL_QQ_Q
	 *
	 * Умножение многочлена на рациональное число
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial MUL_PQ_P(base::Polynomial a, base::RationalFraction b);

	/**
	 * P-4
	 *
	 * Умножение многочлена на x^k
	 * @param a
	 * @param k
	 * @return
	 */
	base::Polynomial MUL_Pxk_P(base::Polynomial a, base::ULongNumber k);

	/**
	 * P-5
	 *
	 * Старший коэффициент многочлена
	 * @param a
	 * @return
	 */
	base::RationalFraction LED_P_Q(base::Polynomial a);

	/**
	 * P-6
	 *
	 * Степень многочлена
	 * @param a
	 * @return
	 */
	base::NLongNumber DEG_P_N(base::Polynomial a);

	/**
	 * P-7
	 * Требуется: ABS_Z_N, TRANS_Z_N, LCM_NN_N, GCF_NN_N, TRANS_N_Z, DIV_ZZ_Z
	 *
	 * Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
	 * @param a
	 * @return
	 */
	base::RationalFraction FAC_P_Q(base::Polynomial a);

	/**
	 * P-8
	 * Требуется: MUL_PQ_P, MUL_Pxk_P, ADD_PP_P
	 *
	 * Умножение многочленов
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial MUL_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-9
	 * Требуется: DIV_QQ_Q, DEG_P_N, MUL_Pxk_P, SUB_PP_P, ADD_PP_P
	 *
	 * Частное от деления многочлена на многочлен при делении с остатком
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial DIV_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-10
	 * Требуется: DIV_PP_P, MUL_PP_P, SUB_PP_P
	 *
	 * Остаток от деления многочлена на многочлен при делении с остатком
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial MOD_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-11
	 * Требуется: DEG_P_N, MOD_PP_P
	 *
	 * НОД многочленов
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial GCF_PP_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-12
	 *
	 * Производная многочлена
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial DER_P_P(base::Polynomial a, base::Polynomial b);

	/**
	 * P-13
	 * Требуется: GCF_PP_P, DER_P_P, DIV_PP_P
	 *
	 * Преобразование многочлена — кратные корни в простые
	 * @param a
	 * @param b
	 * @return
	 */
	base::Polynomial NMR_P_P(base::Polynomial a, base::Polynomial b);



}
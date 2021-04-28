#pragma once

#include <base/RationalFraction.h>

namespace module {
	// Рациональные числа (дроби)

	/**
	 * Q-1
	 * Требуется: ABS_Z_N, GCF_NN_N, DIV_ZZ_Z
	 *
	 * Сокращение дроби
	 * @param a
	 * @return
	 */
	base::RationalFraction RED_Q_Q(base::RationalFraction a);

	/**
	 * Q-2
	 *
	 * Проверка на целое
	 * @param a
	 * @return если рациональное число является целым, то «да», иначе «нет»
	 */
	bool INT_Q_B(base::RationalFraction a);

	/**
	 * Q-3
	 *
	 * Преобразование целого в дробное
	 * @param a
	 * @return
	 */
	base::RationalFraction TRANS_Z_Q(base::LongNumber a);

	/**
	 * Q-4
	 *
	 * Преобразование дробного в целое (если знаменатель равен 1)
	 * Комментарий от архитектора: полагаю, что имелось в виду под "если знаменатель равен 1" уже после выполнения сокращения дробей. А то иначе у нас эта функция не сможет обработать например 6/2
	 * @param a
	 * @return
	 */
	base::LongNumber TRANS_Q_Z(base::RationalFraction a);

	/**
	 * Q-5
	 * Требуется: LCM_NN_N, MUL_ZZ_Z, ADD_ZZ_Z
	 *
	 * Сложение дробей
	 * @param a
	 * @param b
	 * @return
	 */
	base::RationalFraction ADD_QQ_Q(base::RationalFraction a, base::RationalFraction b);

	/**
	 * Q-6
	 * Требуется: LCM_NN_N, MUL_ZZ_Z, SUB_ZZ_Z
	 *
	 * Вычитание дробей
	 * @param a
	 * @param b
	 * @return
	 */
	base::RationalFraction SUB_QQ_Q(base::RationalFraction a, base::RationalFraction b);

	/**
	 * Q-7
	 * Требуется: MUL_ZZ_Z
	 *
	 * Умножение дробей
	 * @param a
	 * @param b
	 * @return
	 */
	base::RationalFraction MUL_QQ_Q(base::RationalFraction a, base::RationalFraction b);

	/**
	 * Q-8
	 * Требуется: MUL_ZZ_Z
	 *
	 * Деление дробей (делитель отличен от нуля)
	 * Комментарий от архитектора: разработчику вручную проверять придется на то, чтобы делитель не равнялся нулю
	 * @param a
	 * @param b
	 * @return
	 */
	base::RationalFraction DIV_QQ_Q(base::RationalFraction a, base::RationalFraction b);

}
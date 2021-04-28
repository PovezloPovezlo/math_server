#pragma once

#include <base/LongNumber.h>

namespace module {
	// Целые числа

	/**
	 * Z-1
	 *
	 * Абсолютная величина числа
	 * @param a
	 * @return
	 */
	base::ULongNumber ABS_Z_N(base::LongNumber a);

	/**
	 * Z-2
	 *
	 * Определение положительности числа
	 * @param a
	 * @return 2 - положительное, 0 — равное нулю, 1 - отрицательное
	 */
	DIGIT POZ_Z_D(base::LongNumber a);

	/**
	 * Z-3
	 *
	 * Умножение целого на (-1)
	 * @param a
	 * @return
	 */
	base::LongNumber MUL_ZM_Z(base::LongNumber a);

	/**
	 * Z-4
	 *
	 * Преобразование натурального в целое
	 * @param a
	 * @return
	 */
	base::LongNumber TRANS_N_Z(base::NLongNumber a);

	/**
	 * Z-5
	 *
	 * Преобразование целого неотрицательного в натуральное
	 * @param a
	 * @return
	 */
	base::NLongNumber TRANS_Z_N(base::ULongNumber a);

	/**
	 * Z-6
	 * Требуется: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z
	 *
	 * Сложение целых чисел
	 * @param a
	 * @param b
	 * @return
	 */
	base::LongNumber ADD_ZZ_Z(base::LongNumber a, base::LongNumber b);

	/**
	 * Z-7
	 * Требуется: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z
	 *
	 * Вычитание целых чисел
	 * @param a
	 * @param b
	 * @return
	 */
	base::LongNumber SUB_ZZ_Z(base::LongNumber a, base::LongNumber b);

	/**
	 * Z-8
	 * Требуется: POZ_Z_D, ABS_Z_N, MUL_NN_N, MUL_ZN_Z
	 *
	 * Умножение целых чисел
	 * @param a
	 * @param b
	 * @return
	 */
	base::LongNumber MUL_ZZ_Z(base::LongNumber a, base::LongNumber b);

	/**
	 * Z-9
	 * Требуется: ABS_Z_N, POZ_Z_D, DIV_NN_N, ADD_1N_N
	 *
	 * Частное от деления целого на целое (делитель отличен от нуля)
	 * @param a
	 * @param b
	 * @return
	 */
	base::LongNumber DIV_ZZ_Z(base::LongNumber a, base::LongNumber b);

	/**
	 * Z-10
	 *
	 * Остаток от деления целого на целое(делитель отличен от нуля).
	 * Комментарий от архитектора: обратите внимание на то, что остаток не может быть отрицательным (поэтому возвращаемый тип я задал ULongNumber)
	 * @param a
	 * @param b
	 * @return
	 */
	base::ULongNumber MOD_ZZ_Z(base::LongNumber a, base::LongNumber b);

}
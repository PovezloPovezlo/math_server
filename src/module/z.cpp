#include "z.h"
#include "n.h"
#include <base/RationalFraction.h>
#include <base/NotImplementedException.h>

using namespace base;
using namespace module;

// Целые числа

/**
 * @authors Имя Фамилия авторов
 * Z-1
 *
 * Абсолютная величина числа
 * @param a
 * @return
 */
ULongNumber module::ABS_Z_N(LongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-2
 *
 * Определение положительности числа
 * @param a
 * @return 2 - положительное, 0 — равное нулю, 1 - отрицательное
 */
DIGIT module::POZ_Z_D(LongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-3
 *
 * Умножение целого на (-1)
 * @param a
 * @return
 */
LongNumber module::MUL_ZM_Z(LongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-4
 *
 * Преобразование натурального в целое
 * @param a
 * @return
 */
LongNumber module::TRANS_N_Z(NLongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-5
 *
 * Преобразование целого неотрицательного в натуральное
 * @param a
 * @return
 */
NLongNumber module::TRANS_Z_N(ULongNumber& a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-6
 * Требуется: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z
 *
 * Сложение целых чисел
 * @param a
 * @param b
 * @return
 */
LongNumber module::ADD_ZZ_Z(LongNumber& a, LongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-7
 * Требуется: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z
 *
 * Вычитание целых чисел
 * @param a
 * @param b
 * @return
 */
LongNumber module::SUB_ZZ_Z(LongNumber& a, LongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Лях Глеб
 * Z-8
 * Требуется: POZ_Z_D, ABS_Z_N, MUL_NN_N, MUL_ZN_Z
 *
 * Умножение целых чисел
 * @param a
 * @param b
 * @return
 */
LongNumber module::MUL_ZZ_Z(LongNumber& a, LongNumber& b) {
	bool sign = false;
	if (module::POZ_Z_D(a) == '1') sign = !sign;
	if (module::POZ_Z_D(b) == '1') sign = !sign;
	LongNumber produced = MUL_NN_N(module::ABS_Z_N(a), module::ABS_Z_N(b));
	if(sign)
		produced = module::MUL_ZM_Z(produced); 
	return produced;
	// throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-9
 * Требуется: ABS_Z_N, POZ_Z_D, DIV_NN_N, ADD_1N_N
 *
 * Частное от деления целого на целое (делитель отличен от нуля)
 * @param a
 * @param b
 * @return
 */
LongNumber module::DIV_ZZ_Z(LongNumber& a, LongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * Z-10
 *
 * Остаток от деления целого на целое(делитель отличен от нуля).
 * Комментарий от архитектора: обратите внимание на то, что остаток не может быть отрицательным (поэтому возвращаемый тип я задал ULongNumber)
 * @param a
 * @param b
 * @return
 */
ULongNumber module::MOD_ZZ_Z(LongNumber& a, LongNumber& b) {
	throw NotImplementedException();
}

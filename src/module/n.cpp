#include "n.h"
#include <base/NLongNumber.h>
#include <base/NotImplementedException.h>

using namespace base;
using namespace module;

// Натуральные числа с нулем
// Собственно говоря поэтому в большинстве мест здесь ULongNumber (неотрицательное целое число), а не NLongNumber (натуральное число)


/**
 * @authors Имя Фамилия авторов
 * N-1
 *
 * Сравнение натуральных чисел
 * @param a
 * @param b
 * @return 2 - если первое больше второго, 0, если равно, 1 иначе
 */
DIGIT module::COM_NN_D(ULongNumber &a, ULongNumber &b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-2
 *
 * Проверка на ноль
 * @param a
 * @return если число не равно нулю, то «да» иначе «нет»
 */
bool module::NZER_N_B(ULongNumber &a) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-3
 *
 * Добавление 1 к натуральному числу
 * @param a
 * @return
 */
ULongNumber module::ADD_1N_N(ULongNumber &a) {
	throw NotImplementedException();
}

/**
 * @authors Кушко Даниил
 * N-4
 * Требуется: COM_NN_D
 *
 * Сложение натуральных чисел
 * @param a
 * @param b
 * @return
 */
ULongNumber module::ADD_NN_N(ULongNumber &a, ULongNumber &b) {
	throw NotImplementedException();

	ULongNumber max = ULongNumber::empty();
	ULongNumber min = ULongNumber::empty();
	if (module::COM_NN_D(a, b) == 2) { max = a; min = b; }
	else { max = b; min = a; }

	ULongNumber res = ULongNumber::empty();

	int digit = 0;
	int nextDigitPlus = 0;

	for (int i = 0; i < max.length(); i++) {
		digit = max[i] + min[i];
		res[i] = (digit + nextDigitPlus) % 10;
		if (digit > 9) {
			nextDigitPlus = 1;
		}
		else {
			nextDigitPlus = 0;
		}
	}
	
	if (nextDigitPlus != 0) {
		res[max.length()] = 1;
	}
	return res;

}

/**
 * @authors Кушко Даниил
 * N-5
 * Требуется: COM_NN_D
 *
 * Вычитание из первого большего натурального числа второго меньшего или равного
 * @param a
 * @param b
 * @return разница чисел по модулю
 */
ULongNumber module::SUB_NN_N(ULongNumber &a, ULongNumber &b) {
	throw NotImplementedException();
	ULongNumber max = ULongNumber::empty();
	ULongNumber min = ULongNumber::empty();
	if (module::COM_NN_D(a, b) == 2) { max = a; min = b; }
	else { max = b; min = a; }


	ULongNumber res = ULongNumber::empty();

	for (int i = 0; i < max.length(); i++) {
		if (max[i] > min[i])  res[i] = max[i] - min[i];
		else {
			if (i < max.length() - 1) {
				max[i + 1] -= 1;
				res[i] = (max[i] + 10) - min[i];
			}
		}
	}
	return res;
}

/**
 * @authors Кушко Даниил
 * N-6
 *
 * Умножение натурального числа на цифру
 * @param a
 * @param b
 * @return
 */
ULongNumber module::MUL_ND_N(ULongNumber &a, DIGIT b) {
	throw NotImplementedException();
	ULongNumber res = ULongNumber::empty();

	int additional = 0;

	for (int i = 0; i < a.length(); i++) {
		res[i] = (a[i] * b + additional) % 10;
		additional = (a[i] * b + additional) / 10;
	}
	if (additional != 0) {
		res[a.length()] = additional;
	}

	return res;
}

/**
 * @authors Имя Фамилия авторов
 * N-7
 *
 * Умножение натурального числа на 10^k
 * @param a
 * @param k
 * @return
 */
ULongNumber module::MUL_Nk_N(ULongNumber &a, ULongNumber &k) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-8
 * Требуется: MUL_ND_N, MUL_Nk_N, ADD_NN_N
 *
 * Умножение натуральных чисел
 * @param a
 * @param b
 * @return
 */
ULongNumber module::MUL_NN_N(ULongNumber &a, ULongNumber &b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-9
 * Требуется: SUB_NN_N, MUL_ND_N, COM_NN_D
 *
 * Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом
 * @param a
 * @param k
 * @param b
 * @return
 */
ULongNumber module::SUB_NDN_N(ULongNumber& a, DIGIT k, ULongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-10
 * Требуется: MUL_Nk_N, COM_NN_D
 *
 * Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
 * @param a
 * @param b
 * @return
 */
std::pair<DIGIT, size_t> module::DIV_NN_Dk(NLongNumber& a, NLongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-11
 * Требуется: DIV_NN_Dk, SUB_NDN_N
 *
 * Частное от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)
 * @param a
 * @param b
 * @return
 */
ULongNumber module::DIV_NN_N(NLongNumber& a, NLongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-12
 * Требуется: DIV_NN_N, SUB_NDN_N
 *
 * Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)
 * @param a
 * @param b
 * @return
 */
ULongNumber module::MOD_NN_N(NLongNumber& a, NLongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-13
 * Требуется: MOD_NN_N, COM_NN_D, NZER_N_B
 *
 * НОД натуральных чисел
 * @param a
 * @param b
 * @return
 */
NLongNumber module::GCF_NN_N(NLongNumber& a, NLongNumber& b) {
	throw NotImplementedException();
}

/**
 * @authors Имя Фамилия авторов
 * N-14
 * Требуется: GCF_NN_N, MUL_NN_N
 *
 * НОК натуральных чисел
 * @param a
 * @param b
 * @return
 */
NLongNumber module::LCM_NN_N(NLongNumber& a, NLongNumber& b) {
	throw NotImplementedException();
}
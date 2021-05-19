#include "p.h"
#include "q.h"
#include "z.h"
#include "n.h"
#include <base/Polynomial.h>
#include <base/NotImplementedException.h>
#include <base/LongNumber.h>

using namespace base;
using namespace module;

// Многочлен с рациональными коэффициентами

/**
 * @authors Артюх Алексей
 * P-1
 * Требуется: ADD_QQ_Q
 *
 * Сложение многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::ADD_PP_P(Polynomial& a, Polynomial& b)
{
	Polynomial temp;
	auto coff1 = RationalFraction::empty();
	auto coff2 = RationalFraction::empty();
	auto len = a.lastElement()->degree + 1 >= b.lastElement()->degree + 1 ? a.lastElement()->degree + 1 : b.lastElement()->degree + 1;
	for (auto i = 0; i < len; i++)
	{
		coff1 = a.getCoefficient(i);
		coff2 = b.getCoefficient(i);
		temp.addElement(i, ADD_QQ_Q(coff1, coff2));
	}
	return temp;
}

/**
 * @authors Артюх Алексей
 * P-2
 * Требуется: SUB_QQ_Q
 *
 * Вычитание многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::SUB_PP_P(Polynomial& a, Polynomial& b)
{
	Polynomial temp;
	auto coff1 = RationalFraction::empty();
	auto coff2 = RationalFraction::empty();
	auto len = a.lastElement()->degree + 1 >= b.lastElement()->degree + 1 ? a.lastElement()->degree + 1 : b.lastElement()->degree + 1;
	for (auto i = 0; i < len; i++)
	{
		coff1 = a.getCoefficient(i);
		coff2 = b.getCoefficient(i);
		temp.addElement(i, SUB_QQ_Q(coff1, coff2));
	}
	return temp;
}

/**
 * @authors Денис Медведев
 * P-3
 * Требуется: MUL_QQ_Q
 *
 * Умножение многочлена на рациональное число
 * @param a
 * @param b
 * @return
 */
Polynomial module::MUL_PQ_P(Polynomial& a, RationalFraction& b)
{
	Polynomial temporary;
	if (b.numerator == LongNumber(0))
	{
		temporary.addElement(0, (RationalFraction)0);
		return temporary;
	}
	for (auto i = a.coefficients.begin(); i != a.coefficients.end(); i++)
	{
		auto el = *i;
		RationalFraction newval = module::MUL_QQ_Q(el->value, b);
		newval = module::RED_Q_Q(newval);
		temporary.addElement(el->degree, newval);
	}
	return temporary;
}

/**
 * @authors Денис Медведев
 * P-4
 *
 * Умножение многочлена на x^k
 * @param a
 * @param k
 * @return
 */
Polynomial module::MUL_Pxk_P(Polynomial& a, ULongNumber& k)
{
	Polynomial temporary;
	auto zero = ULongNumber::empty();
	if ((module::COM_NN_D(k, zero)) == 0)
		return a;
	for (auto i = a.coefficients.rbegin(); i != a.coefficients.rend(); i++)
	{
		auto el = *i;
		ULongNumber udeg = ULongNumber::fromInt(el->degree);
		ULongNumber newdeg = module::ADD_NN_N(udeg, k);
		std::string nds = newdeg.toString();
		const char* ndcc = nds.c_str();
		size_t ndn = atoi(ndcc);
		temporary.addElement(ndn, el->value);
	}
	return temporary;
}

/**
 * @authors Анастасия Аверьянова
 * P-5
 *
 * Старший коэффициент многочлена
 * @param a
 * @return
 */
RationalFraction module::LED_P_Q(Polynomial& a)
{

	return a.lastElement()->value;
	//throw NotImplementedException();
}

/**
 * @authors Анастасия Аверьянова
 * P-6
 *
 * Степень многочлена
 * @param a
 * @return
 */
ULongNumber module::DEG_P_N(Polynomial& a)
{
	return (ULongNumber)a.lastElement()->degree;
	//throw NotImplementedException();
}

/**
 * @authors Алиса Петрова
 * P-7
 * Требуется: ABS_Z_N, TRANS_Z_N, LCM_NN_N, GCF_NN_N, TRANS_N_Z, DIV_ZZ_Z
 *
 * Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
 * @param a
 * @return
 */
RationalFraction module::FAC_P_Q(Polynomial& a) {
	auto nod = ULongNumber("1");
	auto nok = NLongNumber("1");

	for (auto i = a.coefficients.rbegin(); i != a.coefficients.rend(); i++) { //найдём нок и нод
		auto el = *i;

		auto num = TRANS_Z_N(el->value.numerator);
		if (i == a.coefficients.rbegin()) nod = num;
		else nod = GCF_NN_N(nod, num);

		auto denom = el->value.denominator;
		auto t = LCM_NN_N(nok, denom);
		nok = NLongNumber::fromLongNumber(t);
	}

	auto tmp = NLongNumber::fromLongNumber(nod);
	auto nod_upgr = TRANS_N_Z(tmp); //числитель целый => нам нужен целый аналог НОД

	for (auto i = a.coefficients.rbegin(); i != a.coefficients.rend(); i++) { //выносим НОД и НОК
		auto el = *i;

		el->value.numerator = DIV_ZZ_Z(el->value.numerator, nod_upgr);
		auto tmp = DIV_NN_N(nok, el->value.denominator);
		el->value.denominator = NLongNumber::fromLongNumber(tmp);
	}

	auto res = RationalFraction(nod_upgr, nok);

	return res;
}

/**
 * @authors Алиса Петрова
 * P-8
 * Требуется: MUL_PQ_P, MUL_Pxk_P, ADD_PP_P
 *
 * Умножение многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::MUL_PP_P(Polynomial& a, Polynomial& b) {
	Polynomial temp;
	Polynomial res;
	res.addElement(0, RationalFraction::empty());
	for (auto i = a.coefficients.begin(); i != a.coefficients.end(); i++) {
		auto el = *i;

		temp = MUL_PQ_P(b, el->value);

		auto degree_new = ULongNumber(el->degree);
		temp = MUL_Pxk_P(temp, degree_new);
		res = ADD_PP_P(res, temp);
	}
	return res;

}

/**
 * @authors Лях Глеб
 * P-9
 * Требуется: DIV_QQ_Q, DEG_P_N, MUL_Pxk_P, SUB_PP_P, ADD_PP_P
 *
 * Частное от деления многочлена на многочлен при делении с остатком
 * @param a
 * @param b
 * @return
 */
Polynomial module::DIV_PP_P(Polynomial& a, Polynomial& b) {

	Polynomial res_polynomial;
	auto deg_a = module::DEG_P_N(a);
	auto deg_b = module::DEG_P_N(b);
	auto comparison = module::COM_NN_D(deg_a, deg_b);
	if (comparison == 1)
	{
		res_polynomial.addElement(0, RationalFraction::empty());
		return res_polynomial;
	}


	while (comparison == 2 || comparison == 0)
	{
		auto deg_diff = a.lastElement()->degree - b.lastElement()->degree;

		auto a_value = a.lastElement()->value;
		auto b_value = b.lastElement()->value;

		auto res_value = DIV_QQ_Q(a_value, b_value);

		res_polynomial.addElement(deg_diff, res_value);

		auto sub = module::SUB_NN_N(deg_a, deg_b);

		auto mul_val = module::MUL_Pxk_P(b, sub);
		mul_val = module::MUL_PQ_P(mul_val, res_value);

		a = module::SUB_PP_P(a, mul_val);
		a.remove(a.lastElement()->degree);
		deg_a = module::DEG_P_N(a);
		comparison = module::COM_NN_D(deg_a, deg_b);
	}

	return res_polynomial;
}

/**
 * @authors Глеб Лях
 * P-10
 * Требуется: DIV_PP_P, MUL_PP_P, SUB_PP_P
 *
 * Остаток от деления многочлена на многочлен при делении с остатком
 * @param a
 * @param b
 * @return
 */
Polynomial module::MOD_PP_P(Polynomial& a, Polynomial& b)
{
	Polynomial res_polynomial;
	auto deg_a = module::DEG_P_N(a);
	auto deg_b = module::DEG_P_N(b);
	auto comparison = module::COM_NN_D(deg_a, deg_b);
	if (comparison == 1)
	{
		res_polynomial.addElement(0, RationalFraction::empty());
		return res_polynomial;
	}

	auto deg_diff = a.lastElement()->degree - b.lastElement()->degree;

	while (comparison == 2 || comparison == 0)
	{
		auto deg_diff = a.lastElement()->degree - b.lastElement()->degree;

		auto a_value = a.lastElement()->value;
		auto b_value = b.lastElement()->value;

		auto res_value = DIV_QQ_Q(a_value, b_value);

		res_polynomial.addElement(deg_diff, res_value);

		auto sub = module::SUB_NN_N(deg_a, deg_b);

		auto mul_val = module::MUL_Pxk_P(b, sub);
		mul_val = module::MUL_PQ_P(mul_val, res_value);

		a = module::SUB_PP_P(a, mul_val);
		a.remove(a.lastElement()->degree);
		deg_a = module::DEG_P_N(a);
		comparison = module::COM_NN_D(deg_a, deg_b);
	}

	return a;
}

/**
 * @authors Анастасия Аверьянова
 * P-11
 * Требуется: DEG_P_N, MOD_PP_P
 *
 * НОД многочленов
 * @param a
 * @param b
 * @return
 */
Polynomial module::GCF_PP_P(Polynomial& a, Polynomial& b)
{

	auto first = a;
	auto second = b;
	auto lhs1 = module::DEG_P_N(a);
	auto rhs1 = module::DEG_P_N(b);
	if (module::COM_NN_D(lhs1, rhs1) == 1)
	{
		first = b;
		second = a;
	}
	auto ost = module::MOD_PP_P(first, second);
	first = second;
	second = ost;
	auto result = ost;
	auto lhs2 = ULongNumber::fromLongNumber(ost.lastElement()->value.numerator);
	auto zero = ULongNumber::empty();
	while (module::COM_NN_D(lhs2, zero) == 0)
	{
		result = ost;
		ost = module::MOD_PP_P(first, second);
		first = second;
		second = ost;
	}
	return result;
	//throw NotImplementedException();
}

/**
 * @authors Лях Глеб
 * P-12
 *
 * Производная многочлена
 * @param a
 * @param b
 * @return
 */
Polynomial module::DER_P_P(Polynomial& a)
{

	Polynomial temporary;

	for (auto i = a.coefficients.rbegin(); i != a.coefficients.rend(); i++)
	{
		auto el = *i;
		if (el->degree != 0)
		{
			auto t = RationalFraction::fromInt(el->degree);
			RationalFraction newval = module::MUL_QQ_Q(t, el->value);

			temporary.addElement(el->degree - 1, newval);
		}
		else
		{
			if (temporary.coefficients.empty())
			{
				temporary.addElement(0, RationalFraction::empty());
			}
		}
	}

	return temporary;
}

/**
 * @authors Глеб Лях
 * P-13
 * Требуется: GCF_PP_P, DER_P_P, DIV_PP_P
 *
 * Преобразование многочлена — кратные корни в простые
 * @param a
 * @param b
 * @return
 */
Polynomial module::NMR_P_P(Polynomial& a)
{

	Polynomial der;
	der = module::DER_P_P(a);
	Polynomial gcf;
	gcf = module::GCF_PP_P(a, der);
	Polynomial res;
	res = module::DIV_PP_P(a, gcf);
	return res;
}

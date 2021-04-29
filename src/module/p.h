#pragma once

#include <base/Polynomial.h>

namespace module {

	base::Polynomial ADD_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial SUB_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial MUL_PQ_P(const base::Polynomial& a, const base::RationalFraction& b);
	base::Polynomial MUL_Pxk_P(const base::Polynomial& a, const base::ULongNumber& k);
	base::RationalFraction LED_P_Q(const base::Polynomial& a);
	base::ULongNumber DEG_P_N(const base::Polynomial& a);
	base::RationalFraction FAC_P_Q(const base::Polynomial& a);
	base::Polynomial MUL_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial DIV_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial MOD_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial GCF_PP_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial DER_P_P(const base::Polynomial& a, const base::Polynomial& b);
	base::Polynomial NMR_P_P(const base::Polynomial& a, const base::Polynomial& b);

}
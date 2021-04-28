#pragma once

#include <base/NLongNumber.h>

namespace module {

	DIGIT COM_NN_D(const base::ULongNumber& a, const base::ULongNumber& b);
	bool NZER_N_B(const base::ULongNumber& a);
	base::ULongNumber ADD_1N_N(const base::ULongNumber& a);
	base::ULongNumber ADD_NN_N(const base::ULongNumber& a, const base::ULongNumber& b);
	base::ULongNumber SUB_NN_N(const base::ULongNumber& a, const base::ULongNumber& b);
	base::ULongNumber MUL_ND_N(const base::ULongNumber& a, DIGIT b);
	base::ULongNumber MUL_Nk_N(const base::ULongNumber& a, const base::ULongNumber& k);
	base::ULongNumber MUL_NN_N(const base::ULongNumber& a, const base::ULongNumber& b);
	base::ULongNumber SUB_NDN_N(const base::ULongNumber& a, DIGIT k, const base::ULongNumber& b);
	std::pair<DIGIT, size_t> DIV_NN_Dk(const base::NLongNumber& a, const base::NLongNumber& b);
	base::ULongNumber DIV_NN_N(const base::NLongNumber& a, const base::NLongNumber& b);
	base::ULongNumber MOD_NN_N(const base::NLongNumber& a, const base::NLongNumber& b);
	base::NLongNumber GCF_NN_N(const base::NLongNumber& a, const base::NLongNumber& b);
	base::NLongNumber LCM_NN_N(const base::NLongNumber& a, const base::NLongNumber& b);

}

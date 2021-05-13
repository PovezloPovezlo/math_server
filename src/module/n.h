#pragma once

#include <base/NLongNumber.h>

namespace module {

	DIGIT COM_NN_D(base::ULongNumber& a, base::ULongNumber& b);
	bool NZER_N_B(base::ULongNumber& a);
	base::ULongNumber ADD_1N_N(base::ULongNumber& a);
	base::ULongNumber ADD_NN_N(base::ULongNumber& a, base::ULongNumber& b);
	base::ULongNumber SUB_NN_N(base::ULongNumber& a, base::ULongNumber& b);
	base::ULongNumber MUL_ND_N(base::ULongNumber& a, DIGIT b);
	base::ULongNumber MUL_Nk_N(base::ULongNumber& a, size_t k);
	base::ULongNumber MUL_NN_N(base::ULongNumber& a, base::ULongNumber& b);
	base::ULongNumber SUB_NDN_N(base::ULongNumber& a, DIGIT k, base::ULongNumber& b);
	std::pair<DIGIT, size_t> DIV_NN_Dk(base::ULongNumber& a, base::ULongNumber& b);
	base::ULongNumber DIV_NN_N(base::NLongNumber& a, base::NLongNumber& b);
	base::ULongNumber MOD_NN_N(base::NLongNumber& a, base::NLongNumber& b);
	base::ULongNumber GCF_NN_N(base::ULongNumber& a, base::ULongNumber& b);
	base::ULongNumber LCM_NN_N(base::NLongNumber& a, base::NLongNumber& b);

}

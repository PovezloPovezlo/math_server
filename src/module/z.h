#pragma once

#include <base/NLongNumber.h>
#include <base/ULongNumber.h>
#include <base/LongNumber.h>

namespace module {

	base::ULongNumber ABS_Z_N(base::LongNumber a);
	DIGIT POZ_Z_D(base::LongNumber& a);
	base::LongNumber MUL_ZM_Z(base::LongNumber& a);
	base::LongNumber TRANS_N_Z(base::NLongNumber& a);
	base::NLongNumber TRANS_Z_N(base::LongNumber& a);
	base::LongNumber ADD_ZZ_Z(base::LongNumber& a, base::LongNumber& b);
	base::LongNumber SUB_ZZ_Z(base::LongNumber& a, base::LongNumber& b);
	base::LongNumber MUL_ZZ_Z(base::LongNumber& a, base::LongNumber& b);
	base::LongNumber DIV_ZZ_Z(base::LongNumber& a, base::LongNumber& b);
	base::ULongNumber MOD_ZZ_Z(base::LongNumber& a, base::LongNumber& b);
}
#pragma once

#include <base/NLongNumber.h>
#include <base/ULongNumber.h>

namespace module {

	base::ULongNumber ABS_Z_N(const base::LongNumber& a);
	DIGIT POZ_Z_D(const base::LongNumber& a);
	base::LongNumber MUL_ZM_Z(const base::LongNumber& a);
	base::LongNumber TRANS_N_Z(const base::LongNumber& a);
	base::NLongNumber TRANS_Z_N(const base::LongNumber& a);
	base::LongNumber ADD_ZZ_Z(const base::LongNumber& a, const base::LongNumber& b);
	base::LongNumber SUB_ZZ_Z(const base::LongNumber& a, const base::LongNumber& b);
	base::LongNumber MUL_ZZ_Z(const base::LongNumber& a, const base::LongNumber& b);
	base::LongNumber DIV_ZZ_Z(const base::LongNumber& a, const base::LongNumber& b);
	base::ULongNumber MOD_ZZ_Z(const base::LongNumber& a, const base::LongNumber& b);

}
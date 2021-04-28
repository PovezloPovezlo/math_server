#pragma once

#include <base/RationalFraction.h>

namespace module {

	base::RationalFraction RED_Q_Q(const base::RationalFraction& a);
	bool INT_Q_B(const base::RationalFraction& a);
	base::RationalFraction TRANS_Z_Q(const base::LongNumber& a);
	base::LongNumber TRANS_Q_Z(const base::RationalFraction& a);
	base::RationalFraction ADD_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b);
	base::RationalFraction SUB_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b);
	base::RationalFraction MUL_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b);
	base::RationalFraction DIV_QQ_Q(const base::RationalFraction& a, const base::RationalFraction& b);

}
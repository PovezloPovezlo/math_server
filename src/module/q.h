#pragma once

#include <base/RationalFraction.h>

namespace module {

	base::RationalFraction RED_Q_Q(base::RationalFraction& a);
	bool INT_Q_B(base::RationalFraction& a);
	base::RationalFraction TRANS_Z_Q(base::LongNumber& a);
	base::LongNumber TRANS_Q_Z(base::RationalFraction& a);
	base::RationalFraction ADD_QQ_Q(base::RationalFraction& a, base::RationalFraction& b);
	base::RationalFraction SUB_QQ_Q(base::RationalFraction& a, base::RationalFraction& b);
	base::RationalFraction MUL_QQ_Q(base::RationalFraction& a, base::RationalFraction& b);
	base::RationalFraction DIV_QQ_Q(base::RationalFraction& a, base::RationalFraction& b);

}
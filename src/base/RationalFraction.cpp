//
// Created by NolikTop on 26.04.2021.
//

#include "RationalFraction.h"

#include <utility>

using namespace base;

RationalFraction::RationalFraction(LongNumber numerator, NLongNumber denominator) : numerator(std::move(numerator)), denominator(std::move(denominator)) {}

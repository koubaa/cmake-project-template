#include "division.hpp"

#define TEST_NO_MAIN
#include "acutest.h"

namespace {
  static void test_divide(const int64_t numerator, const int64_t denominator, const int64_t result, const int64_t remainder) {
    Fraction       f        = Fraction {numerator, denominator};
    DivisionResult expected_result = DivisionResult {result, remainder};
    DivisionResult division_result   = Division(f).divide();
    TEST_CHECK(division_result.division == expected_result.division);
    TEST_CHECK(division_result.remainder == expected_result.remainder);
  }
}

void test_cxx_standard(void) {
  test_divide(5, 2, 2, 1);
  test_divide(9, 3, 3, 0);
  test_divide(17, 19, 0, 17);
  test_divide(933345453464353416L, 978737423423423499L, 0, 933345453464353416);
}

void test_cxx_divide_by_zero(void) {
  Division d = Division(Fraction{1, 0});
  TEST_EXCEPTION(d.divide(), LibException);
}

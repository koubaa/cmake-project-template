#include "division.h"

#define TEST_NO_MAIN
#include "acutest.h"

namespace {
  static void test_divide(const int64_t numerator, const int64_t denominator, const int64_t result, const int64_t remainder) {
    int64_t actual_remainder, actual_result;

    lib_clear_error();
    lib_divide(numerator, denominator, &actual_remainder, &actual_result);
    TEST_CHECK(lib_get_error() == 0);
    TEST_CHECK(remainder == actual_remainder);
    TEST_CHECK(result == actual_result);
  }
}

void test_c_standard(void) {
  test_divide(5, 2, 2, 1);
  test_divide(9, 3, 3, 0);
  test_divide(17, 19, 0, 17);
  test_divide(933345453464353416L, 978737423423423499L, 0, 933345453464353416);
}

void test_c_divide_by_zero(void) {
  lib_clear_error();
  int64_t remainder, result;
  lib_divide(1, 0, &remainder, &result);
  TEST_CHECK(lib_get_error() == 2);
  const char* err = nullptr;
  lib_get_error_details(2, &err);
  TEST_CHECK(strcmp(err, "Division by zero is illegal") == 0);
}

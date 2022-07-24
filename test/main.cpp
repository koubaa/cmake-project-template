#include "src/acutest.h"

extern void test_c_standard(void);
extern void test_c_divide_by_zero(void);
extern void test_cxx_standard(void);
extern void test_cxx_divide_by_zero(void);

TEST_LIST = {
   { "c_standard", test_c_standard },
   { "c_divide_by_zero", test_c_divide_by_zero},
   { "cxx_standard", test_cxx_standard },
   { "cxx_divide_by_zero", test_cxx_divide_by_zero},
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
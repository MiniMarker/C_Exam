#include <check.h>
#include <stdlib.h>

#include "./include/demo.h"

START_TEST(test_sum) {    
    int result = sum(2,3);
    ck_assert_int_eq(result, 5);
} END_TEST  


Suite *test_suite(void) {       
  Suite *s;                      
  TCase *tc_core;                

  s = suite_create("Test_Suite");     
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sum); 
  suite_add_tcase(s, tc_core);                

  return s;
}

int main(void) {

    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

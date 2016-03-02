  1   #undef NDEBUG

  2   #ifndef _minunit_h

  3   #define _minunit_h

  4

  5   #include <stdio.h>

  6   #include <dbg.h>

  7   #include <stdlib.h>

  8

  9   #define mu_suite_start() char *message = NULL

 10

 11   #define mu_assert(test, message) if (!(test)) {\

 12       log_err(message); return message; }

 13   #define mu_run_test(test) debug("\n-----%s", " " #test); \

 14       message = test(); tests_run++; if (message) return message;

 15

 16   #define RUN_TESTS(name) int main(int argc, char *argv[]) {\

 17       argc = 1; \

 18       debug("----- RUNNING: %s", argv[0]);\

 19       printf("----\nRUNNING: %s\n", argv[0]);\

 20       char *result = name();\

 21       if (result != 0) {\

 22           printf("FAILED: %s\n", result);\

 23       }\

 24       else {\

 25           printf("ALL TESTS PASSED\n");\

 26       }\

 27       printf("Tests run: %d\n", tests_run);\

 28       exit(result != 0);\

 29   }

 30

 31   int tests_run;

 32

 33   #endif
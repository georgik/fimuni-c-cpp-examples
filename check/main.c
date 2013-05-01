#include <stdlib.h>

/* Check testing framework - http://check.sourceforge.net/ */
#include <check.h>

/**
 * Application logic for employee.
 */

typedef struct Person {
     char * name;
     char * surname;
     int age;
} Person;

void increment_age(Person *person) {
    person->age++;
    // Uncomment following line to create bug
    // person->age++;
}

void rename_person(Person *person, char *new_name) {
    person->name = new_name;
}

/**
 * Unit testing stuff - This is just example. In real test case
 * put this to separate file.
 */
Person *employee;

/**
 * Test fixture - setup method - initialize employee
 */
void setup() {
    employee = malloc(sizeof(Person));
    employee->name = "Arnost";
    employee->surname = "Topinka";
    employee->age = 42;
}

/**
 * Clean up after testing. Release memory.
 */
void teardown() {
    free(employee);
}

START_TEST (test_age) {	
    setup();
    increment_age(employee);
    fail_unless(employee->age == 43, "Incorrect age.");
    teardown();
}
END_TEST

START_TEST (test_name) {
    setup();
    rename_person(employee, "Franta");
    fail_unless( !strcmp( employee->name, "Franta"), "Employee should be renamed.");
    teardown();   
}
END_TEST

/**
 * Create test suite.
 */
Suite *make_suite() {
    Suite *suite;
    TCase *test_case;
    suite = suite_create("Employee testing");
    test_case = tcase_create("Core tests");
    tcase_add_test(test_case, test_age);
    tcase_add_test(test_case, test_age);
    tcase_add_test(test_case, test_name);
    tcase_add_test(test_case, test_name);
    tcase_add_test(test_case, test_name);
    tcase_add_test(test_case, test_age);
    tcase_add_test(test_case, test_name);
    suite_add_tcase(suite, test_case); 
    return suite;
}

int main() {
    int number_failed;
    Suite *suite = make_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all (suite_runner, CK_NORMAL);
    number_failed = srunner_ntests_failed (suite_runner);
    srunner_free (suite_runner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

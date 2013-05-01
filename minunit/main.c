#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "parsing.h"

int tests_run = 0;

static char * test_convert() {
    Person* person = malloc(sizeof(Person));
    char name[] = "Jan";
    char surname[] = "Novak";
    person->name = name;
    person->surname = surname;
    person->age = 45;
    convert(person);
    mu_assert("age should be increased to 46",(46==person->age));
    mu_assert("name should be uppercase",!strcmp(person->name,"JAN"));
    mu_assert("surname should be uppercase",!strcmp(person->surname,"NOVAK"));
    free(person);
    return 0;
}

static char * test_name() {
    Person* person = malloc(sizeof(Person));
    person->name = "";
    person->surname = "Topinka";
    mu_assert("name should be empty", !strcmp(person->name, ""));
    mu_assert("surname should be Topinka", !strcmp(person->surname, "Topinka"));
    free(person);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_convert);
    mu_run_test(test_name);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("THERE ARE TEST FAILURES:\n");
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;

}

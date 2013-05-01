#include <string.h>
#include<ctype.h>

/**
 * Structure to store info about person.
 * name - pointer to name string
 * surname - pointer to surname string
 * age - age
 */
typedef struct Person {
     char * name;
     char * surname;
     int age;
} Person;

/**
 * Converts person, e.g name and surname transforms to uppercase
 * and age increases by one.
 * @param person person to convert
 */
void convert(Person * person);


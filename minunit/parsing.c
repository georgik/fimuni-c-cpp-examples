#include "parsing.h"

void convert(Person * person) {
   unsigned int i;
   for (i=0; i<strlen(person->name); i ++) {
       person->name[i] = toupper(person->name[i]);
   }
   for (i=0; i<strlen(person->surname); i ++) {
       person->surname[i] = toupper(person->surname[i]);
   }
   person->age ++;
}

#include "shell.h"

char* _getenv(char* name) {
    char** env;

    for (env = environ; *env != NULL; env++) {
        char* variable = *env;
        if (_strncmp(variable, name, _strlen(name)) == 0 && variable[strlen(name)] == '=') {
            /* Found the variable, return the value */
            return variable + _strlen(name) + 1;
        }
    }

/*     Variable not found   */    
    return NULL;
}

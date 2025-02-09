#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int main(int argc, char *argv[]) {
    toml_table_t* conf = config_load("config.toml");
    if (conf == NULL) {
        return 1;
    }
    toml_table_t* theme = toml_table_in(conf, "theme");
    if (!theme) {
        fprintf(stderr, "missing [theme]\n");
        return 1;
    }
    toml_datum_t font = toml_string_in(theme, "font");
    if (!font.ok) {
        fprintf(stderr, "cannot read theme.font\n");
        return 1;
    }
    printf("theme.font: %s\n", font.u.s);

    return 0;
}

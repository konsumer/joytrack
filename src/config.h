#include <toml.h>

static char errbuf[200];

// load any config file
toml_table_t* config_load_file(char* filename) {
    errbuf[0] = 0;
    FILE* fp;
    fp = fopen(filename, "r");
    if (!fp) {
        strcpy(errbuf, "Could not open file.");
        return NULL;
    }
    toml_table_t* conf = toml_parse_file(fp, errbuf, sizeof(errbuf));
    fclose(fp);
    if (!conf) {
        return NULL;
    }
    return conf;
}

// load default config and override with user-config
toml_table_t* config_load(char* filename) {
    toml_table_t* confDefault = config_load_file("config_default.toml");
    if (confDefault == NULL) {
        if (errbuf[0] != 0) {
            fprintf(stderr, "ERROR: config_default.toml: %s\n", errbuf);

        } else {
            fprintf(stderr, "ERROR: config_default.toml\n");
        }
        return NULL;
    }
    toml_table_t* conf = config_load_file(filename);
    if (conf == NULL) {
        return confDefault;
    }
    return conf;
}

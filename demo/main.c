#include <stdio.h>

#include "conix.h"

void print_default(void* data) {
    puts("Default information!");
}

void print_about(void* data) {
    puts("Some information!");
}

void print_version(void* data) {
    puts("Other version!");
}

ConixApp app = { "test", "0.0.0" };

int main(int argc, const char** argv) {
    Conix* cli = conix_create(app, argc, argv);
    conix_add_options(cli, 3, (ConixOption[]) {
        { "--default", "Display default information", conix_handler_create(print_default, NULL) },
        { "-a, --about", "Display some information", conix_handler_create(print_about, NULL) },
        { "-v, --version", "Display other version", conix_handler_create(print_version, NULL) }
    });
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

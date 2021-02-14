#include <stdio.h>

#include "conix.h"

void print_default(void* data) {
    puts("Default information!");
}

void print_about(void* data) {
    puts("Some information!");
}

ConixApp app = { "test", "0.0.0" };

int main(int argc, const char** argv) {
    Conix* cli = conix_create(app, argc, argv);
    conix_add_options(cli, 2, (ConixOption[]) {
        { "-a, --about", "Display some information", conix_handler_create(print_about, NULL) },
        { "--default", "Display default information", conix_handler_create(print_default, NULL) }
    });
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

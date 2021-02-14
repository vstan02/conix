#include <stdio.h>

#include "conix.h"

void print_about(void* data) {
    puts("Some information!");
}

ConixApp app = { "test", "0.0.0" };

int main(int argc, const char** argv) {
    Conix* cli = conix_create(app, argc, argv);
    conix_add_option(cli, (ConixOption) {
        .name = "-a, --about",
        .description = "Display something",
        .handler = conix_handler_create(print_about, NULL)
    });
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

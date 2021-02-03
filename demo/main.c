#include <stdio.h>

#include "conix.h"

void print_version(void* payload) {
    puts("demo v1.0.0");
}

int main(int argc, const char** argv) {
    Conix* cli = conix_create(argc, argv);

    conix_add_option(cli, (ConixOption) {
        .name = "-v, --version",
        .description = "Display app version",
        .handler = print_version
    });

    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

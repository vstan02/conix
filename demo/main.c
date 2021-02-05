#include <stdio.h>

#include "conix.h"

#define OPTION_COUNT 2

void print_version(char* version) {
    printf("demo v%s\n", version);
}

void print_about(void* data) {
    puts("What do you want to know about me?");
}

int main(int argc, const char** argv) {
    Conix* cli = conix_create("test", argc, argv);
    conix_add_options(cli, OPTION_COUNT, (ConixOption[]) {
        { "-v, --version", "Display something", conix_handler_create(print_version, "0.1.0") },
        { "-a, --about", "Display something", conix_handler_create(print_about, NULL) },
    });
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

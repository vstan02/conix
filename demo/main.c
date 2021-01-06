#include <conix.h>
#include <stdio.h>

void print_version(void) {
    printf("demo 1.0.0");
}

int main(int argc, const char** argv) {
    Conix* cli = conix_create(argc, argv);

    conix_add_option(cli, "-v, --version", print_version);

    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

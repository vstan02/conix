#include <stdio.h>

#include "conix.h"

#define OPTION_COUNT 3

void print_version(void* data) {
    puts("demo v1.0.0");
}

void print_about(void* data) {
    puts("What do you want to know about me?");
}

void print_help(void* data) {
    puts("I will help you!");
}

ConixOption options[OPTION_COUNT] = {
    { "-v, --version", "Display something", print_version },
    { "-a, --about", "Display something", print_about },
    { "-h, --help", "Display something", print_help }
};

int main(int argc, const char** argv) {
    Conix* cli = conix_create(argc, argv);
    conix_add_options(cli, OPTION_COUNT, options);
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

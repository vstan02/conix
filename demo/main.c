#include <conix.h>

int main(int argc, const char** argv) {
    Conix* cli = conix_create(argc, argv);
    conix_run(cli);
    conix_destroy(cli);
    return 0;
}

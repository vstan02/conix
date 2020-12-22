#include <conix.h>

int main() {
    Conix* cli = conix_create("Test");
    conix_destroy(cli);
    return 0;
}

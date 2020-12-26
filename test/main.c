#include <glib.h>

#include "test.h"

int main(int argc, char** argv) {
    g_test_init(&argc, &argv);
    test_list();
    return g_test_run();
}

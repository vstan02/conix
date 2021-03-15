#include "conix.h"

#define NAME "my_app"
#define VERSION "0.1.0"

int main(int argc, const char** argv) {
    CnxCli* cli = cnx_cli_init(NAME, VERSION);
    cnx_cli_run(cli, argc, argv);
    cnx_cli_free(cli);
    return 0;
}

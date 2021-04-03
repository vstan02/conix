#include <stdio.h>
#include <conix.h>

#define NAME "my_app"
#define VERSION "0.1.0"

CnxApp app = { NAME, VERSION };

void not_found(void* data) {
    printf("Invalid option!");
}

int main(int argc, const char** argv) {
    CnxCli* cli = cnx_cli_init(app);

    cnx_cli_add(cli, 1, (CnxOption[]) {
        { "*", NULL, not_found, NULL }
    });

    cnx_cli_run(cli, argc, argv);
    cnx_cli_free(cli);
    return 0;
}

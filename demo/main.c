#include <stdio.h>
#include <conix.h>

CnxApp app = { "my_app", "3.1.1" };

void index_option(void* payload) {
    printf("Welcome to %s!\n", (char*)payload);
}

void about_option(void* payload) {
    printf("%s is a simple app created with conix!\n", (char*)payload);
}

void not_found_option(void* payload) {
    printf("%s: Invalid option!\n", (char*)payload);
}

int main(int argc, const char** argv) {
    CnxCli* cli = cnx_cli_init(app);

    cnx_cli_add(cli, 3, (CnxOption[]) {
        { "--default", "Default option", index_option, (void*)app.name },
        { "-a, --about", "Display something", about_option, (void*)app.name },
        { "*", NULL, not_found_option, (void*)app.name }
    });

    cnx_cli_run(cli, argc, argv);
    cnx_cli_free(cli);
    return 0;
}

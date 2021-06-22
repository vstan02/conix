#include <stdio.h>
#include <conix.h>

void index_option(cnx_app_t* app, void* payload) {
    printf("Welcome to %s!\n", app->name);
}

void about_option(cnx_app_t* app, void* payload) {
    printf("%s is a simple app created with conix!\n", app->name);
}

void version_option(cnx_app_t* app, void* payload) {
    printf("%s -> %s\n", app->name, app->version);
}

void not_found_option(cnx_app_t* app, void* payload) {
    printf("%s: Invalid option!\n", app->name);
}

int main(int argc, const char** argv) {
    // Creating an new cli instance:
    cnx_cli_t* cli = cnx_cli_init((cnx_app_t) { "my_app", "2.8.1" });

    // Adding some options for handling:
    cnx_cli_add(cli, 4, (cnx_option_t[]) {
        // CnxOption -> { name, description, handler, payload }.
        { "-a, --about", "Display something", about_option, NULL },

        // Handlers for "-v, --version" and "-h, --help" are added
        // by default, but you can add your own handlers for them.
        { "-v, --version", "Display version", version_option, NULL },

        // Handler for "--default" is called when are no arguments passed
        { "--default", "Default option", index_option, NULL },

        // Handler for "*" is called when is passed an unknown cli option.
        // By default it has the same handler as the "-h, --help" option.
        { "*", NULL, not_found_option, NULL }
    });

    // Running for some command line arguments:
    cnx_cli_run(cli, argc, argv);

    // Destroying the instance:
    cnx_cli_free(cli);
    return 0;
}

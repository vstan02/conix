#include <stdio.h>
#include <conix.h>

void index_option(void* payload) {
    printf("Welcome to %s!\n", (char*)payload);
}

void about_option(void* payload) {
    printf("%s is a simple app created with conix!\n", (char*)payload);
}

void version_option(void* payload) {
    cnx_app_t* app = (cnx_app_t*)payload;
    printf("%s -> %s\n", app->name, app->version);
}

void not_found_option(void* payload) {
    printf("%s: Invalid option!\n", (char*)payload);
}

int main(int argc, const char** argv) {
    // Creating an new cli instance:
    cnx_app_t app = { "my_app", "2.8.1" };
    cnx_cli_t* cli = cnx_cli_init(app);

    // Adding some options for handling:
    cnx_cli_add(cli, 4, (cnx_option_t[]) {
        // CnxOption -> { name, description, handler, payload }.
        { "-a, --about", "Display something", about_option, (void*)app.name },

        // Handlers for "-v, --version" and "-h, --help" are added
        // by default, but you can add your own handlers for them.
        { "-v, --version", "Display version", version_option, &app },

        // Handler for "--default" is called when are no arguments passed
        { "--default", "Default option", index_option, (void*)app.name },

        // Handler for "*" is called when is passed an unknown cli option.
        // By default it has the same handler as the "-h, --help" option.
        { "*", NULL, not_found_option, (void*)app.name }
    });

    // Running for some command line arguments:
    cnx_cli_run(cli, argc, argv);

    // Destroying the instance:
    cnx_cli_free(cli);
    return 0;
}

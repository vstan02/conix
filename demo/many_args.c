/* Handling of many command line arguments
 * Usage examples:
 * $ ./demo -p -v
 * $ ./demo -v
 * $ ./demo -v -a -h
 * $ ./demo --help -a
 */

#include <stdio.h>
#include <conix.h>

extern int main(int argc, const char** argv) {
	// Creating an new cli instance:
	cnx_cli_t* cli = cnx_cli_init((cnx_app_t) { "my_app", "2.8.1" });

	// Adding some options for handling:
	cnx_cli_add(cli, 5, (cnx_option_t[]) {
		// CnxOption -> { name, description, handler, payload }.
		{ "-a, --about", "Display something", about_option, NULL },
		{ "-p, --print", "Display passed arguments", print_args_option, NULL },

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
	for (size_t i = 0; i < argc - 1; ++i) {
		cnx_cli_run(cli, argc - i, argv + i);
	}

	// Destroying the instance:
	cnx_cli_free(cli);
	return 0;
}

static void index_option(cnx_ctx_t* ctx, void* payload) {
	printf("Welcome to %s!\n", ctx->app.name);
}

static void about_option(cnx_ctx_t* ctx, void* payload) {
	printf("%s is a simple app created with conix!\n", ctx->app.name);
}

static void version_option(cnx_ctx_t* ctx, void* payload) {
	printf("%s -> %s\n", ctx->app.name, ctx->app.version);
}

static void print_args_option(cnx_ctx_t* ctx, void* payload) {
	printf("Total arguments: %zu\n", ctx->argc - 1);
	for (size_t i = 1; i < ctx->argc; ++i) {
		printf("%zu -> %s\n", i, ctx->argv[i]);
	}
}

static void not_found_option(cnx_ctx_t* ctx, void* payload) {
	printf("%s: Invalid option!\n", ctx->app.name);
}

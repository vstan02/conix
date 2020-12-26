#include <glib.h>

#include "test.h"
#include "list.h"

#define VALUE(object) ((Int*) (object))->value

typedef struct {
    int value;
} Int;

static Int* create_int(int value) {
    Int* data = malloc(sizeof(Int));
    data->value = value;
    return data;
}

static void test_list_list(void);
static void test_list_get(void);
static void test_list_get_size(void);
static void test_list_is_empty(void);
static void test_list_exists(void);
static void test_list_push(void);

void test_list(void) {
    g_test_add_func(TEST_LIST_PATH "/list", test_list_list);
    g_test_add_func(TEST_LIST_PATH "/get", test_list_get);
    g_test_add_func(TEST_LIST_PATH "/get_size", test_list_get_size);
    g_test_add_func(TEST_LIST_PATH "/is_empty", test_list_is_empty);
    g_test_add_func(TEST_LIST_PATH "/exists", test_list_exists);
    g_test_add_func(TEST_LIST_PATH "/push", test_list_push);
}

static void test_list_list(void) {
    List* list = list_create();
    g_assert_nonnull(list);
    list_destroy(list);
}

static void test_list_is_empty(void) {
    List* list = list_create();
    g_assert_true(list_is_empty(list));
    list_destroy(list);
}

static void test_list_get_size(void) {
    List* list = list_create();
    g_assert_cmpint((uint8_t) list_get_size(list), ==, 0);
    list_destroy(list);
}

static void test_list_exists(void) {
    List* list = list_create();
    g_assert_false(list_exists(list));
    list_destroy(list);
}

static void test_list_push(void) {
    List* list = list_create();
    list_push(list, create_int(3));
    list_push(list, create_int(2));
    list_push(list, create_int(8));

    g_assert_true(list_exists(list));
    g_assert_cmpint((uint8_t) list_get_size(list), ==, 3);
    list_destroy(list);
}

static void test_list_get(void) {
    List* list = list_create();
    list_push(list, create_int(3));
    list_push(list, create_int(2));
    list_push(list, create_int(8));

    list_to_first(list);
    g_assert_cmpint(VALUE(list_get(list)), ==, 8);
    list_to_next(list);
    g_assert_cmpint(VALUE(list_get(list)), ==, 2);
    list_to_next(list);
    g_assert_cmpint(VALUE(list_get(list)), ==, 3);
    list_destroy(list);
}

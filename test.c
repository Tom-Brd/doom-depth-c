#include "src/storage/json/json.h"
#include "src/utils/array_test.h"

int tests_run = 0;

int main(int argc, char **argv) {
    int json = json_test();
    int array = array_test();
    return json && array;
}

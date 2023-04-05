#include "../Util/rheader.cpp"

namespace sorttest {
    #include "sort-test.cpp"
}
namespace darraytest {
    #include "darray-test.cpp"
}

int main() {
    printf("------------------- DYNAMIC ARRAY TEST ------------------\n");
    darraytest::darray_test();
    printf("\n");
    printf("----------------------- SORT TEST -----------------------\n");
    sorttest::sort_test();
    printf("---------------------------------------------------------\n");
    return 0;
}
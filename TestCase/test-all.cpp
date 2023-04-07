#include "../Util/rheader.cpp"

namespace darraytest {
    #include "darray-test.cpp"
}
namespace heaptest {
    #include "heap-test.cpp"
}
namespace sorttest {
    #include "sort-test.cpp"
}

int main() {
    printf("------------------- DYNAMIC ARRAY TEST ------------------\n");
    darraytest::darray_test();
    printf("\n");
    printf("----------------------- HEAP TEST -----------------------\n");
    heaptest::heap_test();
    printf("\n");
    printf("----------------------- SORT TEST -----------------------\n");
    sorttest::sort_test();
    printf("---------------------------------------------------------\n");
    return 0;
}
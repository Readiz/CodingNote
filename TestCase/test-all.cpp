#ifndef INCLUDED_ALL
    #define INCLUDED_ALL
    #include <bits/stdc++.h>
    #include "../Util/rand.cpp"
#endif
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
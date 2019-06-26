#include "Tests.h"

int main()
{
    TestRunner tr;
    RUN_TEST(tr, ExceptionHandlingTest);
    RUN_TEST(tr, InitializationTest);
    RUN_TEST(tr, IteratingTest);
    RUN_TEST(tr, DictionaryGetSetTests);
    return 0;
}

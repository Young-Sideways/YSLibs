#include "test.h"

#include "debug.h"

int main(int argc, char** argv) {
    explain_assert(1, "+int failed");
    explain_assert(-1, "-int failed");
    explain_assert(100000.f, "float failed");
    explain_assert(.000001f, "float failed");
    explain_assert(INFINITY, "float failed");
    explain_assert(NAN, "float failed");
    explain_assert(HUGE_VALF, "float failed");
    explain_assert(HUGE_VAL, "double failed");
    explain_assert(HUGE_VALL, "long double failed");
    explain_assert("text", "text failed");
    explain_assert(true, "bool failed");

    return EXIT_SUCCESS;
}
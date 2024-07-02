#include <stdio.h>

static void m_inc_printer__(int count) {
    FILE* file = fopen("inc.h", "w");
    if (file) {
        fprintf(file,"#include \"macro/macro.h\"\n\n");
        for (int i = 0; i < count - 1; i++)
            fprintf(file, "#define M_INC_%d %d\n", i, i + 1);
        fprintf(file, "\n#define M_INC(i) M_CONCAT(M_INC_, i)\n");
        fclose(file);
    }
}
static void m_dec_printer__(int count) {
    FILE* file = fopen("dec.h", "w");
    if (file) {
        fprintf(file,"#include \"macro/macro.h\"\n\n");
        fprintf(file, "#define M_DEC_0 0\n");
        for (int i = 1; i < count; i++)
            fprintf(file, "#define M_DEC_%d %d\n", i, i - 1);
        fprintf(file, "\n#define M_DEC(i) M_CONCAT(M_DEC_, i)\n");
        fclose(file);
    }
}
/*******************************************************************************
 *  @file      sequence.h
 *  @brief     MACRO extension lib, that translates arguments to sequence
 *  @author    Young Sideways
 *  @date      2.04.2024
 *  @copyright � young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _M_SEQUENCE_H_
#define _M_SEQUENCE_H_

#pragma once

#pragma region --- MACRO GENERATOR ---
#ifdef _SEQ_PRINTERS

#include <math.h>
#include <string.h>
 // ARG_REVERSE
void _va_seq_semi_printer(int n) {
    printf("#define M_SEQ_SEMI_0()\n");
    printf("#define M_SEQ_SEMI_1(_1) _1;\n");
    printf("#define M_SEQ_SEMI_2(_1, _2) _1; _2;\n");
    for (int i = 3; i < n; ++i)
        printf("#define M_SEQ_SEMI_%d(_1, ...) _1; M_SEQ_UNFOLD_%d(__VA_ARGS__)\n", i, i - 1);

    printf("#define M_SEQ_UNFOLD_0()\n");
    printf("#define M_SEQ_UNFOLD_1(_1) _1\n");
    printf("#define M_SEQ_UNFOLD_2(_1, _2) _1 _2\n");
    for (int i = 3; i < n; ++i)
        printf("#define M_SEQ_UNFOLD_%d(_1, ...) _1 M_SEQ_UNFOLD_%d(__VA_ARGS__)\n", i, i - 1);

    printf(
        "\n#ifdef _VARIADIC_H_\n\n"
        "#define VA_SEQ_SEMI(...) M_CONCAT_LATER(M_SEQ_SEMI_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n"
        "#define VA_SEQ_UNFOLD(...) M_CONCAT_LATER(M_SEQ_UNFOLD_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n\n"
        "#endif // !_VARIADIC_H_\n\n"
        "#define VA_SEQ_COMMA(...) __VA_ARGS__\n"
    );
}

#endif // !_SEQ_PRINTERS
#pragma endregion

#pragma region --- INCLUDE ---

#include "macro.h"
#include "variadic.h"

#pragma endregion

#pragma region --- MACRO ---

// @printer_settings : _va_seq_semi_printer(256)
#define M_SEQ_SEMI_0()
#define M_SEQ_SEMI_1(_1) _1;
#define M_SEQ_SEMI_2(_1, _2) _1; _2;
#define M_SEQ_SEMI_3(_1, ...) _1; M_SEQ_SEMI_2(__VA_ARGS__)
#define M_SEQ_SEMI_4(_1, ...) _1; M_SEQ_SEMI_3(__VA_ARGS__)
#define M_SEQ_SEMI_5(_1, ...) _1; M_SEQ_SEMI_4(__VA_ARGS__)
#define M_SEQ_SEMI_6(_1, ...) _1; M_SEQ_SEMI_5(__VA_ARGS__)
#define M_SEQ_SEMI_7(_1, ...) _1; M_SEQ_SEMI_6(__VA_ARGS__)
#define M_SEQ_SEMI_8(_1, ...) _1; M_SEQ_SEMI_7(__VA_ARGS__)
#define M_SEQ_SEMI_9(_1, ...) _1; M_SEQ_SEMI_8(__VA_ARGS__)
#define M_SEQ_SEMI_10(_1, ...) _1; M_SEQ_SEMI_9(__VA_ARGS__)
#define M_SEQ_SEMI_11(_1, ...) _1; M_SEQ_SEMI_10(__VA_ARGS__)
#define M_SEQ_SEMI_12(_1, ...) _1; M_SEQ_SEMI_11(__VA_ARGS__)
#define M_SEQ_SEMI_13(_1, ...) _1; M_SEQ_SEMI_12(__VA_ARGS__)
#define M_SEQ_SEMI_14(_1, ...) _1; M_SEQ_SEMI_13(__VA_ARGS__)
#define M_SEQ_SEMI_15(_1, ...) _1; M_SEQ_SEMI_14(__VA_ARGS__)
#define M_SEQ_SEMI_16(_1, ...) _1; M_SEQ_SEMI_15(__VA_ARGS__)
#define M_SEQ_SEMI_17(_1, ...) _1; M_SEQ_SEMI_16(__VA_ARGS__)
#define M_SEQ_SEMI_18(_1, ...) _1; M_SEQ_SEMI_17(__VA_ARGS__)
#define M_SEQ_SEMI_19(_1, ...) _1; M_SEQ_SEMI_18(__VA_ARGS__)
#define M_SEQ_SEMI_20(_1, ...) _1; M_SEQ_SEMI_19(__VA_ARGS__)
#define M_SEQ_SEMI_21(_1, ...) _1; M_SEQ_SEMI_20(__VA_ARGS__)
#define M_SEQ_SEMI_22(_1, ...) _1; M_SEQ_SEMI_21(__VA_ARGS__)
#define M_SEQ_SEMI_23(_1, ...) _1; M_SEQ_SEMI_22(__VA_ARGS__)
#define M_SEQ_SEMI_24(_1, ...) _1; M_SEQ_SEMI_23(__VA_ARGS__)
#define M_SEQ_SEMI_25(_1, ...) _1; M_SEQ_SEMI_24(__VA_ARGS__)
#define M_SEQ_SEMI_26(_1, ...) _1; M_SEQ_SEMI_25(__VA_ARGS__)
#define M_SEQ_SEMI_27(_1, ...) _1; M_SEQ_SEMI_26(__VA_ARGS__)
#define M_SEQ_SEMI_28(_1, ...) _1; M_SEQ_SEMI_27(__VA_ARGS__)
#define M_SEQ_SEMI_29(_1, ...) _1; M_SEQ_SEMI_28(__VA_ARGS__)
#define M_SEQ_SEMI_30(_1, ...) _1; M_SEQ_SEMI_29(__VA_ARGS__)
#define M_SEQ_SEMI_31(_1, ...) _1; M_SEQ_SEMI_30(__VA_ARGS__)
#define M_SEQ_SEMI_32(_1, ...) _1; M_SEQ_SEMI_31(__VA_ARGS__)
#define M_SEQ_SEMI_33(_1, ...) _1; M_SEQ_SEMI_32(__VA_ARGS__)
#define M_SEQ_SEMI_34(_1, ...) _1; M_SEQ_SEMI_33(__VA_ARGS__)
#define M_SEQ_SEMI_35(_1, ...) _1; M_SEQ_SEMI_34(__VA_ARGS__)
#define M_SEQ_SEMI_36(_1, ...) _1; M_SEQ_SEMI_35(__VA_ARGS__)
#define M_SEQ_SEMI_37(_1, ...) _1; M_SEQ_SEMI_36(__VA_ARGS__)
#define M_SEQ_SEMI_38(_1, ...) _1; M_SEQ_SEMI_37(__VA_ARGS__)
#define M_SEQ_SEMI_39(_1, ...) _1; M_SEQ_SEMI_38(__VA_ARGS__)
#define M_SEQ_SEMI_40(_1, ...) _1; M_SEQ_SEMI_39(__VA_ARGS__)
#define M_SEQ_SEMI_41(_1, ...) _1; M_SEQ_SEMI_40(__VA_ARGS__)
#define M_SEQ_SEMI_42(_1, ...) _1; M_SEQ_SEMI_41(__VA_ARGS__)
#define M_SEQ_SEMI_43(_1, ...) _1; M_SEQ_SEMI_42(__VA_ARGS__)
#define M_SEQ_SEMI_44(_1, ...) _1; M_SEQ_SEMI_43(__VA_ARGS__)
#define M_SEQ_SEMI_45(_1, ...) _1; M_SEQ_SEMI_44(__VA_ARGS__)
#define M_SEQ_SEMI_46(_1, ...) _1; M_SEQ_SEMI_45(__VA_ARGS__)
#define M_SEQ_SEMI_47(_1, ...) _1; M_SEQ_SEMI_46(__VA_ARGS__)
#define M_SEQ_SEMI_48(_1, ...) _1; M_SEQ_SEMI_47(__VA_ARGS__)
#define M_SEQ_SEMI_49(_1, ...) _1; M_SEQ_SEMI_48(__VA_ARGS__)
#define M_SEQ_SEMI_50(_1, ...) _1; M_SEQ_SEMI_49(__VA_ARGS__)
#define M_SEQ_SEMI_51(_1, ...) _1; M_SEQ_SEMI_50(__VA_ARGS__)
#define M_SEQ_SEMI_52(_1, ...) _1; M_SEQ_SEMI_51(__VA_ARGS__)
#define M_SEQ_SEMI_53(_1, ...) _1; M_SEQ_SEMI_52(__VA_ARGS__)
#define M_SEQ_SEMI_54(_1, ...) _1; M_SEQ_SEMI_53(__VA_ARGS__)
#define M_SEQ_SEMI_55(_1, ...) _1; M_SEQ_SEMI_54(__VA_ARGS__)
#define M_SEQ_SEMI_56(_1, ...) _1; M_SEQ_SEMI_55(__VA_ARGS__)
#define M_SEQ_SEMI_57(_1, ...) _1; M_SEQ_SEMI_56(__VA_ARGS__)
#define M_SEQ_SEMI_58(_1, ...) _1; M_SEQ_SEMI_57(__VA_ARGS__)
#define M_SEQ_SEMI_59(_1, ...) _1; M_SEQ_SEMI_58(__VA_ARGS__)
#define M_SEQ_SEMI_60(_1, ...) _1; M_SEQ_SEMI_59(__VA_ARGS__)
#define M_SEQ_SEMI_61(_1, ...) _1; M_SEQ_SEMI_60(__VA_ARGS__)
#define M_SEQ_SEMI_62(_1, ...) _1; M_SEQ_SEMI_61(__VA_ARGS__)
#define M_SEQ_SEMI_63(_1, ...) _1; M_SEQ_SEMI_62(__VA_ARGS__)
#define M_SEQ_SEMI_64(_1, ...) _1; M_SEQ_SEMI_63(__VA_ARGS__)
#define M_SEQ_SEMI_65(_1, ...) _1; M_SEQ_SEMI_64(__VA_ARGS__)
#define M_SEQ_SEMI_66(_1, ...) _1; M_SEQ_SEMI_65(__VA_ARGS__)
#define M_SEQ_SEMI_67(_1, ...) _1; M_SEQ_SEMI_66(__VA_ARGS__)
#define M_SEQ_SEMI_68(_1, ...) _1; M_SEQ_SEMI_67(__VA_ARGS__)
#define M_SEQ_SEMI_69(_1, ...) _1; M_SEQ_SEMI_68(__VA_ARGS__)
#define M_SEQ_SEMI_70(_1, ...) _1; M_SEQ_SEMI_69(__VA_ARGS__)
#define M_SEQ_SEMI_71(_1, ...) _1; M_SEQ_SEMI_70(__VA_ARGS__)
#define M_SEQ_SEMI_72(_1, ...) _1; M_SEQ_SEMI_71(__VA_ARGS__)
#define M_SEQ_SEMI_73(_1, ...) _1; M_SEQ_SEMI_72(__VA_ARGS__)
#define M_SEQ_SEMI_74(_1, ...) _1; M_SEQ_SEMI_73(__VA_ARGS__)
#define M_SEQ_SEMI_75(_1, ...) _1; M_SEQ_SEMI_74(__VA_ARGS__)
#define M_SEQ_SEMI_76(_1, ...) _1; M_SEQ_SEMI_75(__VA_ARGS__)
#define M_SEQ_SEMI_77(_1, ...) _1; M_SEQ_SEMI_76(__VA_ARGS__)
#define M_SEQ_SEMI_78(_1, ...) _1; M_SEQ_SEMI_77(__VA_ARGS__)
#define M_SEQ_SEMI_79(_1, ...) _1; M_SEQ_SEMI_78(__VA_ARGS__)
#define M_SEQ_SEMI_80(_1, ...) _1; M_SEQ_SEMI_79(__VA_ARGS__)
#define M_SEQ_SEMI_81(_1, ...) _1; M_SEQ_SEMI_80(__VA_ARGS__)
#define M_SEQ_SEMI_82(_1, ...) _1; M_SEQ_SEMI_81(__VA_ARGS__)
#define M_SEQ_SEMI_83(_1, ...) _1; M_SEQ_SEMI_82(__VA_ARGS__)
#define M_SEQ_SEMI_84(_1, ...) _1; M_SEQ_SEMI_83(__VA_ARGS__)
#define M_SEQ_SEMI_85(_1, ...) _1; M_SEQ_SEMI_84(__VA_ARGS__)
#define M_SEQ_SEMI_86(_1, ...) _1; M_SEQ_SEMI_85(__VA_ARGS__)
#define M_SEQ_SEMI_87(_1, ...) _1; M_SEQ_SEMI_86(__VA_ARGS__)
#define M_SEQ_SEMI_88(_1, ...) _1; M_SEQ_SEMI_87(__VA_ARGS__)
#define M_SEQ_SEMI_89(_1, ...) _1; M_SEQ_SEMI_88(__VA_ARGS__)
#define M_SEQ_SEMI_90(_1, ...) _1; M_SEQ_SEMI_89(__VA_ARGS__)
#define M_SEQ_SEMI_91(_1, ...) _1; M_SEQ_SEMI_90(__VA_ARGS__)
#define M_SEQ_SEMI_92(_1, ...) _1; M_SEQ_SEMI_91(__VA_ARGS__)
#define M_SEQ_SEMI_93(_1, ...) _1; M_SEQ_SEMI_92(__VA_ARGS__)
#define M_SEQ_SEMI_94(_1, ...) _1; M_SEQ_SEMI_93(__VA_ARGS__)
#define M_SEQ_SEMI_95(_1, ...) _1; M_SEQ_SEMI_94(__VA_ARGS__)
#define M_SEQ_SEMI_96(_1, ...) _1; M_SEQ_SEMI_95(__VA_ARGS__)
#define M_SEQ_SEMI_97(_1, ...) _1; M_SEQ_SEMI_96(__VA_ARGS__)
#define M_SEQ_SEMI_98(_1, ...) _1; M_SEQ_SEMI_97(__VA_ARGS__)
#define M_SEQ_SEMI_99(_1, ...) _1; M_SEQ_SEMI_98(__VA_ARGS__)
#define M_SEQ_SEMI_100(_1, ...) _1; M_SEQ_SEMI_99(__VA_ARGS__)
#define M_SEQ_SEMI_101(_1, ...) _1; M_SEQ_SEMI_100(__VA_ARGS__)
#define M_SEQ_SEMI_102(_1, ...) _1; M_SEQ_SEMI_101(__VA_ARGS__)
#define M_SEQ_SEMI_103(_1, ...) _1; M_SEQ_SEMI_102(__VA_ARGS__)
#define M_SEQ_SEMI_104(_1, ...) _1; M_SEQ_SEMI_103(__VA_ARGS__)
#define M_SEQ_SEMI_105(_1, ...) _1; M_SEQ_SEMI_104(__VA_ARGS__)
#define M_SEQ_SEMI_106(_1, ...) _1; M_SEQ_SEMI_105(__VA_ARGS__)
#define M_SEQ_SEMI_107(_1, ...) _1; M_SEQ_SEMI_106(__VA_ARGS__)
#define M_SEQ_SEMI_108(_1, ...) _1; M_SEQ_SEMI_107(__VA_ARGS__)
#define M_SEQ_SEMI_109(_1, ...) _1; M_SEQ_SEMI_108(__VA_ARGS__)
#define M_SEQ_SEMI_110(_1, ...) _1; M_SEQ_SEMI_109(__VA_ARGS__)
#define M_SEQ_SEMI_111(_1, ...) _1; M_SEQ_SEMI_110(__VA_ARGS__)
#define M_SEQ_SEMI_112(_1, ...) _1; M_SEQ_SEMI_111(__VA_ARGS__)
#define M_SEQ_SEMI_113(_1, ...) _1; M_SEQ_SEMI_112(__VA_ARGS__)
#define M_SEQ_SEMI_114(_1, ...) _1; M_SEQ_SEMI_113(__VA_ARGS__)
#define M_SEQ_SEMI_115(_1, ...) _1; M_SEQ_SEMI_114(__VA_ARGS__)
#define M_SEQ_SEMI_116(_1, ...) _1; M_SEQ_SEMI_115(__VA_ARGS__)
#define M_SEQ_SEMI_117(_1, ...) _1; M_SEQ_SEMI_116(__VA_ARGS__)
#define M_SEQ_SEMI_118(_1, ...) _1; M_SEQ_SEMI_117(__VA_ARGS__)
#define M_SEQ_SEMI_119(_1, ...) _1; M_SEQ_SEMI_118(__VA_ARGS__)
#define M_SEQ_SEMI_120(_1, ...) _1; M_SEQ_SEMI_119(__VA_ARGS__)
#define M_SEQ_SEMI_121(_1, ...) _1; M_SEQ_SEMI_120(__VA_ARGS__)
#define M_SEQ_SEMI_122(_1, ...) _1; M_SEQ_SEMI_121(__VA_ARGS__)
#define M_SEQ_SEMI_123(_1, ...) _1; M_SEQ_SEMI_122(__VA_ARGS__)
#define M_SEQ_SEMI_124(_1, ...) _1; M_SEQ_SEMI_123(__VA_ARGS__)
#define M_SEQ_SEMI_125(_1, ...) _1; M_SEQ_SEMI_124(__VA_ARGS__)
#define M_SEQ_SEMI_126(_1, ...) _1; M_SEQ_SEMI_125(__VA_ARGS__)
#define M_SEQ_SEMI_127(_1, ...) _1; M_SEQ_SEMI_126(__VA_ARGS__)
#define M_SEQ_SEMI_128(_1, ...) _1; M_SEQ_SEMI_127(__VA_ARGS__)
#define M_SEQ_SEMI_129(_1, ...) _1; M_SEQ_SEMI_128(__VA_ARGS__)
#define M_SEQ_SEMI_130(_1, ...) _1; M_SEQ_SEMI_129(__VA_ARGS__)
#define M_SEQ_SEMI_131(_1, ...) _1; M_SEQ_SEMI_130(__VA_ARGS__)
#define M_SEQ_SEMI_132(_1, ...) _1; M_SEQ_SEMI_131(__VA_ARGS__)
#define M_SEQ_SEMI_133(_1, ...) _1; M_SEQ_SEMI_132(__VA_ARGS__)
#define M_SEQ_SEMI_134(_1, ...) _1; M_SEQ_SEMI_133(__VA_ARGS__)
#define M_SEQ_SEMI_135(_1, ...) _1; M_SEQ_SEMI_134(__VA_ARGS__)
#define M_SEQ_SEMI_136(_1, ...) _1; M_SEQ_SEMI_135(__VA_ARGS__)
#define M_SEQ_SEMI_137(_1, ...) _1; M_SEQ_SEMI_136(__VA_ARGS__)
#define M_SEQ_SEMI_138(_1, ...) _1; M_SEQ_SEMI_137(__VA_ARGS__)
#define M_SEQ_SEMI_139(_1, ...) _1; M_SEQ_SEMI_138(__VA_ARGS__)
#define M_SEQ_SEMI_140(_1, ...) _1; M_SEQ_SEMI_139(__VA_ARGS__)
#define M_SEQ_SEMI_141(_1, ...) _1; M_SEQ_SEMI_140(__VA_ARGS__)
#define M_SEQ_SEMI_142(_1, ...) _1; M_SEQ_SEMI_141(__VA_ARGS__)
#define M_SEQ_SEMI_143(_1, ...) _1; M_SEQ_SEMI_142(__VA_ARGS__)
#define M_SEQ_SEMI_144(_1, ...) _1; M_SEQ_SEMI_143(__VA_ARGS__)
#define M_SEQ_SEMI_145(_1, ...) _1; M_SEQ_SEMI_144(__VA_ARGS__)
#define M_SEQ_SEMI_146(_1, ...) _1; M_SEQ_SEMI_145(__VA_ARGS__)
#define M_SEQ_SEMI_147(_1, ...) _1; M_SEQ_SEMI_146(__VA_ARGS__)
#define M_SEQ_SEMI_148(_1, ...) _1; M_SEQ_SEMI_147(__VA_ARGS__)
#define M_SEQ_SEMI_149(_1, ...) _1; M_SEQ_SEMI_148(__VA_ARGS__)
#define M_SEQ_SEMI_150(_1, ...) _1; M_SEQ_SEMI_149(__VA_ARGS__)
#define M_SEQ_SEMI_151(_1, ...) _1; M_SEQ_SEMI_150(__VA_ARGS__)
#define M_SEQ_SEMI_152(_1, ...) _1; M_SEQ_SEMI_151(__VA_ARGS__)
#define M_SEQ_SEMI_153(_1, ...) _1; M_SEQ_SEMI_152(__VA_ARGS__)
#define M_SEQ_SEMI_154(_1, ...) _1; M_SEQ_SEMI_153(__VA_ARGS__)
#define M_SEQ_SEMI_155(_1, ...) _1; M_SEQ_SEMI_154(__VA_ARGS__)
#define M_SEQ_SEMI_156(_1, ...) _1; M_SEQ_SEMI_155(__VA_ARGS__)
#define M_SEQ_SEMI_157(_1, ...) _1; M_SEQ_SEMI_156(__VA_ARGS__)
#define M_SEQ_SEMI_158(_1, ...) _1; M_SEQ_SEMI_157(__VA_ARGS__)
#define M_SEQ_SEMI_159(_1, ...) _1; M_SEQ_SEMI_158(__VA_ARGS__)
#define M_SEQ_SEMI_160(_1, ...) _1; M_SEQ_SEMI_159(__VA_ARGS__)
#define M_SEQ_SEMI_161(_1, ...) _1; M_SEQ_SEMI_160(__VA_ARGS__)
#define M_SEQ_SEMI_162(_1, ...) _1; M_SEQ_SEMI_161(__VA_ARGS__)
#define M_SEQ_SEMI_163(_1, ...) _1; M_SEQ_SEMI_162(__VA_ARGS__)
#define M_SEQ_SEMI_164(_1, ...) _1; M_SEQ_SEMI_163(__VA_ARGS__)
#define M_SEQ_SEMI_165(_1, ...) _1; M_SEQ_SEMI_164(__VA_ARGS__)
#define M_SEQ_SEMI_166(_1, ...) _1; M_SEQ_SEMI_165(__VA_ARGS__)
#define M_SEQ_SEMI_167(_1, ...) _1; M_SEQ_SEMI_166(__VA_ARGS__)
#define M_SEQ_SEMI_168(_1, ...) _1; M_SEQ_SEMI_167(__VA_ARGS__)
#define M_SEQ_SEMI_169(_1, ...) _1; M_SEQ_SEMI_168(__VA_ARGS__)
#define M_SEQ_SEMI_170(_1, ...) _1; M_SEQ_SEMI_169(__VA_ARGS__)
#define M_SEQ_SEMI_171(_1, ...) _1; M_SEQ_SEMI_170(__VA_ARGS__)
#define M_SEQ_SEMI_172(_1, ...) _1; M_SEQ_SEMI_171(__VA_ARGS__)
#define M_SEQ_SEMI_173(_1, ...) _1; M_SEQ_SEMI_172(__VA_ARGS__)
#define M_SEQ_SEMI_174(_1, ...) _1; M_SEQ_SEMI_173(__VA_ARGS__)
#define M_SEQ_SEMI_175(_1, ...) _1; M_SEQ_SEMI_174(__VA_ARGS__)
#define M_SEQ_SEMI_176(_1, ...) _1; M_SEQ_SEMI_175(__VA_ARGS__)
#define M_SEQ_SEMI_177(_1, ...) _1; M_SEQ_SEMI_176(__VA_ARGS__)
#define M_SEQ_SEMI_178(_1, ...) _1; M_SEQ_SEMI_177(__VA_ARGS__)
#define M_SEQ_SEMI_179(_1, ...) _1; M_SEQ_SEMI_178(__VA_ARGS__)
#define M_SEQ_SEMI_180(_1, ...) _1; M_SEQ_SEMI_179(__VA_ARGS__)
#define M_SEQ_SEMI_181(_1, ...) _1; M_SEQ_SEMI_180(__VA_ARGS__)
#define M_SEQ_SEMI_182(_1, ...) _1; M_SEQ_SEMI_181(__VA_ARGS__)
#define M_SEQ_SEMI_183(_1, ...) _1; M_SEQ_SEMI_182(__VA_ARGS__)
#define M_SEQ_SEMI_184(_1, ...) _1; M_SEQ_SEMI_183(__VA_ARGS__)
#define M_SEQ_SEMI_185(_1, ...) _1; M_SEQ_SEMI_184(__VA_ARGS__)
#define M_SEQ_SEMI_186(_1, ...) _1; M_SEQ_SEMI_185(__VA_ARGS__)
#define M_SEQ_SEMI_187(_1, ...) _1; M_SEQ_SEMI_186(__VA_ARGS__)
#define M_SEQ_SEMI_188(_1, ...) _1; M_SEQ_SEMI_187(__VA_ARGS__)
#define M_SEQ_SEMI_189(_1, ...) _1; M_SEQ_SEMI_188(__VA_ARGS__)
#define M_SEQ_SEMI_190(_1, ...) _1; M_SEQ_SEMI_189(__VA_ARGS__)
#define M_SEQ_SEMI_191(_1, ...) _1; M_SEQ_SEMI_190(__VA_ARGS__)
#define M_SEQ_SEMI_192(_1, ...) _1; M_SEQ_SEMI_191(__VA_ARGS__)
#define M_SEQ_SEMI_193(_1, ...) _1; M_SEQ_SEMI_192(__VA_ARGS__)
#define M_SEQ_SEMI_194(_1, ...) _1; M_SEQ_SEMI_193(__VA_ARGS__)
#define M_SEQ_SEMI_195(_1, ...) _1; M_SEQ_SEMI_194(__VA_ARGS__)
#define M_SEQ_SEMI_196(_1, ...) _1; M_SEQ_SEMI_195(__VA_ARGS__)
#define M_SEQ_SEMI_197(_1, ...) _1; M_SEQ_SEMI_196(__VA_ARGS__)
#define M_SEQ_SEMI_198(_1, ...) _1; M_SEQ_SEMI_197(__VA_ARGS__)
#define M_SEQ_SEMI_199(_1, ...) _1; M_SEQ_SEMI_198(__VA_ARGS__)
#define M_SEQ_SEMI_200(_1, ...) _1; M_SEQ_SEMI_199(__VA_ARGS__)
#define M_SEQ_SEMI_201(_1, ...) _1; M_SEQ_SEMI_200(__VA_ARGS__)
#define M_SEQ_SEMI_202(_1, ...) _1; M_SEQ_SEMI_201(__VA_ARGS__)
#define M_SEQ_SEMI_203(_1, ...) _1; M_SEQ_SEMI_202(__VA_ARGS__)
#define M_SEQ_SEMI_204(_1, ...) _1; M_SEQ_SEMI_203(__VA_ARGS__)
#define M_SEQ_SEMI_205(_1, ...) _1; M_SEQ_SEMI_204(__VA_ARGS__)
#define M_SEQ_SEMI_206(_1, ...) _1; M_SEQ_SEMI_205(__VA_ARGS__)
#define M_SEQ_SEMI_207(_1, ...) _1; M_SEQ_SEMI_206(__VA_ARGS__)
#define M_SEQ_SEMI_208(_1, ...) _1; M_SEQ_SEMI_207(__VA_ARGS__)
#define M_SEQ_SEMI_209(_1, ...) _1; M_SEQ_SEMI_208(__VA_ARGS__)
#define M_SEQ_SEMI_210(_1, ...) _1; M_SEQ_SEMI_209(__VA_ARGS__)
#define M_SEQ_SEMI_211(_1, ...) _1; M_SEQ_SEMI_210(__VA_ARGS__)
#define M_SEQ_SEMI_212(_1, ...) _1; M_SEQ_SEMI_211(__VA_ARGS__)
#define M_SEQ_SEMI_213(_1, ...) _1; M_SEQ_SEMI_212(__VA_ARGS__)
#define M_SEQ_SEMI_214(_1, ...) _1; M_SEQ_SEMI_213(__VA_ARGS__)
#define M_SEQ_SEMI_215(_1, ...) _1; M_SEQ_SEMI_214(__VA_ARGS__)
#define M_SEQ_SEMI_216(_1, ...) _1; M_SEQ_SEMI_215(__VA_ARGS__)
#define M_SEQ_SEMI_217(_1, ...) _1; M_SEQ_SEMI_216(__VA_ARGS__)
#define M_SEQ_SEMI_218(_1, ...) _1; M_SEQ_SEMI_217(__VA_ARGS__)
#define M_SEQ_SEMI_219(_1, ...) _1; M_SEQ_SEMI_218(__VA_ARGS__)
#define M_SEQ_SEMI_220(_1, ...) _1; M_SEQ_SEMI_219(__VA_ARGS__)
#define M_SEQ_SEMI_221(_1, ...) _1; M_SEQ_SEMI_220(__VA_ARGS__)
#define M_SEQ_SEMI_222(_1, ...) _1; M_SEQ_SEMI_221(__VA_ARGS__)
#define M_SEQ_SEMI_223(_1, ...) _1; M_SEQ_SEMI_222(__VA_ARGS__)
#define M_SEQ_SEMI_224(_1, ...) _1; M_SEQ_SEMI_223(__VA_ARGS__)
#define M_SEQ_SEMI_225(_1, ...) _1; M_SEQ_SEMI_224(__VA_ARGS__)
#define M_SEQ_SEMI_226(_1, ...) _1; M_SEQ_SEMI_225(__VA_ARGS__)
#define M_SEQ_SEMI_227(_1, ...) _1; M_SEQ_SEMI_226(__VA_ARGS__)
#define M_SEQ_SEMI_228(_1, ...) _1; M_SEQ_SEMI_227(__VA_ARGS__)
#define M_SEQ_SEMI_229(_1, ...) _1; M_SEQ_SEMI_228(__VA_ARGS__)
#define M_SEQ_SEMI_230(_1, ...) _1; M_SEQ_SEMI_229(__VA_ARGS__)
#define M_SEQ_SEMI_231(_1, ...) _1; M_SEQ_SEMI_230(__VA_ARGS__)
#define M_SEQ_SEMI_232(_1, ...) _1; M_SEQ_SEMI_231(__VA_ARGS__)
#define M_SEQ_SEMI_233(_1, ...) _1; M_SEQ_SEMI_232(__VA_ARGS__)
#define M_SEQ_SEMI_234(_1, ...) _1; M_SEQ_SEMI_233(__VA_ARGS__)
#define M_SEQ_SEMI_235(_1, ...) _1; M_SEQ_SEMI_234(__VA_ARGS__)
#define M_SEQ_SEMI_236(_1, ...) _1; M_SEQ_SEMI_235(__VA_ARGS__)
#define M_SEQ_SEMI_237(_1, ...) _1; M_SEQ_SEMI_236(__VA_ARGS__)
#define M_SEQ_SEMI_238(_1, ...) _1; M_SEQ_SEMI_237(__VA_ARGS__)
#define M_SEQ_SEMI_239(_1, ...) _1; M_SEQ_SEMI_238(__VA_ARGS__)
#define M_SEQ_SEMI_240(_1, ...) _1; M_SEQ_SEMI_239(__VA_ARGS__)
#define M_SEQ_SEMI_241(_1, ...) _1; M_SEQ_SEMI_240(__VA_ARGS__)
#define M_SEQ_SEMI_242(_1, ...) _1; M_SEQ_SEMI_241(__VA_ARGS__)
#define M_SEQ_SEMI_243(_1, ...) _1; M_SEQ_SEMI_242(__VA_ARGS__)
#define M_SEQ_SEMI_244(_1, ...) _1; M_SEQ_SEMI_243(__VA_ARGS__)
#define M_SEQ_SEMI_245(_1, ...) _1; M_SEQ_SEMI_244(__VA_ARGS__)
#define M_SEQ_SEMI_246(_1, ...) _1; M_SEQ_SEMI_245(__VA_ARGS__)
#define M_SEQ_SEMI_247(_1, ...) _1; M_SEQ_SEMI_246(__VA_ARGS__)
#define M_SEQ_SEMI_248(_1, ...) _1; M_SEQ_SEMI_247(__VA_ARGS__)
#define M_SEQ_SEMI_249(_1, ...) _1; M_SEQ_SEMI_248(__VA_ARGS__)
#define M_SEQ_SEMI_250(_1, ...) _1; M_SEQ_SEMI_249(__VA_ARGS__)
#define M_SEQ_SEMI_251(_1, ...) _1; M_SEQ_SEMI_250(__VA_ARGS__)
#define M_SEQ_SEMI_252(_1, ...) _1; M_SEQ_SEMI_251(__VA_ARGS__)
#define M_SEQ_SEMI_253(_1, ...) _1; M_SEQ_SEMI_252(__VA_ARGS__)
#define M_SEQ_SEMI_254(_1, ...) _1; M_SEQ_SEMI_253(__VA_ARGS__)
#define M_SEQ_SEMI_255(_1, ...) _1; M_SEQ_SEMI_254(__VA_ARGS__)

#define M_SEQ_UNFOLD_0()
#define M_SEQ_UNFOLD_1(_1) _1
#define M_SEQ_UNFOLD_2(_1, _2) _1 _2
#define M_SEQ_UNFOLD_3(_1, ...) _1 M_SEQ_UNFOLD_2(__VA_ARGS__)
#define M_SEQ_UNFOLD_4(_1, ...) _1 M_SEQ_UNFOLD_3(__VA_ARGS__)
#define M_SEQ_UNFOLD_5(_1, ...) _1 M_SEQ_UNFOLD_4(__VA_ARGS__)
#define M_SEQ_UNFOLD_6(_1, ...) _1 M_SEQ_UNFOLD_5(__VA_ARGS__)
#define M_SEQ_UNFOLD_7(_1, ...) _1 M_SEQ_UNFOLD_6(__VA_ARGS__)
#define M_SEQ_UNFOLD_8(_1, ...) _1 M_SEQ_UNFOLD_7(__VA_ARGS__)
#define M_SEQ_UNFOLD_9(_1, ...) _1 M_SEQ_UNFOLD_8(__VA_ARGS__)
#define M_SEQ_UNFOLD_10(_1, ...) _1 M_SEQ_UNFOLD_9(__VA_ARGS__)
#define M_SEQ_UNFOLD_11(_1, ...) _1 M_SEQ_UNFOLD_10(__VA_ARGS__)
#define M_SEQ_UNFOLD_12(_1, ...) _1 M_SEQ_UNFOLD_11(__VA_ARGS__)
#define M_SEQ_UNFOLD_13(_1, ...) _1 M_SEQ_UNFOLD_12(__VA_ARGS__)
#define M_SEQ_UNFOLD_14(_1, ...) _1 M_SEQ_UNFOLD_13(__VA_ARGS__)
#define M_SEQ_UNFOLD_15(_1, ...) _1 M_SEQ_UNFOLD_14(__VA_ARGS__)
#define M_SEQ_UNFOLD_16(_1, ...) _1 M_SEQ_UNFOLD_15(__VA_ARGS__)
#define M_SEQ_UNFOLD_17(_1, ...) _1 M_SEQ_UNFOLD_16(__VA_ARGS__)
#define M_SEQ_UNFOLD_18(_1, ...) _1 M_SEQ_UNFOLD_17(__VA_ARGS__)
#define M_SEQ_UNFOLD_19(_1, ...) _1 M_SEQ_UNFOLD_18(__VA_ARGS__)
#define M_SEQ_UNFOLD_20(_1, ...) _1 M_SEQ_UNFOLD_19(__VA_ARGS__)
#define M_SEQ_UNFOLD_21(_1, ...) _1 M_SEQ_UNFOLD_20(__VA_ARGS__)
#define M_SEQ_UNFOLD_22(_1, ...) _1 M_SEQ_UNFOLD_21(__VA_ARGS__)
#define M_SEQ_UNFOLD_23(_1, ...) _1 M_SEQ_UNFOLD_22(__VA_ARGS__)
#define M_SEQ_UNFOLD_24(_1, ...) _1 M_SEQ_UNFOLD_23(__VA_ARGS__)
#define M_SEQ_UNFOLD_25(_1, ...) _1 M_SEQ_UNFOLD_24(__VA_ARGS__)
#define M_SEQ_UNFOLD_26(_1, ...) _1 M_SEQ_UNFOLD_25(__VA_ARGS__)
#define M_SEQ_UNFOLD_27(_1, ...) _1 M_SEQ_UNFOLD_26(__VA_ARGS__)
#define M_SEQ_UNFOLD_28(_1, ...) _1 M_SEQ_UNFOLD_27(__VA_ARGS__)
#define M_SEQ_UNFOLD_29(_1, ...) _1 M_SEQ_UNFOLD_28(__VA_ARGS__)
#define M_SEQ_UNFOLD_30(_1, ...) _1 M_SEQ_UNFOLD_29(__VA_ARGS__)
#define M_SEQ_UNFOLD_31(_1, ...) _1 M_SEQ_UNFOLD_30(__VA_ARGS__)
#define M_SEQ_UNFOLD_32(_1, ...) _1 M_SEQ_UNFOLD_31(__VA_ARGS__)
#define M_SEQ_UNFOLD_33(_1, ...) _1 M_SEQ_UNFOLD_32(__VA_ARGS__)
#define M_SEQ_UNFOLD_34(_1, ...) _1 M_SEQ_UNFOLD_33(__VA_ARGS__)
#define M_SEQ_UNFOLD_35(_1, ...) _1 M_SEQ_UNFOLD_34(__VA_ARGS__)
#define M_SEQ_UNFOLD_36(_1, ...) _1 M_SEQ_UNFOLD_35(__VA_ARGS__)
#define M_SEQ_UNFOLD_37(_1, ...) _1 M_SEQ_UNFOLD_36(__VA_ARGS__)
#define M_SEQ_UNFOLD_38(_1, ...) _1 M_SEQ_UNFOLD_37(__VA_ARGS__)
#define M_SEQ_UNFOLD_39(_1, ...) _1 M_SEQ_UNFOLD_38(__VA_ARGS__)
#define M_SEQ_UNFOLD_40(_1, ...) _1 M_SEQ_UNFOLD_39(__VA_ARGS__)
#define M_SEQ_UNFOLD_41(_1, ...) _1 M_SEQ_UNFOLD_40(__VA_ARGS__)
#define M_SEQ_UNFOLD_42(_1, ...) _1 M_SEQ_UNFOLD_41(__VA_ARGS__)
#define M_SEQ_UNFOLD_43(_1, ...) _1 M_SEQ_UNFOLD_42(__VA_ARGS__)
#define M_SEQ_UNFOLD_44(_1, ...) _1 M_SEQ_UNFOLD_43(__VA_ARGS__)
#define M_SEQ_UNFOLD_45(_1, ...) _1 M_SEQ_UNFOLD_44(__VA_ARGS__)
#define M_SEQ_UNFOLD_46(_1, ...) _1 M_SEQ_UNFOLD_45(__VA_ARGS__)
#define M_SEQ_UNFOLD_47(_1, ...) _1 M_SEQ_UNFOLD_46(__VA_ARGS__)
#define M_SEQ_UNFOLD_48(_1, ...) _1 M_SEQ_UNFOLD_47(__VA_ARGS__)
#define M_SEQ_UNFOLD_49(_1, ...) _1 M_SEQ_UNFOLD_48(__VA_ARGS__)
#define M_SEQ_UNFOLD_50(_1, ...) _1 M_SEQ_UNFOLD_49(__VA_ARGS__)
#define M_SEQ_UNFOLD_51(_1, ...) _1 M_SEQ_UNFOLD_50(__VA_ARGS__)
#define M_SEQ_UNFOLD_52(_1, ...) _1 M_SEQ_UNFOLD_51(__VA_ARGS__)
#define M_SEQ_UNFOLD_53(_1, ...) _1 M_SEQ_UNFOLD_52(__VA_ARGS__)
#define M_SEQ_UNFOLD_54(_1, ...) _1 M_SEQ_UNFOLD_53(__VA_ARGS__)
#define M_SEQ_UNFOLD_55(_1, ...) _1 M_SEQ_UNFOLD_54(__VA_ARGS__)
#define M_SEQ_UNFOLD_56(_1, ...) _1 M_SEQ_UNFOLD_55(__VA_ARGS__)
#define M_SEQ_UNFOLD_57(_1, ...) _1 M_SEQ_UNFOLD_56(__VA_ARGS__)
#define M_SEQ_UNFOLD_58(_1, ...) _1 M_SEQ_UNFOLD_57(__VA_ARGS__)
#define M_SEQ_UNFOLD_59(_1, ...) _1 M_SEQ_UNFOLD_58(__VA_ARGS__)
#define M_SEQ_UNFOLD_60(_1, ...) _1 M_SEQ_UNFOLD_59(__VA_ARGS__)
#define M_SEQ_UNFOLD_61(_1, ...) _1 M_SEQ_UNFOLD_60(__VA_ARGS__)
#define M_SEQ_UNFOLD_62(_1, ...) _1 M_SEQ_UNFOLD_61(__VA_ARGS__)
#define M_SEQ_UNFOLD_63(_1, ...) _1 M_SEQ_UNFOLD_62(__VA_ARGS__)
#define M_SEQ_UNFOLD_64(_1, ...) _1 M_SEQ_UNFOLD_63(__VA_ARGS__)
#define M_SEQ_UNFOLD_65(_1, ...) _1 M_SEQ_UNFOLD_64(__VA_ARGS__)
#define M_SEQ_UNFOLD_66(_1, ...) _1 M_SEQ_UNFOLD_65(__VA_ARGS__)
#define M_SEQ_UNFOLD_67(_1, ...) _1 M_SEQ_UNFOLD_66(__VA_ARGS__)
#define M_SEQ_UNFOLD_68(_1, ...) _1 M_SEQ_UNFOLD_67(__VA_ARGS__)
#define M_SEQ_UNFOLD_69(_1, ...) _1 M_SEQ_UNFOLD_68(__VA_ARGS__)
#define M_SEQ_UNFOLD_70(_1, ...) _1 M_SEQ_UNFOLD_69(__VA_ARGS__)
#define M_SEQ_UNFOLD_71(_1, ...) _1 M_SEQ_UNFOLD_70(__VA_ARGS__)
#define M_SEQ_UNFOLD_72(_1, ...) _1 M_SEQ_UNFOLD_71(__VA_ARGS__)
#define M_SEQ_UNFOLD_73(_1, ...) _1 M_SEQ_UNFOLD_72(__VA_ARGS__)
#define M_SEQ_UNFOLD_74(_1, ...) _1 M_SEQ_UNFOLD_73(__VA_ARGS__)
#define M_SEQ_UNFOLD_75(_1, ...) _1 M_SEQ_UNFOLD_74(__VA_ARGS__)
#define M_SEQ_UNFOLD_76(_1, ...) _1 M_SEQ_UNFOLD_75(__VA_ARGS__)
#define M_SEQ_UNFOLD_77(_1, ...) _1 M_SEQ_UNFOLD_76(__VA_ARGS__)
#define M_SEQ_UNFOLD_78(_1, ...) _1 M_SEQ_UNFOLD_77(__VA_ARGS__)
#define M_SEQ_UNFOLD_79(_1, ...) _1 M_SEQ_UNFOLD_78(__VA_ARGS__)
#define M_SEQ_UNFOLD_80(_1, ...) _1 M_SEQ_UNFOLD_79(__VA_ARGS__)
#define M_SEQ_UNFOLD_81(_1, ...) _1 M_SEQ_UNFOLD_80(__VA_ARGS__)
#define M_SEQ_UNFOLD_82(_1, ...) _1 M_SEQ_UNFOLD_81(__VA_ARGS__)
#define M_SEQ_UNFOLD_83(_1, ...) _1 M_SEQ_UNFOLD_82(__VA_ARGS__)
#define M_SEQ_UNFOLD_84(_1, ...) _1 M_SEQ_UNFOLD_83(__VA_ARGS__)
#define M_SEQ_UNFOLD_85(_1, ...) _1 M_SEQ_UNFOLD_84(__VA_ARGS__)
#define M_SEQ_UNFOLD_86(_1, ...) _1 M_SEQ_UNFOLD_85(__VA_ARGS__)
#define M_SEQ_UNFOLD_87(_1, ...) _1 M_SEQ_UNFOLD_86(__VA_ARGS__)
#define M_SEQ_UNFOLD_88(_1, ...) _1 M_SEQ_UNFOLD_87(__VA_ARGS__)
#define M_SEQ_UNFOLD_89(_1, ...) _1 M_SEQ_UNFOLD_88(__VA_ARGS__)
#define M_SEQ_UNFOLD_90(_1, ...) _1 M_SEQ_UNFOLD_89(__VA_ARGS__)
#define M_SEQ_UNFOLD_91(_1, ...) _1 M_SEQ_UNFOLD_90(__VA_ARGS__)
#define M_SEQ_UNFOLD_92(_1, ...) _1 M_SEQ_UNFOLD_91(__VA_ARGS__)
#define M_SEQ_UNFOLD_93(_1, ...) _1 M_SEQ_UNFOLD_92(__VA_ARGS__)
#define M_SEQ_UNFOLD_94(_1, ...) _1 M_SEQ_UNFOLD_93(__VA_ARGS__)
#define M_SEQ_UNFOLD_95(_1, ...) _1 M_SEQ_UNFOLD_94(__VA_ARGS__)
#define M_SEQ_UNFOLD_96(_1, ...) _1 M_SEQ_UNFOLD_95(__VA_ARGS__)
#define M_SEQ_UNFOLD_97(_1, ...) _1 M_SEQ_UNFOLD_96(__VA_ARGS__)
#define M_SEQ_UNFOLD_98(_1, ...) _1 M_SEQ_UNFOLD_97(__VA_ARGS__)
#define M_SEQ_UNFOLD_99(_1, ...) _1 M_SEQ_UNFOLD_98(__VA_ARGS__)
#define M_SEQ_UNFOLD_100(_1, ...) _1 M_SEQ_UNFOLD_99(__VA_ARGS__)
#define M_SEQ_UNFOLD_101(_1, ...) _1 M_SEQ_UNFOLD_100(__VA_ARGS__)
#define M_SEQ_UNFOLD_102(_1, ...) _1 M_SEQ_UNFOLD_101(__VA_ARGS__)
#define M_SEQ_UNFOLD_103(_1, ...) _1 M_SEQ_UNFOLD_102(__VA_ARGS__)
#define M_SEQ_UNFOLD_104(_1, ...) _1 M_SEQ_UNFOLD_103(__VA_ARGS__)
#define M_SEQ_UNFOLD_105(_1, ...) _1 M_SEQ_UNFOLD_104(__VA_ARGS__)
#define M_SEQ_UNFOLD_106(_1, ...) _1 M_SEQ_UNFOLD_105(__VA_ARGS__)
#define M_SEQ_UNFOLD_107(_1, ...) _1 M_SEQ_UNFOLD_106(__VA_ARGS__)
#define M_SEQ_UNFOLD_108(_1, ...) _1 M_SEQ_UNFOLD_107(__VA_ARGS__)
#define M_SEQ_UNFOLD_109(_1, ...) _1 M_SEQ_UNFOLD_108(__VA_ARGS__)
#define M_SEQ_UNFOLD_110(_1, ...) _1 M_SEQ_UNFOLD_109(__VA_ARGS__)
#define M_SEQ_UNFOLD_111(_1, ...) _1 M_SEQ_UNFOLD_110(__VA_ARGS__)
#define M_SEQ_UNFOLD_112(_1, ...) _1 M_SEQ_UNFOLD_111(__VA_ARGS__)
#define M_SEQ_UNFOLD_113(_1, ...) _1 M_SEQ_UNFOLD_112(__VA_ARGS__)
#define M_SEQ_UNFOLD_114(_1, ...) _1 M_SEQ_UNFOLD_113(__VA_ARGS__)
#define M_SEQ_UNFOLD_115(_1, ...) _1 M_SEQ_UNFOLD_114(__VA_ARGS__)
#define M_SEQ_UNFOLD_116(_1, ...) _1 M_SEQ_UNFOLD_115(__VA_ARGS__)
#define M_SEQ_UNFOLD_117(_1, ...) _1 M_SEQ_UNFOLD_116(__VA_ARGS__)
#define M_SEQ_UNFOLD_118(_1, ...) _1 M_SEQ_UNFOLD_117(__VA_ARGS__)
#define M_SEQ_UNFOLD_119(_1, ...) _1 M_SEQ_UNFOLD_118(__VA_ARGS__)
#define M_SEQ_UNFOLD_120(_1, ...) _1 M_SEQ_UNFOLD_119(__VA_ARGS__)
#define M_SEQ_UNFOLD_121(_1, ...) _1 M_SEQ_UNFOLD_120(__VA_ARGS__)
#define M_SEQ_UNFOLD_122(_1, ...) _1 M_SEQ_UNFOLD_121(__VA_ARGS__)
#define M_SEQ_UNFOLD_123(_1, ...) _1 M_SEQ_UNFOLD_122(__VA_ARGS__)
#define M_SEQ_UNFOLD_124(_1, ...) _1 M_SEQ_UNFOLD_123(__VA_ARGS__)
#define M_SEQ_UNFOLD_125(_1, ...) _1 M_SEQ_UNFOLD_124(__VA_ARGS__)
#define M_SEQ_UNFOLD_126(_1, ...) _1 M_SEQ_UNFOLD_125(__VA_ARGS__)
#define M_SEQ_UNFOLD_127(_1, ...) _1 M_SEQ_UNFOLD_126(__VA_ARGS__)
#define M_SEQ_UNFOLD_128(_1, ...) _1 M_SEQ_UNFOLD_127(__VA_ARGS__)
#define M_SEQ_UNFOLD_129(_1, ...) _1 M_SEQ_UNFOLD_128(__VA_ARGS__)
#define M_SEQ_UNFOLD_130(_1, ...) _1 M_SEQ_UNFOLD_129(__VA_ARGS__)
#define M_SEQ_UNFOLD_131(_1, ...) _1 M_SEQ_UNFOLD_130(__VA_ARGS__)
#define M_SEQ_UNFOLD_132(_1, ...) _1 M_SEQ_UNFOLD_131(__VA_ARGS__)
#define M_SEQ_UNFOLD_133(_1, ...) _1 M_SEQ_UNFOLD_132(__VA_ARGS__)
#define M_SEQ_UNFOLD_134(_1, ...) _1 M_SEQ_UNFOLD_133(__VA_ARGS__)
#define M_SEQ_UNFOLD_135(_1, ...) _1 M_SEQ_UNFOLD_134(__VA_ARGS__)
#define M_SEQ_UNFOLD_136(_1, ...) _1 M_SEQ_UNFOLD_135(__VA_ARGS__)
#define M_SEQ_UNFOLD_137(_1, ...) _1 M_SEQ_UNFOLD_136(__VA_ARGS__)
#define M_SEQ_UNFOLD_138(_1, ...) _1 M_SEQ_UNFOLD_137(__VA_ARGS__)
#define M_SEQ_UNFOLD_139(_1, ...) _1 M_SEQ_UNFOLD_138(__VA_ARGS__)
#define M_SEQ_UNFOLD_140(_1, ...) _1 M_SEQ_UNFOLD_139(__VA_ARGS__)
#define M_SEQ_UNFOLD_141(_1, ...) _1 M_SEQ_UNFOLD_140(__VA_ARGS__)
#define M_SEQ_UNFOLD_142(_1, ...) _1 M_SEQ_UNFOLD_141(__VA_ARGS__)
#define M_SEQ_UNFOLD_143(_1, ...) _1 M_SEQ_UNFOLD_142(__VA_ARGS__)
#define M_SEQ_UNFOLD_144(_1, ...) _1 M_SEQ_UNFOLD_143(__VA_ARGS__)
#define M_SEQ_UNFOLD_145(_1, ...) _1 M_SEQ_UNFOLD_144(__VA_ARGS__)
#define M_SEQ_UNFOLD_146(_1, ...) _1 M_SEQ_UNFOLD_145(__VA_ARGS__)
#define M_SEQ_UNFOLD_147(_1, ...) _1 M_SEQ_UNFOLD_146(__VA_ARGS__)
#define M_SEQ_UNFOLD_148(_1, ...) _1 M_SEQ_UNFOLD_147(__VA_ARGS__)
#define M_SEQ_UNFOLD_149(_1, ...) _1 M_SEQ_UNFOLD_148(__VA_ARGS__)
#define M_SEQ_UNFOLD_150(_1, ...) _1 M_SEQ_UNFOLD_149(__VA_ARGS__)
#define M_SEQ_UNFOLD_151(_1, ...) _1 M_SEQ_UNFOLD_150(__VA_ARGS__)
#define M_SEQ_UNFOLD_152(_1, ...) _1 M_SEQ_UNFOLD_151(__VA_ARGS__)
#define M_SEQ_UNFOLD_153(_1, ...) _1 M_SEQ_UNFOLD_152(__VA_ARGS__)
#define M_SEQ_UNFOLD_154(_1, ...) _1 M_SEQ_UNFOLD_153(__VA_ARGS__)
#define M_SEQ_UNFOLD_155(_1, ...) _1 M_SEQ_UNFOLD_154(__VA_ARGS__)
#define M_SEQ_UNFOLD_156(_1, ...) _1 M_SEQ_UNFOLD_155(__VA_ARGS__)
#define M_SEQ_UNFOLD_157(_1, ...) _1 M_SEQ_UNFOLD_156(__VA_ARGS__)
#define M_SEQ_UNFOLD_158(_1, ...) _1 M_SEQ_UNFOLD_157(__VA_ARGS__)
#define M_SEQ_UNFOLD_159(_1, ...) _1 M_SEQ_UNFOLD_158(__VA_ARGS__)
#define M_SEQ_UNFOLD_160(_1, ...) _1 M_SEQ_UNFOLD_159(__VA_ARGS__)
#define M_SEQ_UNFOLD_161(_1, ...) _1 M_SEQ_UNFOLD_160(__VA_ARGS__)
#define M_SEQ_UNFOLD_162(_1, ...) _1 M_SEQ_UNFOLD_161(__VA_ARGS__)
#define M_SEQ_UNFOLD_163(_1, ...) _1 M_SEQ_UNFOLD_162(__VA_ARGS__)
#define M_SEQ_UNFOLD_164(_1, ...) _1 M_SEQ_UNFOLD_163(__VA_ARGS__)
#define M_SEQ_UNFOLD_165(_1, ...) _1 M_SEQ_UNFOLD_164(__VA_ARGS__)
#define M_SEQ_UNFOLD_166(_1, ...) _1 M_SEQ_UNFOLD_165(__VA_ARGS__)
#define M_SEQ_UNFOLD_167(_1, ...) _1 M_SEQ_UNFOLD_166(__VA_ARGS__)
#define M_SEQ_UNFOLD_168(_1, ...) _1 M_SEQ_UNFOLD_167(__VA_ARGS__)
#define M_SEQ_UNFOLD_169(_1, ...) _1 M_SEQ_UNFOLD_168(__VA_ARGS__)
#define M_SEQ_UNFOLD_170(_1, ...) _1 M_SEQ_UNFOLD_169(__VA_ARGS__)
#define M_SEQ_UNFOLD_171(_1, ...) _1 M_SEQ_UNFOLD_170(__VA_ARGS__)
#define M_SEQ_UNFOLD_172(_1, ...) _1 M_SEQ_UNFOLD_171(__VA_ARGS__)
#define M_SEQ_UNFOLD_173(_1, ...) _1 M_SEQ_UNFOLD_172(__VA_ARGS__)
#define M_SEQ_UNFOLD_174(_1, ...) _1 M_SEQ_UNFOLD_173(__VA_ARGS__)
#define M_SEQ_UNFOLD_175(_1, ...) _1 M_SEQ_UNFOLD_174(__VA_ARGS__)
#define M_SEQ_UNFOLD_176(_1, ...) _1 M_SEQ_UNFOLD_175(__VA_ARGS__)
#define M_SEQ_UNFOLD_177(_1, ...) _1 M_SEQ_UNFOLD_176(__VA_ARGS__)
#define M_SEQ_UNFOLD_178(_1, ...) _1 M_SEQ_UNFOLD_177(__VA_ARGS__)
#define M_SEQ_UNFOLD_179(_1, ...) _1 M_SEQ_UNFOLD_178(__VA_ARGS__)
#define M_SEQ_UNFOLD_180(_1, ...) _1 M_SEQ_UNFOLD_179(__VA_ARGS__)
#define M_SEQ_UNFOLD_181(_1, ...) _1 M_SEQ_UNFOLD_180(__VA_ARGS__)
#define M_SEQ_UNFOLD_182(_1, ...) _1 M_SEQ_UNFOLD_181(__VA_ARGS__)
#define M_SEQ_UNFOLD_183(_1, ...) _1 M_SEQ_UNFOLD_182(__VA_ARGS__)
#define M_SEQ_UNFOLD_184(_1, ...) _1 M_SEQ_UNFOLD_183(__VA_ARGS__)
#define M_SEQ_UNFOLD_185(_1, ...) _1 M_SEQ_UNFOLD_184(__VA_ARGS__)
#define M_SEQ_UNFOLD_186(_1, ...) _1 M_SEQ_UNFOLD_185(__VA_ARGS__)
#define M_SEQ_UNFOLD_187(_1, ...) _1 M_SEQ_UNFOLD_186(__VA_ARGS__)
#define M_SEQ_UNFOLD_188(_1, ...) _1 M_SEQ_UNFOLD_187(__VA_ARGS__)
#define M_SEQ_UNFOLD_189(_1, ...) _1 M_SEQ_UNFOLD_188(__VA_ARGS__)
#define M_SEQ_UNFOLD_190(_1, ...) _1 M_SEQ_UNFOLD_189(__VA_ARGS__)
#define M_SEQ_UNFOLD_191(_1, ...) _1 M_SEQ_UNFOLD_190(__VA_ARGS__)
#define M_SEQ_UNFOLD_192(_1, ...) _1 M_SEQ_UNFOLD_191(__VA_ARGS__)
#define M_SEQ_UNFOLD_193(_1, ...) _1 M_SEQ_UNFOLD_192(__VA_ARGS__)
#define M_SEQ_UNFOLD_194(_1, ...) _1 M_SEQ_UNFOLD_193(__VA_ARGS__)
#define M_SEQ_UNFOLD_195(_1, ...) _1 M_SEQ_UNFOLD_194(__VA_ARGS__)
#define M_SEQ_UNFOLD_196(_1, ...) _1 M_SEQ_UNFOLD_195(__VA_ARGS__)
#define M_SEQ_UNFOLD_197(_1, ...) _1 M_SEQ_UNFOLD_196(__VA_ARGS__)
#define M_SEQ_UNFOLD_198(_1, ...) _1 M_SEQ_UNFOLD_197(__VA_ARGS__)
#define M_SEQ_UNFOLD_199(_1, ...) _1 M_SEQ_UNFOLD_198(__VA_ARGS__)
#define M_SEQ_UNFOLD_200(_1, ...) _1 M_SEQ_UNFOLD_199(__VA_ARGS__)
#define M_SEQ_UNFOLD_201(_1, ...) _1 M_SEQ_UNFOLD_200(__VA_ARGS__)
#define M_SEQ_UNFOLD_202(_1, ...) _1 M_SEQ_UNFOLD_201(__VA_ARGS__)
#define M_SEQ_UNFOLD_203(_1, ...) _1 M_SEQ_UNFOLD_202(__VA_ARGS__)
#define M_SEQ_UNFOLD_204(_1, ...) _1 M_SEQ_UNFOLD_203(__VA_ARGS__)
#define M_SEQ_UNFOLD_205(_1, ...) _1 M_SEQ_UNFOLD_204(__VA_ARGS__)
#define M_SEQ_UNFOLD_206(_1, ...) _1 M_SEQ_UNFOLD_205(__VA_ARGS__)
#define M_SEQ_UNFOLD_207(_1, ...) _1 M_SEQ_UNFOLD_206(__VA_ARGS__)
#define M_SEQ_UNFOLD_208(_1, ...) _1 M_SEQ_UNFOLD_207(__VA_ARGS__)
#define M_SEQ_UNFOLD_209(_1, ...) _1 M_SEQ_UNFOLD_208(__VA_ARGS__)
#define M_SEQ_UNFOLD_210(_1, ...) _1 M_SEQ_UNFOLD_209(__VA_ARGS__)
#define M_SEQ_UNFOLD_211(_1, ...) _1 M_SEQ_UNFOLD_210(__VA_ARGS__)
#define M_SEQ_UNFOLD_212(_1, ...) _1 M_SEQ_UNFOLD_211(__VA_ARGS__)
#define M_SEQ_UNFOLD_213(_1, ...) _1 M_SEQ_UNFOLD_212(__VA_ARGS__)
#define M_SEQ_UNFOLD_214(_1, ...) _1 M_SEQ_UNFOLD_213(__VA_ARGS__)
#define M_SEQ_UNFOLD_215(_1, ...) _1 M_SEQ_UNFOLD_214(__VA_ARGS__)
#define M_SEQ_UNFOLD_216(_1, ...) _1 M_SEQ_UNFOLD_215(__VA_ARGS__)
#define M_SEQ_UNFOLD_217(_1, ...) _1 M_SEQ_UNFOLD_216(__VA_ARGS__)
#define M_SEQ_UNFOLD_218(_1, ...) _1 M_SEQ_UNFOLD_217(__VA_ARGS__)
#define M_SEQ_UNFOLD_219(_1, ...) _1 M_SEQ_UNFOLD_218(__VA_ARGS__)
#define M_SEQ_UNFOLD_220(_1, ...) _1 M_SEQ_UNFOLD_219(__VA_ARGS__)
#define M_SEQ_UNFOLD_221(_1, ...) _1 M_SEQ_UNFOLD_220(__VA_ARGS__)
#define M_SEQ_UNFOLD_222(_1, ...) _1 M_SEQ_UNFOLD_221(__VA_ARGS__)
#define M_SEQ_UNFOLD_223(_1, ...) _1 M_SEQ_UNFOLD_222(__VA_ARGS__)
#define M_SEQ_UNFOLD_224(_1, ...) _1 M_SEQ_UNFOLD_223(__VA_ARGS__)
#define M_SEQ_UNFOLD_225(_1, ...) _1 M_SEQ_UNFOLD_224(__VA_ARGS__)
#define M_SEQ_UNFOLD_226(_1, ...) _1 M_SEQ_UNFOLD_225(__VA_ARGS__)
#define M_SEQ_UNFOLD_227(_1, ...) _1 M_SEQ_UNFOLD_226(__VA_ARGS__)
#define M_SEQ_UNFOLD_228(_1, ...) _1 M_SEQ_UNFOLD_227(__VA_ARGS__)
#define M_SEQ_UNFOLD_229(_1, ...) _1 M_SEQ_UNFOLD_228(__VA_ARGS__)
#define M_SEQ_UNFOLD_230(_1, ...) _1 M_SEQ_UNFOLD_229(__VA_ARGS__)
#define M_SEQ_UNFOLD_231(_1, ...) _1 M_SEQ_UNFOLD_230(__VA_ARGS__)
#define M_SEQ_UNFOLD_232(_1, ...) _1 M_SEQ_UNFOLD_231(__VA_ARGS__)
#define M_SEQ_UNFOLD_233(_1, ...) _1 M_SEQ_UNFOLD_232(__VA_ARGS__)
#define M_SEQ_UNFOLD_234(_1, ...) _1 M_SEQ_UNFOLD_233(__VA_ARGS__)
#define M_SEQ_UNFOLD_235(_1, ...) _1 M_SEQ_UNFOLD_234(__VA_ARGS__)
#define M_SEQ_UNFOLD_236(_1, ...) _1 M_SEQ_UNFOLD_235(__VA_ARGS__)
#define M_SEQ_UNFOLD_237(_1, ...) _1 M_SEQ_UNFOLD_236(__VA_ARGS__)
#define M_SEQ_UNFOLD_238(_1, ...) _1 M_SEQ_UNFOLD_237(__VA_ARGS__)
#define M_SEQ_UNFOLD_239(_1, ...) _1 M_SEQ_UNFOLD_238(__VA_ARGS__)
#define M_SEQ_UNFOLD_240(_1, ...) _1 M_SEQ_UNFOLD_239(__VA_ARGS__)
#define M_SEQ_UNFOLD_241(_1, ...) _1 M_SEQ_UNFOLD_240(__VA_ARGS__)
#define M_SEQ_UNFOLD_242(_1, ...) _1 M_SEQ_UNFOLD_241(__VA_ARGS__)
#define M_SEQ_UNFOLD_243(_1, ...) _1 M_SEQ_UNFOLD_242(__VA_ARGS__)
#define M_SEQ_UNFOLD_244(_1, ...) _1 M_SEQ_UNFOLD_243(__VA_ARGS__)
#define M_SEQ_UNFOLD_245(_1, ...) _1 M_SEQ_UNFOLD_244(__VA_ARGS__)
#define M_SEQ_UNFOLD_246(_1, ...) _1 M_SEQ_UNFOLD_245(__VA_ARGS__)
#define M_SEQ_UNFOLD_247(_1, ...) _1 M_SEQ_UNFOLD_246(__VA_ARGS__)
#define M_SEQ_UNFOLD_248(_1, ...) _1 M_SEQ_UNFOLD_247(__VA_ARGS__)
#define M_SEQ_UNFOLD_249(_1, ...) _1 M_SEQ_UNFOLD_248(__VA_ARGS__)
#define M_SEQ_UNFOLD_250(_1, ...) _1 M_SEQ_UNFOLD_249(__VA_ARGS__)
#define M_SEQ_UNFOLD_251(_1, ...) _1 M_SEQ_UNFOLD_250(__VA_ARGS__)
#define M_SEQ_UNFOLD_252(_1, ...) _1 M_SEQ_UNFOLD_251(__VA_ARGS__)
#define M_SEQ_UNFOLD_253(_1, ...) _1 M_SEQ_UNFOLD_252(__VA_ARGS__)
#define M_SEQ_UNFOLD_254(_1, ...) _1 M_SEQ_UNFOLD_253(__VA_ARGS__)
#define M_SEQ_UNFOLD_255(_1, ...) _1 M_SEQ_UNFOLD_254(__VA_ARGS__)

#pragma endregion

#pragma region --- VARIADIC ---

#define VA_SEQ_SEMI(...) M_CONCAT_LATER(M_SEQ_SEMI_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)
#define VA_SEQ_UNFOLD(...) M_CONCAT_LATER(M_SEQ_UNFOLD_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)

#define VA_SEQ_COMMA(...) __VA_ARGS__

#pragma endregion

#endif // !_M_SEQUENCE_H_

/*******************************************************************************
 *  @file      reverse.h
 *  @brief     MACRO extension lib to reverse arguments
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _M_REVERSE_H_
#define _M_REVERSE_H_

#pragma once

#pragma region --- MACRO GENERATOR ---

#ifdef _SEQ_PRINTERS

#include <math.h>
#include <string.h>
// ARG_REVERSE
void _va_arg_reverse_printer(int n) {
    int padding = log10(n) + 1;
    if (n > 0)
        printf("#define M_ARG_REVERSE_1(_1) _1\n");
    if (n > 1)
        printf("#define M_ARG_REVERSE_2(_1, _2) _2, _1\n");
    for (int i = 3; i < n; ++i) {
        printf("#define M_ARG_REVERSE_%d(_1, ...) M_ARG_REVERSE_%d(__VA_ARGS__), _1\n", i, i - 1);
    }
    printf("\n#ifdef _VADIDATIC_H_\n\n#define VA_ARG_REVERSE(...) M_CONCAT(M_ARG_REVERSE_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n\n#endif // !_VADIDATIC_H_");
}

#endif // !_SEQ_PRINTERS

#pragma endregion

#pragma region --- INCLUDE ---

#include "macro.h"
#include "variadic.h"

#pragma endregion

#pragma region --- MACRO ---

// @printer_setting : _va_arg_reverse_printer(256);
#define M_ARG_REVERSE_1(_1) _1
#define M_ARG_REVERSE_2(_1, _2) _2, _1
#define M_ARG_REVERSE_3(_1, ...) M_ARG_REVERSE_2(__VA_ARGS__), _1
#define M_ARG_REVERSE_4(_1, ...) M_ARG_REVERSE_3(__VA_ARGS__), _1
#define M_ARG_REVERSE_5(_1, ...) M_ARG_REVERSE_4(__VA_ARGS__), _1
#define M_ARG_REVERSE_6(_1, ...) M_ARG_REVERSE_5(__VA_ARGS__), _1
#define M_ARG_REVERSE_7(_1, ...) M_ARG_REVERSE_6(__VA_ARGS__), _1
#define M_ARG_REVERSE_8(_1, ...) M_ARG_REVERSE_7(__VA_ARGS__), _1
#define M_ARG_REVERSE_9(_1, ...) M_ARG_REVERSE_8(__VA_ARGS__), _1
#define M_ARG_REVERSE_10(_1, ...) M_ARG_REVERSE_9(__VA_ARGS__), _1
#define M_ARG_REVERSE_11(_1, ...) M_ARG_REVERSE_10(__VA_ARGS__), _1
#define M_ARG_REVERSE_12(_1, ...) M_ARG_REVERSE_11(__VA_ARGS__), _1
#define M_ARG_REVERSE_13(_1, ...) M_ARG_REVERSE_12(__VA_ARGS__), _1
#define M_ARG_REVERSE_14(_1, ...) M_ARG_REVERSE_13(__VA_ARGS__), _1
#define M_ARG_REVERSE_15(_1, ...) M_ARG_REVERSE_14(__VA_ARGS__), _1
#define M_ARG_REVERSE_16(_1, ...) M_ARG_REVERSE_15(__VA_ARGS__), _1
#define M_ARG_REVERSE_17(_1, ...) M_ARG_REVERSE_16(__VA_ARGS__), _1
#define M_ARG_REVERSE_18(_1, ...) M_ARG_REVERSE_17(__VA_ARGS__), _1
#define M_ARG_REVERSE_19(_1, ...) M_ARG_REVERSE_18(__VA_ARGS__), _1
#define M_ARG_REVERSE_20(_1, ...) M_ARG_REVERSE_19(__VA_ARGS__), _1
#define M_ARG_REVERSE_21(_1, ...) M_ARG_REVERSE_20(__VA_ARGS__), _1
#define M_ARG_REVERSE_22(_1, ...) M_ARG_REVERSE_21(__VA_ARGS__), _1
#define M_ARG_REVERSE_23(_1, ...) M_ARG_REVERSE_22(__VA_ARGS__), _1
#define M_ARG_REVERSE_24(_1, ...) M_ARG_REVERSE_23(__VA_ARGS__), _1
#define M_ARG_REVERSE_25(_1, ...) M_ARG_REVERSE_24(__VA_ARGS__), _1
#define M_ARG_REVERSE_26(_1, ...) M_ARG_REVERSE_25(__VA_ARGS__), _1
#define M_ARG_REVERSE_27(_1, ...) M_ARG_REVERSE_26(__VA_ARGS__), _1
#define M_ARG_REVERSE_28(_1, ...) M_ARG_REVERSE_27(__VA_ARGS__), _1
#define M_ARG_REVERSE_29(_1, ...) M_ARG_REVERSE_28(__VA_ARGS__), _1
#define M_ARG_REVERSE_30(_1, ...) M_ARG_REVERSE_29(__VA_ARGS__), _1
#define M_ARG_REVERSE_31(_1, ...) M_ARG_REVERSE_30(__VA_ARGS__), _1
#define M_ARG_REVERSE_32(_1, ...) M_ARG_REVERSE_31(__VA_ARGS__), _1
#define M_ARG_REVERSE_33(_1, ...) M_ARG_REVERSE_32(__VA_ARGS__), _1
#define M_ARG_REVERSE_34(_1, ...) M_ARG_REVERSE_33(__VA_ARGS__), _1
#define M_ARG_REVERSE_35(_1, ...) M_ARG_REVERSE_34(__VA_ARGS__), _1
#define M_ARG_REVERSE_36(_1, ...) M_ARG_REVERSE_35(__VA_ARGS__), _1
#define M_ARG_REVERSE_37(_1, ...) M_ARG_REVERSE_36(__VA_ARGS__), _1
#define M_ARG_REVERSE_38(_1, ...) M_ARG_REVERSE_37(__VA_ARGS__), _1
#define M_ARG_REVERSE_39(_1, ...) M_ARG_REVERSE_38(__VA_ARGS__), _1
#define M_ARG_REVERSE_40(_1, ...) M_ARG_REVERSE_39(__VA_ARGS__), _1
#define M_ARG_REVERSE_41(_1, ...) M_ARG_REVERSE_40(__VA_ARGS__), _1
#define M_ARG_REVERSE_42(_1, ...) M_ARG_REVERSE_41(__VA_ARGS__), _1
#define M_ARG_REVERSE_43(_1, ...) M_ARG_REVERSE_42(__VA_ARGS__), _1
#define M_ARG_REVERSE_44(_1, ...) M_ARG_REVERSE_43(__VA_ARGS__), _1
#define M_ARG_REVERSE_45(_1, ...) M_ARG_REVERSE_44(__VA_ARGS__), _1
#define M_ARG_REVERSE_46(_1, ...) M_ARG_REVERSE_45(__VA_ARGS__), _1
#define M_ARG_REVERSE_47(_1, ...) M_ARG_REVERSE_46(__VA_ARGS__), _1
#define M_ARG_REVERSE_48(_1, ...) M_ARG_REVERSE_47(__VA_ARGS__), _1
#define M_ARG_REVERSE_49(_1, ...) M_ARG_REVERSE_48(__VA_ARGS__), _1
#define M_ARG_REVERSE_50(_1, ...) M_ARG_REVERSE_49(__VA_ARGS__), _1
#define M_ARG_REVERSE_51(_1, ...) M_ARG_REVERSE_50(__VA_ARGS__), _1
#define M_ARG_REVERSE_52(_1, ...) M_ARG_REVERSE_51(__VA_ARGS__), _1
#define M_ARG_REVERSE_53(_1, ...) M_ARG_REVERSE_52(__VA_ARGS__), _1
#define M_ARG_REVERSE_54(_1, ...) M_ARG_REVERSE_53(__VA_ARGS__), _1
#define M_ARG_REVERSE_55(_1, ...) M_ARG_REVERSE_54(__VA_ARGS__), _1
#define M_ARG_REVERSE_56(_1, ...) M_ARG_REVERSE_55(__VA_ARGS__), _1
#define M_ARG_REVERSE_57(_1, ...) M_ARG_REVERSE_56(__VA_ARGS__), _1
#define M_ARG_REVERSE_58(_1, ...) M_ARG_REVERSE_57(__VA_ARGS__), _1
#define M_ARG_REVERSE_59(_1, ...) M_ARG_REVERSE_58(__VA_ARGS__), _1
#define M_ARG_REVERSE_60(_1, ...) M_ARG_REVERSE_59(__VA_ARGS__), _1
#define M_ARG_REVERSE_61(_1, ...) M_ARG_REVERSE_60(__VA_ARGS__), _1
#define M_ARG_REVERSE_62(_1, ...) M_ARG_REVERSE_61(__VA_ARGS__), _1
#define M_ARG_REVERSE_63(_1, ...) M_ARG_REVERSE_62(__VA_ARGS__), _1
#define M_ARG_REVERSE_64(_1, ...) M_ARG_REVERSE_63(__VA_ARGS__), _1
#define M_ARG_REVERSE_65(_1, ...) M_ARG_REVERSE_64(__VA_ARGS__), _1
#define M_ARG_REVERSE_66(_1, ...) M_ARG_REVERSE_65(__VA_ARGS__), _1
#define M_ARG_REVERSE_67(_1, ...) M_ARG_REVERSE_66(__VA_ARGS__), _1
#define M_ARG_REVERSE_68(_1, ...) M_ARG_REVERSE_67(__VA_ARGS__), _1
#define M_ARG_REVERSE_69(_1, ...) M_ARG_REVERSE_68(__VA_ARGS__), _1
#define M_ARG_REVERSE_70(_1, ...) M_ARG_REVERSE_69(__VA_ARGS__), _1
#define M_ARG_REVERSE_71(_1, ...) M_ARG_REVERSE_70(__VA_ARGS__), _1
#define M_ARG_REVERSE_72(_1, ...) M_ARG_REVERSE_71(__VA_ARGS__), _1
#define M_ARG_REVERSE_73(_1, ...) M_ARG_REVERSE_72(__VA_ARGS__), _1
#define M_ARG_REVERSE_74(_1, ...) M_ARG_REVERSE_73(__VA_ARGS__), _1
#define M_ARG_REVERSE_75(_1, ...) M_ARG_REVERSE_74(__VA_ARGS__), _1
#define M_ARG_REVERSE_76(_1, ...) M_ARG_REVERSE_75(__VA_ARGS__), _1
#define M_ARG_REVERSE_77(_1, ...) M_ARG_REVERSE_76(__VA_ARGS__), _1
#define M_ARG_REVERSE_78(_1, ...) M_ARG_REVERSE_77(__VA_ARGS__), _1
#define M_ARG_REVERSE_79(_1, ...) M_ARG_REVERSE_78(__VA_ARGS__), _1
#define M_ARG_REVERSE_80(_1, ...) M_ARG_REVERSE_79(__VA_ARGS__), _1
#define M_ARG_REVERSE_81(_1, ...) M_ARG_REVERSE_80(__VA_ARGS__), _1
#define M_ARG_REVERSE_82(_1, ...) M_ARG_REVERSE_81(__VA_ARGS__), _1
#define M_ARG_REVERSE_83(_1, ...) M_ARG_REVERSE_82(__VA_ARGS__), _1
#define M_ARG_REVERSE_84(_1, ...) M_ARG_REVERSE_83(__VA_ARGS__), _1
#define M_ARG_REVERSE_85(_1, ...) M_ARG_REVERSE_84(__VA_ARGS__), _1
#define M_ARG_REVERSE_86(_1, ...) M_ARG_REVERSE_85(__VA_ARGS__), _1
#define M_ARG_REVERSE_87(_1, ...) M_ARG_REVERSE_86(__VA_ARGS__), _1
#define M_ARG_REVERSE_88(_1, ...) M_ARG_REVERSE_87(__VA_ARGS__), _1
#define M_ARG_REVERSE_89(_1, ...) M_ARG_REVERSE_88(__VA_ARGS__), _1
#define M_ARG_REVERSE_90(_1, ...) M_ARG_REVERSE_89(__VA_ARGS__), _1
#define M_ARG_REVERSE_91(_1, ...) M_ARG_REVERSE_90(__VA_ARGS__), _1
#define M_ARG_REVERSE_92(_1, ...) M_ARG_REVERSE_91(__VA_ARGS__), _1
#define M_ARG_REVERSE_93(_1, ...) M_ARG_REVERSE_92(__VA_ARGS__), _1
#define M_ARG_REVERSE_94(_1, ...) M_ARG_REVERSE_93(__VA_ARGS__), _1
#define M_ARG_REVERSE_95(_1, ...) M_ARG_REVERSE_94(__VA_ARGS__), _1
#define M_ARG_REVERSE_96(_1, ...) M_ARG_REVERSE_95(__VA_ARGS__), _1
#define M_ARG_REVERSE_97(_1, ...) M_ARG_REVERSE_96(__VA_ARGS__), _1
#define M_ARG_REVERSE_98(_1, ...) M_ARG_REVERSE_97(__VA_ARGS__), _1
#define M_ARG_REVERSE_99(_1, ...) M_ARG_REVERSE_98(__VA_ARGS__), _1
#define M_ARG_REVERSE_100(_1, ...) M_ARG_REVERSE_99(__VA_ARGS__), _1
#define M_ARG_REVERSE_101(_1, ...) M_ARG_REVERSE_100(__VA_ARGS__), _1
#define M_ARG_REVERSE_102(_1, ...) M_ARG_REVERSE_101(__VA_ARGS__), _1
#define M_ARG_REVERSE_103(_1, ...) M_ARG_REVERSE_102(__VA_ARGS__), _1
#define M_ARG_REVERSE_104(_1, ...) M_ARG_REVERSE_103(__VA_ARGS__), _1
#define M_ARG_REVERSE_105(_1, ...) M_ARG_REVERSE_104(__VA_ARGS__), _1
#define M_ARG_REVERSE_106(_1, ...) M_ARG_REVERSE_105(__VA_ARGS__), _1
#define M_ARG_REVERSE_107(_1, ...) M_ARG_REVERSE_106(__VA_ARGS__), _1
#define M_ARG_REVERSE_108(_1, ...) M_ARG_REVERSE_107(__VA_ARGS__), _1
#define M_ARG_REVERSE_109(_1, ...) M_ARG_REVERSE_108(__VA_ARGS__), _1
#define M_ARG_REVERSE_110(_1, ...) M_ARG_REVERSE_109(__VA_ARGS__), _1
#define M_ARG_REVERSE_111(_1, ...) M_ARG_REVERSE_110(__VA_ARGS__), _1
#define M_ARG_REVERSE_112(_1, ...) M_ARG_REVERSE_111(__VA_ARGS__), _1
#define M_ARG_REVERSE_113(_1, ...) M_ARG_REVERSE_112(__VA_ARGS__), _1
#define M_ARG_REVERSE_114(_1, ...) M_ARG_REVERSE_113(__VA_ARGS__), _1
#define M_ARG_REVERSE_115(_1, ...) M_ARG_REVERSE_114(__VA_ARGS__), _1
#define M_ARG_REVERSE_116(_1, ...) M_ARG_REVERSE_115(__VA_ARGS__), _1
#define M_ARG_REVERSE_117(_1, ...) M_ARG_REVERSE_116(__VA_ARGS__), _1
#define M_ARG_REVERSE_118(_1, ...) M_ARG_REVERSE_117(__VA_ARGS__), _1
#define M_ARG_REVERSE_119(_1, ...) M_ARG_REVERSE_118(__VA_ARGS__), _1
#define M_ARG_REVERSE_120(_1, ...) M_ARG_REVERSE_119(__VA_ARGS__), _1
#define M_ARG_REVERSE_121(_1, ...) M_ARG_REVERSE_120(__VA_ARGS__), _1
#define M_ARG_REVERSE_122(_1, ...) M_ARG_REVERSE_121(__VA_ARGS__), _1
#define M_ARG_REVERSE_123(_1, ...) M_ARG_REVERSE_122(__VA_ARGS__), _1
#define M_ARG_REVERSE_124(_1, ...) M_ARG_REVERSE_123(__VA_ARGS__), _1
#define M_ARG_REVERSE_125(_1, ...) M_ARG_REVERSE_124(__VA_ARGS__), _1
#define M_ARG_REVERSE_126(_1, ...) M_ARG_REVERSE_125(__VA_ARGS__), _1
#define M_ARG_REVERSE_127(_1, ...) M_ARG_REVERSE_126(__VA_ARGS__), _1
#define M_ARG_REVERSE_128(_1, ...) M_ARG_REVERSE_127(__VA_ARGS__), _1
#define M_ARG_REVERSE_129(_1, ...) M_ARG_REVERSE_128(__VA_ARGS__), _1
#define M_ARG_REVERSE_130(_1, ...) M_ARG_REVERSE_129(__VA_ARGS__), _1
#define M_ARG_REVERSE_131(_1, ...) M_ARG_REVERSE_130(__VA_ARGS__), _1
#define M_ARG_REVERSE_132(_1, ...) M_ARG_REVERSE_131(__VA_ARGS__), _1
#define M_ARG_REVERSE_133(_1, ...) M_ARG_REVERSE_132(__VA_ARGS__), _1
#define M_ARG_REVERSE_134(_1, ...) M_ARG_REVERSE_133(__VA_ARGS__), _1
#define M_ARG_REVERSE_135(_1, ...) M_ARG_REVERSE_134(__VA_ARGS__), _1
#define M_ARG_REVERSE_136(_1, ...) M_ARG_REVERSE_135(__VA_ARGS__), _1
#define M_ARG_REVERSE_137(_1, ...) M_ARG_REVERSE_136(__VA_ARGS__), _1
#define M_ARG_REVERSE_138(_1, ...) M_ARG_REVERSE_137(__VA_ARGS__), _1
#define M_ARG_REVERSE_139(_1, ...) M_ARG_REVERSE_138(__VA_ARGS__), _1
#define M_ARG_REVERSE_140(_1, ...) M_ARG_REVERSE_139(__VA_ARGS__), _1
#define M_ARG_REVERSE_141(_1, ...) M_ARG_REVERSE_140(__VA_ARGS__), _1
#define M_ARG_REVERSE_142(_1, ...) M_ARG_REVERSE_141(__VA_ARGS__), _1
#define M_ARG_REVERSE_143(_1, ...) M_ARG_REVERSE_142(__VA_ARGS__), _1
#define M_ARG_REVERSE_144(_1, ...) M_ARG_REVERSE_143(__VA_ARGS__), _1
#define M_ARG_REVERSE_145(_1, ...) M_ARG_REVERSE_144(__VA_ARGS__), _1
#define M_ARG_REVERSE_146(_1, ...) M_ARG_REVERSE_145(__VA_ARGS__), _1
#define M_ARG_REVERSE_147(_1, ...) M_ARG_REVERSE_146(__VA_ARGS__), _1
#define M_ARG_REVERSE_148(_1, ...) M_ARG_REVERSE_147(__VA_ARGS__), _1
#define M_ARG_REVERSE_149(_1, ...) M_ARG_REVERSE_148(__VA_ARGS__), _1
#define M_ARG_REVERSE_150(_1, ...) M_ARG_REVERSE_149(__VA_ARGS__), _1
#define M_ARG_REVERSE_151(_1, ...) M_ARG_REVERSE_150(__VA_ARGS__), _1
#define M_ARG_REVERSE_152(_1, ...) M_ARG_REVERSE_151(__VA_ARGS__), _1
#define M_ARG_REVERSE_153(_1, ...) M_ARG_REVERSE_152(__VA_ARGS__), _1
#define M_ARG_REVERSE_154(_1, ...) M_ARG_REVERSE_153(__VA_ARGS__), _1
#define M_ARG_REVERSE_155(_1, ...) M_ARG_REVERSE_154(__VA_ARGS__), _1
#define M_ARG_REVERSE_156(_1, ...) M_ARG_REVERSE_155(__VA_ARGS__), _1
#define M_ARG_REVERSE_157(_1, ...) M_ARG_REVERSE_156(__VA_ARGS__), _1
#define M_ARG_REVERSE_158(_1, ...) M_ARG_REVERSE_157(__VA_ARGS__), _1
#define M_ARG_REVERSE_159(_1, ...) M_ARG_REVERSE_158(__VA_ARGS__), _1
#define M_ARG_REVERSE_160(_1, ...) M_ARG_REVERSE_159(__VA_ARGS__), _1
#define M_ARG_REVERSE_161(_1, ...) M_ARG_REVERSE_160(__VA_ARGS__), _1
#define M_ARG_REVERSE_162(_1, ...) M_ARG_REVERSE_161(__VA_ARGS__), _1
#define M_ARG_REVERSE_163(_1, ...) M_ARG_REVERSE_162(__VA_ARGS__), _1
#define M_ARG_REVERSE_164(_1, ...) M_ARG_REVERSE_163(__VA_ARGS__), _1
#define M_ARG_REVERSE_165(_1, ...) M_ARG_REVERSE_164(__VA_ARGS__), _1
#define M_ARG_REVERSE_166(_1, ...) M_ARG_REVERSE_165(__VA_ARGS__), _1
#define M_ARG_REVERSE_167(_1, ...) M_ARG_REVERSE_166(__VA_ARGS__), _1
#define M_ARG_REVERSE_168(_1, ...) M_ARG_REVERSE_167(__VA_ARGS__), _1
#define M_ARG_REVERSE_169(_1, ...) M_ARG_REVERSE_168(__VA_ARGS__), _1
#define M_ARG_REVERSE_170(_1, ...) M_ARG_REVERSE_169(__VA_ARGS__), _1
#define M_ARG_REVERSE_171(_1, ...) M_ARG_REVERSE_170(__VA_ARGS__), _1
#define M_ARG_REVERSE_172(_1, ...) M_ARG_REVERSE_171(__VA_ARGS__), _1
#define M_ARG_REVERSE_173(_1, ...) M_ARG_REVERSE_172(__VA_ARGS__), _1
#define M_ARG_REVERSE_174(_1, ...) M_ARG_REVERSE_173(__VA_ARGS__), _1
#define M_ARG_REVERSE_175(_1, ...) M_ARG_REVERSE_174(__VA_ARGS__), _1
#define M_ARG_REVERSE_176(_1, ...) M_ARG_REVERSE_175(__VA_ARGS__), _1
#define M_ARG_REVERSE_177(_1, ...) M_ARG_REVERSE_176(__VA_ARGS__), _1
#define M_ARG_REVERSE_178(_1, ...) M_ARG_REVERSE_177(__VA_ARGS__), _1
#define M_ARG_REVERSE_179(_1, ...) M_ARG_REVERSE_178(__VA_ARGS__), _1
#define M_ARG_REVERSE_180(_1, ...) M_ARG_REVERSE_179(__VA_ARGS__), _1
#define M_ARG_REVERSE_181(_1, ...) M_ARG_REVERSE_180(__VA_ARGS__), _1
#define M_ARG_REVERSE_182(_1, ...) M_ARG_REVERSE_181(__VA_ARGS__), _1
#define M_ARG_REVERSE_183(_1, ...) M_ARG_REVERSE_182(__VA_ARGS__), _1
#define M_ARG_REVERSE_184(_1, ...) M_ARG_REVERSE_183(__VA_ARGS__), _1
#define M_ARG_REVERSE_185(_1, ...) M_ARG_REVERSE_184(__VA_ARGS__), _1
#define M_ARG_REVERSE_186(_1, ...) M_ARG_REVERSE_185(__VA_ARGS__), _1
#define M_ARG_REVERSE_187(_1, ...) M_ARG_REVERSE_186(__VA_ARGS__), _1
#define M_ARG_REVERSE_188(_1, ...) M_ARG_REVERSE_187(__VA_ARGS__), _1
#define M_ARG_REVERSE_189(_1, ...) M_ARG_REVERSE_188(__VA_ARGS__), _1
#define M_ARG_REVERSE_190(_1, ...) M_ARG_REVERSE_189(__VA_ARGS__), _1
#define M_ARG_REVERSE_191(_1, ...) M_ARG_REVERSE_190(__VA_ARGS__), _1
#define M_ARG_REVERSE_192(_1, ...) M_ARG_REVERSE_191(__VA_ARGS__), _1
#define M_ARG_REVERSE_193(_1, ...) M_ARG_REVERSE_192(__VA_ARGS__), _1
#define M_ARG_REVERSE_194(_1, ...) M_ARG_REVERSE_193(__VA_ARGS__), _1
#define M_ARG_REVERSE_195(_1, ...) M_ARG_REVERSE_194(__VA_ARGS__), _1
#define M_ARG_REVERSE_196(_1, ...) M_ARG_REVERSE_195(__VA_ARGS__), _1
#define M_ARG_REVERSE_197(_1, ...) M_ARG_REVERSE_196(__VA_ARGS__), _1
#define M_ARG_REVERSE_198(_1, ...) M_ARG_REVERSE_197(__VA_ARGS__), _1
#define M_ARG_REVERSE_199(_1, ...) M_ARG_REVERSE_198(__VA_ARGS__), _1
#define M_ARG_REVERSE_200(_1, ...) M_ARG_REVERSE_199(__VA_ARGS__), _1
#define M_ARG_REVERSE_201(_1, ...) M_ARG_REVERSE_200(__VA_ARGS__), _1
#define M_ARG_REVERSE_202(_1, ...) M_ARG_REVERSE_201(__VA_ARGS__), _1
#define M_ARG_REVERSE_203(_1, ...) M_ARG_REVERSE_202(__VA_ARGS__), _1
#define M_ARG_REVERSE_204(_1, ...) M_ARG_REVERSE_203(__VA_ARGS__), _1
#define M_ARG_REVERSE_205(_1, ...) M_ARG_REVERSE_204(__VA_ARGS__), _1
#define M_ARG_REVERSE_206(_1, ...) M_ARG_REVERSE_205(__VA_ARGS__), _1
#define M_ARG_REVERSE_207(_1, ...) M_ARG_REVERSE_206(__VA_ARGS__), _1
#define M_ARG_REVERSE_208(_1, ...) M_ARG_REVERSE_207(__VA_ARGS__), _1
#define M_ARG_REVERSE_209(_1, ...) M_ARG_REVERSE_208(__VA_ARGS__), _1
#define M_ARG_REVERSE_210(_1, ...) M_ARG_REVERSE_209(__VA_ARGS__), _1
#define M_ARG_REVERSE_211(_1, ...) M_ARG_REVERSE_210(__VA_ARGS__), _1
#define M_ARG_REVERSE_212(_1, ...) M_ARG_REVERSE_211(__VA_ARGS__), _1
#define M_ARG_REVERSE_213(_1, ...) M_ARG_REVERSE_212(__VA_ARGS__), _1
#define M_ARG_REVERSE_214(_1, ...) M_ARG_REVERSE_213(__VA_ARGS__), _1
#define M_ARG_REVERSE_215(_1, ...) M_ARG_REVERSE_214(__VA_ARGS__), _1
#define M_ARG_REVERSE_216(_1, ...) M_ARG_REVERSE_215(__VA_ARGS__), _1
#define M_ARG_REVERSE_217(_1, ...) M_ARG_REVERSE_216(__VA_ARGS__), _1
#define M_ARG_REVERSE_218(_1, ...) M_ARG_REVERSE_217(__VA_ARGS__), _1
#define M_ARG_REVERSE_219(_1, ...) M_ARG_REVERSE_218(__VA_ARGS__), _1
#define M_ARG_REVERSE_220(_1, ...) M_ARG_REVERSE_219(__VA_ARGS__), _1
#define M_ARG_REVERSE_221(_1, ...) M_ARG_REVERSE_220(__VA_ARGS__), _1
#define M_ARG_REVERSE_222(_1, ...) M_ARG_REVERSE_221(__VA_ARGS__), _1
#define M_ARG_REVERSE_223(_1, ...) M_ARG_REVERSE_222(__VA_ARGS__), _1
#define M_ARG_REVERSE_224(_1, ...) M_ARG_REVERSE_223(__VA_ARGS__), _1
#define M_ARG_REVERSE_225(_1, ...) M_ARG_REVERSE_224(__VA_ARGS__), _1
#define M_ARG_REVERSE_226(_1, ...) M_ARG_REVERSE_225(__VA_ARGS__), _1
#define M_ARG_REVERSE_227(_1, ...) M_ARG_REVERSE_226(__VA_ARGS__), _1
#define M_ARG_REVERSE_228(_1, ...) M_ARG_REVERSE_227(__VA_ARGS__), _1
#define M_ARG_REVERSE_229(_1, ...) M_ARG_REVERSE_228(__VA_ARGS__), _1
#define M_ARG_REVERSE_230(_1, ...) M_ARG_REVERSE_229(__VA_ARGS__), _1
#define M_ARG_REVERSE_231(_1, ...) M_ARG_REVERSE_230(__VA_ARGS__), _1
#define M_ARG_REVERSE_232(_1, ...) M_ARG_REVERSE_231(__VA_ARGS__), _1
#define M_ARG_REVERSE_233(_1, ...) M_ARG_REVERSE_232(__VA_ARGS__), _1
#define M_ARG_REVERSE_234(_1, ...) M_ARG_REVERSE_233(__VA_ARGS__), _1
#define M_ARG_REVERSE_235(_1, ...) M_ARG_REVERSE_234(__VA_ARGS__), _1
#define M_ARG_REVERSE_236(_1, ...) M_ARG_REVERSE_235(__VA_ARGS__), _1
#define M_ARG_REVERSE_237(_1, ...) M_ARG_REVERSE_236(__VA_ARGS__), _1
#define M_ARG_REVERSE_238(_1, ...) M_ARG_REVERSE_237(__VA_ARGS__), _1
#define M_ARG_REVERSE_239(_1, ...) M_ARG_REVERSE_238(__VA_ARGS__), _1
#define M_ARG_REVERSE_240(_1, ...) M_ARG_REVERSE_239(__VA_ARGS__), _1
#define M_ARG_REVERSE_241(_1, ...) M_ARG_REVERSE_240(__VA_ARGS__), _1
#define M_ARG_REVERSE_242(_1, ...) M_ARG_REVERSE_241(__VA_ARGS__), _1
#define M_ARG_REVERSE_243(_1, ...) M_ARG_REVERSE_242(__VA_ARGS__), _1
#define M_ARG_REVERSE_244(_1, ...) M_ARG_REVERSE_243(__VA_ARGS__), _1
#define M_ARG_REVERSE_245(_1, ...) M_ARG_REVERSE_244(__VA_ARGS__), _1
#define M_ARG_REVERSE_246(_1, ...) M_ARG_REVERSE_245(__VA_ARGS__), _1
#define M_ARG_REVERSE_247(_1, ...) M_ARG_REVERSE_246(__VA_ARGS__), _1
#define M_ARG_REVERSE_248(_1, ...) M_ARG_REVERSE_247(__VA_ARGS__), _1
#define M_ARG_REVERSE_249(_1, ...) M_ARG_REVERSE_248(__VA_ARGS__), _1
#define M_ARG_REVERSE_250(_1, ...) M_ARG_REVERSE_249(__VA_ARGS__), _1
#define M_ARG_REVERSE_251(_1, ...) M_ARG_REVERSE_250(__VA_ARGS__), _1
#define M_ARG_REVERSE_252(_1, ...) M_ARG_REVERSE_251(__VA_ARGS__), _1
#define M_ARG_REVERSE_253(_1, ...) M_ARG_REVERSE_252(__VA_ARGS__), _1
#define M_ARG_REVERSE_254(_1, ...) M_ARG_REVERSE_253(__VA_ARGS__), _1
#define M_ARG_REVERSE_255(_1, ...) M_ARG_REVERSE_254(__VA_ARGS__), _1

#pragma endregion

#pragma region --- VARIADIC ---

#define VA_ARG_REVERSE(...) M_CONCAT_LATER(M_ARG_REVERSE_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)

#pragma endregion

#endif // !_M_REVERSE_H_

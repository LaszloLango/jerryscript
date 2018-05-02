/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ECMA_BUILTINS_INTERNAL_H
#define ECMA_BUILTINS_INTERNAL_H

#ifndef ECMA_BUILTINS_INTERNAL
# error "!ECMA_BUILTINS_INTERNAL"
#endif /* !ECMA_BUILTINS_INTERNAL */

/**
 * Type of symbolic built-in number types (starting from 256).
 */
typedef enum
{
  ECMA_BUILTIN_NUMBER_MAX = 256, /**< value of ECMA_NUMBER_MAX_VALUE */
  ECMA_BUILTIN_NUMBER_MIN, /**< value of ECMA_NUMBER_MIN_VALUE */
  ECMA_BUILTIN_NUMBER_E, /**< value of ECMA_NUMBER_E */
  ECMA_BUILTIN_NUMBER_PI, /**< value of ECMA_NUMBER_PI */
  ECMA_BUILTIN_NUMBER_LN10, /**< value of ECMA_NUMBER_LN10 */
  ECMA_BUILTIN_NUMBER_LN2, /**< value of ECMA_NUMBER_LN2 */
  ECMA_BUILTIN_NUMBER_LOG2E, /**< value of ECMA_NUMBER_LOG2E */
  ECMA_BUILTIN_NUMBER_LOG10E, /**< value of ECMA_NUMBER_LOG10E */
  ECMA_BUILTIN_NUMBER_SQRT2, /**< value of ECMA_NUMBER_SQRT2 */
  ECMA_BUILTIN_NUMBER_SQRT_1_2, /**< value of ECMA_NUMBER_SQRT_1_2 */
  ECMA_BUILTIN_NUMBER_NAN, /**< result of ecma_number_make_nan () */
  ECMA_BUILTIN_NUMBER_POSITIVE_INFINITY, /**< result of ecma_number_make_infinity (false) */
  ECMA_BUILTIN_NUMBER_NEGATIVE_INFINITY, /**< result of ecma_number_make_infinity (true) */
} ecma_builtin_number_type_t;

#endif /* !ECMA_BUILTINS_INTERNAL_H */

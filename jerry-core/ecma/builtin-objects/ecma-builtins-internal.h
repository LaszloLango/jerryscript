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

#include "ecma-builtins.h"
#include "ecma-globals.h"

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


//extern const ecma_builtin_property_descriptor_t ecma_builtin_array_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_array_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_array_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_array_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_array_property_descriptor_list[]; ecma_value_t ecma_builtin_array_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_array_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_array_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_string_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_string_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_string_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_string_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_string_property_descriptor_list[]; ecma_value_t ecma_builtin_string_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_string_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_string_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_boolean_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_boolean_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_boolean_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_boolean_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_boolean_property_descriptor_list[]; ecma_value_t ecma_builtin_boolean_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_boolean_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_boolean_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_number_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_number_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_number_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_number_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_number_property_descriptor_list[]; ecma_value_t ecma_builtin_number_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_number_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_number_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_math_property_descriptor_list[]; ecma_value_t ecma_builtin_math_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_math_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_math_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_json_property_descriptor_list[]; ecma_value_t ecma_builtin_json_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_json_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_json_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_date_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_date_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_date_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_date_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_date_property_descriptor_list[]; ecma_value_t ecma_builtin_date_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_date_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_date_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_regexp_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_regexp_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_regexp_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_regexp_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_regexp_property_descriptor_list[]; ecma_value_t ecma_builtin_regexp_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_regexp_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_regexp_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_eval_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_eval_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_eval_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_eval_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_eval_error_property_descriptor_list[]; ecma_value_t ecma_builtin_eval_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_eval_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_eval_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_range_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_range_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_range_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_range_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_range_error_property_descriptor_list[]; ecma_value_t ecma_builtin_range_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_range_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_range_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_reference_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_reference_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_reference_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_reference_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_reference_error_property_descriptor_list[]; ecma_value_t ecma_builtin_reference_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_reference_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_reference_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_syntax_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_syntax_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_syntax_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_syntax_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_syntax_error_property_descriptor_list[]; ecma_value_t ecma_builtin_syntax_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_syntax_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_syntax_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_type_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_type_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_type_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_type_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_type_error_property_descriptor_list[]; ecma_value_t ecma_builtin_type_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_type_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_type_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_uri_error_prototype_property_descriptor_list[]; ecma_value_t ecma_builtin_uri_error_prototype_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_uri_error_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_uri_error_prototype_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);
//extern const ecma_builtin_property_descriptor_t ecma_builtin_uri_error_property_descriptor_list[]; ecma_value_t ecma_builtin_uri_error_dispatch_call (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_uri_error_dispatch_construct (const ecma_value_t *, ecma_length_t); ecma_value_t ecma_builtin_uri_error_dispatch_routine (uint16_t builtin_routine_id, ecma_value_t this_arg_value, const ecma_value_t [], ecma_length_t);

#endif /* !ECMA_BUILTINS_INTERNAL_H */

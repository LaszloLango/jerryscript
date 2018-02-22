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

#include "ecma-builtin-error.h"
#include "ecma-builtin-error-prototype.h"
#include "ecma-builtin-function.h"
#include "ecma-builtin-function-prototype.h"
#include "ecma-builtin-global.h"
#include "ecma-builtin-object.h"
#include "ecma-builtin-object-prototype.h"
#include "ecma-builtin-type-error-thrower.h"

typedef ecma_value_t (*ecma_builtin_call_t)(const ecma_value_t argv[],
                                            ecma_length_t argc);

typedef struct
{
  ecma_builtin_call_t call;
  ecma_builtin_call_t construct;
  const ecma_builtin_property_descriptor_t *property_list;
  ecma_object_type_t type;
  ecma_builtin_id_t prototype_id;
  bool is_extensible;
} ecma_builtin_t;

static const ecma_builtin_t ecma_builtins[] =
{
  {
    NULL,
    NULL,
    ecma_builtin_object_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID__COUNT /* no prototype */,
    true
  },
  {
    ecma_builtin_object_dispatch_call,
    ecma_builtin_object_dispatch_construct,
    ecma_builtin_object_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
#if 0
  {
    ecma_builtin_array_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_array_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_ARRAY,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_array_dispatch_routine,
    ecma_builtin_array_dispatch_call,
    ecma_builtin_array_dispatch_construct,
    ecma_builtin_array_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_string_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_string_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_CLASS,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_string_dispatch_routine,
    ecma_builtin_string_dispatch_call,
    ecma_builtin_string_dispatch_construct,
    ecma_builtin_string_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_boolean_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_boolean_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_CLASS,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_boolean_dispatch_routine,
    ecma_builtin_boolean_dispatch_call,
    ecma_builtin_boolean_dispatch_construct,
    ecma_builtin_boolean_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_number_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_number_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_CLASS,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_number_dispatch_routine,
    ecma_builtin_number_dispatch_call,
    ecma_builtin_number_dispatch_construct,
    ecma_builtin_number_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
#endif
  {
    ecma_builtin_function_prototype_dispatch_call,
    ecma_builtin_function_prototype_dispatch_construct,
    ecma_builtin_function_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_function_dispatch_call,
    ecma_builtin_function_dispatch_construct,
    ecma_builtin_function_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
#if 0
  {
    ecma_builtin_math_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_math_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_json_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_json_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_date_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_date_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_CLASS,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_date_dispatch_routine,
    ecma_builtin_date_dispatch_call,
    ecma_builtin_date_dispatch_construct,
    ecma_builtin_date_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_regexp_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_regexp_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_CLASS,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_regexp_dispatch_routine,
    ecma_builtin_regexp_dispatch_call,
    ecma_builtin_regexp_dispatch_construct,
    ecma_builtin_regexp_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
#endif
  {
    ecma_builtin_error_dispatch_call,
    ecma_builtin_error_dispatch_construct,
    ecma_builtin_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    NULL,
    NULL,
    ecma_builtin_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
#if 0
  {
    ecma_builtin_eval_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_eval_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_eval_error_dispatch_routine,
    ecma_builtin_eval_error_dispatch_call,
    ecma_builtin_eval_error_dispatch_construct,
    ecma_builtin_eval_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_range_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_range_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_range_error_dispatch_routine,
    ecma_builtin_range_error_dispatch_call,
    ecma_builtin_range_error_dispatch_construct,
    ecma_builtin_range_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_reference_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_reference_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_reference_error_dispatch_routine,
    ecma_builtin_reference_error_dispatch_call,
    ecma_builtin_reference_error_dispatch_construct,
    ecma_builtin_reference_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_syntax_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_syntax_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_syntax_error_dispatch_routine,
    ecma_builtin_syntax_error_dispatch_call,
    ecma_builtin_syntax_error_dispatch_construct,
    ecma_builtin_syntax_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_type_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_type_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_type_error_dispatch_routine,
    ecma_builtin_type_error_dispatch_call,
    ecma_builtin_type_error_dispatch_construct,
    ecma_builtin_type_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
  {
    ecma_builtin_uri_error_prototype_dispatch_routine,
    NULL,
    NULL,
    ecma_builtin_uri_error_prototype_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  },
  {
    ecma_builtin_uri_error_dispatch_routine,
    ecma_builtin_uri_error_dispatch_call,
    ecma_builtin_uri_error_dispatch_construct,
    ecma_builtin_uri_error_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    true
  },
#endif
  {
    ecma_builtin_type_error_thrower_dispatch_call,
    ecma_builtin_type_error_thrower_dispatch_construct,
    ecma_builtin_type_error_thrower_property_descriptor_list,
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
    false
  },
  {
    NULL,
    NULL,
    ecma_builtin_global_property_descriptor_list,
    ECMA_OBJECT_TYPE_GENERAL,
    ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
    true
  }
};

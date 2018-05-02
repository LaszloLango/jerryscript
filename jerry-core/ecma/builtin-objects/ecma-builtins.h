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

#ifndef ECMA_BUILTINS_H
#define ECMA_BUILTINS_H

#include "ecma-globals.h"

/**
 * Get routine length
 */
#define ECMA_GET_ROUTINE_LENGTH(value) ((uint8_t) (((value) & 0xE0) >> 5))

/**
 * Set routine length
 */
#define ECMA_SET_ROUTINE_LENGTH(value) ((uint8_t) ((value) << 5))

/**
 * Get routine ID
 */
#define ECMA_GET_ROUTINE_ID(value) ((uint16_t) ((value) >> 4))

/**
 * Construct a fully accessor value
 */
#define ECMA_ACCESSOR_READ_WRITE(getter, setter) (((getter) << 8) | (setter))

/**
 * Get accessor setter ID
 */
#define ECMA_ACCESSOR_READ_WRITE_GET_SETTER_ID(value) ((uint16_t) ((value) & 0xff))

/**
 * Get accessor getter ID
 */
#define ECMA_ACCESSOR_READ_WRITE_GET_GETTER_ID(value) ((uint16_t) ((value) >> 8))

typedef enum
{
  ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
  ECMA_BUILTIN_ID_OBJECT,
#ifndef CONFIG_DISABLE_ARRAY_BUILTIN
  ECMA_BUILTIN_ID_ARRAY_PROTOTYPE,
  ECMA_BUILTIN_ID_ARRAY,
#endif /* !CONFIG_DISABLE_ARRAY_BUILTIN*/
#ifndef CONFIG_DISABLE_STRING_BUILTIN
  ECMA_BUILTIN_ID_STRING_PROTOTYPE,
  ECMA_BUILTIN_ID_STRING,
#endif /* !CONFIG_DISABLE_STRING_BUILTIN */
#ifndef CONFIG_DISABLE_BOOLEAN_BUILTIN
  ECMA_BUILTIN_ID_BOOLEAN_PROTOTYPE,
  ECMA_BUILTIN_ID_BOOLEAN,
#endif /* !CONFIG_DISABLE_BOOLEAN_BUILTIN */
#ifndef CONFIG_DISABLE_NUMBER_BUILTIN
  ECMA_BUILTIN_ID_NUMBER_PROTOTYPE,
  ECMA_BUILTIN_ID_NUMBER,
#endif /* !CONFIG_DISABLE_NUMBER_BUILTIN */
  ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE,
  ECMA_BUILTIN_ID_FUNCTION,
#ifndef CONFIG_DISABLE_MATH_BUILTIN
  ECMA_BUILTIN_ID_MATH,
#endif /* !CONFIG_DISABLE_MATH_BUILTIN */
#ifndef CONFIG_DISABLE_JSON_BUILTIN
  ECMA_BUILTIN_ID_JSON,
#endif /* !CONFIG_DISABLE_JSON_BUILTIN */
#ifndef CONFIG_DISABLE_DATE_BUILTIN
  ECMA_BUILTIN_ID_DATE_PROTOTYPE,
  ECMA_BUILTIN_ID_DATE,
#endif /* !CONFIG_DISABLE_DATE_BUILTIN */
#ifndef CONFIG_DISABLE_REGEXP_BUILTIN
  ECMA_BUILTIN_ID_REGEXP_PROTOTYPE,
  ECMA_BUILTIN_ID_REGEXP,
#endif /* !CONFIG_DISABLE_REGEXP_BUILTIN */
  ECMA_BUILTIN_ID_ERROR,
  ECMA_BUILTIN_ID_ERROR_PROTOTYPE,
#ifndef CONFIG_DISABLE_ERROR_BUILTINS
  ECMA_BUILTIN_ID_EVAL_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_EVAL_ERROR,
  ECMA_BUILTIN_ID_RANGE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_RANGE_ERROR,
  ECMA_BUILTIN_ID_REFERENCE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_REFERENCE_ERROR,
  ECMA_BUILTIN_ID_SYNTAX_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_SYNTAX_ERROR,
  ECMA_BUILTIN_ID_TYPE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_TYPE_ERROR,
  ECMA_BUILTIN_ID_URI_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_URI_ERROR,
#endif /* !CONFIG_DISABLE_ERROR_BUILTINS */
  ECMA_BUILTIN_ID_TYPE_ERROR_THROWER,
  ECMA_BUILTIN_ID_GLOBAL,
  ECMA_BUILTIN_ID__COUNT
} ecma_builtin_id_t;

/**
 * Type of built-in properties.
 */
typedef enum
{
  ECMA_BUILTIN_PROPERTY_SIMPLE, /**< simple value property */
  ECMA_BUILTIN_PROPERTY_NUMBER, /**< number value property */
  ECMA_BUILTIN_PROPERTY_STRING, /**< string value property */
  ECMA_BUILTIN_PROPERTY_OBJECT, /**< builtin object property */
  ECMA_BUILTIN_PROPERTY_ROUTINE, /**< routine property */
  ECMA_BUILTIN_PROPERTY_ACCESSOR_READ_WRITE, /**< full accessor property */
  ECMA_BUILTIN_PROPERTY_ACCESSOR_READ_ONLY, /**< read-only accessor property */
  ECMA_BUILTIN_PROPERTY_END, /**< last property */
} ecma_builtin_property_type_t;

/**
 * Function pointer of built-in routines
 */
typedef ecma_value_t (*ecma_builtin_routine0_t)(ecma_value_t this_arg);

typedef ecma_value_t (*ecma_builtin_routine1_t)(ecma_value_t this_arg,
                                                ecma_value_t arg);

typedef ecma_value_t (*ecma_builtin_routine2_t)(ecma_value_t this_arg,
                                               ecma_value_t arg1,
                                               ecma_value_t arg2);

typedef ecma_value_t (*ecma_builtin_routine_non_fixed_t)(ecma_value_t this_arg,
                                                         const ecma_value_t argv[],
                                                         ecma_length_t argc);
/**
 * Description of built-in properties.
 */
typedef struct
{
  uint16_t magic_string_id; /**< name of the property */
  uint8_t type; /**< type of the property */
  uint8_t attributes; /**< attributes of the property */
  union {
    void *routine_p;
//    ecma_builtin_routine0_t *routine0_p; /**< pointer to the builtin routine */
//    ecma_builtin_routine1_t *routine1_p; /**< pointer to the builtin routine */
//    ecma_builtin_routine2_t *routine2_p; /**< pointer to the builtin routine */
//    ecma_builtin_routine_non_fixed_t *routine_non_fixed_p; /**< pointer to the builtin routine */
    uint16_t value; /**< value of the property */
  } u;
} ecma_builtin_property_descriptor_t;

/* ecma-builtins.c */
void ecma_finalize_builtins (void);

ecma_value_t
ecma_builtin_dispatch_call (ecma_object_t *obj_p, ecma_value_t this_arg_value,
                            const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_value_t
ecma_builtin_dispatch_construct (ecma_object_t *obj_p,
                                 const ecma_value_t *arguments_list_p, ecma_length_t arguments_list_len);
ecma_property_t *
ecma_builtin_try_to_instantiate_property (ecma_object_t *object_p, ecma_string_t *string_p);
void
ecma_builtin_list_lazy_property_names (ecma_object_t *object_p,
                                       bool separate_enumerable,
                                       ecma_collection_header_t *main_collection_p,
                                       ecma_collection_header_t *non_enum_collection_p);
bool
ecma_builtin_is (ecma_object_t *obj_p, ecma_builtin_id_t builtin_id);
ecma_object_t *
ecma_builtin_get (ecma_builtin_id_t builtin_id);
bool
ecma_builtin_function_is_routine (ecma_object_t *func_obj_p);

#endif /* !ECMA_BUILTINS_H */

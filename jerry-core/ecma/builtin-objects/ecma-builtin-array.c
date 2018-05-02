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

#include "ecma-alloc.h"
#include "ecma-builtin-array.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-array-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#ifndef CONFIG_DISABLE_ARRAY_BUILTIN

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup array ECMA Array object built-in
 * @{
 */

/**
 * The Array object's 'isArray' routine
 *
 * See also:
 *          ECMA-262 v5, 15.4.3.2
 *
 * @return ecma value
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_array_object_is_array (ecma_value_t this_arg, /**< 'this' argument */
                                    ecma_value_t arg) /**< first argument */
{
  JERRY_UNUSED (this_arg);
  ecma_value_t is_array = ECMA_VALUE_FALSE;

  if (ecma_is_value_object (arg))
  {
    ecma_object_t *obj_p = ecma_get_object_from_value (arg);

    if (ecma_object_get_class_name (obj_p) == LIT_MAGIC_STRING_ARRAY_UL)
    {
      is_array = ECMA_VALUE_TRUE;
    }
  }

  return is_array;
} /* ecma_builtin_array_object_is_array */

/**
 * Handle calling [[Call]] of built-in Array object
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_array_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                  ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  return ecma_builtin_array_dispatch_construct (arguments_list_p, arguments_list_len);
} /* ecma_builtin_array_dispatch_call */

/**
 * Handle calling [[Construct]] of built-in Array object
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_array_dispatch_construct (const ecma_value_t *arguments_list_p, /**< arguments list */
                                       ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  return ecma_op_create_array_object (arguments_list_p, arguments_list_len, true);
} /* ecma_builtin_array_dispatch_construct */

const ecma_builtin_property_descriptor_t
ecma_builtin_array_property_descriptor_list[] =
{
{ LIT_MAGIC_STRING_PROTOTYPE, ECMA_BUILTIN_PROPERTY_OBJECT, ECMA_PROPERTY_FIXED, { .value = ECMA_BUILTIN_ID_ARRAY_PROTOTYPE } },
{ LIT_MAGIC_STRING_LENGTH, ECMA_BUILTIN_PROPERTY_NUMBER, ECMA_PROPERTY_FIXED, { .value = 1 } },
{ LIT_MAGIC_STRING_IS_ARRAY_UL, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (1)), { ecma_builtin_array_object_is_array } },
{ LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

#endif /* !CONFIG_DISABLE_ARRAY_BUILTIN */


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

#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-arraybuffer-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#ifndef CONFIG_DISABLE_ES2015_TYPEDARRAY_BUILTIN

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup arraybuffer ECMA ArrayBuffer object built-in
 * @{
 */

/**
 * The ArrayBuffer object's 'isView' routine
 *
 * See also:
 *         ES2015 24.1.3.1
 *
 * @return ecma value
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_arraybuffer_object_is_view (ecma_value_t this_arg, /**< 'this' argument */
                                         ecma_value_t arg) /**< argument 1 */
{
  JERRY_UNUSED (this_arg);
  JERRY_UNUSED (arg);

  /* TODO: if arg has [[ViewArrayBuffer]], return true */

  return ecma_make_boolean_value (false);
} /* ecma_builtin_arraybuffer_object_is_view */

/**
 * Handle calling [[Call]] of built-in ArrayBuffer object
 *
 * ES2015 24.1.2 ArrayBuffer is not intended to be called as
 * a function and will throw an exception when called in
 * that manner.
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_arraybuffer_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                        ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  return ecma_raise_type_error (ECMA_ERR_MSG ("Constructor ArrayBuffer requires 'new'"));
} /* ecma_builtin_arraybuffer_dispatch_call */

/**
 * Handle calling [[Construct]] of built-in ArrayBuffer object
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_arraybuffer_dispatch_construct (const ecma_value_t *arguments_list_p, /**< arguments list */
                                             ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  return ecma_op_create_arraybuffer_object (arguments_list_p, arguments_list_len);
} /* ecma_builtin_arraybuffer_dispatch_construct */

const ecma_builtin_property_descriptor_t
ecma_builtin_arraybuffer_property_descriptor_list[] =
{
{ LIT_MAGIC_STRING_LENGTH, ECMA_BUILTIN_PROPERTY_NUMBER, ECMA_PROPERTY_FIXED, { .value = 1 } },
{ LIT_MAGIC_STRING_PROTOTYPE, ECMA_BUILTIN_PROPERTY_OBJECT, ECMA_PROPERTY_FIXED, { .value = ECMA_BUILTIN_ID_ARRAYBUFFER_PROTOTYPE } },
{ LIT_MAGIC_STRING_IS_VIEW_UL, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (1)), { ecma_builtin_arraybuffer_object_is_view } },
{ LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

#endif /* !CONFIG_DISABLE_ES2015_TYPEDARRAY_BUILTIN */

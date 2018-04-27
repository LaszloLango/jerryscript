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
#include "ecma-builtin-type-error-thrower.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup type_error_thrower ECMA [[ThrowTypeError]] object built-in
 * @{
 */

/**
 * Handle calling [[Call]] of built-in [[ThrowTypeError]] object
 *
 * See also:
 *          ECMA-262 v5, 13.2.3
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_type_error_thrower_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                               ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  /* The object should throw TypeError */
  return ecma_raise_type_error (ECMA_ERR_MSG (""));
} /* ecma_builtin_type_error_thrower_dispatch_call */

/**
 * Handle calling [[Construct]] of built-in [[ThrowTypeError]] object
 *
 * See also:
 *          ECMA-262 v5, 13.2.3
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_type_error_thrower_dispatch_construct (const ecma_value_t *arguments_list_p, /**< arguments list */
                                                    ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  /* The object is not a constructor */
  return ecma_raise_type_error (ECMA_ERR_MSG (""));
} /* ecma_builtin_type_error_thrower_dispatch_construct */

/*
 * [[ThrowTypeError]] description
 *
 * See also: ECMA-262 v5, 13.2.3
 */
const ecma_builtin_property_descriptor_t
ecma_builtin_type_error_thrower_property_descriptor_list[] =
{
  { LIT_MAGIC_STRING_LENGTH, ECMA_BUILTIN_PROPERTY_NUMBER, 0, { .value = 0 } },
  { LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

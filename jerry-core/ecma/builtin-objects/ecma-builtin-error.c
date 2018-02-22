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
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-builtin-helpers.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#include "ecma-builtin-error.h"

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup error ECMA Error object built-in
 * @{
 */

/**
 * Handle calling [[Call]] of built-in Error object
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_error_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                  ecma_length_t arguments_list_len) /**< number of arguments */
{
  return ecma_builtin_helper_error_dispatch_call (ECMA_ERROR_COMMON, arguments_list_p, arguments_list_len);
} /* ecma_builtin_error_dispatch_call */

/**
 * Handle calling [[Construct]] of built-in Error object
 *
 * @return ecma value
 */
ecma_value_t
ecma_builtin_error_dispatch_construct (const ecma_value_t *arguments_list_p, /**< arguments list */
                                       ecma_length_t arguments_list_len) /**< number of arguments */
{
  return ecma_builtin_error_dispatch_call (arguments_list_p, arguments_list_len);
} /* ecma_builtin_error_dispatch_construct */

/*
 * Error built-in description
 */
const ecma_builtin_property_descriptor_t
ecma_builtin_error_property_descriptor_list[] =
{
  /* ECMA-262 v5, 15.11.3 */
  { LIT_MAGIC_STRING_LENGTH, ECMA_BUILTIN_PROPERTY_NUMBER, 0, { .value = 1 } },
  /* ECMA-262 v5, 15.7.3.1 */
  { LIT_MAGIC_STRING_PROTOTYPE,
    ECMA_BUILTIN_PROPERTY_OBJECT,
    0,
    { .value = ECMA_BUILTIN_ID_ERROR_PROTOTYPE }
  },
  { LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

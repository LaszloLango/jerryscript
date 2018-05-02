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

#include "ecma-globals.h"
#include "ecma-promise-object.h"

#ifndef CONFIG_DISABLE_ES2015_PROMISE_BUILTIN

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup promiseprototype ECMA Promise.prototype object built-in
 * @{
 */

/**
 * Promise routine: then.
 *
 * See also: 25.4.5.3
 *
 * @return ecma value of a new promise object.
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_promise_prototype_then (ecma_value_t this_arg, /**< this argument */
                                     ecma_value_t on_fulfilled, /**< on_fulfilled function */
                                     ecma_value_t on_rejected) /**< on_rejected function */
{
  return ecma_promise_then (this_arg,
                            on_fulfilled,
                            on_rejected);
} /* ecma_builtin_promise_prototype_then */

/**
 * Promise routine: catch.
 *
 * See also: 25.4.5.1
 *
 * @return ecma value of a new promise object.
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_promise_prototype_catch (ecma_value_t this_arg, /**< this argument */
                                      ecma_value_t on_rejected) /**< on_rejected function */
{
  return ecma_promise_then (this_arg,
                            ECMA_VALUE_UNDEFINED,
                            on_rejected);
} /* ecma_builtin_promise_prototype_catch */

const ecma_builtin_property_descriptor_t
ecma_builtin_promise_prototype_property_descriptor_list[] =
{
{ LIT_MAGIC_STRING_CONSTRUCTOR, ECMA_BUILTIN_PROPERTY_OBJECT, ECMA_PROPERTY_CONFIGURABLE_WRITABLE, { .value = ECMA_BUILTIN_ID_PROMISE } },
{ LIT_MAGIC_STRING_LENGTH, ECMA_BUILTIN_PROPERTY_NUMBER, ECMA_PROPERTY_FLAG_WRITABLE, { .value = 1 } },
{ LIT_MAGIC_STRING_THEN, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (2)), { ecma_builtin_promise_prototype_then } },
{ LIT_MAGIC_STRING_CATCH, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (1)), { ecma_builtin_promise_prototype_catch } },
{ LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

#endif /* !CONFIG_DISABLE_ES2015_PROMISE_BUILTIN */

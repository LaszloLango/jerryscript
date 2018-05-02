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
#include "ecma-builtin-evalerror-prototype.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-string-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#ifndef CONFIG_DISABLE_ERROR_BUILTINS

const ecma_builtin_property_descriptor_t
ecma_builtin_eval_error_prototype_property_descriptor_list[] =
{
{ LIT_MAGIC_STRING_CONSTRUCTOR, ECMA_BUILTIN_PROPERTY_OBJECT, ECMA_PROPERTY_CONFIGURABLE_WRITABLE, { .value = ECMA_BUILTIN_ID_EVAL_ERROR } },
{ LIT_MAGIC_STRING_NAME, ECMA_BUILTIN_PROPERTY_STRING, ECMA_PROPERTY_CONFIGURABLE_WRITABLE, { .value = LIT_MAGIC_STRING_EVAL_ERROR_UL } },
{ LIT_MAGIC_STRING_MESSAGE, ECMA_BUILTIN_PROPERTY_STRING, ECMA_PROPERTY_CONFIGURABLE_WRITABLE, { .value = LIT_MAGIC_STRING__EMPTY } },
{ LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

#endif /* !CONFIG_DISABLE_ERROR_BUILTINS */

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

#ifndef ECMA_BUILTIN_ARRAY_PROTOTYPE_H
#define ECMA_BUILTIN_ARRAY_PROTOTYPE_H

#include "ecma-globals.h"
#include "ecma-builtins.h"

extern const ecma_builtin_property_descriptor_t ecma_builtin_array_prototype_property_descriptor_list[];
ecma_value_t ecma_builtin_array_prototype_dispatch_call (const ecma_value_t *, ecma_length_t);
ecma_value_t ecma_builtin_array_prototype_dispatch_construct (const ecma_value_t *, ecma_length_t);

#endif /* !ECMA_BUILTIN_ARRAY_PROTOTYPE_H */


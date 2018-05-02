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
#include "ecma-objects.h"
#include "ecma-string-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"

#ifndef CONFIG_DISABLE_BOOLEAN_BUILTIN

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltins
 * @{
 *
 * \addtogroup booleanprototype ECMA Boolean.prototype object built-in
 * @{
 */

/**
 * The Boolean.prototype object's 'valueOf' routine
 *
 * See also:
 *          ECMA-262 v5, 15.6.4.3
 *
 * @return ecma value
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_boolean_prototype_object_value_of (ecma_value_t this_arg) /**< this argument */
{
  if (ecma_is_value_boolean (this_arg))
  {
    return this_arg;
  }
  else if (ecma_is_value_object (this_arg))
  {
    ecma_object_t *object_p = ecma_get_object_from_value (this_arg);

    if (ecma_object_class_is (object_p, LIT_MAGIC_STRING_BOOLEAN_UL))
    {
      ecma_extended_object_t *ext_object_p = (ecma_extended_object_t *) object_p;

      JERRY_ASSERT (ecma_is_value_boolean (ext_object_p->u.class_prop.u.value));

      return ext_object_p->u.class_prop.u.value;
    }
  }

  return ecma_raise_type_error (ECMA_ERR_MSG ("Argument 'this' is not a Boolean object."));
} /* ecma_builtin_boolean_prototype_object_value_of */

/**
 * The Boolean.prototype object's 'toString' routine
 *
 * See also:
 *          ECMA-262 v5, 15.6.4.2
 *
 * @return ecma value
 *         Returned value must be freed with ecma_free_value.
 */
static ecma_value_t
ecma_builtin_boolean_prototype_object_to_string (ecma_value_t this_arg) /**< this argument */
{
  ecma_value_t ret_value = ECMA_VALUE_EMPTY;

  ECMA_TRY_CATCH (value_of_ret,
                  ecma_builtin_boolean_prototype_object_value_of (this_arg),
                  ret_value);

  if (ecma_is_value_true (value_of_ret))
  {
    ret_value = ecma_make_magic_string_value (LIT_MAGIC_STRING_TRUE);
  }
  else
  {
    JERRY_ASSERT (ecma_is_value_boolean (value_of_ret));

    ret_value = ecma_make_magic_string_value (LIT_MAGIC_STRING_FALSE);
  }

  ECMA_FINALIZE (value_of_ret);

  return ret_value;
} /* ecma_builtin_boolean_prototype_object_to_string */

const ecma_builtin_property_descriptor_t
ecma_builtin_boolean_prototype_property_descriptor_list[] =
{
{ LIT_MAGIC_STRING_CONSTRUCTOR, ECMA_BUILTIN_PROPERTY_OBJECT, ECMA_PROPERTY_CONFIGURABLE_WRITABLE, { .value = ECMA_BUILTIN_ID_BOOLEAN } },
{ LIT_MAGIC_STRING_TO_STRING_UL, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (0)), { ecma_builtin_boolean_prototype_object_to_string } },
{ LIT_MAGIC_STRING_VALUE_OF_UL, ECMA_BUILTIN_PROPERTY_ROUTINE, (ECMA_PROPERTY_FLAG_CONFIGURABLE | ECMA_PROPERTY_FLAG_WRITABLE | ECMA_SET_ROUTINE_LENGTH (0)), { ecma_builtin_boolean_prototype_object_value_of } },
{ LIT_MAGIC_STRING__COUNT, ECMA_BUILTIN_PROPERTY_END, 0, { .value = 0 } }
};

/**
 * @}
 * @}
 * @}
 */

#endif /* !CONFIG_DISABLE_BOOLEAN_BUILTIN */

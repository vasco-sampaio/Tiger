/**
 ** \file bind/tasks.hh
 ** \brief Bind module related tasks.
 */

// DONE: Some code was deleted here.

#pragma once

#include <task/libtask.hh>

namespace ast::tasks
{
  TASK_GROUP("3. Binder");

  TASK_DECLARE("B|bindings-display", "display binding addresses", display_bindings, "parse");

} // namespace ast::tasks
/**
 ** \file bind/tasks.hh
 ** \brief Bind module related tasks.
 */

// DONE: Some code was deleted here.

#pragma once

#include <task/libtask.hh>

namespace bind::tasks
{
  TASK_GROUP("3. Bind");

  TASK_DECLARE("bound",
               "default the computation of bindings to Tiger\n(without objects nor overloading)",
               bound,
               "parse");

  TASK_DECLARE("B|bindings-display",
               "enable bindings display in the AST",
               display_bindings,
               "parse");

  TASK_DECLARE("b|bindings-compute",
               "bind the identifiers",
               compute_bindings,
               "parse");

  TASK_DECLARE("rename",
               "rename identifiers to unique names",
               rename,
               "bindings-compute");

} // namespace ast::tasks
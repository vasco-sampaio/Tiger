/**
 ** \file bind/tasks.cc
 ** \brief Bind module tasks implementation.
 */

// DONE: Some code was deleted here.

#include <ast/libast.hh>
#include <misc/contract.hh>
#include <bind/libbind.hh>
#include <ast/tasks.hh>

#define DEFINE_TASKS 1
#include <bind/tasks.hh>
#undef DEFINE_TASKS

namespace bind::tasks
{
  void display_bindings()
  {
    ast::bindings_display(std::cout) = true;
  }

  void compute_bindings()
  {
    misc::error e = bind::bind(*ast::tasks::the_program);
    e.exit_on_error();
  }

  void rename()
  {
    bind::rename(*ast::tasks::the_program);
  }

} // namespace ast::tasks
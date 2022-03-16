/**
 ** \file bind/tasks.cc
 ** \brief Bind module tasks implementation.
 */

// DONE: Some code was deleted here.

#include <ast/libast.hh>
#include <misc/contract.hh>
#define DEFINE_TASKS 1
#include <ast/tasks.hh>
#undef DEFINE_TASKS

#include <bind/libbind.hh>

namespace ast::tasks
{
  void display_bindings()
  {
    ast::bindings_display(std::cout) = true;
  }

  void compute_bindings()
  {
    bind::bind(*the_program);
  }

  void rename()
  {
    
  }

} // namespace ast::tasks
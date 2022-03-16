/**
 ** \file bind/renamer.hxx
 ** \brief Template methods of bind::Renamer.
 */

#pragma once

#include <bind/renamer.hh>

namespace bind
{
  // DONE: Some code was deleted here.
  template <typename Def>
  inline misc::symbol Renamer::new_name_compute(const Def& e)
  {
    misc::symbol newName = e.name_get().fresh(e.name_get());
    return newName;
  }

  template <class E, class Def> void Renamer::visit(E& e, const Def* def)
  {
    // FIXME: Some code was deleted here.
  }

} // namespace bind

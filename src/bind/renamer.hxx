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

  template <typename Def> 
  inline misc::symbol Renamer::new_name(const Def& e)
  {
    if (new_names_.contains(&e))
      return new_names_.at(&e);
    else
      return new_name_compute(e);
  }

  template <class E, class Def>
  void Renamer::visit(E& e, const Def* def)
  {
    // DONE: Some code was deleted here.
    if (new_names_.contains(def))
      {
        e.name_set(new_names_.at(def));
      }
  }

  // DEBUG: print map of renamer
  inline void Renamer::map_dump()
  {
    for (auto i = new_names_.begin(); i != new_names_.end(); ++i)
    {
      std::cout << "Name: " << i->second << "\tAddress: " << i->first << "\n";
    }
  }

} // namespace bind

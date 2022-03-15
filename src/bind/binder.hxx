/**
 ** \file bind/binder.hxx
 ** \brief Inline methods of bind::Binder.
 **/

#pragma once

#include <bind/binder.hh>

namespace bind
{
  /*-----------------.
  | Error handling.  |
  `-----------------*/

  // FIXME: Some code was deleted here (Error reporting).

  /*----------------------------.
  | Visiting /ChunkInterface/.  |
  `----------------------------*/

  template <class D> void Binder::chunk_visit(ast::Chunk<D>& e)
  {
    // Shorthand.
    using chunk_type = ast::Chunk<D>;
    // DONE: Some code was deleted here (Two passes: once on headers, then on bodies).
    for (auto elt : e.decs_get())
    {
      visit_dec_header(elt);
      visit_dec_body(elt);
    }
  }

  /// Check a Function or Type declaration header.
  template <class D> void visit_dec_header(D& e)
  {
    
  }

  /// Check a Function or Type declaration body.
  template <class D> void visit_dec_body(D& e)
  {

  }
  
  /* These specializations are in bind/binder.hxx, so that derived
     visitors can use them (otherwise, they wouldn't see them).  */

  // FIXME: Some code was deleted here.

} // namespace bind

/**
 ** \file misc/symbol.hxx
 ** \brief Inline implementation of misc::symbol.
 */

#pragma once

#include <misc/symbol.hh>

namespace misc
{
  inline symbol& symbol::operator=(const symbol& rhs)
  {
    // DONE: Some code was deleted here.
    obj_ = rhs.obj_;
    return *this;
  }

  inline bool symbol::operator==(const symbol& rhs) const
  {
    // DONE: Some code was deleted here.
    return unique::operator==(rhs);
  }

  inline bool symbol::operator!=(const symbol& rhs) const
  {
    // DONE: Some code was deleted here.
    return unique::operator!=(rhs);
  }

  inline std::ostream& operator<<(std::ostream& ostr, const symbol& the)
  {
    // DONE: Some code was deleted here.
    ostr << the;
    return ostr;
  }

} // namespace misc

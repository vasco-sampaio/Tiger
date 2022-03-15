/**
 ** \file misc/scoped-map.hh
 ** \brief Declaration of misc::scoped_map.
 **
 ** This implements a stack of dictionnaries.  Each time a scope is
 ** opened, a new dictionnary is added on the top of the stack; the
 ** dictionary is removed when the scope is closed.  Lookup of keys
 ** is done in the last added dictionnary first (LIFO).
 **
 ** In particular this class is used to implement symbol tables.
 **/

#pragma once

#include <map>
#include <vector>

namespace misc
{
  template <typename Key, typename Data> class scoped_map
  {
    // DONE: Some code was deleted here.
  public:
    // Associate value to key in the current scope
    void put(const Key& key, const Data& value);

    // If key was associated to some Data in the open scoped, 
    // return the most recent insertion. 
    // Otherwise, if Data is a pointer type, then return the empty pointer, 
    // else throw a std::range_error. To implement this feature, see <type_traits>.
    Data get(const Key &key) const;

    // Send the content of this table on ostr in a human-readable manner,
    // and return the stream.
    std::ostream& dump(std::ostream& ostr) const;

    // Open a new scope.
    void scope_begin();

    // Close the last scope, forgetting everything since the latest scope_begin()
    void scope_end();

  private:
    // Top of the stack is the last element
    std::vector<std::map<Key, Data>> stack_;
  };

  template <typename Key, typename Data>
  std::ostream& operator<<(std::ostream& ostr,
                           const scoped_map<Key, Data>& tbl);

  // FIXME: Some code was deleted here.

} // namespace misc

#include <misc/scoped-map.hxx>

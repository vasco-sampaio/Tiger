/** \file misc/scoped-map.hxx
 ** \brief Implementation of misc::scoped_map.
 */

#pragma once

#include <sstream>
#include <stdexcept>
#include <type_traits>

#include <misc/algorithm.hh>
#include <misc/contract.hh>
#include <misc/indent.hh>
#include <range/v3/view/reverse.hpp>

namespace misc
{
  // DONE: Some code was deleted here.
  template <typename Key, typename Data>
  inline void scoped_map<Key, Data>::put(const Key& key, const Data& value)
  {
    stack_.rbegin()->insert(std::pair<Key, Data>(key, value));
  }

  template <typename Key, typename Data>
  inline Data scoped_map<Key, Data>::get(const Key& key) const
  {
    for (auto i = stack_.rbegin(); i != stack_.rend(); i++)
    {
      auto find = i->find(key);
      if (find != i->end())
        return find->second;
    }
    if constexpr (std::is_pointer_v<Key>)
      return nullptr;
    throw std::range_error("Data not found");
  }

  template <typename Key, typename Data>
  inline std::ostream& scoped_map<Key, Data>::dump(std::ostream& ostr) const
  {
    for (auto i = stack_.rbegin(); i != stack_.rend(); i++)
    {
      for (auto j = i->begin(); j != i->end(); j++)
      {
        ostr << '(' << j->first << ',' << j->second << ") ";
      }
      ostr << '\n';
    }
    return ostr;
  }

  template <typename Key, typename Data> 
  inline void scoped_map<Key, Data>::scope_begin()
  {
    stack_.push_back(std::map<Key,Data>());
  }

  template <typename Key, typename Data>
  inline void scoped_map<Key, Data>::scope_end()
  {
    stack_.erase(stack_.end() - 1);
  }

    template <typename Key, typename Data>
    inline std::ostream& operator<<(std::ostream& ostr,
                                    const scoped_map<Key, Data>& tbl)
  {
    return tbl.dump(ostr);
  }

  template <typename Key, typename Data> 
  inline int scoped_map<Key, Data>::size_get()
  {
    int res = 0;
    for (auto i = stack_.rbegin(); i != stack_.rend(); i++)
    {
      res += i->size();
    }
    return res;
  }

  template <typename Key, typename Data> 
  inline bool scoped_map<Key, Data>::contains(Key key)
  {
    auto find = stack_.rbegin()->find(key);
    if (find != stack_.rbegin()->end())
      return true;
    return false;
  }

} // namespace misc

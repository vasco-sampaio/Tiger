/**
 ** \file misc/unique.hxx
 ** \brief Inline implementation of misc::unique.
 */

#pragma once

#include <misc/contract.hh>
#include <misc/unique.hh>

namespace misc
{
  template <typename T, class C> unique<T, C>::unique(const data_type& s)
  // DONE: Some code was deleted here (Initializations).
    :obj_(&*(object_set_instance().insert(s).first))
  {}

  template <typename T, class C>
  typename unique<T, C>::object_set_type& unique<T, C>::object_set_instance()
  {
    // DONE: Some code was deleted here (Classical Singleton pattern, a la Scott Meyers').
    static object_set_type s;
    return s;
  }

  template <typename T, class C>
  typename unique<T, C>::object_size_type unique<T, C>::object_map_size()
  {
    // DONE: Some code was deleted here.
    return object_set_instance().size();
  }

  template <typename T, class C>
  inline const typename unique<T, C>::data_type& unique<T, C>::get() const
  {
    // DONE: Some code was deleted here.
    return *obj_;
  }

  template <typename T, class C>
  inline unique<T, C>::operator const data_type&() const
  {
    // DONE: Some code was deleted here.
    return get();
  }

  template <typename T, class C>
  inline typename unique<T, C>::value_type&
  unique<T, C>::operator=(const value_type& rhs)
  {
    if (this != &rhs)
      obj_ = rhs.obj_;
    return *this;
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator==(const value_type& rhs) const
  {
    return obj_ == rhs.obj_;
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator!=(const value_type& rhs) const
  {
    return !operator==(rhs);
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator<(const value_type& rhs) const
  {
    C cmp;
    assertion(obj_);
    assertion(rhs.obj_);
    return cmp(*obj_, *rhs.obj_);
  }

  template <typename T, class C>
  inline std::ostream& operator<<(std::ostream& ostr, const unique<T, C>& the)
  {
    return ostr << the.get();
  }

} // namespace misc

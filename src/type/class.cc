/**
 ** \file type/class.cc
 ** \brief Implementation for type/class.hh.
 */

#include <cstddef>
#include <ostream>
#include <vector>

#include <range/v3/algorithm/find.hpp>
#include <type/class.hh>
#include <type/visitor.hh>

namespace type
{
  Class::Class(const Class* super)
    : Type()
    , id_(fresh_id())
    , super_(super)
    , subclasses_()
  {}

  void Class::accept(ConstVisitor& v) const { v(*this); }

  void Class::accept(Visitor& v) { v(*this); }

  const Type* Class::attr_type(misc::symbol key) const
  {
    // DONE: Some code was deleted here.
    for (auto& e : attrs_)
    {
      if (e.name_get() == key)
        return &(e.type_get());
    }
    return nullptr;
  }

  const Type* Class::meth_type(misc::symbol key) const
  {
    // DONE: Some code was deleted here.
    for (auto& e : meths_)
    {
      if (e->name_get() == key)
        return &(e->type_get());
    }
    return nullptr;
  }

  // DONE: Some code was deleted here (Find common super class).
  const Class* Class::common_root(const Class& other) const
  {
    const Class* cur = this;
    while (cur != nullptr)
    {
      const Class* sub = &other;
      while (sub != nullptr)
      {
        if (sub == cur)
          return cur;
        sub = sub->super_get();
      }
      cur = cur->super_get();
    }
    return nullptr;
  }

  // DONE: Some code was deleted here (Super class soundness test).
  bool Class::sound() const
  {
    const Class* cur = this;
    std::vector<const Class*> visited;
    while (cur != nullptr)
    {
      if (std::find(visited.begin(), visited.end(), cur) != visited.end())
        return false;
      visited.push_back(cur);
      cur = cur->super_get();
    }
    return true;
  }

  // DONE: Some code was deleted here (Special implementation of "compatible_with" for Class).
  bool Class::compatible_with(const Type& other) const
  {
    auto otherclass = dynamic_cast<const Class*>(&other);
    if (otherclass == nullptr)
      return false;
    
    attrs_type allAttr;
    meths_type allMeths;


    const Class* cur = this;
    while (cur != nullptr)
    {
      allAttr.insert(allAttr.end(), cur->attrs_get().begin(), cur->attrs_get().end());
      allMeths.insert(allMeths.end(), cur->meths_get().begin(), cur->meths_get().end());
      cur = cur->super_get();
    }

    attrs_type allAttr2;
    meths_type allMeths2;

    cur = otherclass;
    while (cur != nullptr)
    {
      allAttr2.insert(allAttr2.end(), cur->attrs_get().begin(), cur->attrs_get().end());
      allMeths2.insert(allMeths2.end(), cur->meths_get().begin(), cur->meths_get().end());
      cur = cur->super_get();
    }

    for (auto &x : allAttr)
    {
      bool found = false;
      for (auto i = allAttr2.begin(); i != allAttr2.end(); i++)
      {
        if (x.type_get().compatible_with(i->type_get()))
        {
          allAttr2.erase(i);
          found = true;
          break;
        }
      }
      if (!found)
        return false;
    }

    for (auto &x : allMeths)
    {
      bool found = false;
      for (auto i = allMeths2.begin(); i != allMeths2.end(); i++)
      {
        if (x->compatible_with(**i))
        {
          found = true;
          break;
        }
      }
      if (!found)
        return false;
    }

  }

  const Class& Class::object_instance()
  {
    // DONE: Some code was deleted here.
    static Class obj;
    return obj;
  }

  unsigned Class::fresh_id()
  {
    static unsigned counter_ = 0;
    return counter_++;
  }

} // namespace type

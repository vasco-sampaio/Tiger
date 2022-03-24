/**
 ** \file type/record.cc
 ** \brief Implementation for type/record.hh.
 */

#include <ostream>

#include <type/builtin-types.hh>
#include <type/nil.hh>
#include <type/record.hh>
#include <type/visitor.hh>
#include <type/named.hh>

namespace type
{
  void Record::accept(ConstVisitor& v) const { v(*this); }

  void Record::accept(Visitor& v) { v(*this); }

  // FIXME: Some code was deleted here (Field manipulators).

    const Type* Record::field_type(misc::symbol key) const
    {
      for (auto& e : fields_)
      {
        if (e.name_get() == key)
          return &(e.type_get());
      }
      return nullptr;
    }

    int Record::field_index(misc::symbol key) const
    {
      int i = 0;
      for (auto& e : fields_)
      {
        if (e.name_get() == key)
          return i;
        i++;
      }
      return -1;
    }

  // DONE: Some code was deleted here (Special implementation of "compatible_with" for Record).

    bool Record::compatible_with(const Type& other) const
    {
      if (dynamic_cast<const Nil*>(&other) != nullptr)
        return true;
      auto rec = dynamic_cast<const Record*>(&other);
      if (rec == nullptr)
      {
        auto named = dynamic_cast<const Named*>(&other);
        if (named == nullptr)
          return false;
        return this->compatible_with(*(named->type_get()));
      }
      if (fields_.size() != rec->fields_get().size())
        return false;
      if (rec == this)
        return true;
      for (size_t i = 0; i < fields_.size(); i++)
      {
        const Type* t1 = field_type(fields_.at(i).name_get());
        const Type* t2 = rec->field_type(rec->fields_get().at(i).name_get());
        auto r1 = dynamic_cast<const Record*>(t1);
        auto r2 = dynamic_cast<const Record*>(t2);
        if (r1 != nullptr || r2 != nullptr)
        {
          if (dynamic_cast<const Nil*>(t1) != nullptr || dynamic_cast<const Nil*>(t2) != nullptr)
            continue;
          if (r1 == nullptr || r2 == nullptr)
            return false;
          continue;
        }
        if (!t1->compatible_with(*t2))
          return false;
      }
      return true;
    }

} // namespace type

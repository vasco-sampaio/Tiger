/**
 ** \file type/builtin-types.hh
 ** \brief The classes Int, String, Void.
 */
#pragma once

#include <misc/singleton.hh>
#include <type/fwd.hh>
#include <type/type.hh>

namespace type
{
  // DONE: Some code was deleted here (Other types : Int, String, Void).

  class Int : public Type, public misc::Singleton<Int>
  {
    public:
    bool compatible_with(const Type& other) const override;
  };

  class String : public Type, public misc::Singleton<String>
  {
    public:
    bool compatible_with(const Type& other) const override;
  };

  class Void : public Type, public misc::Singleton<Void>
  {
    public:
    bool compatible_with(const Type& other) const override;
  };
} // namespace type

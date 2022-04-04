/**
 ** \file type/builtin-types.hh
 ** \brief The classes Int, String, Void.
 */
#pragma once

#include <ostream>
#include <misc/singleton.hh>
#include <type/fwd.hh>
#include <type/type.hh>

namespace type
{
  // DONE: Some code was deleted here (Other types : Int, String, Void).

  class Int :public misc::Singleton<Int>, public Type
  {
    public:
    bool compatible_with(const Type& other) const override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;
    std::ostream& operator<<(std::ostream& os)
    {
      std::cout << "HERE" << std::endl;
      return os << "int";
    }
  };

  inline std::ostream& operator<<(std::ostream& os, Int&)
  {
    return os << "int";
  }

  class String : public misc::Singleton<String>, public Type
  {
    public:
    bool compatible_with(const Type& other) const override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;
  };

  inline std::ostream& operator<<(std::ostream& os, String&)
  {
    return os << "string";
  }

  class Void : public misc::Singleton<Void>, public Type
  {
    public:
    bool compatible_with(const Type& other) const override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;
  };

  inline std::ostream& operator<<(std::ostream& os, Void&)
  {
    return os << "void";
  }
} // namespace type

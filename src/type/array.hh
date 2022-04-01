/**
 ** \file type/array.hh
 ** \brief The class Array.
 */
#pragma once

#include <type/fwd.hh>
#include <type/type.hh>

namespace type
{
  /// Array types.
  class Array : public Type
  {
    // DONE: Some code was deleted here.
    public:
    
    Array(const Type& elements_type);

    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;

    const Type& elements_type_get() const;

    bool compatible_with(const Type& other) const override;

    private:
      const Type& elements_type_;
  };

} // namespace type

#include <type/array.hxx>

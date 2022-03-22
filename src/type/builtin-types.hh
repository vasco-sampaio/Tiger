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

  class Int : public misc::Singleton<Int>
  {
    public:
      void operator=(const Int&) = delete;
      Int(Int& other) = delete;

    friend class misc::Singleton<Int>; 
    private:
      Int();
      ~Int();
  };

  class String : public misc::Singleton<String>
  {
    public:
      void operator=(const String&) = delete;
      String(String& other) = delete;

    friend class misc::Singleton<String>; 
    private:
      String();
      ~String();
  };

  class Void : public misc::Singleton<Void>
  {
    public:
      void operator=(const Void&) = delete;
      Void(Void& other) = delete;

    friend class misc::Singleton<Void>; 
    private:
      Void();
      ~Void();
  };
} // namespace type

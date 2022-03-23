/**
 ** \file misc/singleton.hh
 ** \brief Generic singleton
 */

#pragma once

namespace misc
{
  template <typename T> class Singleton
  {
    public:
      Singleton(const Singleton&) = delete;
      Singleton(Singleton&&) = delete;
      Singleton& operator=(const Singleton&) = delete;
      Singleton& operator=(Singleton&&) = delete;

      static Singleton& instance()
       {
         static Singleton theSingleInstance;
         return theSingleInstance;
       }
    private:
      Singleton() = default;
  };

} // namespace misc

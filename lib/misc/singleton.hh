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
      static const T& instance()
       {
         static T instance;
         return instance;
       }
  };

} // namespace misc

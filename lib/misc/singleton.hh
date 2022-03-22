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
      static T& instance()
       {
         static T theSingleInstance;
         return theSingleInstance;
       }
  };

} // namespace misc

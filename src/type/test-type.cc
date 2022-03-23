#undef NDEBUG
#include <iostream>

#include <misc/contract.hh>
#include <type/types.hh>

using namespace type;

#define ASSERT(Exp)                                                            \
  {                                                                            \
    std::cerr << #Exp << '\n';                                                 \
    assertion(Exp);                                                            \
  }

int main()
{
  // Define the named type `a', pointing to `b', pointing to `int'.
  const Named b("b", &Int::instance());
  const Named a("a", &b);

  // This definition is sound.
  ASSERT(a.sound());

  // Check that `a' points to `int'.
  ASSERT(a == b);
  ASSERT(a == Int::instance());

  // Equal types are compatible.
  ASSERT(a.compatible_with(b));
  ASSERT(b.compatible_with(a));
  ASSERT(a.compatible_with(Int::instance()));
  ASSERT(Int::instance().compatible_with(a));

  // Unsound is insane :)
  const Named c = Named("c");
  const Named d = Named("d", &c);
  c.type_set(&d);
  ASSERT(!c.sound());

  // Check the case of records.  Make it recursive for fun, and more
  // in depth checking anyway.
  Record r1;
  Record r2;
  const Named j("j", &Int::instance());
  const Named k("k", &String::instance());
  r1.field_add("s", j);
  r2.field_add("s", k);
  ASSERT(j != k);
  ASSERT(r1 != r2);


  const Named x("f");
  Record rec;
  rec.field_add("y", x);
  x.type_set(&rec);
  ASSERT(x.sound());

  ASSERT(x == rec);
  ASSERT(rec == x);

  const Named y("y", &Int::instance());
  const Named z("z", &Int::instance());
  Record rec1;
  Record rec2;
  rec1.field_add("rec2", rec2);
  rec1.field_add("y", y);
  rec2.field_add("rec1", rec1);
  rec2.field_add("z", z);

  ASSERT(rec1 == rec2);
  ASSERT(rec2 == rec1);



  const Nil n{};
  ASSERT(x.compatible_with(n));
  ASSERT(n.compatible_with(x));

  ASSERT(!x.compatible_with(Int::instance()));
  ASSERT(!Int::instance().compatible_with(x));
}

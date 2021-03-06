///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2019 - 2021.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <wide_integer/generic_template_uintwide_t.h>

bool test_uintwide_t_spot_values()
{
  bool result_is_ok = true;

  {
    using uint512_t = wide_integer::generic_template::uint512_t;

    const uint512_t a("698937339790347543053797400564366118744312537138445607919548628175822115805812983955794321304304417541511379093392776018867245622409026835324102460829431");
    const uint512_t b("100041341335406267530943777943625254875702684549707174207105689918734693139781");

    const uint512_t c = (a / b);
    const uint512_t d = (a % b);

    //   QuotientRemainder
    //     [698937339790347543053797400564366118744312537138445607919548628175822115805812983955794321304304417541511379093392776018867245622409026835324102460829431,
    //      100041341335406267530943777943625254875702684549707174207105689918734693139781]
    //
    //     {6986485091668619828842978360442127600954041171641881730123945989288792389271,
    //      100041341335406267530943777943625254875702684549707174207105689918734693139780}

    const bool c_is_ok = (c == "6986485091668619828842978360442127600954041171641881730123945989288792389271");
    const bool d_is_ok = (d == "100041341335406267530943777943625254875702684549707174207105689918734693139780");

    result_is_ok &= (c_is_ok && d_is_ok);
  }

  return result_is_ok;
}

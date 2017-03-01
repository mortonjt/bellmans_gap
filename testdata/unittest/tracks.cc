// link against -lboost_unit_test_framework if boost/test/unit_test.hpp is
// used ...

// see also https://bugs.launchpad.net/ubuntu/+source/boost/+bug/162155
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE productive
#include <boost/test/unit_test.hpp>

// include everything - no linking needed ...
//#define BOOST_TEST_MAIN
//#include <boost/test/included/unit_test_framework.hpp>

#include "macros.hh"

#include "../../src/driver.hh"
#include "../../src/log.hh"
#include <sstream>

BOOST_AUTO_TEST_CASE( twotrack )
{
  std::ostringstream o;
  Log log;
  log.set_debug();
  log.set_ostream(o);
  Driver driver;
  std::string filename = std::string("../grammar/trackincomp");
  driver.setFilename(filename);
  driver.parse();
  CHECK(!driver.is_failing());

  Grammar *grammar = driver.ast.grammar();

  //see grammar->check_semantic();
  //
  bool b, r = true;
  b = grammar->init_tabulated();
  r = r && b;
  b = grammar->init_axiom();
  CHECK_EQ(b, true);
  r = r && b;
  r = grammar->init_nt_links();
  r = r && b;
  grammar->remove_unreachable();
  CHECK_EQ(r, true);
  b = ! grammar->has_nonproductive_NTs();
  r = r && b;
  CHECK_EQ(r, true);
  b = grammar->init_tracks();
  r = r && b;
  CHECK_EQ(r, false);

  std::string x(o.str());
  CHECK(x.find("Multi-Track mis-match: Caller has 2 tracks") != std::string::npos);
  CHECK(x.find("Callee has 1 tracks") != std::string::npos);

}



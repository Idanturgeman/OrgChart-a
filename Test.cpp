#include "doctest.h"
#include <iostream>
#include "OrgChart.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace ariel;

TEST_CASE("bad input func -> add_sub"){
    OrgChart organization1;
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_THROWS(organization1.add_sub("yossi", "stam"));
    CHECK_THROWS(organization1.add_sub("mordechi", "assain"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    CHECK_THROWS(organization1.add_sub("dvir", "stam"));
    CHECK_NOTHROW(organization1.add_root("CEO"));
}
TEST_CASE("good input"){
    OrgChart organization1;
    SUBCASE("func -> level order iterator"){
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO")); 
    }
    SUBCASE("func -> add sub"){
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW")); 
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    }
}

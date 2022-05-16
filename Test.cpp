#include "doctest.h"
#include <iostream>
#include "OrgChart.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace ariel;


TEST_CASE("good input"){
    OrgChart organization1;
    SUBCASE("func -> add root"){

        CHECK_NOTHROW(organization1.add_root("CEO"));
    }
    /*
    //        CEO
    //        |--------|--------|
    //        CTO      CFO      COO
    //        |                 |
    //        VP_SW             VP_BI
    //  */
    SUBCASE("func -> add sub"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    }
    SUBCASE("func -> level order iterator"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    string factory1;
    for (auto i = organization1.begin_level_order(); i != organization1.end_level_order(); ++i)
    {
    factory1 += (*i);
    factory1 += " ";
    }
    CHECK(factory1 == "CEO CTO CFO COO VP_SW VP_BI ");
    }
    SUBCASE("func -> reverse order iterator"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    string factory2;
    for (auto i = organization1.begin_reverse_order(); i != organization1.reverse_order(); ++i)
    {
    factory2 += (*i);
    factory2 += " ";
    }
    CHECK(factory2 == "VP_SW VP_BI CTO CFO COO CEO ");
    }
    SUBCASE("func -> preorder iterator"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    string factory3;
    for (auto i = organization1.begin_preorder(); i != organization1.end_preorder(); ++i)
    {
    factory3 += (*i);
    factory3 += " ";
    }
    CHECK(factory3 == "CEO CTO VP_SW CFO COO VP_BI ");
    }
    SUBCASE("func -> for each iterator"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    vector<string> level_order = {"CEO" ,"CTO", "CFO", "COO" ,"VP_SW" ,"VP_BI"};
    size_t i = 0;
    for (auto employ : organization1)
    {
        CHECK_EQ(level_order[i], employ);
        i++;
    }
    }
}
TEST_CASE("bad input func -> add_sub"){
    OrgChart organization1;
    CHECK_NOTHROW(organization1.add_root("CEO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    CHECK_THROWS(organization1.add_sub("dvir", "stam"));
    CHECK_THROWS(organization1.add_sub("yossi", "stam"));
    CHECK_THROWS(organization1.add_sub("mordechi", "assain"));
}
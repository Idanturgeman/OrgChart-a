#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

namespace ariel
{
    struct Node
    {
        string name;
        vector<Node> sones;
    };
    class OrgChart
    { 
    public:
        OrgChart();
        ~OrgChart();
        OrgChart &add_root(string name);
        OrgChart &add_sub(string father, string son);
        friend ostream &operator<<(ostream &out,OrgChart &root);
        string* begin_level_order();
        string* end_preorder();
        string* begin_preorder();
        string* begin(){
            return begin_level_order();
        }
        string* end_level_order(); 
        string* begin_reverse_order();
        string* reverse_order();
        
        string* end(){
            return end_level_order();
        }

    private:
        Node root;
        vector<string> b_level_order;
        vector<string> b_reverse_order;
        vector<string> b_preorder;
        void fill_q_for_level_order(Node &node);
        void fill_q_for_preorder(Node &node);
        void fill_q_for_reverse_order(Node &node);
        bool find_sub(Node &node, string &father, string &son);
        

    };
    
}
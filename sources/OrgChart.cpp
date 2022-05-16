#include "OrgChart.hpp"
using namespace std;

namespace ariel
{
    OrgChart::OrgChart(/* args */)
    {
    }

    OrgChart::~OrgChart()
    {
    }
    OrgChart &OrgChart::add_root(string name)
    {
        this->root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string father, string son)
    {
        if (find_sub(this->root, father, son) == 0)
        {
            throw invalid_argument("you dont have this father");
        }
        return *this;
    }
    bool OrgChart::find_sub(Node &node, string &father, string &son)
    {
        int b = node.name.compare(father);
        if (!b)
        {
            Node temp;
            temp.name = son;
            node.sones.push_back(temp);
            return true;
        }
        else
        {
            for (size_t i = 0; i < node.sones.size(); i++)
            {
                if (find_sub(node.sones[i], father, son))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // **************** fill for the q ******************
    // level order
    void OrgChart::fill_q_for_level_order(Node &node)
    {
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            this->b_level_order.push_back(node.sones.at(i).name);
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_q_for_level_order(node.sones[i]);
        }
    }
    // reverse order
    void OrgChart::fill_q_for_reverse_order(Node &node)
    {
        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            this->b_reverse_order.insert(this->b_reverse_order.begin(), node.sones.at((size_t)i).name);
        }

        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            fill_q_for_reverse_order(node.sones[(size_t)i]);
        }
    }
    // preorder
    void OrgChart::fill_q_for_preorder(Node &node)
    {
        b_preorder.push_back(node.name);
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_q_for_preorder(node.sones.at(i));
        }
    }
    // ******************* level order**************
    string *OrgChart::begin_level_order()
    {
        this->b_level_order.clear();
        this->b_level_order.push_back(this->root.name);
        fill_q_for_level_order(root);
        return &this->b_level_order[0];
    }
    string *OrgChart::end_level_order()
    {
        return &this->b_level_order[this->b_level_order.size()];
    }
    // ******************* reverse order**************
    string *OrgChart::begin_reverse_order()
    {
        this->b_reverse_order.clear();
        this->b_reverse_order.insert(b_reverse_order.begin(), this->root.name);
        fill_q_for_reverse_order(root);
        return &b_reverse_order[0];
    }
    string *OrgChart::reverse_order()
    {
        return &this->b_reverse_order[b_reverse_order.size()];
    }
 // ******************* preorder order**************
    string* OrgChart::begin_preorder()
    {
        this->b_preorder.clear();
        fill_q_for_preorder(root);
        return &this->b_preorder[0];
    }
    string* OrgChart::end_preorder()
    {
        return &this->b_preorder[b_preorder.size()];
    }
    ostream &operator<<(ostream &out, OrgChart &root)
    {
        for (auto i = root.begin_level_order(); i != root.end_level_order(); i++)
        {
            out << (*i) << ", ";
        }
        return out;
    }

}
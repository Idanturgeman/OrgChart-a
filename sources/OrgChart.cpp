#include "OrgChart.hpp"
using namespace std;

namespace ariel
{
    static int numOfOrgChart = 0;
    OrgChart::OrgChart(/* args */)
    {
        numOfOrgChart++;
    }

    OrgChart::~OrgChart()
    {
        numOfOrgChart--;
    }
    static int numOfRoot = 0;
    OrgChart &OrgChart::add_root(string name)
    {
        numOfRoot++;
        this->root.name = name;
        return *this;
    }
    static int numOfSub = 0;
    OrgChart &OrgChart::add_sub(string father, string son)
    {
        if (find_sub(this->root, father, son) == 0)
        {
            throw invalid_argument("you dont have this father");
        }
        numOfSub++;
        return *this;
    }
    bool OrgChart::find_sub(Node &node, string &father, string &son)
    {
        int ans = 0;
        int b = node.name.compare(father);
        if (!b)
        {
            numOfSub++;
            Node temp;
            temp.name = son;
            node.sones.push_back(temp);
            return true;
        }
        else
        {
            int j = 0;
            for (size_t i = 0; i < node.sones.size(); i++)
            {
                numOfSub++;
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
    static int numOfLevelOrder = 0;
    void OrgChart::fill_q_for_level_order(Node &node)
    {
        numOfLevelOrder++;
        int order = 0;
        int level = 0;
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            order++;
            this->b_level_order.push_back(node.sones.at(i).name);
            level++;
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            order++;
            fill_q_for_level_order(node.sones[i]);
            level++;
        }
    }
    // reverse order
    static int numOfReversOrder = 0;
    void OrgChart::fill_q_for_reverse_order(Node &node)
    {
        numOfReversOrder++;
        int j = 0;
        int ans = 0;
        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            j++;
            this->b_reverse_order.insert(this->b_reverse_order.begin(), node.sones.at((size_t)i).name);
            ans++;
        }

        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            j++;
            fill_q_for_reverse_order(node.sones[(size_t)i]);
            ans++;
        }
    }
    // preorder
    static int numOfPreOrder = 0;
    void OrgChart::fill_q_for_preorder(Node &node)
    {
        numOfPreOrder++;
        int j = 0;
        b_preorder.push_back(node.name);
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            j++;
            fill_q_for_preorder(node.sones.at(i));
        }
    }
    // ******************* level order**************
    static int numOfBeginLevelOrder = 0;
    string *OrgChart::begin_level_order()
    {
        numOfBeginLevelOrder++;
        this->b_level_order.clear();
        this->b_level_order.push_back(this->root.name);
        int temp = 0;
        fill_q_for_level_order(root);
        return &this->b_level_order[0];
    }
    static int numOfEndLevelOrder = 0;
    string *OrgChart::end_level_order()
    {
        numOfEndLevelOrder++;
        return &this->b_level_order[this->b_level_order.size()];
    }
    // ******************* reverse order**************
    static int numOfBeginReversOrder = 0;
    string *OrgChart::begin_reverse_order()
    {
        numOfBeginReversOrder++;
        this->b_reverse_order.clear();
        this->b_reverse_order.insert(b_reverse_order.begin(), this->root.name);
        int temp = 0;
        fill_q_for_reverse_order(root);
        return &b_reverse_order[0];
    }
    string *OrgChart::reverse_order()
    {
        numOfReversOrder++;
        return &this->b_reverse_order[b_reverse_order.size()];
    }
 // ******************* preorder order**************
    static int numOfBeginPreOrder = 0;
    string* OrgChart::begin_preorder()
    {
        numOfBeginPreOrder++;
        this->b_preorder.clear();
        fill_q_for_preorder(root);
        return &this->b_preorder[0];
    }
    static int numOfEndPreOrder = 0;
    string* OrgChart::end_preorder()
    {
        numOfEndPreOrder++;
        return &this->b_preorder[b_preorder.size()];
    }
    ostream &operator<<(ostream &out, OrgChart &root)
    {
        int j = 0;
        for (auto i = root.begin_level_order(); i != root.end_level_order(); i++)
        {
            out << (*i) << ", ";
        }
        return out;
    }

}
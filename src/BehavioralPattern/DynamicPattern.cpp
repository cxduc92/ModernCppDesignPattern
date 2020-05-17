/*
 * DynamicPattern.cpp
 *
 *  Use case: Many algorithms can be decomposed into higher and lowever-level parts
 *            The high level algorithm can then be reused for making many things
 *              
 *
 *  ========> Dynamic: enables the exact behavior of a system to be selected either at run-time(dynamic) or compile-time(static)
 *            Also known as a policy(especially in C++)
 *
 *          Application Ex: switch printing interpreter
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"
#include "vector"
#include "boost/lexical_cast.hpp"
using namespace std;

enum class OutputFormat
{
    markdown,
    html
};

// * hdajks
// * hdaask
// <ul>
//   <li>dasjkdh</li>
// </ul>

struct ListStrategy
{
    virtual void start(ostringstream &oss) {}
    virtual void add_list_item(ostringstream &oss, const string &item) = 0;
    virtual void end(ostringstream &oss) {}
};

struct MarkdownListrategy : ListStrategy
{
    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss << "* " << item
            << "\n";
    }
};

struct HtmlListrategy : ListStrategy
{
    void start(ostringstream &oss) override
    {
        oss << "<ul>\n";
    }

    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss << "  <li>" << item << "</li>\n";
    }

    void end(ostringstream &oss) override
    {
        oss << "</ul>\n";
    }
};

struct TextProcessor
{
    void clear()
    {
        oss.str("");
        oss.clear();
    }

    void append_list(const vector<string> &items)
    {
        list_strategy->start(oss);
        for (auto &item : items)
        {
            list_strategy->add_list_item(oss, item);
        }
        list_strategy->end(oss);
    }

    void set_output_format(const OutputFormat &format)
    {
        switch (format)
        {
        case OutputFormat::markdown:
            list_strategy = make_unique<MarkdownListrategy>();
            break;
        case OutputFormat::html:
            list_strategy = make_unique<HtmlListrategy>();
            break;
        }
    }

    string str() const { return oss.str(); }

private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};

int runDynamicPattern()
//int main(int argc, char *argv[])
{
    vector<string> items{"foo", "bar", "baz"};

    TextProcessor tp;
    tp.set_output_format(OutputFormat::markdown);
    tp.append_list(items);

    cout << tp.str() << "\n";

    tp.clear();
    tp.set_output_format(OutputFormat::html);
    tp.append_list(items);

    cout << tp.str() << "\n";
    return 0;
}

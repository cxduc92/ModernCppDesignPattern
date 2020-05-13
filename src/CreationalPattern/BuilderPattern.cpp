/*
 * BuilderPattern.cpp
 *
 *  Use case:   Some objects are simple and can be created in a simple constructor call
 *              _ Other objects require a lot of ceremony to create
 *              _ Having an object with multiple constructor arguments is not productive
 *
 *  ========> Builder provides an API for the constructing an object step-by-step
 *            Builder is a separate component for building an object
 *
 *          Application Ex: String builder, JSon builder, Xml builder, Log builder
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "cstdio"
#include "stdint.h"
#include "stdio.h"
#include "string"
#include "vector"
#include "fstream"
#include "boost/lexical_cast.hpp"

using namespace std;
struct HtmlBuilder;

struct HtmlElement
{
        string name, text;
        vector<HtmlElement> elements;

        const size_t indent_size = 2;

        HtmlElement()
        {
        }

        HtmlElement(const string &name, const string &text) :
                        name(name), text(text)
        {
        }

        string str(int indent = 0) const
        {
            ostringstream oss;
            string i(indent_size * indent, ' ');
            oss << i << "<" << name << ">" << endl;
            if (text.size() > 0)
                oss << string(indent_size * (indent + 1), ' ') << text << endl;
            for (const auto &e : elements)
                oss << e.str(indent + 1);

            oss << i << "</" << name << ">" << endl;
            return oss.str();
        }
};

// allow us to add root and then children to the element
// instead of constructing the object in every single line
// use a builder to provide functions to construct the components
struct HtmlBuilder
{
        HtmlElement root;

        HtmlBuilder(string root_name)
        {
            root.name = root_name;
        }

        // Improvement for builder
        // fluent interface
        HtmlBuilder& add_child(string child_name, string child_text)
        {
            HtmlElement e
            { child_name, child_text };
            root.elements.emplace_back(e);
            return *this;
        }

        string str() const
        {
            return root.str();
        }

        operator HtmlElement() const
        {
            return root;
        }
};

int runBuilderPattern()
//int main(int argc, char *argv[])
{
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";
    cout << output << endl;

    string words[] =
    { "hello", "world" };
    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
        oss << " <li>" << w << "</li>";
    oss << "/ul>";
    cout << oss.str() << endl;

    HtmlBuilder builder
    { "ul" };
    builder.add_child("li", "hello").add_child("li", "world");
    cout << builder.str() << endl;

    return 0;
}


/*
 * InterfaceSegregationDiscipline.cpp
 *
 *  Use case: not create interface which is too large
 *  ex: create an interface to scan, document the document
 *  We would have to segregate different interfaces
 *
 *  Advantage: Avoid stacking too much interfaces into 1 interface
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

struct Document
{

};

//struct IMachine
//{
//        virtual void print(Document& doc) = 0;
//        virtual void scan(Document& doc) = 0;
//        virtual void fax(Document& doc) = 0;
//};
//
//struct MFP:IMachine
//{
//        void print(Document &doc) override
//        {
//
//        }
//
//        void scan(Document &doc) override
//        {
//
//        }
//
//        void fax(Document &doc) override
//        {
//
//        }
//};
//
//struct Scanner:IMachine
//{
//        void print(Document &doc) override
//        {
//            // this could be a wrong message to the customer because the scanner could not print
//        }
//
//        void scan(Document &doc) override
//        {
//            // ok
//        }
//
//        void fax(Document &doc) override
//        {
//            // this could be a wrong message to the customer because the scanner could not fax
//        }
//};

struct IPrinter
{
        virtual void print(Document &doc) = 0;
};

struct IScanner
{
        virtual void scan(Document &doc) = 0;
};

struct IFax
{
        virtual void fax(Document &doc) = 0;
};

// if we would like to implement the function for the printer
struct Printer: IPrinter
{
        void print(Document &doc) override
        {
            // print
        }
};

// interface for machine could do printing and scanning
struct IMachine: IPrinter, IScanner
{
};

struct Machine: IMachine
{
        IPrinter &printer;
        IScanner &scanner;

        Machine(IPrinter &printer, IScanner &scanner) :
                        printer(printer), scanner(scanner)
        {
        }

        void print(Document &doc) override
        {
            // print
            printer.print(doc);
        }

        void scan(Document &doc) override
        {
            //scan
            scanner.scan(doc);
        }
};

struct Scanner: IScanner
{
        void scan(Document &doc) override
        {
            // scan
        }
};


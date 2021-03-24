
/********************************************************************************
 *FILE NAME     : header.h
 *DESCRIPTION   : This file contains macros and class declaration.

 ************************************************************************************/

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

    #include<iostream>
    #include<string>
    #include<fstream>
    #include<sstream>
    #include<regex>
    #include<map>

    using namespace std;

    /* class definition for telephone */
    class telephone
    {
        public:
            void setUserName(string name);
            string getUserName();
            void setPhone(string tel);
            string getPhone();

            void readFile(char argv[]);
            void displayAll(void);
            void readInput(void);
            void insertData(void);
            void searchPhone(void);
            void deleteContact(void);
            void deleteAll(void);
            bool validateContact(string s);

            multimap<string,string> directory; /*creating a multimap to store name and phone number */
        private:
            string userName=" ";
            string phoneNumber=" ";
    };

#endif // HEADER_H_INCLUDED

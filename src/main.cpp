/**********************************************************************************
 *FILE NAME     : main.cpp
 *DESCRIPTION   : Main file implements the header prototype.

 **********************************************************************************/

#include "header.h"
int main(int argc,char *argv[]) /*reads command line argument as filename */
{
    telephone tel; /*creating object for class telephone */
    unsigned int choice;
    /*checking for the filename is pass at command line or not */
    if(argc < 2)
	{
		cout << "Usage: " << argv[0] << " <string of text> " << endl;
		return 0;

	}

    while(true)
    {
        cout<<"=========================================================================================="<<endl;
        cout<<"\t\t\t\tPhone Directory\t\t\t\t"<<endl;
        cout<<"\t\t\t------------------------------\t\t\t"<<endl;
        /*providing option to the user to perform operation based on there choice */
        cout<<"Enter 1 to read record from file"<<endl;
        cout<<"Enter 2 to display file content"<<endl;
        cout<<"Enter 3 to search contact based on name"<<endl;
        cout<<"Enter 4 to search and delete contact based on name"<<endl;
        cout<<"Enter 5 to add user contact"<<endl;
        cout<<"Enter 6 to exit"<<endl;
        cout<<"=========================================================================================="<<endl;
        cout<<"Enter your choice to perform operation"<<endl;
        cin>>choice; /*reading user choice of operation */
        if(!cin){
            cout<<"Enter value as digit"<<endl;
            cout<<"Program Terminate Restart Now"<<endl;
            break;
        }
        else
        {
            cout<<"=========================================================================================="<<endl;
            switch(choice)
            {
                case 1:
                    tel.readFile(argv[1]); /*read file from command line and store in multimap */
                    break;
                case 2:
                    cout<<"=========================================================================================="<<endl;
                    cout<<"\t\t\tContacts\t\t\t"<<endl;
                    cout<<"\t\t----------------------\t\t"<<endl;
                    tel.displayAll(); /*display all the contacts in directory */
                    cout<<"=========================================================================================="<<endl;
                    break;
                case 3:
                    cout<<"=========================================================================================="<<endl;
                    tel.searchPhone(); /*search all the phone number of name */
                    cout<<"=========================================================================================="<<endl;
                    break;
                case 4:
                    tel.deleteContact(); /*search and delete phone number */
                    break;
                case 5:
                    tel.readInput(); /*reading name and phone number from user to insert */
                    break;
                case 6:
                    cout<<"==========Thank you=================="<<endl;
                    exit(0); /*terminating the program */
                default:
                    cout<<"Invalid choice of operation"<<endl; /* checking for invalid option */
            }
        }
    }
    return(0);
}

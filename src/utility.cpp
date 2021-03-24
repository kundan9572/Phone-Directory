/*********************************************************************************************
 *FILE NAME     : utility.cpp
 *DESCRIPTION   : This file contains the function definition of complex class.

 *********************************************************************************************/

#include "header.h"

/***********************************************************************************************
*Function Name : setUserName
*Description   : This function is used to set the username .
*Arguments     : @name - name which we want to add
*Returns       : void.
***********************************************************************************************/

void telephone::setUserName(string name)
{
    userName=name;
}

/***********************************************************************************************
*Function Name : getUserName
*Description   : This function will used to get username .
*Arguments     : void.
*Returns       : return name.
***********************************************************************************************/

string telephone::getUserName(void)
{
    return userName;
}

/***********************************************************************************************
*Function Name : setPhone
*Description   : This function is used to set the phone number .
*Arguments     : @tel - phone number which we want to add
*Returns       : void.
***********************************************************************************************/

void telephone::setPhone(string tel)
{
    phoneNumber=tel;
}

/***********************************************************************************************
*Function Name : getPhone
*Description   : This function will used to get phone numeber .
*Arguments     : void.
*Returns       : return phone number.
***********************************************************************************************/

string telephone::getPhone(void)
{
    return phoneNumber;
}

/***********************************************************************************************
*Function Name : readInput
*Description   : This function will read username and phone number and set the value .
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::readInput()
{
    string name,phone;
    telephone tel;
    cout<<"Enter Name"<<endl;
    cin>>name;
    cout<<"Enter phone number"<<endl;
    cin>>phone;
    bool num=validateContact(phone);
    if(num)
    {
        setUserName(name);
        setPhone(phone);
        insertData();
    }
    else{
        cout<<"Phone number must be of 10 digit and should only be number start between 6-9 ."<<endl;
    }
}

/***********************************************************************************************
*Function Name : insertData
*Description   : This function will add username and phone number to container multimap .
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::insertData(void)
{
    directory.insert(pair<string,string>(getUserName(),getPhone()));
    cout<<"Contact added Successfully"<<endl;
}

/***********************************************************************************************
*Function Name : readFile
*Description   : read file content and store in multimap .
*Arguments     : @argv - filename.
*Returns       : void.
***********************************************************************************************/

void telephone::readFile(char argv[])
{
    string line;
    telephone tel;
    static int flag=1;
    if(flag)
    {
        cout<<"Filename is "<<argv<<endl;
        ifstream in;
        in.open(argv);
        cout<<"File read success."<<endl;

        while(getline(in,line)) /*in - source to read line - destination to copy */
        {
            stringstream ss(line);
            string key,value;
            ss>>key;
            while(!ss.eof())
            {
                ss>>value;
                bool num=validateContact(value);
                //if(value.size() == 10)
                if(num)
                {
                    directory.insert(pair<string,string>(key,value));
                }
            }
        }
        flag=0;
    }
    else
    {
        cout<<"File has already been read"<<endl;
        cout<<"You can read file only once"<<endl;
    }
}

/***********************************************************************************************
*Function Name : deleteContact
*Description   : This function will search contact and delete from multimap .
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::deleteContact(void)
{
    string name,phone;
    int flag=0;
    cout<<"Enter the name of the person whose contact you want to delete."<<endl;
    cin>>name;
    cout<<"Enter phone number"<<endl;
    cin>>phone;
    bool num=validateContact(phone);
    if(num){
        typedef multimap<string,string>::iterator itr;
        itr it=directory.begin();
        it=directory.find (name);
        cout<<"=========================================================================================="<<endl;
        if (it!= directory.end())
        {
            /* It returns a pair representing the range of elements with key equal to name */
            pair<itr,itr> result=directory.equal_range(name);
            cout<<"=========================================================================================="<<endl;
            for(itr it=result.first;it!=result.second;it++)
            {
                if(it->second == phone)
                {
                    directory.erase(it);
                    cout<<"Contact deleted Successfully"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"Phone number not found"<<endl;
            }
            cout<<endl;
        }
        else{
            cout<<"Invalid name or phone Number"<<endl;
        }
    }
    else
    {
        cout<<"Invalid phone number"<<endl;
    }
}

/***********************************************************************************************
*Function Name : displayAll
*Description   : display the content in the container .
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::displayAll(void)
{
    multimap<string,string>::iterator i=directory.begin();

    if (i!= directory.end()){
        for(; i != directory.end();)
        {
            auto itr = directory.lower_bound(i->first);
            cout<<i->first<<"\t";
            for(; itr != directory.upper_bound(i->first); itr++)
            cout << itr->second << " ";
            i = itr;
            cout << "\n";
        }
    }
    else{
        cout<<"Directory is empty"<<endl;
    }
}

/***********************************************************************************************
*Function Name : searchPhone
*Description   : This function will search all the phone number based on name and count of it.
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::searchPhone(void)
{
    string name;
    cout<<"Enter the name of the person whose contact you want to search and count the contact he has."<<endl;
    cin>>name;
    typedef multimap<string,string>::iterator itr;
    itr it=directory.begin();
    it=directory.find (name);
    cout<<"=========================================================================================="<<endl;
    if (it!= directory.end())
    {
        /* It returns a pair representing the range of elements with key equal to name */
        pair<itr,itr> result=directory.equal_range(name);
        cout<<"=========================================================================================="<<endl;
        for(itr it=result.first;it!=result.second;it++)
        {
            cout<<it->second<<" ";
        }
        cout<<endl;
        cout<<"=========================================================================================="<<endl;
        cout<<"Total number of contact of " <<name <<" is " << directory.count(name)<<endl;
        cout<<"=========================================================================================="<<endl;
        cout<<endl;
    }
    else{
        cout<<endl<<"Phone number for "<<name <<" not found "<<endl;
    }
}

/***********************************************************************************************
*Function Name : deleteAll
*Description   : This function will delete the multimap .
*Arguments     : void.
*Returns       : void.
***********************************************************************************************/

void telephone::deleteAll(void)
{
     cout<<"Deleting all the directory contacts...."<<endl;
     directory.clear();
     cout<<"All the contacts Successfully deleted"<<endl;
}

/***********************************************************************************************
*Function Name : validateContact
*Description   : This function will validate the phone number .
*Arguments     : @s - which is the phone number.
*Returns       : True or False.
***********************************************************************************************/

bool telephone::validateContact(string s)
{
    const regex pattern("^(([6-9]{1})([0-9]{9}))$");
        if(s.size()==10 && regex_match(s, pattern) )
        {
                return true;
        }
        else
        {
                return false;
        }

}


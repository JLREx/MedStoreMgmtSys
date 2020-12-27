#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Human{ //Human class
    string name;
};

class Customer: public Human{ //Customer class, sub of human
    int custId;
};

class Admin: public Human{ //Admin class, sub of human
    int adminId;
public:
    void cust_add(); //add new customer, append
    void cust_list(); //list all customer
    void cust_update(); //update info of one customer, half from search, replace whole line or part of line, create new file rename
    void cust_delete(); //delete whole line of customer info
    void cust_search(); //search

    void med_add(); //add new medicine, append
    void med_list(); //list all medicine
    void med_update(); //update info of one medicine, half from search, replace whole line or part of line, create new file rename
    void med_delete(); //delete whole line of medicine info
    void med_search(); //search

    //for update in add purpose
    void cust_update(string nric);
    void med_update(string name);
};

void main_menu();

void Admin::med_update(string name){
    string templine, updateline;
    string medSupplier, medBalance, medPrice;
    ifstream myfile;
    myfile.open("medicine.txt");

    system("cls");
    cout << endl;
    cout << "\tMedicine Name exists in record." << endl;
    cout << endl;
    cout << "\tThe system has auto-directed to" << endl;
    cout << "\tUPDATE MEDICINE RECORD" << endl;
    cout << endl << endl;

    bool isFound=0;

    if(myfile.is_open()){
        while(!myfile.eof()){
            string oriMedName, oriMedSupplier, oriMedBalance, oriMedPrice;

            getline(myfile,oriMedName, '\t');
            getline(myfile,oriMedSupplier, '\t');
            getline(myfile,oriMedBalance, '\t');
            getline(myfile,oriMedPrice);

            for(int i=0;i<name.length();i++){ //checking if user input match with any name from file
                if(oriMedName[i]==name[i])
                    isFound = 1;
                else{
                    isFound =0;
                    break;
                }
            }

            if(isFound){
                ofstream tempfile;
                tempfile.open("temp.txt", ios::app);
                updateline = oriMedName + "\t" + oriMedSupplier + "\t" + oriMedBalance + "\t" + oriMedPrice;

                myfile.seekg(0, ios::beg);
                while(getline(myfile, templine)){
                    if (templine != updateline){
                        tempfile << templine << endl;
                    }
                }

                cout << endl;
                cout << "UPDATING DETAILS FOR MEDICINE " << oriMedName <<endl;
                cout << "Press Enter to keep current value." <<endl;
                cout << endl;

                cout << endl;
                cout << "Current Medicine Supplier: " << oriMedSupplier<<endl;
                cout << "New Medicine Supplier: ";
                getline(cin, medSupplier);
                if(medSupplier == ""){
                    medSupplier = oriMedSupplier;
                }

                cout << endl;
                cout << "Current Medicine Balance: " << oriMedBalance<<endl;
                cout << "New Medicine Balance: ";
                getline(cin, medBalance);
                if(medBalance == ""){
                    medBalance = oriMedBalance;
                }

                cout << endl;
                cout << "Current Medicine Price(RM): " << oriMedPrice<<endl;
                cout << "New Medicine Price(RM): ";
                getline(cin, medPrice);
                if(medPrice == ""){
                    medPrice = oriMedPrice;
                }

                tempfile << oriMedName << "\t" << medSupplier << "\t" << medBalance << "\t" << medPrice << endl;
                cout<<"Medicine record updated. "<<endl<<endl;

                tempfile.close();
                myfile.close();
                remove("medicine.txt");
                rename("temp.txt", "medicine.txt");

                break;
            }
        }

        if(myfile.eof()&&(!isFound)){
            cout << "Medicine not found!\n";
        }

    }else{
        cout << "Unable to locate file for search." << endl;
    }

    myfile.close();
    cout << endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_update(string nric){
    string templine, updateline;
    string custPhone, custAge, custEmail, custAddress;
    ifstream myfile;
    myfile.open("customer.txt");

    system("cls");
    cout << endl;
    cout << "\tCustomer NRIC exists in record." << endl;
    cout << endl;
    cout << "\tThe system has auto-directed to" << endl;
    cout << "\tUPDATE CUSTOMER RECORD" << endl;
    cout << endl << endl;

    bool isFound=0;

    if(myfile.is_open()){
        while(!myfile.eof()){
            string oriCustName, oriCustPhone, oriCustNric, oriCustAge, oriCustEmail, oriCustAddress;

            getline(myfile,oriCustNric, '\t');
            getline(myfile,oriCustName, '\t');
            getline(myfile,oriCustAge, '\t');
            getline(myfile,oriCustPhone, '\t');
            getline(myfile,oriCustEmail, '\t');
            getline(myfile,oriCustAddress);

            for(int i=0;i<nric.length();i++){ //checking if user input match with any ic from file
                if(oriCustNric[i]==nric[i])
                    isFound = 1;
                else{
                    isFound =0;
                    break;
                }
            }

            if(isFound){
                ofstream tempfile;
                tempfile.open("temp.txt", ios::app);
                updateline = oriCustNric + "\t" + oriCustName + "\t" + oriCustAge + "\t" + oriCustPhone + "\t" + oriCustEmail + "\t" + oriCustAddress;

                myfile.seekg(0, ios::beg);
                while(getline(myfile, templine)){
                    if (templine != updateline){
                        tempfile << templine << endl;
                    }
                }

                cout << endl;
                cout << "UPDATING DETAILS FOR CUSTOMER " << oriCustName <<endl;
                cout << "Press Enter to keep current value." <<endl;
                cout << endl;

                cout << endl;
                cout << "Current Customer Age: "<<oriCustAge<<endl;
                cout << "New Customer Age: ";
                getline(cin, custAge);
                if(custAge == ""){
                    custAge = oriCustAge;
                }

                cout << endl;
                cout << "Current Customer Phone Number: "<<oriCustPhone<<endl;
                cout << "New Customer Phone Number: ";
                getline(cin, custPhone);
                if(custPhone == ""){
                    custPhone = oriCustPhone;
                }

                cout << endl;
                cout << "Current Customer Email: "<<oriCustEmail<<endl;
                cout << "New Customer Email: ";
                getline(cin, custEmail);
                if(custEmail == ""){
                    custEmail = oriCustEmail;
                }

                cout << endl;
                cout << "Current Customer Address: "<<oriCustAddress<<endl;
                cout << "New Customer Address: ";
                getline(cin, custAddress);
                if(custAddress == ""){
                    custAddress = oriCustAddress;
                }

                cout << endl;
                tempfile << oriCustNric << "\t" << oriCustName << "\t" << custAge << "\t" << custPhone << "\t" << custEmail << "\t" << custAddress << endl;
                cout<<"Customer details updated. "<<endl<<endl;

                tempfile.close();
                myfile.close();
                remove("customer.txt");
                rename("temp.txt", "customer.txt");

                break;
            }
        }

        if(myfile.eof()&&(!isFound)){
            cout << "Customer not found!\n";
        }

    }else{
        cout << "Unable to locate file for search." << endl;
    }
    myfile.close();

    cout << endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_search(){
    string searchline, header;
    char redo;
    ifstream myfile;

    do{
        myfile.open("customer.txt");
        system("cls");
        cout << endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   SEARCH CUSTOMER RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the keyword: ";
        cin  >> searchline;
        bool isFound=0;

        if(myfile.is_open()){
            getline(myfile, header);

            while(!myfile.eof()){
                string custNric = "", custName = "", custOtherDetails = "", custLowerName = "";

                getline(myfile,custNric, '\t');
                getline(myfile,custName, '\t');
                getline(myfile,custOtherDetails);

                for (int i = 0; i<custName.length(); i++){
                    custLowerName[i] = tolower(custName[i]);
                }

                for(int i=0;i<searchline.length();i++){ //checking if user input match with any ic from file
                    if(custNric[i]==searchline[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << endl << endl;
                    cout << header << endl;
                    cout << custNric <<"\t"<< custName <<"\t"<< custOtherDetails<<endl;
                    cout << endl;
                    break;
                }else{
                    for(int i=0;i<searchline.length();i++){ //checking if user input match with any name from file
                        if(custLowerName[i]==searchline[i])
                            isFound = 1;
                        else{
                            isFound =0;
                            break;
                        }
                    }

                    if(isFound){
                        cout << endl << endl;
                        cout << header << endl;
                        cout << custNric <<"\t"<< custName <<"\t"<< custOtherDetails<<endl;
                        cout << endl;
                        break;
                    }
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Customer not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to look for another customer (Y/N)?";
        cin>>redo;
        myfile.close();
    }while (redo == 'Y' || redo == 'y');

    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::med_search(){
    string searchline, header;
    char redo;
    ifstream myfile;

    do{
        myfile.open("medicine.txt");
        system("cls");
        cout << endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   SEARCH MEDICINE RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the keyword: ";
        cin  >> searchline;
        bool isFound=0;

        if(myfile.is_open()){
            getline(myfile, header);

            while(!myfile.eof()){
                string medName = "", medOtherDetails = "", medLowerName = "";

                getline(myfile,medName, '\t');
                getline(myfile,medOtherDetails);

                for (int i = 0; i<medName.length(); i++){
                    medLowerName[i] = tolower(medName[i]);
                }

                for(int i=0;i<searchline.length();i++){ //checking if user input match with any name from file
                    if(medLowerName[i]==searchline[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << endl << endl;
                    cout << header << endl;
                    cout << medName <<"\t"<< medOtherDetails << endl << endl;
                    break;
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Medicine not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to look for another medicine (Y/N)?";
        cin>>redo;
        myfile.close();
    }while (redo == 'Y' || redo == 'y');

    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_add(){
    ofstream myfile;
    const int NRICSIZE = 12;
    string custName, custPhone, custNric, custAge, custEmail, custAddress;
    char redo;
    myfile.open("customer.txt", ios::app);
    do{
        system("cls");
        cout << endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                    ADD CUSTOMER RECORD                     *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Customer NRIC: ";
        cin.ignore();
        getline(cin, custNric);

        while(custNric.length()!= NRICSIZE){
            cout << "Invalid NRIC entered. NRIC should have 12 characters. " << endl;
            cout << "Please enter again." << endl;
            cout << endl;
            cout << "Customer NRIC: ";
            getline(cin, custNric);
        }
        //try check for availability of cust record, if exist update
        //check if exist, then update instead
        ifstream checkfile;
        checkfile.open("customer.txt");
        bool isFound=0;

        if(checkfile.is_open()){
            while(!checkfile.eof()){
                string custNricFromFile = "", custOtherDetailsFromFile = "";

                getline(checkfile,custNricFromFile, '\t');
                getline(checkfile,custOtherDetailsFromFile);

                for(int i=0;i<custNricFromFile.length();i++){ //checking if user input match with any ic from file
                    if(custNricFromFile[i]== custNric[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }
                if(isFound){
                    myfile.close();
                    checkfile.close();
                    cust_update(custNric);
                    break;
                }
            }
        }else{
            cout << "Unable to locate file for checking." << endl;
        }
        //end of checking

        cout << endl;
        cout << "Customer Name: ";
        getline(cin, custName);

        cout << endl;
        cout << "Customer Age: ";
        getline(cin, custAge);

        cout << endl;
        cout << "Customer Phone Number: ";
        getline(cin, custPhone);

        cout << endl;
        cout << "Customer Email: ";
        getline(cin, custEmail);

        cout << endl;
        cout << "Customer Address: ";
        getline(cin, custAddress);

        cout << endl;
        myfile << custNric << "\t" << custName << "\t" << custAge << "\t" << custPhone << "\t" << custEmail << "\t" << custAddress << endl;

        cout << endl;
        cout<<"Do you want to add another customer (Y/N)?";
        cin>>redo;

    }while (redo == 'Y' || redo == 'y');
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_list(){
    string line;
    ifstream myfile;
    char menu;
    myfile.open("customer.txt");
    system("cls");
        cout << endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                    LIST CUSTOMER RECORD                    *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout << line << endl;
        }
        if(myfile.eof()){
            cout << endl;
            cout << "End of record" << endl;
        }
    }else{
        cout << "Unable to open record." << endl;
    }
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_update(){ //just enter for values that dont need to change
    string header, templine, updateline;
    string custPhone, custNric, custAge, custEmail, custAddress;
    char redo, updateConfirm;
    const int NRICSIZE = 12;
    ifstream myfile;

    do{
        myfile.open("customer.txt");
        system("cls");
        cout<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   UPDATE CUSTOMER RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the NRIC for the customer: ";
        cin.ignore();
        getline(cin, custNric);
        while(custNric.length()!= NRICSIZE){
            cout << "Invalid NRIC entered. NRIC should have 12 characters. " << endl;
            cout << "Please enter again." << endl;
            cout << endl;
            cout << "Customer NRIC: ";
            getline(cin, custNric);
        }

        bool isFound=0;

        if(myfile.is_open()){
            while(!myfile.eof()){
                string oriCustName, oriCustPhone, oriCustNric, oriCustAge, oriCustEmail, oriCustAddress;

                getline(myfile,oriCustNric, '\t');
                getline(myfile,oriCustName, '\t');
                getline(myfile,oriCustAge, '\t');
                getline(myfile,oriCustPhone, '\t');
                getline(myfile,oriCustEmail, '\t');
                getline(myfile,oriCustAddress);

                for(int i=0;i<custNric.length();i++){ //checking if user input match with any ic from file
                    if(oriCustNric[i]==custNric[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << "Customer record found! " << endl << endl;
                    myfile.seekg(0, ios::beg);
                    getline(myfile, header);
                    cout << header << endl;

                    updateline = oriCustNric + "\t" + oriCustName + "\t" + oriCustAge + "\t" + oriCustPhone + "\t" + oriCustEmail + "\t" + oriCustAddress ;
                    cout << updateline << endl;
                    cout << endl;
                    cout << "Proceed to update (Y/N)? ";
                    cin >> updateConfirm;

                    ofstream tempfile;
                    tempfile.open("temp.txt", ios::app);

                    if (updateConfirm == 'Y' || updateConfirm == 'y'){
                        myfile.seekg(0, ios::beg);
                        while(getline(myfile, templine)){
                            if (templine != updateline){
                                tempfile << templine << endl;
                            }
                        }

                        system("cls");
                        cout << "UPDATING DETAILS FOR CUSTOMER " << oriCustName <<endl;
                        cout << "Press Enter to keep current value." <<endl; //to be modify
                        cout << endl;

                        cout << endl;
                        cout << "Current Customer Age: "<<oriCustAge<<endl;
                        cout << "New Customer Age: ";
                        cin.ignore();
                        getline(cin, custAge);
                        if(custAge == ""){
                            custAge = oriCustAge;
                        }

                        cout << endl;
                        cout << "Current Customer Phone Number: "<<oriCustPhone<<endl;
                        cout << "New Customer Phone Number: ";
                        getline(cin, custPhone);
                        if(custPhone == ""){
                            custPhone = oriCustPhone;
                        }

                        cout << endl;
                        cout << "Current Customer Email: "<<oriCustEmail<<endl;
                        cout << "New Customer Email: ";
                        getline(cin, custEmail);
                        if(custEmail == ""){
                            custEmail = oriCustEmail;
                        }

                        cout << endl;
                        cout << "Current Customer Address: "<<oriCustAddress<<endl;
                        cout << "New Customer Address: ";
                        getline(cin, custAddress);
                        if(custAddress == ""){
                            custAddress = oriCustAddress;
                        }

                        cout << endl;
                        cout << "Customer details updated."<<endl;
                        tempfile << oriCustNric << "\t" << oriCustName << "\t" << custAge << "\t" << custPhone << "\t" << custEmail << "\t" << custAddress << endl;


                        tempfile.close();
                        myfile.close();
                        remove("customer.txt");
                        rename("temp.txt", "customer.txt");

                        break;
                    }else{break;}
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Customer not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to update record for another customer (Y/N)?";
        cin>>redo;
    }while (redo == 'Y' || redo == 'y');
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::cust_delete(){ //search for then delete while line, move all wanted to temp then rename
    string searchline, header, templine, deleteline;
    char redo, deleteConfirm;
    ifstream myfile;

    do{
        system("cls");
        cout<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   DELETE CUSTOMER RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the NRIC for the customer: ";
        cin  >> searchline;
        bool isFound=0;
        myfile.open("customer.txt");

        if(myfile.is_open()){
            while(!myfile.eof()){
                string custNric = "", custOtherDetails = "";

                getline(myfile,custNric, '\t');
                getline(myfile,custOtherDetails);

                for(int i=0;i<searchline.length();i++){ //checking if user input match with any ic from file
                    if(custNric[i]==searchline[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << "Customer record found! " << endl << endl;
                    myfile.seekg(0, ios::beg);
                    getline(myfile, header);
                    cout << header << endl;

                    cout << custNric <<"\t"<< custOtherDetails << endl;
                    cout << endl;
                    cout << "Proceed to delete (Y/N)? ";
                    cin >> deleteConfirm;

                    deleteline = custNric + "\t" + custOtherDetails;
                    ofstream tempfile;
                    tempfile.open("temp.txt");

                    if (deleteConfirm == 'Y' || deleteConfirm == 'y'){
                        myfile.seekg(0, ios::beg);
                        while(getline(myfile, templine)){
                            if (templine != deleteline){
                                tempfile << templine << endl;
                            }
                        }
                        cout << "Customer details deleted."<<endl;
                    	tempfile.close();
                    	myfile.close();
                    	remove("customer.txt");
                    	rename("temp.txt", "customer.txt");
                    }
                    break;
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Customer not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to delete record for another customer (Y/N)?";
        cin>>redo;

    }while (redo == 'Y' || redo == 'y');

    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::med_add(){
    ofstream myfile;
    string medName, medSupplier, medBalance, medPrice;
    char redo;
    myfile.open("medicine.txt", ios::app);
    do{
        system("cls");
        cout<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                    ADD MEDICINE RECORD                     *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Medicine Name: ";
        cin.ignore();
        getline(cin, medName);
        //try check for availability of med record, if exist update
        //check if exist, then update instead
        ifstream Medcheckfile;
        Medcheckfile.open("medicine.txt");
        bool isFoundMed=0;

        if(Medcheckfile.is_open()){
            while(!Medcheckfile.eof()){
                string medNameFromFile = "", medOtherDetailsFromFile = "";

                getline(Medcheckfile,medNameFromFile, '\t');
                getline(Medcheckfile,medOtherDetailsFromFile);

                //since adding record is entering the exact name, no tolower function needed
                for(int i=0;i<medNameFromFile.length();i++){ //checking if user input match with any name from file
                    if(medNameFromFile[i]== medName[i])
                        isFoundMed = 1;
                    else{
                        isFoundMed =0;
                        break;
                    }
                }
                if(isFoundMed){
                    myfile.close();
                    Medcheckfile.close();
                    med_update(medName);
                    break;
                }
            }
        }else{
            cout << "Unable to locate file for checking." << endl;
        }
        //end of checking

        cout << endl;
        cout << "Medicine Supplier: ";
        getline(cin, medSupplier);

        cout << endl;
        cout << "Medicine Balance: ";
        cin >> medBalance;

        cout << endl;
        cout << "Medicine Price(RM): ";
        cin >> medPrice;

        cout << endl;
        myfile << medName << "\t" << medSupplier << "\t" << medBalance << "\t" << medPrice << endl;

        cout << endl;
        cout<<"Do you want to add another medicine (Y/N)?";
        cin>>redo;

    }while (redo == 'Y' || redo == 'y');
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::med_list(){
    string line;
    ifstream myfile;
    char menu;
    myfile.open("medicine.txt");
    system("cls");
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*                    LIST MEDICINE RECORD                    *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<endl;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout << line << endl;
        }
        if(myfile.eof()){
            cout << endl;
            cout << "End of record" << endl;
        }
    }else{
        cout << "Unable to open record." << endl;
    }
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::med_update(){ //just enter for values that dont need to change
    string header, templine, updateline;
    string medName, medSupplier, medBalance, medPrice;
    char redo, updateConfirm;
    ifstream myfile;
    myfile.open("medicine.txt");

    do{
        system("cls");
        cout<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   UPDATE MEDICINE RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the name of medicine: ";
        cin.ignore();
        getline(cin, medName);

        bool isFound=0;

        if(myfile.is_open()){
            while(!myfile.eof()){ //while it is not end of file
                string oriMedName, oriMedSupplier, oriMedBalance, oriMedPrice, oriMedLowerName, medLowerName;

                getline(myfile,oriMedName, '\t');
                getline(myfile,oriMedSupplier, '\t');
                getline(myfile,oriMedBalance, '\t');
                getline(myfile,oriMedPrice);

                for (int i = 0; i<oriMedName.length(); i++){ //convert medicine name from file into lowercase
                    oriMedLowerName[i] = tolower(oriMedName[i]);
                }

                for (int i = 0; i<medName.length(); i++){ //convert user input line into lowercase
                    medLowerName[i] = tolower(medName[i]);
                }

                for(int i=0;i<medName.length();i++){ //checking if user input match with any name from file
                    if(medLowerName[i]==oriMedLowerName[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << "Medicine record found! " << endl << endl;
                    myfile.seekg(0, ios::beg); //put the cursor back to the beginning of file
                    getline(myfile, header);
                    cout << header << endl;

                    updateline = oriMedName + "\t" + oriMedSupplier + "\t" + oriMedBalance + "\t" + oriMedPrice;
                    cout << updateline << endl;
                    cout << endl;
                    cout << "Proceed to update (Y/N)? ";
                    cin >> updateConfirm;

                    ofstream tempfile;
                    tempfile.open("temp.txt", ios::app);

                    if (updateConfirm == 'Y' || updateConfirm == 'y'){
                        myfile.seekg(0, ios::beg); //put the cursor back to the beginning of file
                        while(getline(myfile, templine)){
                            if (templine != updateline){
                                tempfile << templine << endl;
                            }
                        }
                        system("cls");
                        cout << "UPDATING DETAILS FOR MEDICINE " << oriMedName <<endl;
                        cout << "Press Enter to keep current value." <<endl; //if user press enter, replace the empty string with initial value
                        cout << endl;

                        cout << endl;
                        cout << "Current Medicine Supplier: "<< oriMedSupplier <<endl;
                        cout << "New Medicine Supplier: ";
                        cin.ignore();
                        getline(cin, medSupplier);
                        if(medSupplier == ""){
                            medSupplier = oriMedSupplier;
                        }

                        cout << endl;
                        cout << "Current Medicine Balance: "<< oriMedBalance <<endl;
                        cout << "New Medicine Balance: ";
                        getline(cin, medBalance);
                        if(medBalance == ""){
                            medBalance = oriMedBalance;
                        }

                        cout << endl;
                        cout << "Current Medicine Price(RM): "<<oriMedPrice<<endl;
                        cout << "New Medicine Price(RM): ";
                        getline(cin, medPrice);
                        if(medPrice == ""){
                            medPrice = oriMedPrice;
                        }

                        cout << endl;
                        tempfile << oriMedName << "\t" << medSupplier << "\t" << medBalance << "\t" << medPrice << endl;
                        cout << "Medicine record updated. "<<endl<<endl;

                        tempfile.close();
                        myfile.close();
                        remove("medicine.txt");
                        rename("temp.txt", "medicine.txt");

                        break;
                	}else{break;}
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Medicine not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to update record for another medicine (Y/N)?";
        cin>>redo;
    }while (redo == 'Y' || redo == 'y');
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void Admin::med_delete(){ //search for then delete while line, move all wanted to temp then rename
    string searchline, header, templine, deleteline, searchlineLower;
    char redo, deleteConfirm;
    ifstream myfile;

    do{
        myfile.open("medicine.txt");
        system("cls");
        cout << endl;
        cout<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"*                   DELETE MEDICINE RECORD                   *"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<endl;
        cout << "Please enter the name of medicine: ";
        cin  >> searchline;
        bool isFound=0;

        if(myfile.is_open()){
            while(!myfile.eof()){
                string medName = "", medOtherDetails = "", medLowerName = "";

                getline(myfile,medName, '\t'); //getline until "\t"
                getline(myfile,medOtherDetails);

                for (int i = 0; i<searchline.length(); i++){ //convert user input line into lowercase
                    searchlineLower[i] = tolower(searchline[i]);
                }

                for (int i = 0; i<medName.length(); i++){ //convert medicine name from file into lowercase
                    medLowerName[i] = tolower(medName[i]);
                }

                for(int i=0;i<searchline.length();i++){ //checking if user input match with any name from file
                    if(medLowerName[i]==searchlineLower[i])
                        isFound = 1;
                    else{
                        isFound =0;
                        break;
                    }
                }

                if(isFound){
                    cout << "Medicine record found! " << endl << endl;
                    myfile.seekg(0, ios::beg);
                    getline(myfile, header);
                    cout << header << endl;

                    cout << medName <<"\t"<< medOtherDetails << endl;
                    cout << endl;
                    cout << "Proceed to delete (Y/N)? ";
                    cin >> deleteConfirm;

                    deleteline = medName + "\t" + medOtherDetails;
                    ofstream tempfile;
                    tempfile.open("temp.txt");

                    if (deleteConfirm == 'Y' || deleteConfirm == 'y'){
                        myfile.seekg(0, ios::beg);
                        while(getline(myfile, templine)){
                            if (templine != deleteline){
                                tempfile << templine << endl;
                            }
                        }
                        cout << "Medicine record deleted."<<endl;
                    	tempfile.close();
                    	myfile.close();
                    	remove("medicine.txt");
                    	rename("temp.txt", "medicine.txt");
                    }

                    break;
                }
            }

            if(myfile.eof()&&(!isFound)){
                cout << "Medicine not found!\n";
            }

        }else{
            cout << "Unable to locate file for search." << endl;
        }

        cout << endl;
        cout<<"Do you want to delete record for another medicine (Y/N)?";
        cin>>redo;

    }while (redo == 'Y' || redo == 'y');
    myfile.close();
    cout<<endl;
    cout << "You will be directed to the Main Menu."<<endl<<endl;
    system("pause");
    main_menu();
}

void exitProgram(){ //exit page
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*  Thank you for using the Medical Store Management System   *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"                   Program created by : NJL - SCW - GYS - CYL "<<endl;
    cout<<endl;
    cout<<endl;
    exit(0);
}

void cust_menu(){ //menu for customer
    Admin a1;
    int menuchoice;
    system("cls");
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*               MEDICAL STORE MANAGEMENT SYSTEM              *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*                       CUSTOMER MENU                        *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"\tWhat would you like to do today?"<<endl;
    cout<<endl;
    cout<<"\t\t1) Add new customer record"<<endl;
    cout<<"\t\t2) Update customer record"<<endl;
    cout<<"\t\t3) Delete customer record"<<endl;
    cout<<"\t\t4) Search for customer record"<<endl;
    cout<<"\t\t5) List all customer record"<<endl;
    cout<<endl;
    cout<<"Please enter your choice : ";
    cin>>menuchoice;

    if(menuchoice==1){
        a1.cust_add();
    }else if(menuchoice==2){
        a1.cust_update();
    }else if(menuchoice==3){
        a1.cust_delete();
    }else if(menuchoice==4){
        a1.cust_search();
    }else if(menuchoice==5){
        a1.cust_list();
    }else{
        cout<<endl;
        cout<<"Invalid Input!"<<endl;
        cout << "You will be directed to the Main Menu."<<endl<<endl;
        system("pause");
        main_menu();
    }
}

void med_menu(){ //menu for medicine
    Admin a1;
    int menuchoice;
    system("cls");
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*               MEDICAL STORE MANAGEMENT SYSTEM              *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*                       MEDICINE MENU                        *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"\tWhat would you like to do today?"<<endl;
    cout<<endl;
    cout<<"\t\t1) Add new medicine record"<<endl;
    cout<<"\t\t2) Update medicine record"<<endl;
    cout<<"\t\t3) Delete medicine record"<<endl;
    cout<<"\t\t4) Search for medicine record"<<endl;
    cout<<"\t\t5) List all medicine record"<<endl;
    cout<<endl;
    cout<<"Please enter your choice : ";
    cin>>menuchoice;

    if(menuchoice==1){
        a1.med_add();
    }else if(menuchoice==2){
        a1.med_update();
    }else if(menuchoice==3){
        a1.med_delete();
    }else if(menuchoice==4){
        a1.med_search();
    }else if(menuchoice==5){
        a1.med_list();
    }else{
        cout<<endl;
        cout<<"Invalid Input!"<<endl;
        cout << "You will be directed to the Main Menu."<<endl<<endl;
        system("pause");
        main_menu();
    }
}

void main_menu(){
    system("cls");
    int mselect;
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*               MEDICAL STORE MANAGEMENT SYSTEM              *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*                          MAIN MENU                         *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<endl;
    cout<<"\t\t\t1) Customer Menu"<<endl;
    cout<<"\t\t\t2) Medicine Menu"<<endl;
    cout<<"\t\t\t3) Exit System"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Please select which menu you would like to go to : ";
    cin>>mselect;

    if(mselect==1){
        cust_menu();
    }else if(mselect==2){
        med_menu();
    }else if(mselect==3){
        exitProgram();
    }else{
        cout<<endl;
        cout<<"Invalid Input!"<<endl;
        cout<<"You will be directed to the Main Menu."<<endl<<endl;
        system("pause");
        main_menu();
    }
}

void login(){ //login page, with **** pw
    const string PASSWORD = "admin";
    const int ATTEMPTS = 2;
    const int pwlength = 5;
    char password[pwlength];
    string completePassword;

    for(int attemptCount = ATTEMPTS; attemptCount >=0 ; attemptCount--){
        cout<<endl;
        cout<<"\tPlease enter your password: ";

        int i = 0;
        while (i<pwlength){
            password[i] = getch();
            if(password[i] != ' '){
                completePassword = completePassword + password[i];
                cout<<"*";
            }else{
                break;
            }
            i++;
        }

        if(completePassword == PASSWORD){
            main_menu();
            break;
        }else{
            cout<<endl;
            cout<<"\tIncorrect password entered."<<endl;
            cout<<"\tWARNING : You have "<<attemptCount<<" attempt(s) left."<<endl;
            cout<<endl;
        }

        completePassword.clear();
        if(attemptCount == 0){
            cout<<"\tThe system has automatically exits itself."<<endl;
        }
    }
}

void welcome(){ //first page
    cout<<endl;
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"*                        WELCOME TO THE                      *"<<endl;
    cout<<"*               MEDICAL STORE MANAGEMENT SYSTEM              *"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<endl;
    cout<<endl;

    login();
}

int main(){
    welcome();
}

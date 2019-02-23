#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>
using namespace std;

void saveClientRecords(vector<Person> &clients);
void saveStaffRecords(vector<Person> &staff);
void savePersonalTrainerRecords(vector<Person> &personalTraining);
void saveRecords(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void loadClientRecords(vector<Person> &clients);
void loadStaffRecords(vector<Person> &staff);
void loadPersonalTrainerRecords(vector<Person> &personalTraining);
void loadRecords(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void welcomeMessage(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void fitnessProgramAssistant(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void personalTrainer(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void supervisor(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
string identification(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
string clientIdentification(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
int findUserName(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining, const string &inputUserName);
int findClientUserName(vector<Person> &clients, const string &inputUserName);
int findStaffUserName(vector<Person> &staff, const string &inputUserName);
int findPersonalTrainerUserName(vector<Person> &personalTrainersVector, const string &inputUserName);
int findClientByName(vector<Person> &clients, const string &inputName);
void supervisorMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void supervisorMainMenu2(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void client(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void clientMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining, string &username);
void fpaMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void ptMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void personalTrainingSession(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void addClient(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void addDeletePersonalTrainer(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void addDeleteFpa(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void addDeleteSupervisor(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
void viewActiveClients(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining);
const string &setTrainer(vector<Person> &personalTraining);
int getStaffList(vector<Person> &personalTrainers);

void safeDeleteCheckForTrainer(vector<Person> &clients,vector<Person> &personalTrainersVector, Person trainer);

int findTrainerByName(vector<Person> &personalTrainingVector, const string &trainerName);
int findStaffByName(vector<Person> &staff, string staffName);

Person loggedOn;

int main(){
    vector<Person> clientVector;
    vector<Person> staffVector;
    vector<Person> personalTrainersVector;
    loadRecords(clientVector, staffVector, personalTrainersVector);
    //saveClientRecords(clientVector);
    //loadClientRecords(clientVector);
    /*Person Isaiah("Isaiah Britto", 20, "08/24/1997");
    clientVector.push_back(Isaiah);
    int isaiah = findClientByName(clientVector, "Isaiah Britto");
    clientVector[isaiah].setIsAdmin(true);
    clientVector[isaiah].setUserName("iebritto");
    clientVector[isaiah].setPassword("QwErTy123456");
    clientVector[isaiah].setIsPersonalTrainer(true);
    clientVector[isaiah].setIsFpa(true);
    clientVector[isaiah].setIsClient(false);*/

    /*personalTrainersVector.push_back(clientVector[0]);
    //isaiah = findTrainerByName(personalTrainersVector, "Isaiah Britto");
    personalTrainersVector[0].setIsAdmin(true);
    personalTrainersVector[0].setUserName("iebritto");
    personalTrainersVector[0].setPassword("QwErTy123456");
    personalTrainersVector[0].setIsPersonalTrainer(true);
    personalTrainersVector[0].setIsFpa(true);
    personalTrainersVector[0].setIsClient(false);*/

    //loadRecords(clientVector, staffVector, personalTrainersVector);
    welcomeMessage(clientVector, staffVector, personalTrainersVector);
    return 0;
}

void welcomeMessage(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    string userInputStr;
    int userInput = 0;
    cout << "               Welcome to the Personal Training Tracker               \n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "What Position do you hold?\n"
            "\t1. Personal Trainer\n\t2. Fitness Program Assistant\n\t3. Supervisor\n"
            "\t4. Client\n"
            "Enter corresponding number: ";
    cin >> userInputStr;
    try {
        userInput = stoi(userInputStr);
    }catch (exception &e){
        cout << "\nInvalid input, only enter numbers 1, 2 or 3.\n\n\n";
        welcomeMessage(clients, staff, personalTrainersVector);
    }

    if (userInput == 1){
        cout << string(50, '\n');
        personalTrainer(clients, staff, personalTrainersVector);
    }else if(userInput == 2){
        cout << string(50, '\n');
        fitnessProgramAssistant(clients, staff, personalTrainersVector);
    }else if(userInput == 3){
        cout << string(50, '\n');
        supervisor(clients, staff, personalTrainersVector);
    }else if(userInput == 4){
        client(clients, staff, personalTrainersVector);
    }else {
        cout << "\nPlease enter either 1, 2 or 3 only.\n\n";
        welcomeMessage(clients, staff, personalTrainersVector);
    }

}

void supervisor(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    if(identification(clients, staff, personalTrainersVector) == loggedOn.getUserName()){
        cout << string(50, '\n');
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(identification(clients, staff, personalTrainersVector) == "NOT-AUTHORIZED"){
        int userInput;
        cout << string(50, '\n');
        cout << "Username and Password to not match out records. Would you like to:\n"
                "1. Go back to the Welcome screen\n"
                "2. Try entering your Username and Password again\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            welcomeMessage(clients, staff, personalTrainersVector);
        }else if(userInput == 2){
            supervisor(clients, staff, personalTrainersVector);
        }else{
            cout << "\nPlease enter either 1 or 2 only.\n\n";
            supervisor(clients, staff, personalTrainersVector);
        }
    }
}

void personalTrainer(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << string(50, '\n');
    string clear = identification(clients, staff, personalTrainersVector);
    if( clear == loggedOn.getUserName()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(clear == "NOT-AUTHORIZED"){
        int userInput;
        cout << string(50, '\n');
        cout << "Username and Password do not match out records. Would you like to:\n"
                "1. Go back to the Welcome screen\n"
                "2. Try entering your Username and Password again\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            cout << string(50, '\n');
            welcomeMessage(clients, staff, personalTrainersVector);
        }else if(userInput == 2){
            personalTrainer(clients, staff, personalTrainersVector);
        }else{
            cout << "\nPlease enter either 1 or 2 only.\n\n";
            personalTrainer(clients, staff, personalTrainersVector);
        }
    }
}

void fitnessProgramAssistant(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    if(identification(clients, staff, personalTrainersVector) == loggedOn.getUserName()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }else if(identification(clients, staff, personalTrainersVector) == "NOT-AUTHORIZED"){
        int userInput;
        cout << "Username and Password to not match our records. Would you like to:\n"
                "1. Go back to the Welcome screen\n"
                "2. Try entering your Username and Password again\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            welcomeMessage(clients, staff, personalTrainersVector);
        }else if(userInput == 2){
            personalTrainer(clients, staff, personalTrainersVector);
        }else{
            cout << "\nPlease enter either 1 or 2 only.\n\n";
            personalTrainer(clients, staff, personalTrainersVector);
        }
    }
}

void client(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining){
    string username = clientIdentification(clients, staff, personalTraining);
    if(username == "NOT-AUTHORIZED"){
        int userInput;
        cout << "Username and Password to not match our records. Would you like to:\n"
                "1. Go back to the Welcome screen\n"
                "2. Try entering your Username and Password again\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            welcomeMessage(clients, staff, personalTraining);
        }else if(userInput == 2){
            client(clients, staff, personalTraining);
        }else{
            cout << "\nPlease enter either 1 or 2 only.\n\n";
            client(clients, staff, personalTraining);
        }
    }else {
        clientMenu(clients, staff, personalTraining, username);
    }
}
void clientMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining, string &username){
    int userinput, location;
    location = findClientUserName(clients, username);
    cout << "\n\nWhat information would you like to change?\n"
            "1. Name\n"
            "2. Username\n"
            "3. Password\n"
            "4. Date of Birth\n"
            "5. Age\n"
            "6. Log out\n"
            "Enter corresponding number: ";
    cin >> userinput;
    if(userinput == 1){
        string firstName, lastName, newName;
        cout << "Currently your name in our records is " << clients[location].getName() << ".\n";
        cout << "What would you like to change your first name to? ";
        cin >> firstName;
        cout << "What would you like to change your last name to? ";
        cin >> lastName;
        newName = firstName + " " + lastName;
        cout << "Your name in our records has been changed from " << clients[location].getName() << " to " << newName << ".\n";
        clients[location].setName(newName);
        saveClientRecords(clients);
        clientMenu(clients, staff, personalTraining ,username);
    }else if(userinput == 2){
        string newUsername;
        cout << "Currently your username in our records is " << clients[location].getUserName() << ".\n";
        cout << "What would you like to change your username to? ";
        cin >> newUsername;
        cout << "Your username in our records has been changed from " << clients[location].getUserName() << " to " << newUsername << ".\n";
        clients[location].setUserName(newUsername);
        saveClientRecords(clients);
        clientMenu(clients, staff, personalTraining ,username);
    }else if(userinput == 3){
        string password;
        cout << "Currently your password in our records is " << clients[location].getName() << ".\n";
        cout << "What would you like to change your password to? ";
        cin >> password;
        cout << "Your password in our records has been changed from " << clients[location].getPassword() << " to " << password << ".\n";
        clients[location].setPassword(password);
        saveClientRecords(clients);
        clientMenu(clients, staff, personalTraining ,username);
    }else if(userinput == 4){
        string dob;
        cout << "Currently your date of birth in our records is " << clients[location].getName() << ".\n";
        cout << "What would you like to change your date of birth to? ";
        cin >> dob;
        cout << "Your date of birth in our records has been changed from " << clients[location].getName() << " to " << dob << ".\n";
        clients[location].setDob(dob);
        saveClientRecords(clients);
        clientMenu(clients, staff, personalTraining ,username);
    }else if(userinput == 5){
        int age;
        cout << "Currently your age in our records is " << clients[location].getAge() << ".\n";
        cout << "What would you like to change your age to? ";
        cin >> age;
        cout << "Your age in our records has been changed from " << clients[location].getAge() << " to " << age << ".\n";
        clients[location].setAge(age);
        saveClientRecords(clients);
        clientMenu(clients, staff, personalTraining ,username);
    }else if(userinput == 6){
        welcomeMessage(clients, staff, personalTraining);
    }else{
        cout << "Invalid input. Only enter 1, 2, 3, 4, 5 or 6.";
        clientMenu(clients, staff, personalTraining ,username);
    }
}

string identification(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    string userName, password;
    cout << "Username: ";
    cin.ignore();
    getline(cin, userName);
    int location = findStaffUserName(staff, userName);
    if (location == -1) {
        location = findPersonalTrainerUserName(personalTrainersVector, userName);
        if (location == -1) {
            cout << "\nUsername '" << userName << "' was not found. Please try again.\n"
                                                  "\t*remember* Username and Password are case sensitive.\n\n\n\n\n";
            welcomeMessage(clients, staff, personalTrainersVector);
        } else if (location > -1) {
            loggedOn = personalTrainersVector[location];
            cout << "Password: ";
            cin >> password;
            if (personalTrainersVector[location].getPassword() == password) {
                cout << string(50, '\n');
                cout << "\nWelcome " << personalTrainersVector[location].getName() << ".\n";
                return userName;
            }else {
                return "NOT-AUTHORIZED";
            }
        }
    } else if (location > -1) {
        loggedOn = staff[location];
        cout << "Password: ";
        cin >> password;
        if (staff[location].getPassword() == password) {
            cout << string(50, '\n');
            cout << "\nWelcome " << staff[location].getName() << ".\n";
            return userName;
        } else {
            return "NOT-AUTHORIZED";
        }
    }
}

string clientIdentification(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining){
    string userName, password;
    cout << "Username: ";
    cin.ignore();
    getline(cin, userName);
    int location = findClientUserName(clients, userName);
    if (location == -1) {
        cout << "\nUsername '" << userName << "' was not found. Please try again.\n"
                                              "\t*remember* Username and Password are case sensitive.\n";
        if(loggedOn.getIsAdmin()){
            supervisorMainMenu(clients, staff, personalTraining);
        }else if(loggedOn.getIsPersonalTrainer()){
            ptMainMenu(clients, staff, personalTraining);
        }
    } else if (location > -1) {
        cout << "Password: ";
        cin >> password;
        if (clients[location].getPassword() == password) {
            cout << string(50, '\n');
            cout << "\nWelcome " << clients[location].getName() << ".\n";
            return userName;
        }else {
            return "NOT-AUTHORIZED";
        }
    }
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTraining);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTraining);
    }
}

int findUserName(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector, const string &inputUserName) {
    int location = -1;
    for(unsigned int i = 0; i < clients.size(); i++){
        if(clients[i].getUserName() == inputUserName){
            location = i;
        }
    }
    for(unsigned int i = 0; i < staff.size(); i++){
        if(staff[i].getUserName() == inputUserName){
            location = i;
        }
    }
    for(unsigned int i = 0; i < personalTrainersVector.size(); i++){
        if(personalTrainersVector[i].getUserName() == inputUserName){
            location = i;
        }
    }
    return location;
}

int findClientUserName(vector<Person> &clients, const string &inputUserName){
    int location = -1;
    for(unsigned int i = 0; i < clients.size(); i++){
        if(clients[i].getUserName() == inputUserName){
            location = i;
        }
    }
    return location;
}

int findStaffUserName(vector<Person> &staff, const string &inputUserName){
    int location = -1;
    for(unsigned int i = 0; i < staff.size(); i++){
        if(staff[i].getUserName() == inputUserName){
            location = i;
        }
    }
    return location;
}

int findPersonalTrainerUserName(vector<Person> &personalTrainersVector, const string &inputUserName){
    int location = -1;
    for(unsigned int i = 0; i < personalTrainersVector.size(); i++){
        if(personalTrainersVector[i].getUserName() == inputUserName){
            location = i;
        }
    }
    return location;
}

void supervisorMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    cout << string(50, '\n');
    int userInput;
    cout << "What would you like to do?\n"
            "1. Conduct Personal Training Session\n"
            "2. Add Client\n"
            "3. View Active Clients\n"
            "4. Add/Delete Fitness Program Assistant\n"
            "5. Add/Delete Supervisor\n"
            "6. Add/Delete Personal Trainer\n"
            "7. Additional Options\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        personalTrainingSession(clients, staff, personalTrainersVector);
    }else if(userInput == 2){
        addClient(clients, staff, personalTrainersVector);
    }else if(userInput == 3){
        viewActiveClients(clients, staff, personalTrainersVector);
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(userInput == 4){
        addDeleteFpa(clients,staff, personalTrainersVector);
    }else if(userInput == 5){
        addDeleteSupervisor(clients, staff, personalTrainersVector);
    }else if(userInput == 6){
        addDeletePersonalTrainer(clients, staff, personalTrainersVector);
    }else if(userInput == 7){
        supervisorMainMenu2(clients, staff, personalTrainersVector);
    }else{
            cout << "\nEnter only 1, 2, 3, 4, 5 or 6.\n";
            supervisorMainMenu(clients, staff, personalTrainersVector);
    }
}

void supervisorMainMenu2(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector) {
    cout << string(50, '\n');
    int userInput;
    cout << "What would you like to do?\n"
            "1. View Complete Client Record\n"
            "2. Save and Exit\n"
            "3. Clear\n"
            "4. Size\n"
            "5. \n"
            "6. \n"
            "7. Return to Previous Menu Options\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        cout << "\n\nHow would you like to view complete client records?\n"
                "1. View a single clients complete record\n"
                "2. View complete records for a given Personal Trainer\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if(userInput == 1){
            string clientName;
            cout << "\n\nWould you like to\n"
                    "1. View all clients\n"
                    "2. View a given Personal Trainers Clients\n"
                    "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                cout << "\n\nWhich Client would you like to view?\n";
                for(unsigned int i = 0; i < clients.size(); i++) {
                    cout << i+1 << ". " << clients[i].getName() << endl;
                }
                cout << "Enter corresponding number: ";
                cin >> userInput;
                cout << clients[userInput-1];
                cout << clients[userInput-1].getAddingSessionRecord();
                cout << "\n" << clients[userInput-1].getSessionRecord();
            }else if(userInput == 2){
                string trainer = setTrainer(personalTrainersVector);
                int count = 1;
                string clientName;
                cout << "\n\nWhich Client would you like to view?\n";
                for(unsigned int i = 0; i < clients.size(); i++) {
                    if(trainer == clients[i].getClientTrainer()){
                        cout << count << ". " << clients[i].getName() << endl;
                        count++;
                    }
                }
                cout << "Enter corresponding number: ";
                cin >> userInput;
                int iterator = 0;
                for(unsigned int i = 0; i < clients.size(); i++) {
                    if(trainer == clients[i].getClientTrainer()){
                        if(iterator == userInput){
                            clientName = clients[i].getName();
                        }
                    iterator++;
                    }
                }
                int location = findClientByName(clients, clientName);
                cout << clients[location];
                cout << clients[location].getAddingSessionRecord() << "\n";
                cout << clients[location].getSessionRecord() << "\n";
            }else{
                cout << "Invalid input. Enter only 1 or 2.\n";
                supervisorMainMenu2(clients, staff, personalTrainersVector);
            }
        }else if(userInput == 2){
            string trainer = setTrainer(personalTrainersVector);
            string clientName;
            for(unsigned int i = 0; i < clients.size(); i++) {
                if(trainer == clients[i].getClientTrainer()){
                    cout << clients[i];
                    cout << clients[i].getAddingSessionRecord();
                    cout << clients[i].getSessionRecord();
                }
            }
        }else{
            cout << "Invalid input. Enter only 1 or 2.\n";
            supervisorMainMenu2(clients, staff, personalTrainersVector);
        }
    }else if(userInput == 2){
        //saveClientRecords(clients);
        saveRecords(clients, staff, personalTrainersVector);
    }else if(userInput == 3){
        vector<Person> newVector;
        clients = newVector;
    }else if(userInput == 4){
        cout << clients.size();
    }else if(userInput == 5){
        for(int i = 0; i < clients.size(); i++){
            cout << "\n" << clients[i].getSessionRecord();
        }

    }else if(userInput == 6){

    }else if(userInput == 7){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else{
        cout << "\nEnter only 1, 2, 3, 4, 5, 6 or 7.\n";
        supervisorMainMenu2(clients, staff, personalTrainersVector);
    }
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsFpa()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

int getStaffList(vector<Person> &personalTrainers) {
    int userInput;
    string ptName;
    cout << "Staff List:\n\n";
    for(unsigned int i; i < personalTrainers.size(); i++){
        cout << i+1 << ". " << personalTrainers[i].getName() << endl;
    }
    cout << "\nEnter corresponding number for the correct trainer: ";
    cin >> userInput;
    return userInput-1;
}

void ptMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << string(50, '\n');
    int userInput;
    cout << "What would you like to do?\n"
            "1. Conduct Personal Training Session\n"
            "2. View Active Clients\n"
            "3. Add Client\n"
            "4. Log Out\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        personalTrainingSession(clients, staff, personalTrainersVector);
    }else if(userInput == 2){
        cout << loggedOn.getName() << "'s client list:\n";
        for(unsigned int i = 0; i < clients.size(); i++){
            if (clients[i].getClientTrainer() == loggedOn.getName())
                cout << "\t" << clients[i];
        }
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(userInput == 3){
        addClient(clients, staff, personalTrainersVector);
    }else if(userInput == 4){
        cout << "You are being signed out..\n";
        welcomeMessage(clients, staff, personalTrainersVector);
    }else{
        cout << "\nEnter only 1, 2, or 3.\n";
        ptMainMenu(clients, staff, personalTrainersVector);
    }
}

void fpaMainMenu(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << string(50, '\n');
    int userInput;
    cout << "What would you like to do?\n"
            "1. View Active Clients\n"
            "2. Add Client\n"
            "3. Log Out\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        viewActiveClients(clients, staff, personalTrainersVector);
        fpaMainMenu(clients, staff, personalTrainersVector);
    }else if(userInput == 2){
        addClient(clients, staff, personalTrainersVector);
    }else if(userInput == 3){
        cout << "You are being signed out..\n";
        welcomeMessage(clients, staff, personalTrainersVector);
    }else{
        cout << "\nEnter only 1 or 2.\n";
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

void viewActiveClients(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << string(50, '\n');
    int userInput;
    cout << "How would you like to view the active clients?\n"
            "1. View All\n"
            "2. View By Personal Trainer\n"
            "3. Go back to to previous menu\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        cout << string(50, '\n');
        for(unsigned int i = 0; i < clients.size(); i++){
            cout << clients[i];
        }
    }else if(userInput == 2){
        cout << string(50, '\n');
        for(unsigned int i = 0; i < personalTrainersVector.size(); i++){
            cout << endl << personalTrainersVector[i].getName() << "'s Clients: \n";
            for(unsigned int j = 0; j < clients.size(); j++){
                if (clients[j].getClientTrainer() == personalTrainersVector[i].getName())
                    cout << "\t" <<clients[j];
            }
        }
        int noTrainerCount = 0;
        for(unsigned int j = 0; j < clients.size(); j++){
            if (clients[j].getClientTrainer() == "NoTrainer")
                noTrainerCount++;
        }
        if(noTrainerCount > 0){
            cout << endl << "NoTrainer's Clients: \n";
            for(unsigned int j = 0; j < clients.size(); j++){
                if (clients[j].getClientTrainer() == "NoTrainer")
                    cout << "\t" <<clients[j];
            }
        }
    }else if(userInput == 3){
        if(loggedOn.getIsAdmin()){
            supervisorMainMenu(clients, staff, personalTrainersVector);
        }else if(loggedOn.getIsPersonalTrainer()){
            ptMainMenu(clients, staff, personalTrainersVector);
        }else if(loggedOn.getIsFpa()){
            fpaMainMenu(clients, staff, personalTrainersVector);
        }
    }else{
        cout << "\nEnter only 1, 2 or 3.\n";
        viewActiveClients(clients,staff, personalTrainersVector);
    }
}

void addDeleteSupervisor(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    int userInput;
    cout << "What would you like to do?\n"
            "1. Add Supervisor\n"
            "2. Delete Supervisor\n"
            "3. Give Supervisor Access\n"
            "4. Delete Supervisor Access\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if(userInput == 1){
        cout << string(50, '\n');
        string firstName, lastName, supName, supDob;
        int supAge;
        cout << "Enter supervisors first name: ";
        cin >> firstName;
        cout << "Enter " << firstName << "'s last name: ";
        cin >> lastName;
        supName = firstName + " " + lastName;
        cout << "Enter " << supName << "'s age: ";
        cin >> supAge;
        cout << "(Format: MM/DD/YYYY)\nEnter " << supName << "'s Date Of Birth: ";
        cin >> supDob;
        Person newSupervisor(supName, supAge, supDob);
        newSupervisor.setIsAdmin(true);
        newSupervisor.setIsClient(false);
        newSupervisor.setUserName(supName);
        newSupervisor.setPassword(supDob);

        cout << "Is " << supName << " a Personal Trainer as well?\n"
                                    "1. Yes\n"
                                    "2. No\n"
                                    "Enter corresponding number: ";
        cin >> userInput;
        if(userInput == 1){
            newSupervisor.setIsPersonalTrainer(true);
            personalTrainersVector.push_back(newSupervisor);
            staff.push_back(newSupervisor);
            savePersonalTrainerRecords(personalTrainersVector);
            saveStaffRecords(staff);
            cout << supName << " has been added to the supervisor and personal training lists.\n";
        }else {
            newSupervisor.setIsPersonalTrainer(false);
            staff.push_back(newSupervisor);
            savePersonalTrainerRecords(personalTrainersVector);
            cout << supName << " has been added to the supervisor list.\n";
        }
        if(loggedOn.getIsAdmin()){
            supervisorMainMenu(clients, staff, personalTrainersVector);
        }else if(loggedOn.getIsPersonalTrainer()){
            ptMainMenu(clients, staff, personalTrainersVector);
        }else if(loggedOn.getIsFpa()){
            fpaMainMenu(clients, staff, personalTrainersVector);
        }
    }else if(userInput == 2){
        cout << "Would you like to:\n"
                "1. Remove Supervisor Access\n"
                "2. Delete Supervisor completely from records\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if(userInput == 1){
            string deleteSup;
            int count = 1;
            cout << "Which supervisor would you like to remove access for?\n";
            for(unsigned int i = 0; i < staff.size(); i++){
                if(staff[i].getIsAdmin()){
                    cout << count << staff[i].getName() << endl;
                    count++;
                }
            }
            cout << "\nPlease enter the full name of correct supervisor: ";
            cin >> deleteSup;
            int staffLocation = findStaffByName(staff, deleteSup);
            if(staff[staffLocation].getIsPersonalTrainer() || staff[staffLocation].getIsFpa()){
                staff[staffLocation].setIsAdmin(false);
                saveStaffRecords(staff);
                cout << deleteSup << "'s supervisor access has been removed.\n\n";
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else{
                cout << staff[staffLocation].getName() << " is only in the system as a Supervisor.\nDeleting " << staff[staffLocation].getName()
                        << " will permanently remove them from records.\n"
                           "What would you like to do?\n"
                           "1. Remove Supervisor Access and Delete " << staff[staffLocation].getName() << " from records\n"
                           "2. Remove Supervisor Access but give " << staff[staffLocation].getName() << " another level of access\n"
                        << "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    cout << "Are you sure you want to permanently delete " << staff[staffLocation].getName() << " from records?\n"
                                                                                                                "1. Yes\n"
                                                                                                                "2. No\n"
                                                                                                                "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        staff[staffLocation] = staff[staff.size()];
                        staff.pop_back();
                        saveStaffRecords(staff);
                    }else if(userInput == 2){
                        addDeleteSupervisor(clients, staff, personalTrainersVector);
                    }
                }else if(userInput == 2){
                    cout << "What access would you like to give before removing Supervisor Access?\n"
                            "1. Personal Trainer\n"
                            "2. Fitness Program Assistant\n"
                            "3. Both Personal Trainer & Fitness Program Assistant\n"
                            "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        staff[staffLocation].setIsPersonalTrainer(true);
                        saveStaffRecords(staff);
                        personalTrainersVector.push_back(staff[staffLocation]);
                        savePersonalTrainerRecords(personalTrainersVector);
                        cout << staff[staffLocation].getName() <<  " has been given Personal Trainer access and has been added to the active Personal Trainer list.\n\n";
                        supervisorMainMenu(clients, staff, personalTrainersVector);
                    }else if(userInput == 2){
                        staff[staffLocation].setIsFpa(true);
                        saveStaffRecords(staff);
                        cout << staff[staffLocation].getName() <<  " has been given FPA access.\n\n";
                    }else if(userInput == 3){
                        staff[staffLocation].setIsPersonalTrainer(true);
                        staff[staffLocation].setIsFpa(true);
                        personalTrainersVector.push_back(staff[staffLocation]);
                        savePersonalTrainerRecords(personalTrainersVector);
                        saveStaffRecords(staff);
                        cout << staff[staffLocation].getName() <<  " has been given Personal Trainer and FPA access.\n\n";
                    }else{
                        cout << "Invalid input. Only enter 1, 2 or 3.\n";
                        addDeleteSupervisor(clients, staff, personalTrainersVector);
                    }
                }
            }
            staff[staffLocation].setIsAdmin(false);
            saveStaffRecords(staff);
            cout << deleteSup << " no longer has Supervisor Access.";
            supervisorMainMenu(clients, staff, personalTrainersVector);
        }else if(userInput == 2){
            cout << "Are you sure you want to delete a supervisor permanently?\n"
                    "1. Yes\n"
                    "2. No\n"
                    "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                int count = 1;
                string deleteSup;
                cout << "Which supervisor would you like to remove access for?\n";
                for(unsigned int i = 0; i < staff.size(); i++){
                    if(staff[i].getIsAdmin()) {
                        cout << count << ". " << staff[i];
                        count++;
                    }
                }
                cout << "\nPlease enter the full name of correct supervisor: ";
                cin >> deleteSup;
                int located = findStaffByName(staff, deleteSup);
                if(located == -1){
                    cout << "Supervisor's name was not correct. You are being brought back to the main add/delete menu\n";
                    addDeleteSupervisor(clients, staff, personalTrainersVector);
                }else{
                    if(staff[located].getIsPersonalTrainer()){
                        safeDeleteCheckForTrainer(clients, personalTrainersVector, staff[located]);
                    }
                        //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                        // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                    staff[located] = staff[staff.size()];
                    staff.pop_back();
                    saveStaffRecords(staff);
                }
                cout << deleteSup << " has been fully deleted.";
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else{
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }

        }else{
            cout << "\nEnter only 1 or 2.\n";
            addDeleteSupervisor(clients, staff, personalTrainersVector);
        }
    }else if(userInput == 3){
        int staffMember;
        cout << "Which employee would you like to give Supervisor Access to?\n";
        unsigned int i = 0;
        for(i; i < staff.size(); i++){
                cout << (i+1) << ". " << staff[i].getName() << endl;
        }
        cout << "Enter corresponding number: ";
        cin >> staffMember;
        staff[staffMember].setIsAdmin(true);
        saveStaffRecords(staff);
        cout << staff[staffMember].getName() << " has been given Supervisor Access.\n";
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(userInput == 4){
        string deleteSup;
        int count = 1;
        cout << "Which supervisor would you like to remove access for?\n";
        for(unsigned int i = 0; i < staff.size(); i++){
            if(staff[i].getIsAdmin()){
                cout << count << staff[i].getName() << endl;
                count++;
            }
        }
        cout << "\nPlease enter the full name of correct supervisor: ";
        cin >> deleteSup;
        int staffLocation = findStaffByName(staff, deleteSup);
        if(staff[staffLocation].getIsPersonalTrainer() || staff[staffLocation].getIsFpa()){
            int ptLocation = findPersonalTrainerUserName(personalTrainersVector, staff[staffLocation].getUserName());
            personalTrainersVector[ptLocation].setIsAdmin(false);
            staff[staffLocation].setIsAdmin(false);
            savePersonalTrainerRecords(personalTrainersVector);
            saveStaffRecords(staff);
            cout << deleteSup << "'s supervisor access has been removed.\n\n";
            supervisorMainMenu(clients, staff, personalTrainersVector);
        }else{
            cout << staff[staffLocation].getName() << " is only in the system as a Supervisor.\nDeleting " << staff[staffLocation].getName()
                 << " will permanently remove them from records.\n"
                    "What would you like to do?\n"
                    "1. Remove Supervisor Access and Delete " << staff[staffLocation].getName() << " from records\n"
                                                                                                   "2. Remove Supervisor Access but give " << staff[staffLocation].getName() << " another level of access\n"
                 << "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                cout << "Are you sure you want to permanently delete " << staff[staffLocation].getName() << " from records?\n"
                                                                                                            "1. Yes\n"
                                                                                                            "2. No\n"
                                                                                                            "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                    // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                    staff[staffLocation] = staff[staff.size()];
                    staff.pop_back();
                    saveStaffRecords(staff);
                }else if(userInput == 2){
                    addDeleteSupervisor(clients, staff, personalTrainersVector);
                }
            }else if(userInput == 2){
                cout << "What access would you like to give before removing Supervisor Access?\n"
                        "1. Personal Trainer\n"
                        "2. Fitness Program Assistant\n"
                        "3. Both Personal Trainer & Fitness Program Assistant\n"
                        "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    staff[staffLocation].setIsPersonalTrainer(true);
                    staff[staffLocation].setIsAdmin(false);
                    personalTrainersVector.push_back(staff[staffLocation]);
                    saveStaffRecords(staff);
                    savePersonalTrainerRecords(personalTrainersVector);
                    cout << staff[staffLocation].getName() <<  " has been given Personal Trainer access and has been added to the active Personal Trainer list.\n\n";
                    supervisorMainMenu(clients, staff, personalTrainersVector);
                }else if(userInput == 2){
                    staff[staffLocation].setIsFpa(true);
                    staff[staffLocation].setIsAdmin(false);
                    saveStaffRecords(staff);
                    cout << staff[staffLocation].getName() <<  " has been given FPA access.\n\n";
                }else if(userInput == 3){
                    staff[staffLocation].setIsPersonalTrainer(true);
                    staff[staffLocation].setIsFpa(true);
                    staff[staffLocation].setIsAdmin(false);
                    personalTrainersVector.push_back(staff[staffLocation]);
                    saveStaffRecords(staff);
                    savePersonalTrainerRecords(personalTrainersVector);
                    cout << staff[staffLocation].getName() <<  " has been given Personal Trainer and FPA access.\n\n";
                }else{
                    cout << "Invalid input. Only enter 1, 2 or 3.\n";
                    addDeleteSupervisor(clients, staff, personalTrainersVector);
                }
            }
        }
        //staff[staffLocation].setIsAdmin(false);
        cout << deleteSup << " no longer has Supervisor Access.";
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else{
        cout << "Invalid Input. Only enter 1, 2, 3 or 4.\n\n";
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }
}

int findStaffByName(vector<Person> &staff, string staffName) {
    int location = -1;
    for(unsigned int i = 0; i < staff.size(); i++){
        if(staff[i].getName() == staffName){
            location = i;
        }
    }
    return location;
}

void safeDeleteCheckForTrainer(vector<Person> &clients, vector<Person> &personalTrainersVector, Person trainer) {
    int userInput;
    if(trainer.getIsPersonalTrainer()){
        int clientCount = 1;
        cout << trainer.getName() << "'s client list:\n";
        for(unsigned int i = 0; i < clients.size(); i ++){
            if(clients[i].getClientTrainer() == trainer.getName()){
                cout << clientCount << ". " << clients[i].getName() << endl;
                clientCount++;
            }
        }
        if(clientCount-1 == 0){
            cout << "\n" << trainer.getName() << " has " << clientCount-1 << " clients.";
        }else{
            cout << "\n" << trainer.getName() << " has " << clientCount-1 << " clients. What would you like to do?\n"
                                                                             "1. Set every client's trainer to default\n"
                                                                             "2. Set every client's trainer to another active Personal Trainer\n"
                                                                             "3. Set each client's trainer individually\n"
                                                                             "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                for(unsigned int i = 0; i < clients.size(); i ++){
                    if(clients[i].getClientTrainer() == trainer.getName()){
                        clients[i].setClientTrainer("NoTrainer");
                    }
                }
                saveClientRecords(clients);
                cout << "The default 'NoTrainer' has been set as the new trainer for all of " << trainer.getName() << "'s clients.\n";
            }else if(userInput == 2){
                string newTrainer = setTrainer(personalTrainersVector);
                for(unsigned int i = 0; i < clients.size(); i ++){
                    if(clients[i].getClientTrainer() == trainer.getName()){
                        clients[i].setClientTrainer(newTrainer);
                    }
                }
                saveClientRecords(clients);
                cout << newTrainer << " has been set as the new trainer for all of " << trainer.getName() << "'s clients.\n";
            }else if(userInput == 3){
                for(unsigned int i = 0; i < clients.size(); i ++){
                    if(clients[i].getClientTrainer() == trainer.getName()){
                        string newTrainer = setTrainer(personalTrainersVector);
                        clients[i].setClientTrainer(newTrainer);
                        cout << newTrainer << " has been set as the new trainer for " << clients[i].getName() << ".\n";
                    }
                }
                saveClientRecords(clients);
            }else{
                cout << "Invalid input. Enter only 1, 2 or 3.\n";
                safeDeleteCheckForTrainer(clients, personalTrainersVector, trainer);
            }
            cout << "All of " << trainer.getName() << "'s active clients have been given a new trainer in our records.\n"
                  << "It is now safe to continue removing " << trainer.getName();
        }
    }
}

const string &setTrainer(vector<Person> &personalTrainers) {
    int userInput;
    string ptName;
    cout << "Personal Trainer List:\n\n";
    if(personalTrainers.size() == 0){
        cout << "There are currently no personal trainers in the system.\n"
                "The trainer has been set to \"NoTrainer\"\n";
        ptName = "NoTrainer";
    }else {
        for(unsigned int i = 0; i < personalTrainers.size(); i++){
            cout << i+1 << ". " << personalTrainers[i].getName() << "\n";
        }
        cout << "\nEnter corresponding number for the correct trainer: ";
        cin >> userInput;
        ptName = personalTrainers[userInput-1].getName();
    }
    return ptName;
}

void addDeleteFpa(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    int userInput;
    cout << "Would you like to add or delete a Fitness Programs Assistant?\n"
            "1. Add\n"
            "2. Delete\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        cout << "Is the new Fitness Programs Assistant currently an employee?\n"
                "1. Yes\n"
                "2. No\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            int staffLocation = getStaffList(staff);
            staff[staffLocation].setIsFpa(true);
            staff.push_back(staff[staffLocation]);
            saveStaffRecords(staff);
        }else if (userInput == 2){
            cout << string(50, '\n');
            string firstName, lastName, fpaName, fpaDob;
            int staffAge;
            cout << "Enter employee's first name: ";
            cin >> firstName;
            cout << "Enter " << firstName << "'s last name: ";
            cin >> lastName;
            fpaName = firstName + " " + lastName;
            cout << "Enter " << fpaName << "'s age: ";
            cin >> staffAge;
            cout << "(Format: MM/DD/YYYY)\nEnter " << fpaName << "'s Date Of Birth: ";
            cin >> fpaDob;
            Person newFpa(fpaName, staffAge, fpaDob);
            newFpa.setIsFpa(true);
            newFpa.setIsClient(false);
            cout << "Does " << firstName << " hold any other positions?\n"
                                            "1. Yes\n"
                                            "2. No\n"
                                            "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                cout << "Is " << firstName << " also an Admin?\n"
                                              "1. Yes\n"
                                              "2. No\n"
                                              "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    newFpa.setIsAdmin(true);
                }else {
                    newFpa.setIsAdmin(false);
                }
                newFpa.setUserName(fpaName);
                newFpa.setPassword(fpaDob);
                staff.push_back(newFpa);
                cout << "Is " << firstName << " also a Personal Trainer?\n"
                                              "1. Yes\n"
                                              "2. No\n"
                                              "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    newFpa.setIsPersonalTrainer(true);
                    personalTrainersVector.push_back(newFpa);
                    savePersonalTrainerRecords(personalTrainersVector);
                }else {
                    newFpa.setIsPersonalTrainer(false);
                }
                staff.push_back(newFpa);
                saveStaffRecords(staff);
            }else if(userInput ==2){
                newFpa.setIsAdmin(false);
                newFpa.setIsPersonalTrainer(false);
                newFpa.setUserName(fpaName);
                newFpa.setPassword(fpaDob);
                staff.push_back(newFpa);
                saveStaffRecords(staff);
            }else {
                cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
                supervisorMainMenu2(clients, staff, personalTrainersVector);
            }
            cout << fpaName << " has been added to the records.\n";
        }else {
            cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
            supervisorMainMenu2(clients, staff, personalTrainersVector);
        }
    }else if (userInput == 2){
        cout << "Which Fitness Programs Assistant would you like to delete?\n";
        string fpaToDelete = setTrainer(staff);
        int count = 1;
        for(int i = 0; i < staff.size(); i++){
            cout << "\n";
            if(staff[i].getIsFpa()){
                cout << count << staff[i].getName() << "\n";
            }
        }
        cout << "Enter correct FPA's full name: ";
        cin >> fpaToDelete;
        int fpaLocation = findStaffByName(staff, fpaToDelete);
        if(fpaLocation == -1){
            cout << fpaToDelete << " is not a valid name.\nYou are being redirected.\n\n";
            addDeleteFpa(clients, staff, personalTrainersVector);
        }
        cout << "Would you like to: \n1. Permanently delete " << staff[fpaLocation].getName() << "\n";
        cout << "2. Remove FPA status but still keep " << staff[fpaLocation].getName() << " in the records\n";
        cout << "Enter corresponding number: ";
        cin >> userInput;
        if(userInput == 1){
            cout << "Are you sure you would like to permanently delete " << staff[fpaLocation].getName() << "?\n";
            cout << "1. Yes\n"
                    "2. no\n"
                    "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                safeDeleteCheckForTrainer(clients, personalTrainersVector, staff[fpaLocation]);
                cout << staff[fpaLocation].getName() << " is now being removed..\n";
                //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                staff[fpaLocation] = staff[staff.size()];
                staff.pop_back();
                saveStaffRecords(staff);
                cout << fpaToDelete << " has been safely removed from the records.\n";
            }else if(userInput == 2){
                cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                addDeletePersonalTrainer(clients, staff, personalTrainersVector);
            }else{
                cout << "Invalid input. Enter only 1 or 2.\n";
                cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                addDeletePersonalTrainer(clients, staff, personalTrainersVector);
            }
        }else if(userInput == 2){
            safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[fpaLocation]);

            if(staff[fpaLocation].getIsPersonalTrainer() || staff[fpaLocation].getIsAdmin()){
                staff[fpaLocation].setIsFpa(false);
                cout << staff[fpaLocation].getName() << "'s FPA access has been removed.\n\n";
                saveStaffRecords(staff);
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else{
                cout << staff[fpaLocation].getName() << " is only in the system as an FPA.\nDeleting " << personalTrainersVector[fpaLocation].getName()
                     << " will permanently remove them from records.\n"
                        "What would you like to do?\n"
                        "1. Remove FPA Access and Delete " << staff[fpaLocation].getName() << " from records\n"
                                                                                                                                "2. Remove FPA Access but give " << personalTrainersVector[fpaLocation].getName() << " another level of access\n"
                     << "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    cout << "Are you sure you would like to permanently delete " << staff[fpaLocation].getName() << "?\n";
                    cout << "1. Yes\n"
                            "2. no\n"
                            "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        //safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[fpaLocation]);
                        cout << staff[fpaLocation].getName() << " is now being removed..";
                        //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                        // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                        staff[fpaLocation] = staff[staff.size()];
                        staff.pop_back();
                        saveStaffRecords(staff);
                        cout << fpaToDelete << " has been safely removed from the records.\n";
                    }else if(userInput == 2){
                        cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                        addDeletePersonalTrainer(clients, staff, personalTrainersVector);
                    }else{
                        cout << "Invalid input. Enter only 1 or 2.\n";
                        cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                        addDeletePersonalTrainer(clients, staff, personalTrainersVector);
                    }
                }else if(userInput == 2){
                    /*
                     * SEE IF PERSONAL TRAINERS ARE ADDED TO THE STAFF LIST AS WELL AS THE PERSONAL TRAINING LIST WHEN THEY ARE NEWLY ADDED. IF NOT
                     * THAT NEEDS TO BE CORRECTED WHEN ASSIGNING DIFFERENT LEVELS OF ACCESS HERE
                     */
                    cout << "What access would you like to give before removing FPA Access?\n"
                            "1. Supervisor \n"
                            "2. Personal Trainer\n"
                            "3. Both Supervisor & Personal Trainer\n"
                            "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        staff[fpaLocation].setIsAdmin(true);
                        saveStaffRecords(staff);
                        cout << staff[fpaLocation].getName() <<  " has been given Supervisor access.\n\n";
                        supervisorMainMenu(clients, staff, personalTrainersVector);
                    }else if(userInput == 2){
                        staff[fpaLocation].setIsPersonalTrainer(true);
                        personalTrainersVector.push_back(staff[fpaLocation]);
                        saveStaffRecords(staff);
                        savePersonalTrainerRecords(personalTrainersVector);
                        cout << staff[fpaLocation].getName() <<  " has been given Personal Trainer access.\n\n";
                    }else if(userInput == 3){
                        staff[fpaLocation].setIsAdmin(true);
                        staff[fpaLocation].setIsPersonalTrainer(true);
                        personalTrainersVector.push_back(staff[fpaLocation]);
                        saveStaffRecords(staff);
                        savePersonalTrainerRecords(personalTrainersVector);
                        cout << staff[fpaLocation].getName() <<  " has been given Supervisor and FPA access.\n\n";
                    }else{
                        cout << "Invalid input. Only enter 1, 2 or 3.\n";
                        addDeleteSupervisor(clients, staff, personalTrainersVector);
                    }
                }
            }
            //safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[trainerLocation]);
            cout << staff[fpaLocation].getName() << "'s Personal Trainer status is now being removed..";
            staff[fpaLocation].setIsFpa(false);
            //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
            // the staff member I'm trying to delete and then 'pop' the back of the staff vector
            staff[fpaLocation] = staff[staff.size()];
            staff.pop_back();
            saveStaffRecords(staff);
            cout << fpaToDelete << "'s FPA status has been removed safely.\n"
                                       "You are not being brought back to your main menu.\n";
        }else{
            cout << "Invalid input. Enter only 1 or 2.\n";
            addDeletePersonalTrainer(clients, staff, personalTrainersVector);
        }
    }else {
        cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
    }
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsFpa()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

void addDeletePersonalTrainer(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    int userInput;
    cout << "Would you like to add or delete a Personal Trainer?\n"
            "1. Add\n"
            "2. Delete\n"
            "Enter corresponding number: ";
    cin >> userInput;
    if (userInput == 1){
        cout << "Is the new Personal trainer currently an employee?\n"
                "1. Yes\n"
                "2. No\n"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            int staffLocation = getStaffList(staff);
            staff[staffLocation].setIsPersonalTrainer(true);
            personalTrainersVector.push_back(staff[staffLocation]);

        }else if (userInput == 2){
            cout << string(50, '\n');
            string firstName, lastName, trainerName, trainerDob;
            int staffAge;
            cout << "Enter employee's first name: ";
            cin >> firstName;
            cout << "Enter " << firstName << "'s last name: ";
            cin >> lastName;
            trainerName = firstName + " " + lastName;
            cout << "Enter " << trainerName << "'s age: ";
            cin >> staffAge;
            cout << "(Format: MM/DD/YYYY)\nEnter " << trainerName << "'s Date Of Birth: ";
            cin >> trainerDob;
            Person newTrainer(trainerName, staffAge, trainerDob);
            newTrainer.setIsPersonalTrainer(true);
            newTrainer.setIsClient(false);
            cout << "Does " << firstName << " hold any other positions?\n"
                                            "1. Yes\n"
                                            "2. No\n"
                                            "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                cout << "Is " << firstName << " also an Admin?\n"
                                              "1. Yes\n"
                                              "2. No\n"
                                              "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    newTrainer.setIsAdmin(true);
                }else
                    newTrainer.setIsAdmin(false);
                cout << "Is " << firstName << " also an FPA?\n"
                                              "1. Yes\n"
                                              "2. No\n"
                                              "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    newTrainer.setIsFpa(true);
                }else {
                    newTrainer.setIsFpa(false);
                }
                newTrainer.setUserName(trainerName);
                newTrainer.setPassword(trainerDob);
                personalTrainersVector.push_back(newTrainer);
                staff.push_back(newTrainer);
            }else if(userInput ==2){
                newTrainer.setIsAdmin(false);
                newTrainer.setIsFpa(false);
                newTrainer.setUserName(trainerName);
                newTrainer.setPassword(trainerDob);
                personalTrainersVector.push_back(newTrainer);
                staff.push_back(newTrainer);
            }else {
                cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
                supervisorMainMenu2(clients, staff, personalTrainersVector);
            }
            cout << trainerName << " has been added to the active Personal Trainer list.\n";
        }else {
            cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
            supervisorMainMenu2(clients, staff, personalTrainersVector);
        }
    }else if (userInput == 2){
        cout << "Which trainer would you like to delete?\n";
        string trainerToDelete = setTrainer(personalTrainersVector);
        int trainerLocation = findTrainerByName(personalTrainersVector, trainerToDelete);
        cout << "Would you like to: \n1. Permanently delete " << personalTrainersVector[trainerLocation].getName() << "\n";
        cout << "2. Remove Personal Training status but still keep " << personalTrainersVector[trainerLocation].getName() << " in the records\n";
        cout << "Enter corresponding number: ";
        cin >> userInput;
        if(userInput == 1){
            cout << "Are you sure you would like to permanently delete " << personalTrainersVector[trainerLocation].getName() << "?\n";
            cout << "1. Yes\n"
                    "2. no\n"
                    "Enter corresponding number: ";
            cin >> userInput;
            if(userInput == 1){
                safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[trainerLocation]);
                cout << personalTrainersVector[trainerLocation].getName() << " is now being removed..\n";
                //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                personalTrainersVector[trainerLocation] = personalTrainersVector[personalTrainersVector.size()];
                personalTrainersVector.pop_back();

                cout << trainerToDelete << " has been safely removed from the records.\n";
            }else if(userInput == 2){
                cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                addDeletePersonalTrainer(clients, staff, personalTrainersVector);
            }else{
                cout << "Invalid input. Enter only 1 or 2.\n";
                cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                addDeletePersonalTrainer(clients, staff, personalTrainersVector);
            }
        }else if(userInput == 2){
            safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[trainerLocation]);

            if(personalTrainersVector[trainerLocation].getIsPersonalTrainer() || personalTrainersVector[trainerLocation].getIsFpa()){
                personalTrainersVector[trainerLocation].setIsPersonalTrainer(false);
                cout << personalTrainersVector[trainerLocation].getName() << "'s supervisor access has been removed.\n\n";
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else{
                cout << personalTrainersVector[trainerLocation].getName() << " is only in the system as a Personal Trainer.\nDeleting " << personalTrainersVector[trainerLocation].getName()
                     << " will permanently remove them from records.\n"
                        "What would you like to do?\n"
                        "1. Remove Personal Trainer Access and Delete " << personalTrainersVector[trainerLocation].getName() << " from records\n"
                                                                                                       "2. Remove Personal Trainer Access but give " << personalTrainersVector[trainerLocation].getName() << " another level of access\n"
                     << "Enter corresponding number: ";
                cin >> userInput;
                if(userInput == 1){
                    cout << "Are you sure you would like to permanently delete " << personalTrainersVector[trainerLocation].getName() << "?\n";
                    cout << "1. Yes\n"
                            "2. no\n"
                            "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[trainerLocation]);
                        cout << personalTrainersVector[trainerLocation].getName() << " is now being removed..";
                        //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
                        // the staff member I'm trying to delete and then 'pop' the back of the staff vector
                        personalTrainersVector[trainerLocation] = personalTrainersVector[personalTrainersVector.size()];
                        personalTrainersVector.pop_back();

                        cout << trainerToDelete << " has been safely removed from the records.\n";
                    }else if(userInput == 2){
                        cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                        addDeletePersonalTrainer(clients, staff, personalTrainersVector);
                    }else{
                        cout << "Invalid input. Enter only 1 or 2.\n";
                        cout << "You are being redirected back to the Add/Delete Trainer Menu\n";
                        addDeletePersonalTrainer(clients, staff, personalTrainersVector);
                    }
                }else if(userInput == 2){
                    /*
                     * SEE IF PERSONAL TRAINERS ARE ADDED TO THE STAFF LIST AS WELL AS THE PERSONAL TRAINING LIST WHEN THEY ARE NEWLY ADDED. IF NOT
                     * THAT NEEDS TO BE CORRECTED WHEN ASSIGNING DIFFERENT LEVELS OF ACCESS HERE
                     */
                    cout << "What access would you like to give before removing Personal Training Access?\n"
                            "1. Supervisor \n"
                            "2. Fitness Program Assistant\n"
                            "3. Both Supervisor & Fitness Program Assistant\n"
                            "Enter corresponding number: ";
                    cin >> userInput;
                    if(userInput == 1){
                        personalTrainersVector[trainerLocation].setIsAdmin(true);
                        cout << personalTrainersVector[trainerLocation].getName() <<  " has been given Supervisor access.\n\n";
                        supervisorMainMenu(clients, staff, personalTrainersVector);
                    }else if(userInput == 2){
                        personalTrainersVector[trainerLocation].setIsFpa(true);
                        cout << personalTrainersVector[trainerLocation].getName() <<  " has been given FPA access.\n\n";
                    }else if(userInput == 3){
                        personalTrainersVector[trainerLocation].setIsAdmin(true);
                        personalTrainersVector[trainerLocation].setIsFpa(true);
                        cout << personalTrainersVector[trainerLocation].getName() <<  " has been given Supervisor and FPA access.\n\n";
                    }else{
                        cout << "Invalid input. Only enter 1, 2 or 3.\n";
                        addDeleteSupervisor(clients, staff, personalTrainersVector);
                    }
                }
            }
            safeDeleteCheckForTrainer(clients, personalTrainersVector, personalTrainersVector[trainerLocation]);
            cout << personalTrainersVector[trainerLocation].getName() << "'s Personal Trainer status is now being removed..";
            personalTrainersVector[trainerLocation].setIsPersonalTrainer(false);
            //Not sure if this is doing what I need it to do.. I need to take the data from the last spot and copy it to
            // the staff member I'm trying to delete and then 'pop' the back of the staff vector
            personalTrainersVector[trainerLocation] = personalTrainersVector[personalTrainersVector.size()];
            staff.pop_back();

            cout << trainerToDelete << "'s Personal Trainer status has been removed safely.\n"
                                       "You are not being brought back to your main menu.\n";
        }else{
            cout << "Invalid input. Enter only 1 or 2.\n";
            addDeletePersonalTrainer(clients, staff, personalTrainersVector);
        }
    }else {
        cout << "Please enter in either only 1 or 2. You are now being redirected back to the main menu..";
    }
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsFpa()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

int findTrainerByName(vector<Person> &personalTrainingVector, const string &trainerName) {
    int location = -1;
    for(unsigned int i = 0; i < personalTrainingVector.size(); i++){
        if(personalTrainingVector[i].getName() == trainerName){
            location = i;
        }
    }
    return location;
}

void addClient(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << string(50, '\n');
    string firstName, lastName, clientName, clientDob;
    int clientAge;
    cout << "Enter clients first name: ";
    cin >> firstName;
    cout << "Enter " << firstName << "'s last name: ";
    cin >> lastName;
    clientName = firstName + " " + lastName;
    cout << "Enter " << clientName << "'s age: ";
    cin >> clientAge;
    cout << "(Format: MM/DD/YYYY)\nEnter " << clientName << "'s Date Of Birth: ";
    cin >> clientDob;
    Person newClient(clientName, clientAge, clientDob);
    newClient.setIsPersonalTrainer(false);
    newClient.setIsAdmin(false);
    newClient.setIsFpa(false);
    newClient.setIsClient(true);
    newClient.setUserName(clientName);
    newClient.setPassword(clientDob);
    newClient.setClientTrainer(setTrainer(personalTrainersVector));
    clients.push_back(newClient);
    cout << clientName << " has been added to the active client list.\n";
    saveClientRecords(clients);
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsFpa()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

void personalTrainingSession(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTrainersVector){
    cout << "Client Sign In: \n";
    string logIn = clientIdentification(clients, staff, personalTrainersVector);
    if(logIn == "NOT-AUTHORIZED"){
        int userInput;
        cout << string(50, '\n');
        cout << "Username and Password to not match out records. Would you like to:\n"
                "1. Go back to the Welcome screen"
                "2. Try entering your Username and Password again"
                "Enter corresponding number: ";
        cin >> userInput;
        if (userInput == 1){
            if(loggedOn.getIsAdmin()){
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else if(loggedOn.getIsPersonalTrainer()){
                ptMainMenu(clients, staff, personalTrainersVector);
            }else if(loggedOn.getIsFpa()){
                fpaMainMenu(clients, staff, personalTrainersVector);
            }
        }else if(userInput == 2){
            personalTrainingSession(clients, staff, personalTrainersVector);
        }else{
            cout << "\nPlease enter either 1 or 2 only.\n\n";
            if(loggedOn.getIsAdmin()){
                supervisorMainMenu(clients, staff, personalTrainersVector);
            }else if(loggedOn.getIsPersonalTrainer()){
                ptMainMenu(clients, staff, personalTrainersVector);
            }else if(loggedOn.getIsFpa()){
                fpaMainMenu(clients, staff, personalTrainersVector);
            }
        }
    }else {
        cout << string(50, '\n');
        int clientLocation = findClientUserName(clients, logIn);
        int sessionRemaining = clients[clientLocation].getRemainingNumOfSessions();
        if(sessionRemaining > 0){
            clients[clientLocation].useSession();
            saveClientRecords(clients);
        }else if(sessionRemaining <= 0){
            cout << clients[clientLocation].getName() << " is out of sessions. What would you like to do?\n"
                                                          "1. Add more sessions to " << clients[clientLocation].getName() << "'s account\n"
                                                       << "2. Go back to the Welcome screen\n"
                                                          "Enter corresponding number: ";
            int userInput;
            cin >> userInput;
            if (userInput == 1){
                cout << "How many sessions are you adding?\n"
                        "1. 3 Sessions\n"
                        "2. 5 Sessions\n"
                        "3. 10 Sessions\n"
                        "Enter Corresponding Number: ";
                cin >> userInput;
                if(userInput == 1){
                    clients[clientLocation].setNumOfSessions(3, loggedOn.getName());
                    cout << "3 Sessions have been added to " << clients[clientLocation].getName() << "'s records.";
                }else if(userInput == 2){
                    clients[clientLocation].setNumOfSessions(5, loggedOn.getName());
                    cout << "5 Sessions have been added to " << clients[clientLocation].getName() << "'s records.";
                }else if(userInput == 3){
                    clients[clientLocation].setNumOfSessions(10, loggedOn.getName());
                    cout << "10 Sessions have been added to " << clients[clientLocation].getName() << "'s records.";
                }
                saveClientRecords(clients);
                if(loggedOn.getIsAdmin()){
                    supervisorMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsPersonalTrainer()){
                    ptMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsFpa()){
                    fpaMainMenu(clients, staff, personalTrainersVector);
                }
            }else if(userInput == 2){
                if(loggedOn.getIsAdmin()){
                    supervisorMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsPersonalTrainer()){
                    ptMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsFpa()){
                    fpaMainMenu(clients, staff, personalTrainersVector);
                }
            }else{
                cout << "\nPlease enter either 1 or 2 only.\n\n";
                if(loggedOn.getIsAdmin()){
                    supervisorMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsPersonalTrainer()){
                    ptMainMenu(clients, staff, personalTrainersVector);
                }else if(loggedOn.getIsFpa()){
                    fpaMainMenu(clients, staff, personalTrainersVector);
                }
            }
        }
    }
    if(loggedOn.getIsAdmin()){
        supervisorMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsPersonalTrainer()){
        ptMainMenu(clients, staff, personalTrainersVector);
    }else if(loggedOn.getIsFpa()){
        fpaMainMenu(clients, staff, personalTrainersVector);
    }
}

int findClientByName(vector<Person> &clients, const string &inputName) {
    int location = -1;
    for(unsigned int i = 0; i < clients.size(); i++){
        if(clients[i].getName() == inputName){
            location = i;
        }
    }
    return location;
}

void saveClientRecords(vector<Person> &clients){
    ofstream writeFile("PersonalTrainingClientsData.txt");
    if(!clients.empty() && writeFile.is_open()){
        writeFile << clients.size();
        for(int i = 0; i < clients.size(); i++){
            writeFile << "\n" << clients[i].getAddingSessionCount() << "\n";
            writeFile << clients[i].getNumOfSessionsCount() << "\n";
            writeFile << clients[i].getName() << "\n";
            writeFile << clients[i].getClientTrainer() << "\n";
            writeFile << clients[i].getSessionRecord() << "\n";
            writeFile << clients[i].getAddingSessionRecord() << "\n";
            writeFile << clients[i].getIsPersonalTrainer() << "\n";
            writeFile << clients[i].getIsAdmin() << "\n";
            writeFile << clients[i].getIsFpa() << "\n";
            writeFile << clients[i].getTotalNumOfSessions() << "\n";
            writeFile << clients[i].getUserName() << "\n";
            writeFile << clients[i].getPassword() << "\n";
            writeFile << clients[i].getDob() << "\n";
            writeFile << clients[i].getAge() << "\n";
            writeFile << clients[i].getIsClient() << "\n";
            writeFile << clients[i].getUsedNumOfSessions();
        }
    }
    writeFile.close();
}

void saveStaffRecords(vector<Person> &staff){
    ofstream writeFile("PersonalTrainingStaffData.txt");
    if(!staff.empty() && writeFile.is_open()){
        writeFile << staff.size();
        for(int i = 0; i < staff.size(); i++){
            writeFile << "\n" << staff[i].getName() << "\n";
            writeFile << staff[i].getClientTrainer() << "\n";
            writeFile << staff[i].getSessionRecord() << "\n";
            writeFile << staff[i].getAddingSessionRecord() << "\n";
            writeFile << staff[i].getIsPersonalTrainer() << "\n";
            writeFile << staff[i].getIsAdmin() << "\n";
            writeFile << staff[i].getIsFpa() << "\n";
            writeFile << staff[i].getTotalNumOfSessions() << "\n";
            writeFile << staff[i].getUserName() << "\n";
            writeFile << staff[i].getPassword() << "\n";
            writeFile << staff[i].getDob() << "\n";
            writeFile << staff[i].getAge() << "\n";
            writeFile << staff[i].getIsClient() << "\n";
            writeFile << staff[i].getUsedNumOfSessions();
        }
    }
    writeFile.close();

    /*ofstream writeFile;
    writeFile.open("PersonalTrainingStaffData.dat", ios::out | ios::binary);
    if(!staff.empty()){
        writeFile.write(reinterpret_cast<char*>(&staff[0]), staff.size() * sizeof(staff[0]));
    }
    writeFile.close();*/
}

void savePersonalTrainerRecords(vector<Person> &personalTraining){
    ofstream writeFile("PersonalTrainingPersonalTrainingData.txt");
    if(!personalTraining.empty() && writeFile.is_open()){
        writeFile << personalTraining.size();
        for(int i = 0; i < personalTraining.size(); i++){
            writeFile << "\n" << personalTraining[i].getName() << "\n";
            writeFile << personalTraining[i].getClientTrainer() << "\n";
            writeFile << personalTraining[i].getSessionRecord() << "\n";
            writeFile << personalTraining[i].getAddingSessionRecord() << "\n";
            writeFile << personalTraining[i].getIsPersonalTrainer() << "\n";
            writeFile << personalTraining[i].getIsAdmin() << "\n";
            writeFile << personalTraining[i].getIsFpa() << "\n";
            writeFile << personalTraining[i].getTotalNumOfSessions() << "\n";
            writeFile << personalTraining[i].getUserName() << "\n";
            writeFile << personalTraining[i].getPassword() << "\n";
            writeFile << personalTraining[i].getDob() << "\n";
            writeFile << personalTraining[i].getAge() << "\n";
            writeFile << personalTraining[i].getIsClient() << "\n";
            writeFile << personalTraining[i].getUsedNumOfSessions();
        }
    }
    writeFile.close();

    /*ofstream writeFile;
    writeFile.open("PersonalTrainingPersonalTrainingData.dat", ios::out | ios::binary);
    if(!personalTraining.empty()){
        writeFile.write(reinterpret_cast<char*>(&personalTraining[0]), personalTraining.size() * sizeof(personalTraining[0]));
    }
    writeFile.close();*/
}

void saveRecords(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining){
    saveClientRecords(clients);
    saveStaffRecords(staff);
    savePersonalTrainerRecords(personalTraining);
}

void loadClientRecords(vector<Person> &clients){
    ifstream inputFile("PersonalTrainingClientsData.txt");
    if(inputFile.is_open()){
        /*string stringSize;
        getline(inputFile, stringSize);

        int size;
        try{
            size = stoi(stringSize);
        }catch(invalid_argument &e){
        }


        if(size != NULL){
            for(int i = 0; i < 1; i++) {
                string name, trainer, sessionRecord, addingSessionRecord, isPt, isAdmin, isFpa, remainingSessions,
                        totalSessionsStr, userName, password, dob, ageStr, isClient, usedSessions;
                int usedNumSession, age, totalSessions;

                getline(inputFile, name);
                getline(inputFile, trainer);
                getline(inputFile, sessionRecord);
                getline(inputFile, addingSessionRecord);
                getline(inputFile, isPt);
                getline(inputFile, isAdmin);
                getline(inputFile, isFpa);
                getline(inputFile, remainingSessions);
                getline(inputFile, totalSessionsStr);
                getline(inputFile, userName);
                getline(inputFile, password);
                getline(inputFile, dob);
                getline(inputFile, ageStr);
                getline(inputFile, isClient);
                getline(inputFile, usedSessions);

                bool isTrainer = (strcasecmp("true", isPt.c_str()) == 0);
                bool isFPA = (strcasecmp("true", isFpa.c_str()) == 0);
                bool isCLIENT = (strcasecmp("true", isClient.c_str()) == 0);

                //remainingNumSessions = stoi(remainingSessions);
                try{
                    usedNumSession = stoi(usedSessions);
                    age = stoi(ageStr);
                    totalSessions = stoi(totalSessionsStr);
                }catch(invalid_argument &e){
                }

                Person inputClient(name, age, dob);
                clients.push_back(inputClient);
                clients[i].setName(name);
                clients[i].setClientTrainer(trainer);
                clients[i].setSessionRecord(sessionRecord);
                clients[i].setAddingSessionRecord(addingSessionRecord);
                clients[i].setIsPersonalTrainer(isTrainer);
                clients[i].setIsFpa(isFPA);
                //clients[i].setRemainingSessionsRecord(remainingSessions);
                clients[i].setTotalSessions(totalSessions);
                clients[i].setUserName(userName);
                clients[i].setPassword(password);
                //clients[i].setDob(dob);
                //clients[i].setAge(age);
                clients[i].setIsClient(isCLIENT);
                clients[i].setUsedNumOfSessions(usedNumSession);
            }


            /*
             * writeFile << clients[i].getName() << "\n";
            writeFile << clients[i].getClientTrainer() << "\n";
            writeFile << clients[i].getSessionRecord() << "\n";
            writeFile << clients[i].getAddingSessionRecord() << "\n";
            writeFile << clients[i].getIsPersonalTrainer() << "\n";
            writeFile << clients[i].getIsAdmin() << "\n";
            writeFile << clients[i].getIsFpa() << "\n";
            writeFile << clients[i].getRemainingNumOfSessions() << "\n";
            writeFile << clients[i].getTotalNumOfSessions() << "\n";
            writeFile << clients[i].getUserName() << "\n";
            writeFile << clients[i].getPassword() << "\n";
            writeFile << clients[i].getDob() << "\n";
            writeFile << clients[i].getAge() << "\n";
            writeFile << clients[i].getIsClient() << "\n";
            writeFile << clients[i].getUsedNumOfSessions() << "\n";
             */

        string name, trainer, sessionRecord, addingSessionRecord, isPt = "0", isAdmin = "0", isFpa = "0",
                totalSessionsStr, userName, password, dob, ageStr, isClient = "0", usedSessions;
        int usedNumSession = 0, age = 0, totalSessions = 0;
        string addingSessionCountStr = "0";
        int addingSessionCount = 0;
        string numOfSessionCountStr = "0";
        int numOfSessionCount = 0;
        //int i = 0;
        string clientsToLoadStr = "0";
        getline(inputFile, clientsToLoadStr);
        int clientsToLoad = 0;
        try {
            clientsToLoad = stoi(clientsToLoadStr);
        } catch (invalid_argument &e) {
        }

        for(int i = 0; i < clientsToLoad; i++) {
            getline(inputFile, addingSessionCountStr);
            try {
                addingSessionCount = stoi(addingSessionCountStr);
            } catch (invalid_argument &e) {
            }
            getline(inputFile, numOfSessionCountStr);
            try {
                numOfSessionCount = stoi(numOfSessionCountStr);

            } catch (invalid_argument &e) {
            }



            getline(inputFile, name);
            getline(inputFile, trainer);
            getline(inputFile, sessionRecord);
            for(int k = 0; k < numOfSessionCount; k++){
                string str;
                getline(inputFile, str);
                sessionRecord += "\n" + str;
            }
            getline(inputFile, addingSessionRecord);
            for(int j = 0; j < addingSessionCount; j++){
                string str;
                getline(inputFile, str);
                addingSessionRecord += "\n" + str;
            }

            getline(inputFile, isPt);
            getline(inputFile, isAdmin);
            getline(inputFile, isFpa);
            getline(inputFile, totalSessionsStr);
            getline(inputFile, userName);
            getline(inputFile, password);
            getline(inputFile, dob);
            getline(inputFile, ageStr);
            getline(inputFile, isClient);
            getline(inputFile, usedSessions);

            bool isTrainer;
            if (isPt == "0" ){
                isTrainer = false;
            }else{
                isTrainer = true;
            }

            bool isSupervisor;
            if(isAdmin == "0"){
                isSupervisor = false;
            }else{
                isSupervisor = true;
            }

            bool isFPA;
            if(isFpa == "0"){
                isFPA = false;
            }else{
                isFPA = true;
            }

            bool isCLIENT;
            if(isClient == "0"){
                isCLIENT = false;
            }else{
                isCLIENT = true;
            }

            try {
                usedNumSession = stoi(usedSessions);
                age = stoi(ageStr);
                totalSessions = stoi(totalSessionsStr);
            } catch (invalid_argument &e) {
            }

            Person inputClient(name, age, dob);
            clients.push_back(inputClient);
            clients[i].setName(name);
            clients[i].setClientTrainer(trainer);
            clients[i].setSessionRecord(sessionRecord);
            clients[i].setAddingSessionRecord(addingSessionRecord);
            clients[i].setIsPersonalTrainer(isTrainer);
            clients[i].setIsAdmin(isSupervisor);
            clients[i].setIsFpa(isFPA);
            clients[i].setTotalSessions(totalSessions);
            clients[i].setUserName(userName);
            clients[i].setPassword(password);
            clients[i].setDob(dob);
            clients[i].setAge(age);
            clients[i].setIsClient(isCLIENT);
            clients[i].setUsedNumOfSessions(usedNumSession);
            clients[i].setNumOfSessionCount(numOfSessionCount);
            clients[i].setAddingSessionCount(addingSessionCount);
        }
    }
    inputFile.close();


    /*ifstream inputFile("PersonalTrainingClientsData.dat", ios::in | ios::binary);
    {
        inputFile.seekg(0, ifstream::end);
        long int size = inputFile.tellg() / sizeof(Person);
        Person temp2[size];
        inputFile.seekg(0, ifstream::beg);
        inputFile.read((char*) &temp2, sizeof(temp2));
        int counter;
        for(counter = 0; counter < size; counter++){
            clients.push_back(temp2[counter]);
        }
        inputFile.close();
    }*/
}

void loadStaffRecords(vector<Person> &staff){
    ifstream inputFile("PersonalTrainingStaffData.txt");
    if(inputFile.is_open()){
        /*string stringSize;
        getline(inputFile, stringSize);

        int size;
        try{
            size = stoi(stringSize);
        }catch(invalid_argument &e){
        }


        if(size != NULL){
            for(int i = 0; i < 1; i++) {
                string name, trainer, sessionRecord, addingSessionRecord, isPt, isAdmin, isFpa, remainingSessions,
                        totalSessionsStr, userName, password, dob, ageStr, isClient, usedSessions;
                int usedNumSession, age, totalSessions;

                getline(inputFile, name);
                getline(inputFile, trainer);
                getline(inputFile, sessionRecord);
                getline(inputFile, addingSessionRecord);
                getline(inputFile, isPt);
                getline(inputFile, isAdmin);
                getline(inputFile, isFpa);
                getline(inputFile, remainingSessions);
                getline(inputFile, totalSessionsStr);
                getline(inputFile, userName);
                getline(inputFile, password);
                getline(inputFile, dob);
                getline(inputFile, ageStr);
                getline(inputFile, isClient);
                getline(inputFile, usedSessions);

                bool isTrainer = (strcasecmp("true", isPt.c_str()) == 0);
                bool isFPA = (strcasecmp("true", isFpa.c_str()) == 0);
                bool isCLIENT = (strcasecmp("true", isClient.c_str()) == 0);

                //remainingNumSessions = stoi(remainingSessions);
                try{
                    usedNumSession = stoi(usedSessions);
                    age = stoi(ageStr);
                    totalSessions = stoi(totalSessionsStr);
                }catch(invalid_argument &e){
                }

                Person inputClient(name, age, dob);
                clients.push_back(inputClient);
                clients[i].setName(name);
                clients[i].setClientTrainer(trainer);
                clients[i].setSessionRecord(sessionRecord);
                clients[i].setAddingSessionRecord(addingSessionRecord);
                clients[i].setIsPersonalTrainer(isTrainer);
                clients[i].setIsFpa(isFPA);
                //clients[i].setRemainingSessionsRecord(remainingSessions);
                clients[i].setTotalSessions(totalSessions);
                clients[i].setUserName(userName);
                clients[i].setPassword(password);
                //clients[i].setDob(dob);
                //clients[i].setAge(age);
                clients[i].setIsClient(isCLIENT);
                clients[i].setUsedNumOfSessions(usedNumSession);
            }


            /*
             * writeFile << clients[i].getName() << "\n";
            writeFile << clients[i].getClientTrainer() << "\n";
            writeFile << clients[i].getSessionRecord() << "\n";
            writeFile << clients[i].getAddingSessionRecord() << "\n";
            writeFile << clients[i].getIsPersonalTrainer() << "\n";
            writeFile << clients[i].getIsAdmin() << "\n";
            writeFile << clients[i].getIsFpa() << "\n";
            writeFile << clients[i].getRemainingNumOfSessions() << "\n";
            writeFile << clients[i].getTotalNumOfSessions() << "\n";
            writeFile << clients[i].getUserName() << "\n";
            writeFile << clients[i].getPassword() << "\n";
            writeFile << clients[i].getDob() << "\n";
            writeFile << clients[i].getAge() << "\n";
            writeFile << clients[i].getIsClient() << "\n";
            writeFile << clients[i].getUsedNumOfSessions() << "\n";
             */

        string name, trainer, sessionRecord, addingSessionRecord, isPt = "0", isAdmin = "0", isFpa = "0",
                totalSessionsStr, userName, password, dob, ageStr, isClient = "0", usedSessions;
        int usedNumSession = 0, age = 0, totalSessions = 0;
        string clientsToLoadStr = "0";
        getline(inputFile, clientsToLoadStr);
        int clientsToLoad = 0;
        try {
            clientsToLoad = stoi(clientsToLoadStr);
        } catch (invalid_argument &e) {
        }

        for(int i = 0; i < clientsToLoad; i++) {
            getline(inputFile, name);
            getline(inputFile, trainer);
            getline(inputFile, sessionRecord);
            getline(inputFile, addingSessionRecord);
            getline(inputFile, isPt);
            getline(inputFile, isAdmin);
            getline(inputFile, isFpa);
            getline(inputFile, totalSessionsStr);
            getline(inputFile, userName);
            getline(inputFile, password);
            getline(inputFile, dob);
            getline(inputFile, ageStr);
            getline(inputFile, isClient);
            getline(inputFile, usedSessions);

            bool isTrainer;
            if (isPt == "0" ){
                isTrainer = false;
            }else{
                isTrainer = true;
            }

            bool isSupervisor;
            if(isAdmin == "0"){
                isSupervisor = false;
            }else{
                isSupervisor = true;
            }

            bool isFPA;
            if(isFpa == "0"){
                isFPA = false;
            }else{
                isFPA = true;
            }

            bool isCLIENT;
            if(isClient == "0"){
                isCLIENT = false;
            }else{
                isCLIENT = true;
            }

            try {
                usedNumSession = stoi(usedSessions);
                age = stoi(ageStr);
                totalSessions = stoi(totalSessionsStr);
            } catch (invalid_argument &e) {
            }

            Person inputClient(name, age, dob);
            staff.push_back(inputClient);
            staff[i].setName(name);
            staff[i].setClientTrainer(trainer);
            staff[i].setSessionRecord(sessionRecord);
            staff[i].setAddingSessionRecord(addingSessionRecord);
            staff[i].setIsPersonalTrainer(isTrainer);
            staff[i].setIsAdmin(isSupervisor);
            staff[i].setIsFpa(isFPA);
            staff[i].setTotalSessions(totalSessions);
            staff[i].setUserName(userName);
            staff[i].setPassword(password);
            staff[i].setDob(dob);
            staff[i].setAge(age);
            staff[i].setIsClient(isCLIENT);
            staff[i].setUsedNumOfSessions(usedNumSession);
        }
    }
    inputFile.close();


    /*ifstream fin("PersonalTrainingStaffData.dat", ios::in | ios::binary);
    {
        fin.seekg(0, ifstream::end);
        long int size = fin.tellg() / sizeof(Person);
        Person temp2[size];
        fin.seekg(0, ifstream::beg);
        fin.read((char*) &temp2, sizeof(temp2));
        int counter;
        for(counter = 0; counter < size; counter++){
            staff.push_back(temp2[counter]);
        }
        fin.close();
    }*/
}

void loadPersonalTrainerRecords(vector<Person> &personalTraining){
    ifstream inputFile("PersonalTrainingPersonalTrainingData.txt");
    if(inputFile.is_open()){
        /*string stringSize;
        getline(inputFile, stringSize);

        int size;
        try{
            size = stoi(stringSize);
        }catch(invalid_argument &e){
        }


        if(size != NULL){
            for(int i = 0; i < 1; i++) {
                string name, trainer, sessionRecord, addingSessionRecord, isPt, isAdmin, isFpa, remainingSessions,
                        totalSessionsStr, userName, password, dob, ageStr, isClient, usedSessions;
                int usedNumSession, age, totalSessions;

                getline(inputFile, name);
                getline(inputFile, trainer);
                getline(inputFile, sessionRecord);
                getline(inputFile, addingSessionRecord);
                getline(inputFile, isPt);
                getline(inputFile, isAdmin);
                getline(inputFile, isFpa);
                getline(inputFile, remainingSessions);
                getline(inputFile, totalSessionsStr);
                getline(inputFile, userName);
                getline(inputFile, password);
                getline(inputFile, dob);
                getline(inputFile, ageStr);
                getline(inputFile, isClient);
                getline(inputFile, usedSessions);

                bool isTrainer = (strcasecmp("true", isPt.c_str()) == 0);
                bool isFPA = (strcasecmp("true", isFpa.c_str()) == 0);
                bool isCLIENT = (strcasecmp("true", isClient.c_str()) == 0);

                //remainingNumSessions = stoi(remainingSessions);
                try{
                    usedNumSession = stoi(usedSessions);
                    age = stoi(ageStr);
                    totalSessions = stoi(totalSessionsStr);
                }catch(invalid_argument &e){
                }

                Person inputClient(name, age, dob);
                clients.push_back(inputClient);
                clients[i].setName(name);
                clients[i].setClientTrainer(trainer);
                clients[i].setSessionRecord(sessionRecord);
                clients[i].setAddingSessionRecord(addingSessionRecord);
                clients[i].setIsPersonalTrainer(isTrainer);
                clients[i].setIsFpa(isFPA);
                //clients[i].setRemainingSessionsRecord(remainingSessions);
                clients[i].setTotalSessions(totalSessions);
                clients[i].setUserName(userName);
                clients[i].setPassword(password);
                //clients[i].setDob(dob);
                //clients[i].setAge(age);
                clients[i].setIsClient(isCLIENT);
                clients[i].setUsedNumOfSessions(usedNumSession);
            }


            /*
             * writeFile << clients[i].getName() << "\n";
            writeFile << clients[i].getClientTrainer() << "\n";
            writeFile << clients[i].getSessionRecord() << "\n";
            writeFile << clients[i].getAddingSessionRecord() << "\n";
            writeFile << clients[i].getIsPersonalTrainer() << "\n";
            writeFile << clients[i].getIsAdmin() << "\n";
            writeFile << clients[i].getIsFpa() << "\n";
            writeFile << clients[i].getRemainingNumOfSessions() << "\n";
            writeFile << clients[i].getTotalNumOfSessions() << "\n";
            writeFile << clients[i].getUserName() << "\n";
            writeFile << clients[i].getPassword() << "\n";
            writeFile << clients[i].getDob() << "\n";
            writeFile << clients[i].getAge() << "\n";
            writeFile << clients[i].getIsClient() << "\n";
            writeFile << clients[i].getUsedNumOfSessions() << "\n";
             */

        string name, trainer, sessionRecord, addingSessionRecord, isPt = "0", isAdmin = "0", isFpa = "0",
                totalSessionsStr, userName, password, dob, ageStr, isClient = "0", usedSessions;
        int usedNumSession = 0, age = 0, totalSessions = 0;
        string trainersToLoadStr = "0";
        getline(inputFile, trainersToLoadStr);
        int trainersToLoad = 0;
        try {
            trainersToLoad = stoi(trainersToLoadStr);
        } catch (invalid_argument &e) {
        }

        for(int i = 0; i < trainersToLoad; i++) {
            getline(inputFile, name);
            getline(inputFile, trainer);
            getline(inputFile, sessionRecord);
            getline(inputFile, addingSessionRecord);
            getline(inputFile, isPt);
            getline(inputFile, isAdmin);
            getline(inputFile, isFpa);
            getline(inputFile, totalSessionsStr);
            getline(inputFile, userName);
            getline(inputFile, password);
            getline(inputFile, dob);
            getline(inputFile, ageStr);
            getline(inputFile, isClient);
            getline(inputFile, usedSessions);

            bool isTrainer;
            if (isPt == "0" ){
                isTrainer = false;
            }else{
                isTrainer = true;
            }

            bool isSupervisor;
            if(isAdmin == "0"){
                isSupervisor = false;
            }else{
                isSupervisor = true;
            }

            bool isFPA;
            if(isFpa == "0"){
                isFPA = false;
            }else{
                isFPA = true;
            }

            bool isCLIENT;
            if(isClient == "0"){
                isCLIENT = false;
            }else{
                isCLIENT = true;
            }

            try {
                usedNumSession = stoi(usedSessions);
                age = stoi(ageStr);
                totalSessions = stoi(totalSessionsStr);
            } catch (invalid_argument &e) {
            }

            Person inputClient(name, age, dob);
            personalTraining.push_back(inputClient);
            personalTraining[i].setName(name);
            personalTraining[i].setClientTrainer(trainer);
            personalTraining[i].setSessionRecord(sessionRecord);
            personalTraining[i].setAddingSessionRecord(addingSessionRecord);
            personalTraining[i].setIsPersonalTrainer(isTrainer);
            personalTraining[i].setIsAdmin(isSupervisor);
            personalTraining[i].setIsFpa(isFPA);
            personalTraining[i].setTotalSessions(totalSessions);
            personalTraining[i].setUserName(userName);
            personalTraining[i].setPassword(password);
            personalTraining[i].setDob(dob);
            personalTraining[i].setAge(age);
            personalTraining[i].setIsClient(isCLIENT);
            personalTraining[i].setUsedNumOfSessions(usedNumSession);

        }
    }
    inputFile.close();

    /*ifstream fin("PersonalTrainingPersonalTrainingData.dat", ios::in | ios::binary);
    {
        fin.seekg(0, ifstream::end);
        long int size = fin.tellg() / sizeof(Person);
        Person temp2[size];
        fin.seekg(0, ifstream::beg);
        fin.read((char*) &temp2, sizeof(temp2));
        int counter;
        for(counter = 0; counter < size; counter++){
            personalTraining.push_back(temp2[counter]);
        }
        fin.close();
    }*/
}

void loadRecords(vector<Person> &clients, vector<Person> &staff, vector<Person> &personalTraining){
    loadClientRecords(clients);
    loadStaffRecords(staff);
    loadPersonalTrainerRecords(personalTraining);
}

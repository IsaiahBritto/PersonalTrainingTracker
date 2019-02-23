//
// Created by Isaiah Britto on 6/2/18.
//

#pragma once
using namespace std;
#include <string>
#include <vector>

class Person {
private:
     string name;
    int age;
    string dob;
    string userName;
    string password;
    bool isAdmin;
    bool isPersonalTrainer;
    //int numOfClients;
    bool isCLient;
    bool isFpa;
    int usedSessions = 0;
    string sessionRecords = "\tSession Records:";
    string addingSessionsRecord = "\tAdding Sessions Record:";
    string clientTrainer;
    int numOfSessions = 0;


public:

    Person();
    Person(const string &inputName, const int &inputAge, const string &inputDob);
    void setName(const string &inputName);
    string getName()const {return name;};
    void setAge(const int &inputAge);
    int getAge()const {return age;};
    void setDob(const string &inputDob);
    string getDob()const {return dob;};
    void setClientTrainer(const string &trainerName);
    string getClientTrainer()const {return clientTrainer;};
    string getAddingSessionRecord(){return addingSessionsRecord;};
    //void addSessions(int inputSessions){ numOfSessions += inputSessions;};
    int useSessionCount = 0, addingSessionCount = 0;

    void setNumOfSessionCount(int input){useSessionCount = input;};
    void setAddingSessionCount(int input){addingSessionCount = input;};
    int getNumOfSessionsCount(){return useSessionCount;};
    int getAddingSessionCount(){return addingSessionCount;};

    void setUserName(const string &inputUserName);
    void setPassword(const string &inputPassword);
    string getUserName()const {return userName;};
    string getPassword(){return password;};

    void setNumOfSessions(int inputSessions, string trainerName);
    int getTotalNumOfSessions()const {return numOfSessions;};
    int getUsedNumOfSessions()const {return usedSessions;}
    int getRemainingNumOfSessions()const {return numOfSessions - usedSessions;};
    string getSessionRecord(){return sessionRecords;};
    void useSession();
    bool getIsAdmin() const;
    void setIsAdmin(bool inputIsAdmin);
    bool getIsPersonalTrainer() const;
    void setIsPersonalTrainer(bool inputIsPersonalTrainer);
    bool getIsClient() const;
    void setIsClient(bool inputIsClient);
    void setIsFpa(bool inputIsFpa);
    bool getIsFpa() const;

    void setSessionRecord(string inputSessionRecord){sessionRecords = inputSessionRecord;};
    void setAddingSessionRecord(string inputAddingSessionRecord){addingSessionsRecord = inputAddingSessionRecord;};
    void setTotalSessions(int inputTotalSessions){numOfSessions = inputTotalSessions;};
    void setUsedNumOfSessions(int usedNumOfSession){usedSessions = usedNumOfSession;};

    friend ostream& operator<<(ostream &output, const Person &displayPerson);
    static void getCurrentTime(int &seconds, int &minutes, int &hours, int &dayOfMonth, int &month, int &year,
                               string &weekday);

};



//
// Created by Isaiah Britto on 6/2/18.
//

#include <iostream>
#include "Person.h"
using namespace std;

Person::Person() {
    setName("noName");
    setAge(0);
    setDob("00/00/0000");
}

Person::Person(const string &inputName, const int &inputAge, const string &inputDob) {
    setName(inputName);
    setAge(inputAge);
    setDob(inputDob);
}

void Person::setName(const string &inputName) {
    name = inputName;

}

void Person::setAge(const int &inputAge) {
    age = inputAge;
}

void Person::setDob(const string &inputDob) {
    dob = inputDob;
}

bool Person::getIsAdmin() const {
    return isAdmin;
}

void Person::setIsAdmin(bool inputIsAdmin) {
    isAdmin = inputIsAdmin;
}

bool Person::getIsPersonalTrainer() const {
    return isPersonalTrainer;
}

void Person::setIsPersonalTrainer(bool inputIsPersonalTrainer) {
    isPersonalTrainer = inputIsPersonalTrainer;
}

bool Person::getIsClient() const {
    return isCLient;
}

void Person::setIsClient(bool inputIsClient) {
    isCLient = inputIsClient;
}

void Person::setUserName(const string &inputUserName) {
    userName = inputUserName;
}

void Person::setPassword(const string &inputPassword) {
    password = inputPassword;
}

void Person::setClientTrainer(const string &trainerName) {
    clientTrainer = trainerName;
}

ostream &operator<<(ostream &output, const Person &displayPerson) {
    if(displayPerson.getIsAdmin()){
        output << "Admin: " << displayPerson.getName() << "\n\t";
        if(displayPerson.isPersonalTrainer){
            output << "Personal Trainer: Yes\n";
        }else{
            output << "Personal Trainer: No\n";
        }
        if(displayPerson.isFpa){
            output << "\tFitness Program Assistant: Yes\n";
        }else{
            output << "\tFitness Program Assistant: No\n";
        }
        return output;
    }else if(displayPerson.getIsPersonalTrainer()){
        output << "Personal Trainer: " << displayPerson.getName();
        if(displayPerson.isFpa){
            output << "\n\tFitness Program Assistant: Yes\n";
        }else{
            output << "\n\tFitness Program Assistant: No\n";
        }
        return output;
    }else if(displayPerson.getIsFpa()){
        output << "Fitness Program Assistant: " << displayPerson.getName();
        return output;
    }else if(displayPerson.getIsClient()){
        output << "\nClient: " << displayPerson.getName() << " (" << displayPerson.getAge() << " years old)";
        output << "\n\tUsername: " << displayPerson.getUserName();
        output << "\n\tTrainer: " << displayPerson.getClientTrainer();
        output << "\n\tTotal Sessions:     " << displayPerson.getTotalNumOfSessions()
               << "\n\tRemaining Sessions: " << displayPerson.getRemainingNumOfSessions();
        output << "\n\tDate Of Birth: " << displayPerson.getDob()
               << "\n";
        return output;
    }
    return output;
}

void Person::setIsFpa(bool inputIsFpa) {
    isFpa = inputIsFpa;
}

bool Person::getIsFpa() const{
    return isFpa;
}

void Person::useSession() {
    useSessionCount = useSessionCount + 1;
    int seconds, minutes, hours, dayOfMonth, month, year;
    string weekday, stringMinute;
    getCurrentTime(seconds, minutes, hours, dayOfMonth, month, year, weekday);
    if(minutes < 10){
        stringMinute = "0" + to_string(minutes);
    }else{
        stringMinute = to_string(minutes);
    }
    sessionRecords += "\n\t\t\t\t\t " + to_string(month);
    sessionRecords += "/" + to_string(dayOfMonth);
    sessionRecords += "/" + to_string(year);
    if(hours > 12){
        hours = hours - 12;
        sessionRecords += "\t" + to_string(hours);
        sessionRecords += ":" + stringMinute;
        sessionRecords += " PM";
    }else if(hours <= 12){
        sessionRecords += "\t" + to_string(hours);
        sessionRecords += ":" + to_string(minutes);
        sessionRecords += " AM";
    }
    sessionRecords += "    1 Session used";
    usedSessions++;
}

void Person::getCurrentTime(int &seconds, int &minutes, int &hours, int &dayOfMonth, int &month, int &year,
                            string &weekday){
    string timeDate;

    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);

    seconds = (timePtr->tm_sec);
    minutes = (timePtr->tm_min);
    hours = (timePtr->tm_hour);
    dayOfMonth = (timePtr->tm_mday);
    month = (timePtr->tm_mon)+1 ;
    year = (timePtr->tm_year)+1900;
    int day = (timePtr->tm_wday );
    switch(day) {
        case 1:
            weekday = "Monday";
            break;
        case 2:
            weekday = "Tuesday";
            break;
        case 3:
            weekday = "Wednesday";
            break;
        case 4:
            weekday = "Thursday";
            break;
        case 5:
            weekday = "Friday";
            break;
        case 6:
            weekday = "Saturday";
            break;
        case 7:
            weekday = "Sunday";
            break;
    }
    //delete[] timePtr;
}

void Person::setNumOfSessions(int inputSessions, string trainerName) {
    addingSessionCount = addingSessionCount + 1;
    numOfSessions += inputSessions;
    addingSessionsRecord += "\n\t\t\t\t\t\t\t";
    addingSessionsRecord += trainerName;
    addingSessionsRecord += " added ";
    addingSessionsRecord += to_string(inputSessions);
    addingSessionsRecord += " on ";
    int seconds, minutes, hours, dayOfMonth,month, year;
    string weekday;
    getCurrentTime(seconds, minutes, hours, dayOfMonth, month, year, weekday);
    addingSessionsRecord += (" " + to_string(month));
    addingSessionsRecord += ("/" + to_string(dayOfMonth));
    addingSessionsRecord += ("/" + to_string(year));
    addingSessionsRecord += (" at ");
    if(hours > 12){
        hours = hours - 12;
        addingSessionsRecord += (" " + to_string(hours));
        addingSessionsRecord += (":" + to_string(minutes));
        addingSessionsRecord += (" PM");
    }else if(hours <= 12){
        addingSessionsRecord += ("\t" + to_string(hours));
        addingSessionsRecord += (":" + to_string(minutes));
        addingSessionsRecord += (" AM");
    }
}
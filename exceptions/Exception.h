//
// Created by devwurm on 05.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_EXCEPTION_H
#include <string>
#include <exception>
#include <QString>

using namespace std;

class Exception: public exception {
protected:
    string msg;
public:
    Exception(const char* message): msg(message) {};
    Exception(const string& message): msg(message) {};
    Exception(const QString& message): msg(message.toUtf8().constData()) {};

    virtual const char* what() const throw (){
       return msg.c_str();
    }

};

#define HTW_MEDIA_MANAGER_2_EXCEPTION_H
#endif //HTW_MEDIA_MANAGER_2_EXCEPTION_H

#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "sqlite3.h"

using namespace std;

namespace Persistencia {
    class Result {
    private:
        string column;
        string result;
    public:
        Result(const string&, const string&);
        string getColumn() const;
        string get() const;
    };
    inline string Result::getColumn() const {
        return column;
    }
    inline string Result::get() const {
        return result;
    }
    
    class SQLCommand {
    private:
        const char *dbName = "gov.db";
        sqlite3 *db;
        char *message;
        int rc;
        int connect();
        int disconnect();
        static int callback(void *, int, char **, char **);
    protected:
        static list<Result> results;
        string command;
    public:
        int Execute();
    };

    class PersistenciaException {
    private:
        string errMsg;
    public:
        PersistenciaException(string);
        string what() const;
    };
    inline PersistenciaException::PersistenciaException(string errMsg) {
        this->errMsg = errMsg;
    }
    inline string PersistenciaException::what() const {
        return errMsg;
    }
}

#endif // PERSISTENCIA_H_INCLUDED
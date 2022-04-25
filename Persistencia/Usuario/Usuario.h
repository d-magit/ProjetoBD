#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED

#include "entidades.h"

#include <list>
#include <vector>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;

namespace Persistencia {
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
        list<Result> results;
        string command;
    public:
        int Execute();
    };

    class Result {
    private:
        string column;
        string result;
    public:
        Result(string&, string&);
        string getColumn() const;
        string get() const;
    };
    inline string Result::getColumn() const {
        return column;
    }
    inline string Result::get() const {
        return result;
    }

    class PersistenciaException {
    private:
        string errMsg;
    public:
        PersistenciaException(string);
        string what();
    };
    inline PersistenciaException::PersistenciaException(string errMsg) const {
        this->errMsg = errMsg;
    }
    inline string PersistenciaException::what() const {
        return errMsg;
    }
}

#endif // PERSISTENCIA_H_INCLUDED
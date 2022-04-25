#include "Persistencia.h"

using namespace std;

Persistencia::Result::Result(const string& column, const string& result) {
    this->column = column;
    this->result = result;
}

int Persistencia::SQLCommand::connect() {
    rc = sqlite3_open(dbName, &db);
    if (rc != SQLITE_OK)
        return 1;
    return 0;
}

int Persistencia::SQLCommand::disconnect() {
    rc =  sqlite3_close(db);
    if (rc != SQLITE_OK)
        return 1;
    return 0;
}

list<Persistencia::Result> *resultsPtr;
int Persistencia::SQLCommand::callback(void *notUsed, int argc, char **qResults, char **qColumns) {
    notUsed = 0;
    for(int i = 0; i < argc; i++) {
        Result result(qResults[i] ? qResults[i] : "NULL", qColumns[i]);
        resultsPtr->push_front(result);
    }
    return 0;
}

int Persistencia::SQLCommand::Execute() {
    connect();
    resultsPtr = &results;
    rc = sqlite3_exec(db, command.c_str(), callback, 0, &message);
    if (rc != SQLITE_OK){
        sqlite3_free(message);
        disconnect();
        return 1;
    }
    disconnect();
    return 0;
}
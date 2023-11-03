#include "../../lib/sqlite3/sqlite3.h"
#include <stdio.h>
#include <iostream>
#pragma once

class DataBase 
{
    private:
        sqlite3 *db;

    public:
        DataBase();
        ~DataBase();
    private:
        int createTables();

};


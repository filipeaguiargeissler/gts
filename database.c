#include <stdio.h>
#include <sqlite3.h>
#include "database.h"

#define GTS_DATABASE "gts.db"

static sqlite3 *db;

static int callback(void *NotUsed, int argc, char **argv, 
		char **azColName)
{
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int init_database(void)
{
   int rc;
   char *zErrMsg = 0;

   rc = sqlite3_open(GTS_DATABASE, &db);
   if (rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			return -1;
   }


	 rc = sqlite3_exec(db, FOREIGN_KEY_SUPPORT, callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
		 fprintf(stderr, "SQL error: %s\n", zErrMsg);
		 sqlite3_free(zErrMsg);
		 return -1;
	 }

	 rc = sqlite3_exec(db, CHECK_TABLE_EXISTS, callback, 0, &zErrMsg);
	 if (rc == SQLITE_OK)
		 return 0;

	 // Create tables
	 rc = sqlite3_exec(db, CUSTOMER_ID, callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
		 fprintf(stderr, "SQL error: %s\n", zErrMsg);
		 sqlite3_free(zErrMsg);
		 return -1;
	 }

	 rc = sqlite3_exec(db, CUSTOMER_FINANCES, callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
		 fprintf(stderr, "SQL error: %s\n", zErrMsg);
		 sqlite3_free(zErrMsg);
		 return -1;
	 }

	 rc = sqlite3_exec(db, CUSTOMER_DEVICE, callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
		 fprintf(stderr, "SQL error: %s\n", zErrMsg);
		 sqlite3_free(zErrMsg);
		 return -1;
	 }

	 rc = sqlite3_exec(db, DEVICE_TRACK_INFO, callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
		 fprintf(stderr, "SQL error: %s\n", zErrMsg);
		 sqlite3_free(zErrMsg);
		 return -1;
	 }

	 return 0;
}

int add_customer_database(char *name)
{



}	


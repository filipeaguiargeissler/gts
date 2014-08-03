// Tables

#define FOREIGN_KEY_SUPPORT "PRAGMA foreign_keys = ON"

#define CUSTOMER_ID "CREATE TABLE customer(" \
	"CustomerID INT PRIMARY KEY," \
	"Name TEXT," \
	"Born TEXT," \
	"Address CHAR(100)," \
	"Tel1 CHAR(12)," \
	"Tel2 CHAR(12)," \
	"cel1 CHAR(12)," \
	"cel2 CHAR(12)," \
	"Gender CHAR(1)," \
	"ContactEmail TEXT," \
	"Username CHAR(20)," \
	"Password CHAR(20),"\
	"Status CHAR(1)" \
	");"	

#define CUSTOMER_FINANCES "CREATE TABLE finances(" \
	"Date TEXT," \
	"Price REAL," \
	"LimitDate TEXT," \
	"Paid CHAR(1)," \
	"CustomerFinances INTEGER," \
	"FOREIGN KEY(CustomerFinances) REFERENCES customer(CustomerID)" \
	");"	

#define CUSTOMER_DEVICE  "CREATE TABLE device(" \
	"DeviceID INT PRIMARY KEY," \
	"Car TEXT," \
	"CelNumber CHAR(12)," \
	"SerialNumber CHAR(12)," \
	"Blocked CHAR(1)," \
	"VoiceMonitor CHAR(1)," \
	"LimitAreaLatitude REAL," \
	"LimitAreaLongitude REAL," \
	"LimitVelocity REAL," \
	"CustomerDevice INTEGER," \
	"FOREIGN KEY(CustomerDevice) REFERENCES customer(CustomerID)" \
	");"

#define DEVICE_TRACK_INFO "CREATE TABLE deviceTrackInfo(" \
	"Date TEXT" \
	"Latitude REAL,"  \
	"Longitude REAL," \
	"Velocity REAL," \
	"Direction REAL," \
	"SatePos INTEGER," \
	"TotalKM INTEGER," \
	"CustomerDeviceTrackInfo INTEGER," \
	"FOREIGN KEY(CustomerDeviceTrackInfo) REFERENCES device(DeivceID)" \
	");"

// Helpers

#define CHECK_TABLE_EXISTS "SELECT * FROM customer"




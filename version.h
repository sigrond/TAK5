#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "13";
	static const char MONTH[] = "09";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.09";
	
	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";
	
	//Standard Version Type
	static const long MAJOR  = 6;
	static const long MINOR  = 50;
	static const long BUILD  = 511;
	static const long REVISION  = 2398;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 660;
	#define RC_FILEVERSION 6,50,511,2398
	#define RC_FILEVERSION_STRING "6, 50, 511, 2398\0"
	static const char FULLVERSION_STRING [] = "6.50.511.2398";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 2;
	

}
#endif //VERSION_H

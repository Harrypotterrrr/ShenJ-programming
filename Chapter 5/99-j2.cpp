/* 1∞‡ º÷Íª¡ÿ 1651574*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	char a[80];
#ifdef _MSC_VER
	gets_s(a);
	cout << "Visual Studio:\t" << _MSC_VER << endl;
#else	//#define __GNUC__
	#define GCC_VERSION (__GNUC__ * 10000 \
						+ __GNUC_MINOR__ * 100 \
						+ __GNUC_PATCHLEVEL__)
	#if (GCC_VERSION == 40902)
		gets(a);
		cout << "DEV or Codeblocks:\t" << GCC_VERSION << endl;
	#elif(GCC_VERSION == 40805)
		fgets(a, 1000, stdin);
		cout << "Linux:\t" << GCC_VERSION << endl;
	#endif
#endif
		cout << a << endl;
	return 0;
}
//	VS			_MSC_VER
//	DEV			__GNUC__40902
//	Codebloks	__GNUC__40902
//	Linux		__GNUC__40805
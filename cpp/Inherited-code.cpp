#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/**
 * Note: This solution only works with C++20 version of the online compiler
 *       Don't know why :)
 * 
 */

class BadLengthException: public exception
{
  int n;
  
  public:
  const char* what() throw()
  {
    stringstream tmp;
    tmp << n;
    char const *num_char = tmp.str().c_str();  
    return num_char;
  }
  
  BadLengthException(int a)
  {
      n = a;
  }

};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
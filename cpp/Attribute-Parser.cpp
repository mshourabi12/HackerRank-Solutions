#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * A struct to record information of each tag
 * 
 * vectors of attr and value are index-corresponding  
 * 
 */

struct Tag
{
    string name;
    vector<string> attr;
    vector<string> value;
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    string line;
    string str;
    string preTag;
    char ch;

    struct Tag t[20]; // max number of N

    // getting the N and Q from cin
    cin >> n >> q;
    cin.ignore(); // to ignore current line remainings for proper usage of getline()

    // parsing the first n lines
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);

        stringstream ss(line);

        // check whether it is a new tag
        if (line[0] == '<' && line[1] != '/')
        {
            ss >> ch >> str;

            if (ss.eof()) // no attributes for this tag is defined
            {
                str.pop_back(); // removing closing sign
            }

            if (preTag == "")
            {
                t[i].name = str;
            }

            else
            {
                t[i].name = preTag + "." + str;
            }

            preTag = t[i].name;
        }

        // if reaching a closing sign, remove the latest nested tag from preTag and continue the loop
        else if (line[0] == '<' && line[1] == '/')
        {
            int pos = preTag.find_last_of(".");
            if (pos == string::npos) // no '.' found. so this is the root tag
            {
                preTag = "";
            }
            else
            {
                preTag = preTag.substr(0, pos);
            }
            continue;
        }


        // recording attributes and values
        if (ss.eof()) // if no attributes for this tag is defined
        {
            continue; // then continue the loop
        }

        while (!ss.eof())
        {
            ss >> str;

            t[i].attr.push_back(str);

            ss >> str; // the '=' sign

            ss >> str;

            if (ss.eof())
            {
                str.pop_back(); // removing the closing sign
            }

            // removing the double quotation marks
            str.pop_back();
            str.erase(0, 1);

            t[i].value.push_back(str);
        }
    }

    // parsing and responding to queries
    for (int i = 0; i < q; i++)
    {
        getline(cin, line);

        stringstream ss(line);

        string qTag, qAttr;

        getline(ss, str, '~');

        qTag = str;

        getline(ss, str);

        qAttr = str;

        str = "Not Found!"; // set a default value for str

        // searching in all of the recorded tags for a matching tag name and attribute
        for (int i = 0; i < (n); i++) 
        {
            if (t[i].name == qTag)
            {
                for (int j = 0; j < t[i].attr.size(); j++)
                {
                    if (t[i].attr[j] == qAttr)
                    {
                        str = t[i].value[j]; // if a matching attribute found, assign it to str
                        break;
                    }
                }
            }
        }
        cout << str << endl;
    }

    return 0;
}

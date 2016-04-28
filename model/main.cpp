#include <iostream>
#include <map>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    std::map<QString,int> chatMap;
    std::cout<< chatMap["abc"] << std::endl;
    return 0;
}

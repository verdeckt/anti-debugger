//////////////////////////////////////////
// basic internet check heartbeat.
//////////////////////////////////////////

#include <iostream>
#include <Windows.h>
#include <wininet.h>

bool CheckInternetConnection()
{
    DWORD dwConnectionFlags = 0;
    return InternetGetConnectedState(&dwConnectionFlags, 0);
}

int main()
{
    while (true)
    {
        if (CheckInternetConnection())
        {
            std::cout << "Internet connection is active." << std::endl;
        }
        else
        {
            std::cerr << "No internet connection detected. Exiting application." << std::endl;
            exit(-1);
        }

    }

    return 0;
}

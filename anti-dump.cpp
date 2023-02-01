//////////////////////////////////////////
// Basic Dumper Check.
//////////////////////////////////////////

BOOL CheckForDumper()
{
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(VirtualQuery, &mbi, sizeof(mbi));
    return (mbi.Protect & PAGE_GUARD);
}

int main()
{

    if (CheckForDumper())
    {
        std::cout << "Dumper detected." << std::endl;
        std::cout << "Exiting program." << std::endl;
        return 0;
    }

    return 0;
}

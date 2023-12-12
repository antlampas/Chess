static turnManager& turnManager::getInstance(board& b)
{
    static turnManager instance(&b);
    return instance;
}
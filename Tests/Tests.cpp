import logging;
import <iostream>;

int main()
{
    std::cout<<"abc";
    Logger l = Logger(std::cout,Logger::Level::Debug,"./log.txt");
    l.Log("test 1",Logger::Level::Warning);
    return 0;
}

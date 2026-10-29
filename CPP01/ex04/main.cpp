
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Please use the program like this:" << std::endl;
        std::cout << "./bed <path_to_file> <to_find> <to_replace>" << std::endl;
        return 1;
    }

    std::string to_find = argv[2];
    if (to_find.empty())
    {
        std::cerr << "Error: The string to find cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream streamFile(argv[1]);
    if (!streamFile)
    {
        std::cerr << "Cannot open `" << argv[1] << "` for reading." << std::endl;
        return 1;
    }

    std::ofstream outStream((std::string(argv[1]) + ".replace").c_str());
    if (!outStream)
    {
        std::cerr << "Cannot open `" << argv[1] << ".replace` for writing." << std::endl;
        streamFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(streamFile, line))
    {
        std::string result;
        std::size_t pos = 0;
        std::size_t found_pos;

        while ((found_pos = line.find(to_find, pos)) != std::string::npos)
        {
            result += line.substr(pos, found_pos - pos);
            result += argv[3];
            pos = found_pos + to_find.length();
        }
        result += line.substr(pos);

        outStream << result << std::endl;
    }

    streamFile.close();
    outStream.close();
    return 0;
}

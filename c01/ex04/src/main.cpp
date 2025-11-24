#include <iostream>
#include <fstream>
#include <string>

std::string replace_all(std::string line, const std::string &s1, const std::string &s2) {
    size_t pos = line.find(s1);

    while (pos != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos = line.find(s1, pos + s2.length());
    }
    return line;
}

int error_message(const std::string &msg) {
    std::cerr << msg << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return error_message("Wrong number of args");

    std::string s1 = argv[2];
    if (s1.empty())
        return error_message("Empty s1 string");

    std::ifstream in(argv[1]);
    if (!in.is_open())
        return error_message("Error to open file");

    std::string outfile = std::string(argv[1]) + ".replace";
    std::ofstream out(outfile.c_str());
    if (!out.is_open())
        return error_message("Error to create file");

    std::string s2 = argv[3];
    std::string line;

    while (std::getline(in, line)) {
        out << replace_all(line, s1, s2) << "\n";
    }
}


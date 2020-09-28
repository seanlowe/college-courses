/* @slowe, make your own ls command */
#include <iostream>
#include <vector>
#include <algorithm>
#include <dirent.h>

int main(int argc, char* argv[]) {
    DIR *dir; struct dirent *direc; std::vector<std::string> list;
    dir = (argc >= 2) ? opendir(argv[1]) : opendir(".");
    if (!dir) { exit(1); } else {
        while ( (direc = readdir(dir)) != NULL ) { std::string a(direc->d_name); list.push_back(a); }
        closedir(dir);
        sort(list.begin(), list.end());
        for (int i = 0; i < list.size(); i++) {
            std::cout << list[i] << std::endl;
        } } exit(0); }
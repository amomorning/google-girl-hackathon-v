#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <io.h>
#include <direct.h>

std::vector<std::string> getFiles(const std::string &cate_dir)
{
	std::vector<std::string> files;

	_finddata_t file;
	intptr_t lf;
	// the type should be intptr_t in x64 machine
	// but it will be fine using long in x86

	if ((lf = _findfirst(cate_dir.c_str(), &file)) == -1) {
		std::cout << cate_dir << " not found!!!" << std::endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			// cout<<file.name<<endl;
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			files.push_back(file.name);
		}
	}
	_findclose(lf);

	std::sort(files.begin(), files.end());
	return files;
}
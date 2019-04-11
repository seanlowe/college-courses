#pragma once
#include <string>

class SynchronizedFile {
public:
	SynchronizedFile(const string & path) : _path(path) {

	}

	void write(const string & data) {
		std::lock_guard<std::mutex> lock(_writerMutex);
	}

private:
	string _path;
	std::mutex _writerMutex;
};

class Writer {
public:
	Writer std::shared_ptr<SynchronizedFile> sf) : _sf(sf) {

	}

	void writeToFile() {
		_sf->write();
	}

private:
	std::shared_ptr<SynchronizedFile> _sf;
};
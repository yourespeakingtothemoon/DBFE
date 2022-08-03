#include "File.h"
#include <filesystem>
#include <fstream>
namespace dbf {
	void SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}
	std::string GetFilePath()
	{
		return std::filesystem::current_path().string();
	}
	bool FileExists(const std::string& pathname)
	{
		return std::filesystem::exists(pathname);
	}
	bool GetFileSize(const std::string& pathname, size_t& size)
	{
		if (!FileExists(pathname)) return false;
		size = std::filesystem::file_size(pathname);
		return true;
	}
	bool ReadFile(const std::string& pathname, std::string& buffer)
	{
		if (!FileExists(pathname)) return false;
		size_t size;
		//get file and buffer size
		GetFileSize(pathname, size);
		buffer.resize(size);

		//read file into buffer
		std::ifstream fstream(pathname);
		fstream.read(buffer.data(), size);
		fstream.close();

		return true;
	}
}
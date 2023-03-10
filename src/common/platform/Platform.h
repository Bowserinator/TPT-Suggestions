#pragma once
#include "common/String.h"
#include <string>

namespace Platform
{
	ByteString GetCwd();
	ByteString ExecutableNameFirstApprox();
	ByteString ExecutableName();
	void DoRestart();

	void OpenURI(ByteString uri);

	void Millisleep(long int t);
	long unsigned int GetTime();

	bool Stat(ByteString filename);
	bool FileExists(ByteString filename);
	bool DirectoryExists(ByteString directory);
	/**
	 * @return true on success
	 */
	bool RemoveFile(ByteString filename);
	bool RenameFile(ByteString filename, ByteString newFilename, bool replace);

	/**
	 * @return true on success
	 */
	bool DeleteDirectory(ByteString folder);

	/**
	 * @return true on success
	 */
	bool MakeDirectory(ByteString dir);
	std::vector<ByteString> DirectoryList(ByteString directory);
	std::vector<ByteString> DirectorySearch(ByteString directory, ByteString search, std::vector<ByteString> extensions);

	bool ReadFile(std::vector<char> &fileData, ByteString filename);
	bool WriteFile(const std::vector<char> &fileData, ByteString filename);

	ByteString WinNarrow(const std::wstring &source);
	std::wstring WinWiden(const ByteString &source);

	extern std::string originalCwd;
	extern std::string sharedCwd;

	bool CanUpdate();

	bool Install();

	bool ChangeDir(ByteString toDir);

	bool UpdateStart(const std::vector<char> &data);
	bool UpdateFinish();
	void UpdateCleanup();

	void SetupCrt();

	using ExitFunc = void (*)();
	void Atexit(ExitFunc exitFunc);
	void Exit(int code);
}

#pragma once

#include <string>
#include <locale>
#include <codecvt>

using namespace std;

class ConverterString
{
	static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
public:
	static std::string toString(const wstring& s);
	static std::string toString(const wchar_t* s);

	static std::wstring toWString(const string& s);
	static std::wstring toWString(const char* s);

};

#define nameof(x) gcnew System::String(ConverterString::toWString(#x).c_str())
#include "ConverterString.h"

std::string ConverterString::toString(const wstring& s)
{
	return converter.to_bytes(s.c_str());
}

std::string ConverterString::toString(const wchar_t* s)
{
	return converter.to_bytes(s);
}

std::wstring ConverterString::toWString(const string& s)
{
	return converter.from_bytes(s.c_str());
}

std::wstring ConverterString::toWString(const char* s)
{
	return converter.from_bytes(s);
}

std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> ConverterString::converter;
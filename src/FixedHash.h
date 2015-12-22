#pragma once

class FixedHash {
	//from Aslan Dzodzikov
	//taken from http://www.humus.name/index.php?page=Comments&ID=296&start=16
	//  void PrintHash(const Hash& _hash) { 
	//    printf( "%x", (unsigned)_hash ); 
	//  } 
	//  PrintHash("Creating Device! Just a test for StringHash"); 
	//this version seems to work only in vs2008 and above :/
	unsigned m_val;

	template<size_t N> unsigned _Hash(const char(&str)[N]) {
		typedef const char(&truncated_str)[N - 1];
		return str[N - 1] + 65599 * _Hash((truncated_str)str);
	}
	unsigned _Hash(const char(&str)[2]) { return str[1] + 65599 * str[0]; }
public:
	template <size_t N> FixedHash(const char(&str)[N]) {
		m_val = _Hash(str);
	}
	operator unsigned() {
		return m_val;
	}
};
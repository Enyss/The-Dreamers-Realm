#pragma once

#define ME_INLINE __forceinline

template <unsigned int N, unsigned int I>
struct FnvHash
{
	ME_INLINE static unsigned int Hash(const char(&str)[N])
	{
		return (FnvHash<N, I - 1>::Hash(str) ^ str[I - 1]) * 16777619u;
	}
};

template <unsigned int N>
struct FnvHash<N, 1>
{
	ME_INLINE static unsigned int Hash(const char(&str)[N])
	{
		return (2166136261u ^ str[0]) * 16777619u;
	}
};

class Hash
{
public:
	template <unsigned int N>
	ME_INLINE Hash(const char(&str)[N])
		: m_hash(FnvHash<N, N>::Hash(str))
	{
	}
	bool const operator==(const Hash& hash) const { return m_hash == hash.m_hash; }
	bool const operator!=(const Hash& hash) const { return m_hash != hash.m_hash; }
	bool const operator<(const Hash& hash) const { return m_hash < hash.m_hash; }
	int m_hash;
};
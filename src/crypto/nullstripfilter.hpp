#ifndef SRC_CRYPTO_NULLSTRIPFILTER_HPP_
#define SRC_CRYPTO_NULLSTRIPFILTER_HPP_

#include <cryptopp/filters.h>

class NullStripFilter: public CryptoPP::Filter
{
public:
	NullStripFilter(BufferedTransformation* attachment = NULL)
			: CryptoPP::Filter(attachment) { };

	std::size_t Put2(const CryptoPP::byte * inString,
			std::size_t length, int messageEnd, bool blocking);

	bool IsolatedFlush(bool, bool){
		return false;
	}
};
#endif

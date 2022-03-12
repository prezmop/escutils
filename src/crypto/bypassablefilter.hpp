#ifndef CRYPTO_BYPASSABLEFILTER_HPP_
#define CRYPTO_BYPASSABLEFILTER_HPP_

#include <cryptopp/filters.h>

class BypassableFilter : public CryptoPP::Filter {
public:
	BypassableFilter( bool use, BufferedTransformation* bypass, BufferedTransformation* next = NULL )
		: Filter(use ? bypass : next) {
		if (use){
			bypass->Attach(next);
		}else{
			delete bypass;
		}
	}

	std::size_t Put2(const CryptoPP::byte * inString,
		std::size_t length, int messageEnd, bool blocking ){
		return AttachedTransformation()->Put2(
			inString, length, messageEnd, blocking );
	}
	bool IsolatedFlush( bool, bool ) { return false; }
};

#endif

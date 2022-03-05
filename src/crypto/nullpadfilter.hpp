#ifndef SRC_CRYPTO_NULLPADFILTER_HPP_
#define SRC_CRYPTO_NULLPADFILTER_HPP_

#include <cryptopp/filters.h>

template <std::size_t blockSize>
class NullPadFilter: public CryptoPP::Filter
{
public:
	NullPadFilter(BufferedTransformation* attachment = NULL)
			: CryptoPP::Filter(attachment) { };

	std::size_t Put2(const CryptoPP::byte * inString,
			std::size_t length, int messageEnd, bool blocking){
		if (length % blockSize != 0){
			//we have to create a new (larger) buffer
			CryptoPP::SecByteBlock newBuffer(((length / blockSize) + 1) * blockSize);
			std::size_t i = 0;
			for(i = 0; i < length; i++){
				newBuffer[i] = inString[i];
			}
			for(; i < newBuffer.size(); i++){
				newBuffer[i] = 0x00;
			}
			return AttachedTransformation()->Put2(
					newBuffer.data(), newBuffer.size(), messageEnd, blocking );
		}else{
			return AttachedTransformation()->Put2(
					inString, length, messageEnd, blocking );
		}
	}

	bool IsolatedFlush(bool, bool){
		return false;
	}
};
#endif

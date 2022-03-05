#ifndef REVERSEFILTER_HPP_
#define REVERSEFILTER_HPP_

#include <stdexcept>
#include <algorithm>
#include <cryptopp/filters.h>

template <std::size_t blockSize>
class ReverseFilter : public CryptoPP::Filter
{
public:
	ReverseFilter(BufferedTransformation* attachment = NULL)
		: CryptoPP::Filter(attachment) { };

	std::size_t Put2(const CryptoPP::byte * inString,
		std::size_t length, int messageEnd, bool blocking ){


		if(length % blockSize != 0){
			//we have to create a new (larger) buffer
			CryptoPP::SecByteBlock newBuffer(((length / blockSize) + 1) * blockSize );

			for(std::size_t i = 0;i < length; i++){
				newBuffer.data()[(i / blockSize) * blockSize + (blockSize - (i % blockSize) - 1)] = inString[i];
			}
			return AttachedTransformation()->Put2(
				newBuffer.data(), newBuffer.size(), messageEnd, blocking );
		}else{

			for(std::size_t i = 0;i < length; i += blockSize){
				std::reverse((char *)inString + i,(char *)inString + i + blockSize);
			}

			return AttachedTransformation()->Put2(
					inString, length, messageEnd, blocking );
		}
	}

	bool IsolatedFlush(bool hardFlush, bool blocking){
		return false;
	}
};
#endif

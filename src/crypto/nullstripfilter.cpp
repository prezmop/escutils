#include "nullstripfilter.hpp"

#include <iostream>

std::size_t NullStripFilter::Put2(const CryptoPP::byte * inString,
		std::size_t length, int messageEnd, bool blocking){
	std::size_t i;
	for(i = length; i > 0; i--){
		if (inString[i - 1] != 0){
			break;
		}
	}

	return AttachedTransformation()->Put2(
			inString, i, messageEnd, blocking );
}


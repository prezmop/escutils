#include "cryptography.hpp"

#include <cryptopp/blowfish.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>

#include "reversefilter.hpp"
#include "cryptokeys.hpp"
#include "bypassablefilter.hpp"
#include "nullstripfilter.hpp"
#include "nullpadfilter.hpp"

void decrypt(std::istream& in,std::ostream& out, bool stripNull){
	CryptoPP::ECB_Mode< CryptoPP::Blowfish >::Decryption d;
	d.SetKey(defaultkey, defaultkeysize);

	CryptoPP::FileSource s( in, true,
		new ReverseFilter<4>(
			new CryptoPP::StreamTransformationFilter( d,
				new ReverseFilter<4>(
					new BypassableFilter(stripNull, new NullStripFilter(),
						new CryptoPP::FileSink( out )
					) // NullStripFilter (bypassable)
				), // ReverseFilter
			CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme::NO_PADDING
			) // StreamTransformationFilter
		) // ReverseFilter
	); // FileSource
}

void encrypt(std::istream& in,std::ostream& out){
	CryptoPP::ECB_Mode< CryptoPP::Blowfish >::Encryption e;
	e.SetKey(defaultkey, defaultkeysize);

	CryptoPP::FileSource s( in, true,
		new NullPadFilter<8>(
			new ReverseFilter<4>(
				new CryptoPP::StreamTransformationFilter( e,
					new ReverseFilter<4>(
						new CryptoPP::FileSink( out )
					), // ReverseFilter
					CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme::NO_PADDING
				) // StreamTransformationFilter
			) // ReverseFilter
		) // NullPadFilter
	); // FileSource
}


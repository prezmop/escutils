#include "cryptography.hpp"

#include <cryptopp/blowfish.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>

#include "reversefilter.hpp"
#include "cryptokeys.hpp"
#include "bypassablefilter.hpp"
#include "nullstripfilter.hpp"

void pipeline(std::istream& in, std::ostream& out, CryptoPP::StreamTransformation& t, bool stripNull = false){
	CryptoPP::FileSource s( in, true,
		new ReverseFilter<4>(
			new CryptoPP::StreamTransformationFilter( t,
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

void decrypt(std::istream& in,std::ostream& out, bool stripNull){
	CryptoPP::ECB_Mode< CryptoPP::Blowfish >::Decryption d;
	d.SetKey(defaultkey, defaultkeysize);

	pipeline(in, out, d, stripNull);
}

void encrypt(std::istream& in,std::ostream& out){
	CryptoPP::ECB_Mode< CryptoPP::Blowfish >::Encryption e;
	e.SetKey(defaultkey, defaultkeysize);

	pipeline(in, out, e);
}


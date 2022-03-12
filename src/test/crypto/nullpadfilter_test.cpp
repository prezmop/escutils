#include <crypto/nullpadfilter.hpp>

#include <catch2/catch.hpp>

#include <vector>

std::vector<CryptoPP::byte> padpipeline(std::vector<CryptoPP::byte> in){
	std::vector<CryptoPP::byte> ret(( in.size() / 4 + 1 ) * 4, '@');
	CryptoPP::ArraySource s(in.data(),in.size(),true,
		new NullPadFilter<4>(
			new CryptoPP::ArraySink(ret.data(),ret.size())
		)
	);
	return ret;
}

TEST_CASE("null pad filter","[NullPadFilter]"){
	SECTION("pads with null bytes"){
		REQUIRE(padpipeline({ 'a'}) ==
			std::vector<CryptoPP::byte>({ 'a', 0, 0, 0}));
		REQUIRE(padpipeline({ 'a', 'b'}) ==
			std::vector<CryptoPP::byte>({ 'a', 'b', 0, 0}));
		REQUIRE(padpipeline({ 'a', 'b', 'c', 'd', 'e', 'f', 'g'}) ==
			std::vector<CryptoPP::byte>({ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 0}));
	}
	SECTION("does not pad when length is a multiple of the block size (demonstrated by magic @)"){
		REQUIRE(padpipeline({}) ==
			std::vector<CryptoPP::byte>({ '@', '@', '@', '@'}));
		REQUIRE(padpipeline({ 'a', 'b', 'c', 'd'}) ==
			std::vector<CryptoPP::byte>({ 'a', 'b', 'c', 'd', '@', '@', '@', '@'}));
		REQUIRE(padpipeline({ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}) ==
			std::vector<CryptoPP::byte>({ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '@', '@', '@', '@'}));
	}
}

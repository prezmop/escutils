#include <crypto/nullstripfilter.hpp>

#include <catch2/catch.hpp>

#include <vector>

std::vector<CryptoPP::byte> strippipeline(std::vector<CryptoPP::byte> in){
	std::vector<CryptoPP::byte> ret(in.size(), '@');
	CryptoPP::ArraySource s(in.data(),in.size(),true,
		new NullStripFilter(
			new CryptoPP::ArraySink(ret.data(),ret.size())
		)
	);
	return ret;
}

TEST_CASE("null strip filter","[NullPadFilter]"){
	SECTION("strips tailing null bytes"){
		REQUIRE(strippipeline(std::vector<CryptoPP::byte>(10, 0)) ==
			std::vector<CryptoPP::byte>(10, '@'));
		REQUIRE(strippipeline({ 1, 2, 3, 4, 0, 0, 0}) ==
			std::vector<CryptoPP::byte>({ 1, 2, 3, 4, '@', '@', '@'}));
	}
	SECTION("doesn't touch other (non-tailing) null bytes"){
		REQUIRE(strippipeline({ 'a', 0, 'a', 'a'}) ==
			std::vector<CryptoPP::byte>({ 'a', 0, 'a', 'a'}));
		REQUIRE(strippipeline({ 0, 0, 'b', 0}) ==
			std::vector<CryptoPP::byte>({ 0, 0, 'b', '@'}));
	}
	SECTION("does nothing when there are no null bytes"){
		REQUIRE(strippipeline({ 'a', 'a', 'a', 'a'}) ==
			std::vector<CryptoPP::byte>({ 'a', 'a', 'a', 'a'}));
	}
}

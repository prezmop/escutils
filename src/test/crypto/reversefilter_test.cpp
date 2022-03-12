#include <crypto/reversefilter.hpp>

#include <catch2/catch.hpp>

#include <vector>

std::vector<CryptoPP::byte> revpipeline(std::vector<CryptoPP::byte> in){
	std::vector<CryptoPP::byte> ret(in.size(),'@');
	CryptoPP::ArraySource s(in.data(),in.size(),true,
		new ReverseFilter<4>(
			new CryptoPP::ArraySink(ret.data(),in.size())
		)
	);
	return ret;
}

TEST_CASE("reverse filter","[ReverseFilter]"){
	SECTION("reverses byte order in a loop"){
		REQUIRE(revpipeline({'a','b','c','d'}) ==
			std::vector<CryptoPP::byte>({'d','c','b','a'}));
		REQUIRE(revpipeline({ 0, 1, 2, 3, 4, 5, 6, 7}) ==
			std::vector<CryptoPP::byte>({ 3, 2, 1, 0, 7, 6, 5, 4}));
	}

	SECTION("throws on invalid size"){
		REQUIRE_THROWS(revpipeline({ 0, 1, 2}));
		REQUIRE_THROWS(revpipeline({ 0, 1, 2, 'a', 'b', 'c'}));
	}
}



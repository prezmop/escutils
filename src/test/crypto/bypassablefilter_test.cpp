#include <crypto/bypassablefilter.hpp>

#include <catch2/catch.hpp>

#include <vector>

class ExplosiveFilter : public CryptoPP::Filter {
public:
	std::size_t Put2(const CryptoPP::byte*,std::size_t , int, bool){
		throw true;
	}
	bool IsolatedFlush( bool, bool ) { return false; }
};

std::vector<CryptoPP::byte> bypasspipeline(std::vector<CryptoPP::byte> in, bool use){
	std::vector<CryptoPP::byte> ret(in.size(),'@');
	CryptoPP::ArraySource s(in.data(),in.size(),true,
		new BypassableFilter(use,new ExplosiveFilter(),
			new CryptoPP::ArraySink(ret.data(),in.size())
		)
	);
	return ret;
}

TEST_CASE("bypassable filter","[BypassableFilter]"){
	SECTION("can bypass a filter"){
		REQUIRE_THROWS(bypasspipeline({},true));
		REQUIRE_NOTHROW(bypasspipeline({},false));
	}
	SECTION("does not alter pipeline contents on its own"){
		REQUIRE(bypasspipeline(std::vector<CryptoPP::byte>(11,'@'),false) ==
			std::vector<CryptoPP::byte>(11,'@'));
	}
}

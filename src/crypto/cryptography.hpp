#ifndef CRYPTOGRAPHY_HPP_
#define CRYPTOGRAPHY_HPP_

#include <istream>
#include <ostream>

void encrypt(std::istream& in,std::ostream& out);
void decrypt(std::istream& in,std::ostream& out, bool stripNull = false);

#endif

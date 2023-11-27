#include <string>

#include "Parameter.h"
#include "Token.h"

string Parameter::toString() {
	return token.getLiteral();
}
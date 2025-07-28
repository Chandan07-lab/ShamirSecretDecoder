#ifndef SSS_HPP
#define SSS_HPP

#include <string>
#include <vector>
#include <map>

#define BIGINT std::string
#define PAIR_INT_BIGINT std::pair<int, BIGINT>
#define VEC_PAIR_INT_BIGINT std::vector<PAIR_INT_BIGINT>
#define MAP_STR_STR std::map<std::string, std::string>
#define MAP_STR_MAP std::map<std::string, MAP_STR_STR>

using namespace std;

namespace sss {

BIGINT base_to_bigint(const string& s, int base);
BIGINT lagrange_constant_term(const VEC_PAIR_INT_BIGINT& pts);
MAP_STR_MAP read_json_cases(const string& fname);
BIGINT process_jsonfile(const string& fname);
BIGINT string_add(const BIGINT& a, const BIGINT& b);
BIGINT string_mul(const BIGINT& a, const BIGINT& b);
BIGINT string_div(const BIGINT& a, const BIGINT& b);
BIGINT string_sub(const BIGINT& a, const BIGINT& b);

}
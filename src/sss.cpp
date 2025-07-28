#include "sss.hpp"
    int k = pts.size();
    for (int i = 0; i < k; ++i) {
        BIGINT num = "1", denom = "1";
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            num = string_mul(num, to_string(-pts[j].first));
            denom = string_mul(denom, to_string(pts[i].first - pts[j].first));
        }
        BIGINT term = string_div(string_mul(pts[i].second, num), denom);
        secret = string_add(secret, term);
    }
    return secret;
}

MAP_STR_MAP read_json_cases(const string& fname) {
    ifstream fin(fname);
    if (!fin) throw runtime_error("Unable to open file " + fname);

    stringstream buf;
    buf << fin.rdbuf();
    string raw = buf.str();
    raw.erase(remove_if(raw.begin(), raw.end(), ::isspace), raw.end());

    MAP_STR_MAP TC;
    regex re(R"("(\d+)":\{"base":"(\d+)","value":"([a-zA-Z0-9]+)"\})");
    smatch m;
    auto it = raw.cbegin();
    while (regex_search(it, raw.cend(), m, re)) {
        string k = m[1], base = m[2], value = m[3];
        TC[k]["base"] = base;
        TC[k]["value"] = value;
        it = m.suffix().first;
    }

    regex rek(R"("keys":\{"n":(\d+),"k":(\d+)\})");
    smatch mk;
    if (regex_search(raw, mk, rek)) {
        TC["keys"]["n"] = mk[1];
        TC["keys"]["k"] = mk[2];
    }
    return TC;
}

BIGINT process_jsonfile(const string& fname) {
    auto obj = read_json_cases(fname);
    int n = stoi(obj["keys"]["n"]);
    int k = stoi(obj["keys"]["k"]);

    VEC_PAIR_INT_BIGINT pts;
    for (int cnt = 0, idx = 1; cnt < n; ++idx) {
        string key = to_string(idx);
        if (obj.count(key) == 0) continue;
        int base = stoi(obj[key]["base"]);
        string yval = obj[key]["value"];
        BIGINT y = base_to_bigint(yval, base);
        pts.emplace_back(idx, y);
        ++cnt;
    }
    if (pts.size() < k) throw runtime_error("Not enough valid points to reconstruct secret");
    auto subset = VEC_PAIR_INT_BIGINT(pts.begin(), pts.begin() + k);
    return lagrange_constant_term(subset);
}

#include <iostream>

#if __has_include(<drogon/drogon.h>)
#   define RUN_WEBSERVER 1
#   include <drogon/drogon.h>
#   include <module/n.h>
#include <module/z.h>
#include <module/q.h>
#include <base/RationalFraction.h>

using namespace drogon;
#else
#   define RUN_WEBSERVER 0
#endif

#if RUN_WEBSERVER

void initNModule(){
	app()
	.registerHandler(
		"/COM_NN_D?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::ULongNumber vA(a);
			base::ULongNumber vB(b);

			Json::Value json;
			json["response"] = module::COM_NN_D(vA, vB);
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
		)
	.registerHandler(
		"/NZER_N_B?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::ULongNumber vA(a);

			Json::Value json;
			json["response"] = module::NZER_N_B(vA);
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
		)
	.registerHandler(
		"/ADD_1N_N?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::ULongNumber vA(a);

			Json::Value json;
			json["response"] = module::ADD_1N_N(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/ADD_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::ULongNumber vA(a);
			base::ULongNumber vB(b);

			Json::Value json;
			json["response"] = module::ADD_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::ULongNumber vA(a);
			base::ULongNumber vB(b);

			Json::Value json;
			json["response"] = module::SUB_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_ND_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const DIGIT &b) {
			base::ULongNumber vA(a);

			Json::Value json;
			json["response"] = module::MUL_ND_N(vA, b).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_Nk_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const size_t &k) {
			base::ULongNumber vA(a);

			Json::Value json;
			json["response"] = module::MUL_Nk_N(vA, k).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::ULongNumber vA(a);
			base::ULongNumber vB(b);

			Json::Value json;
			json["response"] = module::MUL_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_NDN_N?a={a}&k={k}&&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const DIGIT k, const std::string &b) {
			base::ULongNumber vA(a);
			base::ULongNumber vB(b);

			Json::Value json;
			json["response"] = module::SUB_NDN_N(vA, k, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_NN_Dk?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::NLongNumber vA(a);
			base::NLongNumber vB(b);
			auto t = module::DIV_NN_Dk(vA, vB);

			Json::Value json;
			json["response"]["digit"] = t.first;
			json["response"]["k"] = (long long)t.second;
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::NLongNumber vA(a);
			base::NLongNumber vB(b);

			Json::Value json;
			json["response"] = module::DIV_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MOD_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::NLongNumber vA(a);
			base::NLongNumber vB(b);

			Json::Value json;
			json["response"] = module::MOD_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/GCF_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::NLongNumber vA(a);
			base::NLongNumber vB(b);

			Json::Value json;
			json["response"] = module::GCF_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/LCM_NN_N?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::NLongNumber vA(a);
			base::NLongNumber vB(b);

			Json::Value json;
			json["response"] = module::LCM_NN_N(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	;
}

void initZModule(){
	app()
	.registerHandler(
		"/ABS_Z_N?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::LongNumber vA(a);

			Json::Value json;
			json["response"] = module::ABS_Z_N(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/POZ_Z_D?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::LongNumber vA(a);

			Json::Value json;
			json["response"] = module::POZ_Z_D(vA);
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_ZM_Z?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::LongNumber vA(a);

			Json::Value json;
			json["response"] = module::MUL_ZM_Z(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/TRANS_N_Z?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::NLongNumber vA(a);

			Json::Value json;
			json["response"] = module::TRANS_N_Z(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/TRANS_Z_N?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::LongNumber vA(a);

			Json::Value json;
			json["response"] = module::TRANS_Z_N(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/ADD_ZZ_Z?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::LongNumber vA(a);
			base::LongNumber vB(b);

			Json::Value json;
			json["response"] = module::ADD_ZZ_Z(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_ZZ_Z?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::LongNumber vA(a);
			base::LongNumber vB(b);

			Json::Value json;
			json["response"] = module::SUB_ZZ_Z(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_ZZ_Z?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::LongNumber vA(a);
			base::LongNumber vB(b);

			Json::Value json;
			json["response"] = module::MUL_ZZ_Z(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_ZZ_Z?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::LongNumber vA(a);
			base::LongNumber vB(b);

			Json::Value json;
			json["response"] = module::DIV_ZZ_Z(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MOD_ZZ_Z?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			base::LongNumber vA(a);
			base::LongNumber vB(b);

			Json::Value json;
			json["response"] = module::MOD_ZZ_Z(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	;
}

void initQModule(){
	app()
	.registerHandler(
		"/RED_Q_Q?numerator={n}&denominator={d}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n, const std::string &d) {
			base::RationalFraction number((base::LongNumber(n)), base::NLongNumber(d));

			Json::Value json;
			json["response"] = module::RED_Q_Q(number).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/INT_Q_B?numerator={n}&denominator={d}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n, const std::string &d) {
			base::RationalFraction number((base::LongNumber(n)), base::NLongNumber(d));

			Json::Value json;
			json["response"] = module::INT_Q_B(number);
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/TRANS_Z_Q?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			base::LongNumber vA(a);

			Json::Value json;
			json["response"] = module::TRANS_Z_Q(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/TRANS_Q_Z?numerator={n}&denominator={d}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n, const std::string &d) {
			base::RationalFraction number((base::LongNumber(n)), base::NLongNumber(d));

			Json::Value json;
			json["response"] = module::TRANS_Q_Z(number).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/ADD_QQ_Q?numerator1={n1}&denominator1={d1}&numerator2={n2}&denominator2={d2}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n1, const std::string &d1, const std::string &n2, const std::string &d2
		   ) {
			base::RationalFraction number1((base::LongNumber(n1)), base::NLongNumber(d1));
			base::RationalFraction number2((base::LongNumber(n2)), base::NLongNumber(d2));

			Json::Value json;
			json["response"] = module::ADD_QQ_Q(number1, number2).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_QQ_Q?numerator1={n1}&denominator1={d1}&numerator2={n2}&denominator2={d2}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n1, const std::string &d1, const std::string &n2, const std::string &d2
		   ) {
			base::RationalFraction number1((base::LongNumber(n1)), base::NLongNumber(d1));
			base::RationalFraction number2((base::LongNumber(n2)), base::NLongNumber(d2));

			Json::Value json;
			json["response"] = module::SUB_QQ_Q(number1, number2).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_QQ_Q?numerator1={n1}&denominator1={d1}&numerator2={n2}&denominator2={d2}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n1, const std::string &d1, const std::string &n2, const std::string &d2
		   ) {
			base::RationalFraction number1((base::LongNumber(n1)), base::NLongNumber(d1));
			base::RationalFraction number2((base::LongNumber(n2)), base::NLongNumber(d2));

			Json::Value json;
			json["response"] = module::MUL_QQ_Q(number1, number2).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_QQ_Q?numerator1={n1}&denominator1={d1}&numerator2={n2}&denominator2={d2}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &n1, const std::string &d1, const std::string &n2, const std::string &d2
		   ) {
			base::RationalFraction number1((base::LongNumber(n1)), base::NLongNumber(d1));
			base::RationalFraction number2((base::LongNumber(n2)), base::NLongNumber(d2));

			Json::Value json;
			json["response"] = module::DIV_QQ_Q(number1, number2).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	;
}

void initPModule(){

}

#endif

int main() {
#if RUN_WEBSERVER
	initNModule();
	initZModule();
	initQModule();
	initPModule();
	std::cout << "Running web server..." << std::endl;
	app()
	.addListener("0.0.0.0", 3041)
	.setThreadNum(1)
	//.enableRunAsDaemon()
	//.enableReusePort()
	.run();
#else
	std::cout << "I cant run webserver due to no drogon lib";
#endif
	return 0;
}
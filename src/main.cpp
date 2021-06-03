#include <iostream>
//#define WINDOWS

#if __has_include(<drogon/drogon.h>)
#   define RUN_WEBSERVER 1
#   include <drogon/drogon.h>
#   include <module/n.h>
#include <module/z.h>
#include <module/q.h>
#include <base/RationalFraction.h>
#include <module/p.h>
#include <base/Polynomial.h>

#include <iostream>

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
			json["response"]["digit"] = t.first; //t.first;
			json["response"]["k"] = (long long)t.second; //(long long)t.second;
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
		"/RED_Q_Q?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::RationalFraction::fromString(a);

			Json::Value json;
			json["response"] = module::RED_Q_Q(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/INT_Q_B?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::RationalFraction::fromString(a);

			Json::Value json;
			json["response"] = module::INT_Q_B(vA);
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
		"/TRANS_Q_Z?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::RationalFraction::fromString(a);

			Json::Value json;
			json["response"] = module::TRANS_Q_Z(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/ADD_QQ_Q?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b
		) {
			auto vA = base::RationalFraction::fromString(a);
			auto vB = base::RationalFraction::fromString(b);

			Json::Value json;
			json["response"] = module::ADD_QQ_Q(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_QQ_Q?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b
		) {
			auto vA = base::RationalFraction::fromString(a);
			auto vB = base::RationalFraction::fromString(b);

			Json::Value json;
			json["response"] = module::SUB_QQ_Q(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_QQ_Q?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b
		) {
			auto vA = base::RationalFraction::fromString(a);
			auto vB = base::RationalFraction::fromString(b);

			Json::Value json;
			json["response"] = module::MUL_QQ_Q(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_QQ_Q?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b
		   ) {
			auto vA = base::RationalFraction::fromString(a);
			auto vB = base::RationalFraction::fromString(b);

			Json::Value json;
			json["response"] = module::DIV_QQ_Q(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	;
}

void initPModule(){
	app()
	.registerHandler(
		"/ADD_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::ADD_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/SUB_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::SUB_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_PQ_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::RationalFraction::fromString(b);

			Json::Value json;
			json["response"] = module::MUL_PQ_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_Pxk_P?a={a}&k={k}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &k) {
			auto vA = base::Polynomial::fromString(a);
			auto vK = base::ULongNumber(k);

			Json::Value json;
			json["response"] = module::MUL_Pxk_P(vA, vK).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/LED_P_Q?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::Polynomial::fromString(a);

			Json::Value json;
			json["response"] = module::LED_P_Q(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DEG_P_N?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::Polynomial::fromString(a);

			Json::Value json;
			json["response"] = module::DEG_P_N(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/FAC_P_Q?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::Polynomial::fromString(a);

			Json::Value json;
			json["response"] = module::FAC_P_Q(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MUL_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::MUL_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DIV_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::DIV_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/MOD_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::MOD_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/GCF_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::GCF_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/GCF_PP_P?a={a}&b={b}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a, const std::string &b) {
			auto vA = base::Polynomial::fromString(a);
			auto vB = base::Polynomial::fromString(b);

			Json::Value json;
			json["response"] = module::GCF_PP_P(vA, vB).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/DER_P_P?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::Polynomial::fromString(a);

			Json::Value json;
			json["response"] = module::DER_P_P(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	.registerHandler(
		"/NMR_P_P?a={a}",
		[](const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   const std::string &a) {
			auto vA = base::Polynomial::fromString(a);

			Json::Value json;
			json["response"] = module::NMR_P_P(vA).toString();
			callback(HttpResponse::newHttpJsonResponse(json));
		},{Get}
	)
	;
}

#endif

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include<iostream>
using namespace std;

std::string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir( buff, FILENAME_MAX );
	string current_working_dir(buff);
	return current_working_dir;
}

int main() {

	#if RUN_WEBSERVER
	initNModule();
	initZModule();
	initQModule();
	initPModule();
	std::cout << "Running web server #..." << std::endl;
	app().setExceptionHandler(
		[](
			const std::exception &exception,
			const HttpRequestPtr& req,
	        std::function<void (const HttpResponsePtr &)> &&callback
	    ){
			Json::Value json;
			json["error"]["message"] = exception.what();
			callback(HttpResponse::newHttpJsonResponse(json));
		}
	);

	std::cout << "set exception handler\n";
	auto cur_dir = get_current_dir() + "/static";

	std::cout << "Using static dir as \"" + cur_dir + "\"\n";

	app()
	.setDocumentRoot(cur_dir)
	.addALocation("/", cur_dir)
	.setFileTypes({"html", "js", "css"});

	std::cout << "Starting\n";

	app().setIdleConnectionTimeout(10);
	app().setLogLevel(trantor::Logger::kTrace);

	app().addListener("0.0.0.0", 3041);
	std::cout << "set listener\n";

	app().setThreadNum(64);
	std::cout << "set thread num\n";
	//.enableRunAsDaemon()
	//.enableReusePort()
	std::cout << "Run ###\n";
	app().run();
#else
	std::cout << "I cant run webserver due to no drogon lib";
#endif
	return 0;
}

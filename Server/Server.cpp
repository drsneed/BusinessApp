// BusinessApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>
#include <cpprest/json.h>
using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


void handle_get(http_request request)
{
	cout << "RECEIVED 'GET' REQUEST" << endl;

	json::value obj;
	obj[U("name")] = json::value::string(U("Ludwig"));

	request.reply(status_codes::OK, obj);
}

int main()
{
	http_listener listener{ U("http://localhost:8819") };
	listener.support(methods::GET, handle_get);
	try
	{
		listener
			.open()
			.then([&listener]() {wcout << (L"\nstarting to listen\n"); })
			.wait();

		while (true);
	}
	catch (exception const & e)
	{
		wcout << e.what() << endl;
	}
    return 0;
}


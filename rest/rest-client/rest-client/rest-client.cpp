// rest-client.cpp : Simple example which downloads data in asynchronous fashion
//

#pragma once
#include <tchar.h>
#include <iostream>
#include <cpprest\http_client.h>
#include <cpprest\http_msg.h>

using namespace concurrency;
using namespace concurrency::streams;
using namespace web::http;
using namespace web::http::client;

int _tmain(int argc, _TCHAR* argv[])
{
	http_client client(L"http://feeds.feedburner.com/PythonInsider?format=xml");
	http_request request(methods::GET);
	std::wcout << "Initializing client" << std::endl;
	client.request(request).then([](http_response response)
	{
		// Perform actions here to inspect the HTTP response...
		if (response.status_code() == status_codes::OK)
		{
			std::wcout << "Ok.";
		} else {
			std::wcout << "Error.";
		}

		std::wcout << " Result code : " << response.status_code() << std::endl;
		std::wcout << "Response, reading 512 bytes" << std::endl;
		istream bodyStream = response.body();
		container_buffer<std::string> inStringBuffer;
			
		return bodyStream.read(inStringBuffer, 512).then([inStringBuffer](size_t bytesRead){
			const std::string &text = inStringBuffer.collection();
			std::wcout << text.c_str();
		});
	}).wait();

	return 0;
}


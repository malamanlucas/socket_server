#pragma once
#include "include.h"

class Server {
public: 
	void init();
	void listenClients();
	void handleMessage(char* msg);
};
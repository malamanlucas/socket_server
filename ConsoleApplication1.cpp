#include "include.h"
#include "Server.h"

int qtClients = 0;
bool running = true;
fd_set master;
Server server;

int main()
{
	thread th1([]() {
		server.init();
		server.listenClients();
	});

	thread th3([]() {
		while (true) {
			if (GetAsyncKeyState(VK_SCROLL) & 1) {
				running = false;
				break;
			}
			if (GetAsyncKeyState(VK_INSERT) & 1) {
				cout << qtClients << " clients." << endl;
				for (int i = 0; i < master.fd_count; i++)
				{
					SOCKET outSock = master.fd_array[i];
					ostringstream buffer;
					buffer << "test broadcasting" << endl;
					send(outSock, buffer.str().c_str(), buffer.str().size() + 1, 0);
				}
			}
			/*containers->drawLoot();
			player->inventory->refillBurstArrows();*/
			Sleep(10);
		}
	});

	th3.join();
	th1.join();
	//system("pause");
	return 0;
}
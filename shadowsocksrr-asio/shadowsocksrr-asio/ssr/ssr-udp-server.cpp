#include "ssr-udp-server.h"

SsrUdpServer::SsrUdpServer(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref)
	:io_service_(io_service), ssr_config_(ssr_config), socket_in_(io_service)
{
	parents_server_ref_ = parents_server_ref->weak_from_this();
}

void SsrUdpServer::start()
{
	// start to run

	// TODO 1, create ssr stack
	// TODO 2, async receive a UDP package from port same as TCP
	// TODO 3, push the UDP package to ssr server stack, 
	// TODO 4, a raw UDP package and info spit out from ssr server stack, send the raw UDP package
	// TODO 5, [need registe the receive connect and user and send port as the key-pair to make a (ssr_client_and_udp_endpoint-2-ssr_server_port) binding]
	// TODO 6, listen on the UDP send port and make a timeout-timer to terminal it (remove the registed info), if registed ssr_client_and_udp_endpoint send again or registed ssr_server_port received, reset timer 0 to recount
	// TODO 7, goto 2
}

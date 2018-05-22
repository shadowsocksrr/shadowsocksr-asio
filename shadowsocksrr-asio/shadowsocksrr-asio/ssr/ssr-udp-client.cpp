#include "ssr-udp-client.h"

SsrUdpClientSession::SsrUdpClientSession(boost::asio::io_service& io_service, std::shared_ptr<SsrUdpClient> parents_server_ref)
	:socket_out_(io_service), timer_(io_service)
{
	parents_server_ref_ = parents_server_ref->weak_from_this();
}

void SsrUdpClientSession::start(boost::asio::ip::udp::endpoint endpoint_in)
{
	endpoint_in_ = endpoint_in;

	// TODO request and register a new local UDP port , to fill endpoint_out

	// TODO run listen(recv)
}

void SsrUdpClientSession::next_package()
{
	// 
}

SsrUdpClient::SsrUdpClient(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref)
	:io_service_(io_service), ssr_config_(ssr_config), socket_in_(io_service)
{
	parents_server_ref_ = parents_server_ref->weak_from_this();
}

void SsrUdpClient::start()
{
	// start to run

	// draft 1
	// TO DO 1, create ssr stack
	// TO DO 2, async receive a UDP package from port same as TCP
	// TO DO 3, push the UDP package to ssr client stack, 
	// TO DO 4, a ssr UDP package spit out from ssr server stack, send the ssr UDP package use a new port
	// TO DO 5, [need registe the receive endpoint(user client) and send port as the key-pair to make a (user_client_udp_endpoint-2-ssr_client_port) binding]
	// TO DO 6, listen on the UDP send port and make a timeout-timer to terminal it (remove the registed info), if registed user_client_udp_endpoint send again or registed ssr_client_port received, reset timer 0 to recount
	// TO DO 7, goto 2

	// draft 2
	// TODO 1, create ssr stack
	// TODO 2, async receive a UDP package from port same as TCP (main listen endpoint)
	// TODO 3, push the UDP package to socsk5 stack, 
	// TODO 4, a raw UDP package and info spit out from socks5 stack, create SsrUdpClientSession or put it to exist one, [this step will registe new one or use a registed one]
	// TODO 5.1, SsrUdpClientSession put raw UDP package to ssr client stack, a ssr UDP package spit out from ssr client stack, and send ssr UDP package
	// TODO 5.2, SsrUdpClientSession listen on send port to recv back package from ssr server , use ssr client stack decode it, a raw UDP package and info spit out
	// TODO 5.3, SsrUdpClientSession put raw UDP package and info to socks5 stack , get socks5 UDP package , send back to user client use main listen endpoint
	// TODO 6, goto 2

}

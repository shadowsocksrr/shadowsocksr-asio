#include "ssr-session-server.h"

SsrSessionServer::SsrSessionServer(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref)
	: io_service_(io_service), ssr_config_(ssr_config), socket_in_(io_service), socket_out_(io_service)
{
	parents_server_ref_ = parents_server_ref->weak_from_this();
}

boost::asio::ip::tcp::socket& SsrSessionServer::accept_socket()
{
	return socket_in_;
}

void SsrSessionServer::start()
{
	// now, a socket accepted, begin run

	// TODO 1, create ssr stack,
	// TODO 2, receive request and push it to ssr server stack,
	// TODO 3, the raw data or task are spit out from ssr server stack, follow it to do something,
	// TODO    [maybe need resolve dns on this step 3]
	// TODO 4, contiue transfor data or close connect
}

#include "ssr-session-client.h"

SsrSessionClient::SsrSessionClient(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref)
	: io_service_(io_service), ssr_config_(ssr_config), socket_in_(io_service), socket_out_(io_service)
{
	parents_server_ref_ = parents_server_ref->weak_from_this();
}

boost::asio::ip::tcp::socket& SsrSessionClient::accept_socket()
{
	return socket_in_;
}

void SsrSessionClient::start()
{
	// now, a socket accepted, begin run

	// TODO 1, create socks5 server stack,
	// TODO 2, receive request and push to socks5 stack to verify and analysis it,
	// TODO 3, create ssr stack, [maybe need resolve ssr server dns on this step 3]
	// TODO 4, push the request or raw data which decode from socks5 stack,
	// TODO    and push it to ssr client stack,
	// TODO 5, the ssr data or task are spit out from ssr client stack, follow it to do something
	// TODO    [maybe it's a UDP ASSOCIATE socks5, let's tell the socks5 client to connect to the  and wait the socks5 income sockets]
	// TODO 6, contiue transfor data or close connect
}

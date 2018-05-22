#include "ssr-dns-resolver.h"

SsrDnsResolver::SsrDnsResolver(boost::asio::io_service& io_service)
	:io_service_(io_service), tcp_resolver(io_service_), udp_resolver(io_service_)
{}

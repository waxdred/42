/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:32:21 by jmilhas           #+#    #+#             */
/*   Updated: 2022/08/18 10:53:44 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include <exception>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>
#include <sys/_endian.h>
#include <vector>
# include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iomanip>
#include <sstream>

namespace irc {
	class	Connect{
		private:	
			std::string _port; 
			std::string _password; 
			int _server;
			int _client;
	                //struct setting socket address 
			struct sockaddr_in _addrServer;
			struct sockaddr_in _addrClient;
			socklen_t _sizeClient;
			Connect(void);
			
		public:
			Connect(std::string &port, std::string &password){
				if (_check_port(port))
					throw ErrorTCP("Error TCP unvalid");
				_port = port;
				_password = password;
				//create soket AF_INET  => ipv4 | type socket SOCK_STREAM => protocol TCP
				_server = socket(AF_INET, SOCK_STREAM, 0);
				if (_server == -1)
					throw ErrorTCP("Error Socker can't be create");

				_addrServer.sin_addr.s_addr = inet_addr("0.0.0.0");
				_addrServer.sin_family = AF_INET;
				_addrServer.sin_port = htons(std::atoi(_port.c_str()));
	
				//connetion server with bind
				if (bind(_server, (const struct sockaddr *)&_addrServer, sizeof(_addrServer)) == -1){
					throw ErrorTCP("Error bind");
				}else{
					std::cout << "bind: " << _server << std::endl;
				}
				_display();
				listen(_server, 5);
				_sizeClient = sizeof(_addrClient);
				//wait connection client
				_client = accept(_server, (struct sockaddr *)&_addrClient, &_sizeClient);
				std::cout << "Client connected:" << std::endl;
			};
	
			Connect(const Connect &connect);
			~Connect(void){
				close(_server);
				close(_client);
			};
			Connect &operator = (const Connect &fn_class);
			void ft_run(void){
				char buff[256];
				int i = 0;
				while (i < 4){
					if (_client == -1)
						throw ErrorTCP("connection lost");
					// receive command from client
				        recv(_client, &buff, sizeof(buff), 0);
					if (strcmp("PING", buff) == 0)
				                send(_server, "PONG", sizeof(char) * 5, 0);
					// send command for client
				        send(_server, &buff, sizeof(std::string), 0);
				        std::cout << buff;
					i++;
				};
	
			}
			class ErrorTCP :public std::runtime_error{
				public: 
					ErrorTCP(const char *msg) : std::runtime_error(msg){};
			};
	
		private:
			bool _check_port(std::string &port)const{
				if (port.length() > 0 && port.length() < 5 && !_isDigit(port))
					return (false);
				int p = std::atoi(port.c_str());
				if (_attribution_port(p))
					return (false);
				return (true);
			}
	
			bool _isDigit(std::string &port) const{
				for (int i = 0; port[i]; i++){
					if(!std::isdigit(port[i]))
						return (false);
				}
				return (true);
			}
	
			bool _attribution_port(int p)const{
				std::vector<int> att;
				att = _allAtribute();
				for (std::vector<int>::iterator it = att.begin(); it != att.end(); it++){
					if (*it == p)
						return false;
				} 
				return (true);
			}
	
			std::vector<int>_allAtribute(void)const{
				std::vector<int> att;
	
				att.push_back(0);
				att.push_back(5);
				att.push_back(24);
				att.push_back(39);
				att.push_back(42);
				att.push_back(138);
				att.push_back(500);
				att.push_back(993);
				att.push_back(5000);
				for (int i = 50; i < 70; i++)
					att.push_back(i);
				for (int i = 75; i < 87; i++)
					att.push_back(i);
				for (int i = 90; i < 100; i++)
					att.push_back(i);
				for (int i = 120; i < 126; i++)
					att.push_back(i);
				for (int i = 127; i < 134; i++)
					att.push_back(i);
				for (int i = 127; i < 134; i++)
					att.push_back(i);
				for (int i = 752; i < 755; i++)
					att.push_back(i);
				for (int i = 897; i < 904; i++)
					att.push_back(i);
				return (att);
			}
	
			void _display(void){
				std::cout << "┌───────────────────────────────────────────────┐" << std::endl;
				std::cout << "│                                               │" << std::endl;
				std::cout << "│ " << std::setw(25) << std::right << "ft_irc v1" << std::setw(24) << "│" << std::endl;
				std::cout << "│ " << std::setw(28) << std::right << "http://127.0.0.1:" << _port << std::setw(21 - (_port.length())) << "│" << std::endl;
				std::cout << "│ " << std::setw(29) << std::right << "(host 0.0.0.0 port: " << _port << ")" << std::setw(19 - (_port.length())) << "│" << std::endl;
				std::cout << "│                                               │" << std::endl;
				std::cout << "│ " << "Bind " << std::setfill('.') << std::setw(10)<< _server << std::setfill(' ') 
					          << std::setw(20) << std::right << "Processes " << std::setfill('.') << std::setw(10)<< '1' << std::setfill(' ') << " │" << std::endl;
				std::cout << "│ " << "Listen " << std::setfill('.') << std::setw(8)<< _client << std::setfill(' ') 
						  << std::setw(14) << std::right << "Pid " << std::setfill('.') << std::setw(16)<< getpid() << std::setfill(' ') << " │" << std::endl;
				std::cout << "│                                               │" << std::endl;
				std::cout << "└───────────────────────────────────────────────┘" << std::endl;
			}
	};
	#endif /* ifndef CONNECT_HPP */

}//namespace irc

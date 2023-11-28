/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"
#include <iostream>
#include <cstring>
#include <cerrno>

extern "C" {
    #include <fcntl.h>
    #include <unistd.h>
}

Network::Network() : sock_(-1), port_(0), ip_(nullptr), message_(nullptr) {}

Network::Network(int port, const char* ip)
{
    sock_ = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_ < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(84);
    }

    ip_ = strdup(ip);
    port_ = port;

    server_.sin_family = AF_INET;
    server_.sin_addr.s_addr = inet_addr(ip_);
    server_.sin_port = htons(port_);

    if (connect(sock_, reinterpret_cast<struct sockaddr*>(&server_), sizeof(server_)) < 0) {
        std::cerr << "Failed to connect to the server" << std::endl;
        close(sock_);
        exit(84);
    }

    while (std::strcmp(receive_message().c_str(), "WELCOME\n") != 0);
    send_message("GRAPHIC\n");
}

Network::~Network()
{
    if (sock_ != -1)
        close(sock_);
}

void Network::send_message(const std::string& message)
{
    int length_message = message.length();

    if (send(sock_, message.c_str(), length_message, 0) == -1)
        std::cerr << "Error: Can't send the message" << std::endl;
}

std::string Network::receive_message()
{
    char buffer[_bufferLength];
    memset(buffer, 0, _bufferLength);

    int lengthMessage = recv(sock_, buffer, _bufferLength - 1, 0);

    if (lengthMessage > 0) {
        message_.append(buffer);
        return message_;
    }
    return nullptr;
}

void Network::initializeData(DataManager& data)
{
    std::vector<std::string> splitMessages;
    
    clearMessage();
    send_message("tna\n");
    data = parser.parsing_msg(data, receive_message());
    send_message("msz\n");
    data = parser.parsing_msg(data, receive_message());
    send_message("sgt\n");
    data = parser.parsing_msg(data, receive_message());
    clearMessage();
    data = UpdateMap(data);

}

DataManager Network::UpdateMap(DataManager data)
{
    for (int x = 0; x != data.getSize().x; x++) {
        for (int z = 0; z != data.getSize().y; z++) {
            std::string message = "bct " + std::to_string(x) + " " + std::to_string(z) + "\n";
            send_message(message);
            data = parser.parsing_msg(data, receive_message());
            clearMessage();
        } 
    }
    return (data);
}

DataManager Network::updateTilePlayer(Vector3 pos, DataManager data)
{
    std::string message;
    int x = (pos.x + 0.5f);
    int y = (pos.z + 0.5f);
    message = ("bct " + std::to_string(x) + ' ' + std::to_string(y) +"\n");
    send_message(message);
    return parser.parsing_msg(data, receive_message());
}

DataManager Network::UpdatePlayer(DataManager data)
{   
    for (auto team : data.getAllTeams()) {
        if (team.getAllPlayers().size() != 0)
            for (auto player : team.getAllPlayers()) {
                std::string message;
                message = "ppo " + std::to_string(player.getId()) + "\n";
                send_message(message);
                data = parser.parsing_msg(data, receive_message());
                clearMessage();
                message = "pin " + std::to_string(player.getId()) + "\n";
                send_message(message);
                data = parser.parsing_msg(data, receive_message());
                clearMessage();
                data = updateTilePlayer(player.getPos(), data);
            }
    }
    return data;
}

void Network::updateData(DataManager &data)
{
    currentTime = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsedTimePlayer = currentTime - startTimePlayer;
    if (elapsedTimePlayer >= std::chrono::seconds(1)) 
    {
        data = UpdatePlayer(data);
        startTimePlayer = currentTime;
    }

    send_message("sgt\n");
    data = parser.parsing_msg(data, receive_message());
    clearMessage();
} 

void Network::clearMessage()
{
    message_.clear();
}

std::string Network::getMessage() const
{
    return message_;
}

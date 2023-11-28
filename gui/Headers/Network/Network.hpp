/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Newtork
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

    #include "Parser.hpp"
    #include <chrono>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <string>

    #define LOCALHOST "127.0.0.1"

class Network {
    public:
        Network();
        Network(int port, const char *ip);
        ~Network();

        Parser parser;

        void send_message(const std::string&);
        std::string receive_message(void);
        std::string getMessage(void) const;
        void clearMessage();

        void initializeData(DataManager&);

        DataManager updateTilePlayer(Vector3 pos, DataManager data);
        DataManager UpdatePlayer(DataManager);
        DataManager UpdateMap(DataManager);
        void updateData(DataManager&);

    private:
        const int _bufferLength = 1024;

        int sock_;
        int port_;
        char *ip_;

        std::string message_;
        sockaddr_in server_;

        std::chrono::steady_clock::time_point startTimePlayer = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point currentTime;
};

#endif